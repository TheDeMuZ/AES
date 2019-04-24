
#include <cstring>
#include <stdlib.h>
#include<sstream>
#include <fstream>
#include "aeslib.h"
#include "MainForm.h"


using namespace AES;
using namespace System;
using namespace System::Text;
using namespace System::Runtime::InteropServices;
using namespace System::IO;
[STAThreadAttribute]

int main(array<System::String ^> ^args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	AES::MainForm mainwindow;
	Application::Run(%mainwindow);
	return 0;
}
