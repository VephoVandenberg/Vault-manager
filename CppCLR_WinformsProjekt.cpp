#include "pch.h"

using namespace System;
using namespace std;
//int main(array<System::String ^> ^args)
//{
//    return 0;
//}

#include "RSA.h"

#include "Form1.h"

using namespace System::Windows::Forms;

[STAThread]
int main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew CppCLRWinformsProjekt::Form1()); 
	return 0;
}