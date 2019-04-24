#pragma once

namespace AES {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Podsumowanie informacji o MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
	



		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: W tym miejscu dodaj kod konstruktora
			//


		}

	protected:
		/// <summary>
		/// Wyczyœæ wszystkie u¿ywane zasoby.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^  tabControl1;
	protected:
	private: System::Windows::Forms::TabPage^  tabPage1;

	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  decryptButton;

	private: System::Windows::Forms::Button^  encryptButton;
	private: System::Windows::Forms::RichTextBox^  outText;

	private: System::Windows::Forms::RichTextBox^  inText;




	private: System::Windows::Forms::TextBox^  keyText;


	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label4;




	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  keyFile;

	private: System::Windows::Forms::TextBox^  fileNameIn;


	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::OpenFileDialog^  openFile;
	private: System::Windows::Forms::Button^  decryptButtonFile;
	private: System::Windows::Forms::Button^  encryptButtonFile;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  fileNameOut;
	private: System::Windows::Forms::ComboBox^  methodData;


	private: System::Windows::Forms::Label^  label8;
















	protected:

	private:
		/// <summary>
		/// Wymagana zmienna projektanta.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metoda wymagana do obs³ugi projektanta — nie nale¿y modyfikowaæ
		/// jej zawartoœci w edytorze kodu.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->methodData = (gcnew System::Windows::Forms::ComboBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->decryptButton = (gcnew System::Windows::Forms::Button());
			this->encryptButton = (gcnew System::Windows::Forms::Button());
			this->outText = (gcnew System::Windows::Forms::RichTextBox());
			this->inText = (gcnew System::Windows::Forms::RichTextBox());
			this->keyText = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->fileNameOut = (gcnew System::Windows::Forms::TextBox());
			this->decryptButtonFile = (gcnew System::Windows::Forms::Button());
			this->encryptButtonFile = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->keyFile = (gcnew System::Windows::Forms::TextBox());
			this->fileNameIn = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->openFile = (gcnew System::Windows::Forms::OpenFileDialog());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Location = System::Drawing::Point(0, 0);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(798, 308);
			this->tabControl1->TabIndex = 0;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->label8);
			this->tabPage1->Controls->Add(this->methodData);
			this->tabPage1->Controls->Add(this->label4);
			this->tabPage1->Controls->Add(this->label3);
			this->tabPage1->Controls->Add(this->decryptButton);
			this->tabPage1->Controls->Add(this->encryptButton);
			this->tabPage1->Controls->Add(this->outText);
			this->tabPage1->Controls->Add(this->inText);
			this->tabPage1->Controls->Add(this->keyText);
			this->tabPage1->Controls->Add(this->label2);
			this->tabPage1->Controls->Add(this->label1);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(790, 282);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Szyfrowanie tekstu";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(606, 114);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(116, 13);
			this->label8->TabIndex = 11;
			this->label8->Text = L"Wprowadzanie danych";
			// 
			// methodData
			// 
			this->methodData->FormattingEnabled = true;
			this->methodData->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Text", L"hex" });
			this->methodData->Location = System::Drawing::Point(626, 142);
			this->methodData->Name = L"methodData";
			this->methodData->Size = System::Drawing::Size(80, 21);
			this->methodData->TabIndex = 10;
			this->methodData->Text = L"Text";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(11, 10);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(79, 13);
			this->label4->TabIndex = 9;
			this->label4->Text = L"WprwadŸ dane";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(8, 198);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(33, 13);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Klucz";
			// 
			// decryptButton
			// 
			this->decryptButton->Location = System::Drawing::Point(626, 62);
			this->decryptButton->Name = L"decryptButton";
			this->decryptButton->Size = System::Drawing::Size(80, 30);
			this->decryptButton->TabIndex = 6;
			this->decryptButton->Text = L"Deszyfruj";
			this->decryptButton->UseVisualStyleBackColor = true;
			this->decryptButton->Click += gcnew System::EventHandler(this, &MainForm::decryptButton_Click);
			// 
			// encryptButton
			// 
			this->encryptButton->Location = System::Drawing::Point(626, 26);
			this->encryptButton->Name = L"encryptButton";
			this->encryptButton->Size = System::Drawing::Size(80, 30);
			this->encryptButton->TabIndex = 5;
			this->encryptButton->Text = L"Zaszyfruj";
			this->encryptButton->UseVisualStyleBackColor = true;
			this->encryptButton->Click += gcnew System::EventHandler(this, &MainForm::encryptButton_Click);
			// 
			// outText
			// 
			this->outText->Location = System::Drawing::Point(314, 32);
			this->outText->Name = L"outText";
			this->outText->Size = System::Drawing::Size(280, 150);
			this->outText->TabIndex = 4;
			this->outText->Text = L"";
			// 
			// inText
			// 
			this->inText->Location = System::Drawing::Point(14, 32);
			this->inText->Name = L"inText";
			this->inText->Size = System::Drawing::Size(280, 150);
			this->inText->TabIndex = 3;
			this->inText->Text = L"";
			// 
			// keyText
			// 
			this->keyText->Location = System::Drawing::Point(14, 222);
			this->keyText->Name = L"keyText";
			this->keyText->Size = System::Drawing::Size(583, 20);
			this->keyText->TabIndex = 2;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(311, 10);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(77, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Wynik operacji";
			// 
			// label1
			// 
			this->label1->Location = System::Drawing::Point(0, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(100, 23);
			this->label1->TabIndex = 8;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->label7);
			this->tabPage2->Controls->Add(this->fileNameOut);
			this->tabPage2->Controls->Add(this->decryptButtonFile);
			this->tabPage2->Controls->Add(this->encryptButtonFile);
			this->tabPage2->Controls->Add(this->button3);
			this->tabPage2->Controls->Add(this->label6);
			this->tabPage2->Controls->Add(this->keyFile);
			this->tabPage2->Controls->Add(this->fileNameIn);
			this->tabPage2->Controls->Add(this->label5);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(790, 282);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Szyfrowanie pliku";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(24, 105);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(144, 13);
			this->label7->TabIndex = 8;
			this->label7->Text = L"Nazwa zaszyfrowanego pliku";
			// 
			// fileNameOut
			// 
			this->fileNameOut->Location = System::Drawing::Point(27, 130);
			this->fileNameOut->Name = L"fileNameOut";
			this->fileNameOut->Size = System::Drawing::Size(304, 20);
			this->fileNameOut->TabIndex = 7;
			// 
			// decryptButtonFile
			// 
			this->decryptButtonFile->Location = System::Drawing::Point(120, 167);
			this->decryptButtonFile->Name = L"decryptButtonFile";
			this->decryptButtonFile->Size = System::Drawing::Size(75, 23);
			this->decryptButtonFile->TabIndex = 6;
			this->decryptButtonFile->Text = L"Deszyfruj";
			this->decryptButtonFile->UseVisualStyleBackColor = true;
			this->decryptButtonFile->Click += gcnew System::EventHandler(this, &MainForm::decryptButtonFile_Click);
			// 
			// encryptButtonFile
			// 
			this->encryptButtonFile->Location = System::Drawing::Point(27, 167);
			this->encryptButtonFile->Name = L"encryptButtonFile";
			this->encryptButtonFile->Size = System::Drawing::Size(75, 23);
			this->encryptButtonFile->TabIndex = 5;
			this->encryptButtonFile->Text = L"Zaszyfruj";
			this->encryptButtonFile->UseVisualStyleBackColor = true;
			this->encryptButtonFile->Click += gcnew System::EventHandler(this, &MainForm::encryptButtonFile_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(337, 24);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 20);
			this->button3->TabIndex = 4;
			this->button3->Text = L"Wybierz plik";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MainForm::button3_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(24, 55);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(33, 13);
			this->label6->TabIndex = 3;
			this->label6->Text = L"Klucz";
			// 
			// keyFile
			// 
			this->keyFile->Location = System::Drawing::Point(27, 71);
			this->keyFile->Name = L"keyFile";
			this->keyFile->Size = System::Drawing::Size(304, 20);
			this->keyFile->TabIndex = 2;
			// 
			// fileNameIn
			// 
			this->fileNameIn->Location = System::Drawing::Point(27, 24);
			this->fileNameIn->Name = L"fileNameIn";
			this->fileNameIn->Size = System::Drawing::Size(304, 20);
			this->fileNameIn->TabIndex = 1;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(24, 7);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(70, 13);
			this->label5->TabIndex = 0;
			this->label5->Text = L"Œcie¿ka pliku";
			// 
			// openFile
			// 
			this->openFile->FileName = L"openFileDialog1";
			this->openFile->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &MainForm::openFile_FileOk);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(738, 306);
			this->Controls->Add(this->tabControl1);
			this->Name = L"MainForm";
			this->Text = L"Algorytm szyfrowania AES";
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			this->ResumeLayout(false);

		}

