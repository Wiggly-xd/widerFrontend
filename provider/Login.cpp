#include "Login.h"
#include <string>

std::string apiKey;

using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]

void main(array<String^>^ args) {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	provider::Login frm;
	Application::Run(% frm);
}