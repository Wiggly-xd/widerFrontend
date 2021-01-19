#pragma once
#include "Api.h"
#include "json.hpp"
#include <string>
#include <iostream>
#include <msclr\marshal_cppstd.h>
#include <fstream>
#include <windows.h>

namespace provider {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Invite
	/// </summary>
	public ref class Invite : public System::Windows::Forms::Form
	{
	private: System::String^ curUserID;
	public:
		Invite(void)
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
		~Invite()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ userTable;
	protected:

	protected:
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ username;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ userID;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ sendBtn;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Invite::typeid));
			this->userTable = (gcnew System::Windows::Forms::DataGridView());
			this->username = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->userID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->sendBtn = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->userTable))->BeginInit();
			this->SuspendLayout();
			//
			// userTable
			//
			this->userTable->AllowUserToAddRows = false;
			this->userTable->AllowUserToDeleteRows = false;
			this->userTable->AllowUserToOrderColumns = true;
			this->userTable->AllowUserToResizeColumns = false;
			this->userTable->AllowUserToResizeRows = false;
			this->userTable->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->userTable->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) { this->username, this->userID });
			this->userTable->Location = System::Drawing::Point(22, 37);
			this->userTable->MultiSelect = false;
			this->userTable->Name = L"userTable";
			this->userTable->ReadOnly = true;
			this->userTable->Size = System::Drawing::Size(243, 231);
			this->userTable->TabIndex = 0;
			this->userTable->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Invite::userTable_CellContentClick);
			//
			// username
			//
			this->username->HeaderText = L"Username";
			this->username->Name = L"username";
			this->username->ReadOnly = true;
			//
			// userID
			//
			this->userID->HeaderText = L"ID";
			this->userID->Name = L"userID";
			this->userID->ReadOnly = true;
			//
			// label1
			//
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->label1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label1->Location = System::Drawing::Point(54, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(181, 25);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Select user to invite";
			//
			// sendBtn
			//
			this->sendBtn->Location = System::Drawing::Point(190, 285);
			this->sendBtn->Name = L"sendBtn";
			this->sendBtn->Size = System::Drawing::Size(75, 23);
			this->sendBtn->TabIndex = 2;
			this->sendBtn->Text = L"Send";
			this->sendBtn->UseVisualStyleBackColor = true;
			this->sendBtn->Click += gcnew System::EventHandler(this, &Invite::sendBtn_Click);
			//
			// Invite
			//
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(292, 320);
			this->Controls->Add(this->sendBtn);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->userTable);
			this->Name = L"Invite";
			this->Text = L"Invite";
			this->Load += gcnew System::EventHandler(this, &Invite::Invite_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->userTable))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion
	private: System::Void Invite_Load(System::Object^ sender, System::EventArgs^ e) {
		userTable->Rows->Clear();

		Api api;
		extern std::string apiKey;
		std::string userList = api.sendData("/api/user/read_user.php", "", apiKey);

		nlohmann::json strjson = nlohmann::json::parse(userList);

		char title[]{ ":" };

		int length = static_cast<int>(std::count(userList.begin(), userList.end(), title[0]));

		int real_length = (length - 1) / 2;

		for (int i = 0; i < real_length; i++) {
			std::string uname = strjson["data"][i]["username"];
			std::string uID = strjson["data"][i]["userID"];

			String^ username = gcnew String(uname.c_str());
			String^ userID = gcnew String(uID.c_str());

			int insert = this->userTable->Rows->Add(username, userID);
		}
	}
	private: System::Void userTable_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		if (e->RowIndex >= 0) {
			DataGridViewRow^ row = userTable->Rows[e->RowIndex];

			String^ uID = row->Cells["userID"]->Value->ToString();

			msclr::interop::marshal_context context;

			std::string userID = context.marshal_as<std::string>(uID);

			std::cout << "\n" << "userID: " << userID;

			curUserID = uID;
		}
	}

	private: System::Void sendBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		Api api;
		extern std::string apiKey;
		extern std::string eventID;

		msclr::interop::marshal_context context;
		std::string convertedCurUserID = context.marshal_as<std::string>(curUserID);


		nlohmann::json j;
		j["inviteID"] = convertedCurUserID;
		std::string json{ j.dump() };

		std::cout << "\n" << "curUserID: " << convertedCurUserID;

		std::cout << json;

		std::string inviteUser = api.sendData("/api/event/invite_user_event.php", json, apiKey + "&eventID=" + eventID);

		std::string incorrect("user Not Invited");

		if (apiKey.find(incorrect) == std::string::npos) {
			MessageBox::Show("Invitation: Successful!");
			this->Hide();
		}
		else {
			MessageBox::Show("Invitation: Failed!");
		}
	}
	};
}