#pragma endregion


private: array<Byte>^ makeManagedArray(unsigned char* input, int len)
{
	array<Byte>^ result = gcnew array<Byte>(len);
	for (int i = 0; i < len; i++)
    {
		result[i] = input[i];
	}
	 return result;
}
private: int complementCount(int len) {
	if ((len % 16) != 0) {
		len = (len / 16 + 1) * 16;
	}
	return len;
}
private: unsigned char* makeUnManagedChar(array<unsigned char>^ tab, int tabLenTmp, int tabOrgLen) {
	unsigned char* tabUnChar = new unsigned char[tabLenTmp];
	for (int i = 0; i < tabLenTmp; i++) {
		if (i < tabOrgLen) {
			tabUnChar[i] = tab[i];
		}
		else {
			tabUnChar[i] = 0;
		}
	}
	return tabUnChar;
}
private: int* makeCharToInt(array<unsigned char>^ tab) {
	int*tabInt = new int[tab->Length];
	for (int i = 0; i < tab->Length; i++) {
		tabInt[i] = (int)tab[i];
	}
	return tabInt;
}
private: String^ addHexInfo(array<unsigned char>^ tab) {
	String ^ text = System::Text::Encoding::ASCII->GetString(tab);
	int*tabInt = new int[tab->Length];
	tabInt = makeCharToInt(tab);
	Int32^ numer;
	text += "\n Zapis w hexa\n";
	int test;
	for (int i = 0; i < tab->Length; i++) {
		numer = System::Convert::ToInt32(tabInt[i]);
		text += numer->ToString("x");
		text += " ";
	}
	delete tabInt;
	return text;
}

