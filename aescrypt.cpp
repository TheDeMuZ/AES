#include "aescrypt.h"
AesLibrary::AesLibrary(int method) {
	this->nb = 4; //liczba kolumn
	if (method == 128) {
		this->nk = 4; //Liczba 32-bitowych s³ów sk³adaj¹cych siê na klucz szyfrowania. 
		this->nr = 10;
	}
	else if (method == 192) {
		this->nk = 6;
		this->nr = 12;
	}
	else {
		this->nk = 8;
		this->nr = 14;
	}
	blockBytesLen = 4 * this->nb;
}
void AesLibrary::rotWord(unsigned char *tab)
{
	unsigned char sign = tab[0];
	tab[0] = tab[1];
	tab[1] = tab[2];
	tab[2] = tab[3];
	tab[3] = sign;
}
void AesLibrary::subWord(unsigned char *tab) {
	for (int i = 0; i < 4; i++)
		tab[i] = sbox[tab[i] / 16][tab[i] % 16];
}
unsigned char AesLibrary::xTime(unsigned char b) {    // multiply on x{
	unsigned char mask = 0x80, m = 0x1b;
	unsigned char high_bit = b & mask;
	b = b << 1;
	if (high_bit) {    // mod m(x)
		b = b ^ m;
	}
	return b;
}
void AesLibrary::rCon(unsigned char * tab, int n) {
	unsigned char c = 1;
	for (int i = 0; i < n - 1; i++)
		c = xTime(c);

	tab[0] = c;
	tab[1] = 0;
	tab[2] = 0;
	tab[3] = 0;
}
void AesLibrary::xorWords(unsigned char *tabA, unsigned char *tabB, unsigned char *outTab) {
	for (int i = 0; i < 4; i++)
		outTab[i] = tabA[i] ^ tabB[i];
}
void AesLibrary::keyExpansion(unsigned char key[], unsigned char expandedKey[]) {
	unsigned char *tmp = new unsigned char[4];
	unsigned char *rcon = new unsigned char[4];
	for (int i = 0; i < 4 * nk; i++)
		expandedKey[i] = key[i];//jest to operacja przepisania klucza
	for (int i = 4 * nk; i < 4 * nb * (nr + 1); i += 4) {//nastepnie od pozostalej ilosci bajtow dorabiamy klucz ta pêtl¹

		for (int j = 0; j < 4; j++)
			tmp[j] = expandedKey[i - 4 + j];
		if (i / 4 % nk == 0) {
			rotWord(tmp);//cykliczna permutacja
			subWord(tmp);
			rCon(rcon, i / (nk * 4));
			xorWords(tmp, rcon, tmp);
		}
		else if (nk > 6 && i / 4 % nk == 4) {
			subWord(tmp);
		}
		for (int j = 0; j < 4; j++)
			expandedKey[i + j] = expandedKey[i + j - 4 * nk] ^ tmp[j];

	}
	delete[]rcon, tmp;
}
void AesLibrary::addRoundKey(unsigned char **state, unsigned char *expandedKey) {
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < nb; j++)
			state[i][j] = state[i][j] ^ expandedKey[i + 4 * j];

}
void AesLibrary::subBytes(unsigned char **state) {
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < nb; j++)
			state[i][j] = sbox[state[i][j] / 16][state[i][j] % 16];
}
void AesLibrary::shiftRows(unsigned char **state) {
	unsigned char tmp;
	//petla przesuwajaca i rzad o n pozycji w petli //0 nie przesuwamy //1 o 1 // 2 o 2 // 3 o 3
	for (int i = 1; i <= 3; i++)
		for (int k = 0; k < i; k++) {
			tmp = state[i][0];
			for (int j = 0; j < nb - 1; j++)
				state[i][j] = state[i][j + 1];
			state[i][nb - 1] = tmp;
		}
}
unsigned char AesLibrary::multiplicationBytes(unsigned char a, unsigned char b) {
	unsigned char product, one = 1, bit, tmp;
	for (int i = 0; i < 8; i++) {
		bit = b & one;
		if (bit) {
			tmp = a;
			for (int j = 0; j < i; j++)
				tmp = xTime(tmp);//x^i
			product = product ^ tmp;
		}
		b = b >> 1;
	}
	return product;
}
void AesLibrary::mixColumns(unsigned char **state) {
	unsigned char tab[4], tab1[4];
	for (int i = 0; i < nb; i++) {
		for (int j = 0; j < 4; j++)
			tab[j] = state[j][i];

		tab1[0] = multiplicationBytes(0x02, tab[0]) ^ multiplicationBytes(0x03, tab[1]) ^ tab[2] ^ tab[3];
		tab1[1] = tab[0] ^ multiplicationBytes(0x02, tab[1]) ^ multiplicationBytes(0x03, tab[2]) ^ tab[3];
		tab1[2] = tab[0] ^ tab[1] ^ multiplicationBytes(0x02, tab[2]) ^ multiplicationBytes(0x03, tab[3]);
		tab1[3] = multiplicationBytes(0x03, tab[0]) ^ tab[1] ^ tab[2] ^ multiplicationBytes(0x02, tab[3]);

		for (int j = 0; j < 4; j++)
			state[j][i] = tab1[j];
	}
}
void AesLibrary::encryptBlock(unsigned char textIn[], unsigned char textOut[], unsigned  char key[]) {
	unsigned char *expandedKey = new unsigned char[4 * nb*(nr + 1)];
	keyExpansion(key, expandedKey);
	unsigned char **state = new unsigned char *[4];
	state[0] = new unsigned  char[4 * nb];
	for (int i = 0; i < 4; i++)
		state[i] = state[0] + nb * i;

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < nb; j++)
			state[i][j] = textIn[i + 4 * j];

	addRoundKey(state, expandedKey);
	for (int i = 1; i <= nr - 1; i++) {
		subBytes(state);
		shiftRows(state);
		mixColumns(state);
		addRoundKey(state, expandedKey + (i*nb * 4));
	}
	//runda konczaca
	subBytes(state);
	shiftRows(state);
	addRoundKey(state, expandedKey + (nr * 4)*nb);

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < nb; j++)
			textOut[i + 4 * j] = state[i][j];

	delete[] state[0], state, expandedKey;
}

