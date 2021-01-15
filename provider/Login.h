#pragma once
#include "Api.h"
#include "json.hpp"
#include <string>
#include <iostream>
#include "createCalendar.h"
#include <msclr\marshal_cppstd.h>
#include <fstream>
#include "Register.h"

namespace provider {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Login
	/// </summary>
	public ref class Login : public System::Windows::Forms::Form
	{
	public:
		Login(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Login()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ username;
	private: System::Windows::Forms::TextBox^ password;
	protected:

	protected:

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ loginBtn;
	private: System::Windows::Forms::LinkLabel^ linkRegister;







	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Login::typeid));
			this->username = (gcnew System::Windows::Forms::TextBox());
			this->password = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->loginBtn = (gcnew System::Windows::Forms::Button());
			this->linkRegister = (gcnew System::Windows::Forms::LinkLabel());
			this->SuspendLayout();
			// 
			// username
			// 
			this->username->Location = System::Drawing::Point(82, 73);
			this->username->Name = L"username";
			this->username->Size = System::Drawing::Size(217, 20);
			this->username->TabIndex = 0;
			this->username->TextChanged += gcnew System::EventHandler(this, &Login::username_TextChanged);
			// 
			// password
			// 
			this->password->Location = System::Drawing::Point(82, 139);
			this->password->Name = L"password";
			this->password->PasswordChar = '*';
			this->password->Size = System::Drawing::Size(217, 20);
			this->password->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label1->Location = System::Drawing::Point(79, 48);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(55, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Username";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label2->Location = System::Drawing::Point(81, 113);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(53, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Password";
			// 
			// loginBtn
			// 
			this->loginBtn->Location = System::Drawing::Point(149, 178);
			this->loginBtn->Name = L"loginBtn";
			this->loginBtn->Size = System::Drawing::Size(75, 23);
			this->loginBtn->TabIndex = 4;
			this->loginBtn->Text = L"Login";
			this->loginBtn->UseVisualStyleBackColor = true;
			this->loginBtn->Click += gcnew System::EventHandler(this, &Login::loginBtn_Click);
			// 
			// linkRegister
			// 
			this->linkRegister->AutoSize = true;
			this->linkRegister->BackColor = System::Drawing::Color::Transparent;
			this->linkRegister->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9));
			this->linkRegister->LinkColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->linkRegister->Location = System::Drawing::Point(122, 204);
			this->linkRegister->Name = L"linkRegister";
			this->linkRegister->Size = System::Drawing::Size(132, 15);
			this->linkRegister->TabIndex = 5;
			this->linkRegister->TabStop = true;
			this->linkRegister->Text = L"Dont have an account\?";
			this->linkRegister->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &Login::linkRegister_LinkClicked);
			// 
			// Login
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(374, 278);
			this->Controls->Add(this->linkRegister);
			this->Controls->Add(this->loginBtn);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->password);
			this->Controls->Add(this->username);
			this->Name = L"Login";
			this->Text = L"Login";
			this->Load += gcnew System::EventHandler(this, &Login::Login_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Login_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void loginBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		
		System::String ^ uName = username->Text;
		System::String ^ pWord = password->Text;

		msclr::interop::marshal_context context;
		std::string usrName = context.marshal_as<std::string>(uName);
		std::string pasWord = context.marshal_as<std::string>(pWord);

		nlohmann::json j;
		j["username"] = usrName;
		j["password"] = pasWord;
		std::string json{ j.dump() };

		Api api;
		extern std::string apiKey;
		apiKey = api.sendData("/api/user/authenticate_user.php", json);

		Api uapi;
		extern std::string userID;
		userID = uapi.sendData("/api/user/authenticate_user_getinfo.php", json);

		std::string incorrect("nono");

		std::cout << "key: " << apiKey << "\n";
		std::cout << "userID: " << userID << "\n";

		if (apiKey.find(incorrect) == std::string::npos) {
			MessageBox::Show("Authentication: Successful!");
			this->Hide();
			createCalendar^ Cc = gcnew createCalendar();
			Cc->ShowDialog();
		}
		else {
			MessageBox::Show("Authentication: Failed!");
		}
	}
	private: System::Void username_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void linkRegister_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
	Register^ Re = gcnew Register();
	Re->ShowDialog();
}
};
}