private: array<unsigned char>^hexToDec(){
	String ^textIn = inText->Text;
	array<String^>^ tab =textIn->Split();
	unsigned char* tab2 = new unsigned char[tab->Length];
	int tmp;
	for (int i = 0; i < tab->Length; i++) {
		tmp = System::Int32::Parse(tab[i], System::Globalization::NumberStyles::AllowHexSpecifier);
		tab2[i] = (unsigned char)tmp;
	}
	array<Byte>^ result = gcnew array<Byte>(tab->Length);
	for (int i = 0; i < tab->Length; i++)
	{
		result[i] = tab2[i];
	}
	delete tab2;
	return result;
}
private: System::Void encryptButton_Click(System::Object^  sender, System::EventArgs^  e) {
	String^ plainTextString = inText->Text;
	String^ keyTextString = keyText->Text;
	array<unsigned char>^ plainTextArray;
	array<unsigned char>^ keyArray = System::Text::Encoding::ASCII->GetBytes(keyTextString);
	if (methodData->Text == "Text") {
		plainTextArray = System::Text::Encoding::ASCII->GetBytes(plainTextString);
	}
	else {
		plainTextArray = hexToDec();
	}
	int plainTextLen = plainTextArray->Length;
	int keyLen = keyTextString->Length;
	int plainLenTmp = complementCount(plainTextLen);
	int keyLenTmp = complementCount(keyLen);

	unsigned char* plainTextChar = new unsigned char[plainLenTmp];
	unsigned char* keyChar = new unsigned char[keyLenTmp];

	plainTextChar = makeUnManagedChar(plainTextArray, plainLenTmp, plainTextLen);
	keyChar = makeUnManagedChar(keyArray, keyLenTmp, keyLen);
	aeslib^ y = gcnew aeslib(keyLenTmp);

	unsigned char* encryptedText = y->encrypt(plainTextChar, plainLenTmp, keyChar);
	plainTextArray = makeManagedArray(encryptedText, plainLenTmp);
	outText->Text = addHexInfo(plainTextArray);//+ hexString;
	delete plainTextChar, keyChar, encryptedText;
}