unsigned char *AesLibrary::encrypt(unsigned char plainText[], unsigned int plainTextLen, unsigned  char key[]) {
	unsigned int outTextLen = (plainTextLen / blockBytesLen) * blockBytesLen;//tworzy nam odpowiednio 16 32 ....
	unsigned char *outText = new unsigned char[outTextLen];
	for (unsigned int i = 0; i < outTextLen; i += blockBytesLen) {
		encryptBlock(plainText + i, outText + i, key);
	}
	return outText;
}


void AesLibrary::invSubBytes(unsigned char **state) {
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < nb; j++)
			state[i][j] = inv_sbox[state[i][j] / 16][state[i][j] % 16];
}
void AesLibrary::invMixColumns(unsigned char **state) {
	unsigned char tab[4], tab1[4];
	for (int i = 0; i < nb; i++) {
		for (int j = 0; j < 4; j++)
			tab[j] = state[j][i];

		tab1[0] = multiplicationBytes(0x0e, tab[0]) ^ multiplicationBytes(0x0b, tab[1]) ^ multiplicationBytes(0x0d, tab[2]) ^ multiplicationBytes(0x09, tab[3]);
		tab1[1] = multiplicationBytes(0x09, tab[0]) ^ multiplicationBytes(0x0e, tab[1]) ^ multiplicationBytes(0x0b, tab[2]) ^ multiplicationBytes(0x0d, tab[3]);
		tab1[2] = multiplicationBytes(0x0d, tab[0]) ^ multiplicationBytes(0x09, tab[1]) ^ multiplicationBytes(0x0e, tab[2]) ^ multiplicationBytes(0x0b, tab[3]);
		tab1[3] = multiplicationBytes(0x0b, tab[0]) ^ multiplicationBytes(0x0d, tab[1]) ^ multiplicationBytes(0x09, tab[2]) ^ multiplicationBytes(0x0e, tab[3]);

		for (int j = 0; j < 4; j++)
			state[j][i] = tab1[j];
	}
}
void AesLibrary::invShiftRows(unsigned char **state) {
	unsigned char tmp;
	for (int i = 1; i <= 3; i++)
		for (int k = 0; k < nb - i; k++) {//zmiana w tym miejscu nb -1 czyli na odwrot
			tmp = state[i][0];
			for (int j = 0; j < nb - 1; j++)
				state[i][j] = state[i][j + 1];
			state[i][nb - 1] = tmp;
		}
}
void AesLibrary::decryptBlock(unsigned char textIn[], unsigned char textOut[], unsigned  char key[]) {
	unsigned char *expandedKey = new unsigned char[4 * nb*(nr + 1)];
	keyExpansion(key, expandedKey);
	unsigned char **state = new unsigned char *[4];
	state[0] = new unsigned  char[4 * nb];
	for (int i = 0; i < 4; i++)
		state[i] = state[0] + nb * i;

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < nb; j++)
			state[i][j] = textIn[i + 4 * j];

	addRoundKey(state, expandedKey + (nr * 4)*nb);
	for (int i = nr - 1; i >= 1; i--) {
		invSubBytes(state);
		invShiftRows(state);
		addRoundKey(state, expandedKey + (i*nb * 4));
		invMixColumns(state);
	}
	//runda konczaca
	invSubBytes(state);
	invShiftRows(state);
	addRoundKey(state, expandedKey);

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < nb; j++)
			textOut[i + 4 * j] = state[i][j];

	delete[] state[0], state, expandedKey;
}
unsigned char *AesLibrary::decrypt(unsigned char encryptedText[], unsigned int encryptedTextLen, unsigned  char key[]) {
	unsigned int outTextLen = (encryptedTextLen / blockBytesLen) * blockBytesLen;//tworzy nam odpowiednio 16 32 ....
	unsigned char *outText = new unsigned char[outTextLen];
	for (unsigned int i = 0; i < outTextLen; i += blockBytesLen) {
		decryptBlock(encryptedText + i, outText + i, key);
	}
	return outText;
}