private: System::Void decryptButton_Click(System::Object^  sender, System::EventArgs^  e) {
	String^ plainTextString = inText->Text;
	String^ keyTextString = keyText->Text;
	array<unsigned char>^ plainTextArray;
	array<unsigned char>^ keyArray = System::Text::Encoding::ASCII->GetBytes(keyTextString);
	if (methodData->Text == "Text") {
		plainTextArray = System::Text::Encoding::ASCII->GetBytes(plainTextString);
	}
	else {
		plainTextArray = hexToDec();
	}
	int plainTextLen = plainTextArray->Length;
	int keyLen = keyTextString->Length;
	int plainLenTmp = complementCount(plainTextLen);
	int keyLenTmp = complementCount(keyLen);

	unsigned char* plainTextChar = new unsigned char[plainLenTmp];
	unsigned char* keyChar = new unsigned char[keyLenTmp];

	plainTextChar = makeUnManagedChar(plainTextArray, plainLenTmp, plainTextLen);
	keyChar = makeUnManagedChar(keyArray, keyLenTmp, keyLen);
	aeslib^ y = gcnew aeslib(keyLenTmp);

	unsigned char* encryptedText = y->decrypt(plainTextChar, plainLenTmp, keyChar);
	plainTextArray = makeManagedArray(encryptedText, plainLenTmp);
	outText->Text = addHexInfo(plainTextArray);//+ hexString;
	delete plainTextChar, keyChar, encryptedText;
}

private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	openFile->ShowDialog();
	fileNameIn->Text = openFile->FileName;
}



private: unsigned char* completionFile(unsigned char *tab, int orginalLen, int tmpLen) {
	unsigned char *buffer = new unsigned char[tmpLen];
	for (int i = 0; i < tmpLen; i++) {
		if (i < orginalLen) {
			buffer[i] = tab[i];
		}
		else {
			buffer[i] = 0;
		}
	}
	return buffer;
}

private: System::Void encryptButtonFile_Click(System::Object^  sender, System::EventArgs^  e) {
	String^ fileName = fileNameIn->Text;
	String^ fileNameO = fileNameOut->Text;
	String^ key = keyFile->Text;
	int keyLen = key->Length;
	if (fileName->Length == 0) {
		MessageBox::Show("Musisz podaæ klucz");
	}
	else if (keyLen == 0) {
		MessageBox::Show("Musisz wybraæ plik");
	}
	else if (fileNameO->Length == 0) {
		MessageBox::Show("Musisz wpisaæ nazwê pliku wyjœciowego");
	}
	else {
		array<unsigned char>^ keyArray = System::Text::Encoding::ASCII->GetBytes(key);
		int keyLenTmp = complementCount(keyLen);
		unsigned char* keyChar = new unsigned char[keyLenTmp];
		keyChar = makeUnManagedChar(keyArray, keyLenTmp, keyLen);
		System::IO::FileStream^ stream = System::IO::File::Open(fileName, System::IO::FileMode::Open);
		System::IO::BinaryReader^ reader = gcnew System::IO::BinaryReader(stream);
		
		int fileLen = stream->Length;
		int FileLenTmp = complementCount(fileLen);
		unsigned char* buffor = new unsigned char[fileLen/ sizeof(unsigned char)];
		for (int i = 0; i < fileLen; i += sizeof(unsigned char)) {
			buffor[i] = reader->ReadByte();
		}
		stream->Close();
		unsigned char* bufforComplete = new unsigned char[FileLenTmp];
		bufforComplete = completionFile(buffor, fileLen, FileLenTmp);
		aeslib^ y = gcnew aeslib(keyLenTmp);
		unsigned char* encryptedText = y->encrypt(bufforComplete, FileLenTmp, keyChar);

		//Zapisanie do nowego pliku
		System::IO::FileStream^ streamOut = System::IO::File::Open(fileNameO, System::IO::FileMode::Create);
		System::IO::BinaryWriter^ writer = gcnew System::IO::BinaryWriter(streamOut);
		array<unsigned char>^ tab = makeManagedArray(encryptedText, FileLenTmp);
		writer->Write(tab, 0, tab->Length);
		streamOut->Close();
		delete keyChar, buffor, bufforComplete, encryptedText;
		MessageBox::Show("zaszyfrowano podany plik"); 
	}
}
private: System::Void decryptButtonFile_Click(System::Object^  sender, System::EventArgs^  e) {
	String^ fileName = fileNameIn->Text;
	String^ fileNameO = fileNameOut->Text;
	String^ key = keyFile->Text;
	int keyLen = key->Length;
	if (fileName->Length == 0) {
		MessageBox::Show("Musisz podaæ klucz");
	}
	else if (keyLen == 0) {
		MessageBox::Show("Musisz wybraæ plik");
	}
	else if (fileNameO->Length == 0) {
		MessageBox::Show("Musisz wpisaæ nazwê pliku wyjœciowego");
	}
	else {
		array<unsigned char>^ keyArray = System::Text::Encoding::ASCII->GetBytes(key);
		int keyLenTmp = complementCount(keyLen);
		unsigned char* keyChar = new unsigned char[keyLenTmp];
		keyChar = makeUnManagedChar(keyArray, keyLenTmp, keyLen);
		System::IO::FileStream^ stream = System::IO::File::Open(fileName, System::IO::FileMode::Open);
		System::IO::BinaryReader^ reader = gcnew System::IO::BinaryReader(stream);

		int fileLen = stream->Length;
		int FileLenTmp = complementCount(fileLen);
		unsigned char* buffor = new unsigned char[fileLen / sizeof(unsigned char)];
		for (int i = 0; i < fileLen; i += sizeof(unsigned char)) {
			buffor[i] = reader->ReadByte();
		}
		stream->Close();
		unsigned char* bufforComplete = new unsigned char[FileLenTmp];
		bufforComplete = completionFile(buffor, fileLen, FileLenTmp);
		aeslib^ y = gcnew aeslib(keyLenTmp);
		unsigned char* encryptedText = y->decrypt(bufforComplete, FileLenTmp, keyChar);

		//Zapisanie do nowego pliku
		System::IO::FileStream^ streamOut = System::IO::File::Open(fileNameO, System::IO::FileMode::Create);
		System::IO::BinaryWriter^ writer = gcnew System::IO::BinaryWriter(streamOut);
		array<unsigned char>^ tab = makeManagedArray(encryptedText, FileLenTmp);
		writer->Write(tab, 0, tab->Length);
		streamOut->Close();
		delete keyChar, buffor, bufforComplete, encryptedText;
		MessageBox::Show("Odszyfrowano plik");
	}
}
};
}
