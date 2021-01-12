#pragma once
#include "Api.h"
#include "json.hpp"
#include <string>
#include <iostream>
#include "Event.h"
#include <msclr\marshal_cppstd.h>
#include <fstream>

namespace provider {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyEvents
	/// </summary>
	public ref class MyEvents : public System::Windows::Forms::Form
	{
	public:
		MyEvents(void)
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
		~MyEvents()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ deleteBtn;
	private: System::Windows::Forms::Button^ editBtn;
	private: System::Windows::Forms::Button^ createBtn;
	private: System::Windows::Forms::TextBox^ inviteIDsend;

	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::DataGridView^ table;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ eventTitle;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ startDate;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ endDate;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ description;
	private: System::Windows::Forms::Button^ inviteBtn;
	private: System::Windows::Forms::Button^ Reload;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ userID;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ inviteID;
	private: System::ComponentModel::IContainer^ components;

	protected:


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyEvents::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->deleteBtn = (gcnew System::Windows::Forms::Button());
			this->editBtn = (gcnew System::Windows::Forms::Button());
			this->createBtn = (gcnew System::Windows::Forms::Button());
			this->inviteIDsend = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->table = (gcnew System::Windows::Forms::DataGridView());
			this->eventTitle = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->startDate = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->endDate = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->description = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->inviteBtn = (gcnew System::Windows::Forms::Button());
			this->Reload = (gcnew System::Windows::Forms::Button());
			this->userID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->inviteID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->table))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->label1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label1->Location = System::Drawing::Point(289, 36);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(104, 25);
			this->label1->TabIndex = 8;
			this->label1->Text = L"My Events";
			// 
			// deleteBtn
			// 
			this->deleteBtn->Location = System::Drawing::Point(98, 348);
			this->deleteBtn->Name = L"deleteBtn";
			this->deleteBtn->Size = System::Drawing::Size(75, 20);
			this->deleteBtn->TabIndex = 9;
			this->deleteBtn->Text = L"Delete Event";
			this->deleteBtn->UseVisualStyleBackColor = true;
			this->deleteBtn->Click += gcnew System::EventHandler(this, &MyEvents::button1_Click);
			// 
			// editBtn
			// 
			this->editBtn->Location = System::Drawing::Point(179, 348);
			this->editBtn->Name = L"editBtn";
			this->editBtn->Size = System::Drawing::Size(75, 20);
			this->editBtn->TabIndex = 10;
			this->editBtn->Text = L"Edit";
			this->editBtn->UseVisualStyleBackColor = true;
			this->editBtn->Click += gcnew System::EventHandler(this, &MyEvents::button2_Click);
			// 
			// createBtn
			// 
			this->createBtn->Location = System::Drawing::Point(12, 348);
			this->createBtn->Name = L"createBtn";
			this->createBtn->Size = System::Drawing::Size(80, 20);
			this->createBtn->TabIndex = 11;
			this->createBtn->Text = L"Create";
			this->createBtn->UseVisualStyleBackColor = true;
			this->createBtn->Click += gcnew System::EventHandler(this, &MyEvents::button3_Click);
			// 
			// inviteIDsend
			// 
			this->inviteIDsend->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->inviteIDsend->Location = System::Drawing::Point(497, 348);
			this->inviteIDsend->Name = L"inviteIDsend";
			this->inviteIDsend->Size = System::Drawing::Size(75, 20);
			this->inviteIDsend->TabIndex = 18;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->BackColor = System::Drawing::Color::Transparent;
			this->label10->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label10->Location = System::Drawing::Point(494, 332);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(103, 13);
			this->label10->TabIndex = 19;
			this->label10->Text = L"Id of person to invite";
			// 
			// table
			// 
			this->table->AccessibleName = L"dataGridView";
			this->table->AllowUserToOrderColumns = true;
			this->table->BackgroundColor = System::Drawing::SystemColors::Highlight;
			this->table->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->table->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->eventTitle, this->startDate,
					this->endDate, this->description, this->userID, this->inviteID
			});
			this->table->Location = System::Drawing::Point(12, 80);
			this->table->Name = L"table";
			this->table->Size = System::Drawing::Size(643, 182);
			this->table->TabIndex = 21;
			this->table->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyEvents::table_CellContentClick);
			// 
			// eventTitle
			// 
			this->eventTitle->HeaderText = L"Event name";
			this->eventTitle->Name = L"eventTitle";
			// 
			// startDate
			// 
			this->startDate->HeaderText = L"Start date";
			this->startDate->Name = L"startDate";
			// 
			// endDate
			// 
			this->endDate->HeaderText = L"End date";
			this->endDate->Name = L"endDate";
			// 
			// description
			// 
			this->description->HeaderText = L"Description";
			this->description->Name = L"description";
			// 
			// inviteBtn
			// 
			this->inviteBtn->Location = System::Drawing::Point(578, 348);
			this->inviteBtn->Name = L"inviteBtn";
			this->inviteBtn->Size = System::Drawing::Size(75, 20);
			this->inviteBtn->TabIndex = 22;
			this->inviteBtn->Text = L"Invite";
			this->inviteBtn->UseVisualStyleBackColor = true;
			// 
			// Reload
			// 
			this->Reload->Location = System::Drawing::Point(21, 36);
			this->Reload->Name = L"Reload";
			this->Reload->Size = System::Drawing::Size(80, 20);
			this->Reload->TabIndex = 23;
			this->Reload->Text = L"Reload";
			this->Reload->UseVisualStyleBackColor = true;
			this->Reload->Click += gcnew System::EventHandler(this, &MyEvents::Reload_Click);
			// 
			// userID
			// 
			this->userID->HeaderText = L"User id";
			this->userID->Name = L"userID";
			// 
			// inviteID
			// 
			this->inviteID->HeaderText = L"Invite id";
			this->inviteID->Name = L"inviteID";
			// 
			// MyEvents
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(665, 383);
			this->Controls->Add(this->Reload);
			this->Controls->Add(this->inviteBtn);
			this->Controls->Add(this->table);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->inviteIDsend);
			this->Controls->Add(this->createBtn);
			this->Controls->Add(this->editBtn);
			this->Controls->Add(this->deleteBtn);
			this->Controls->Add(this->label1);
			this->Name = L"MyEvents";
			this->Text = L"MyEvents";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->table))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		Event^ Me = gcnew Event();
		Me->ShowDialog();
	}
	private: System::Void radioButton2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label12_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void inviteBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void Reload_Click(System::Object^ sender, System::EventArgs^ e) {

			Api api;
			extern std::string apiKey;
			std::string eventInfo = api.sendData("/api/event/read_event.php", "", apiKey);

			
			/*std::ofstream myfile;
			myfile.open("c:\\data\\example.txt");
			myfile << eventInfo.substr();
			myfile.close();*/

			/*
			Leker bara runt
			med olika möjliga lösningar.
			*/

			nlohmann::json strjson = nlohmann::json::parse(eventInfo);

			std::cout << "jsonParsed: " << strjson << "\n";

			//std::cout << "jsonParsedSpecific: " << strjson["data"][1]["eventTitle"] << "\n";

			char title[]{ ":" };

			int length = static_cast<int>(std::count(eventInfo.begin(), eventInfo.end(), title[0]));

			int real_length = (length - 1) / 6;
			std::cout << "len: " << real_length;

			for (int i = 0; i < real_length; i++) {
				std::string title = strjson["data"][i]["eventTitle"];
				std::string sDate = strjson["data"][i]["startDate"];
				std::string eDate = strjson["data"][i]["endDate"];
				std::string desc = strjson["data"][i]["description"];
				std::string uID = strjson["data"][i]["userID"];
				std::string iID = strjson["data"][i]["inviteID"];

				String^ eventTitle = gcnew String(title.c_str());
				String^ startDate = gcnew String(sDate.c_str());
				String^ endDate = gcnew String(eDate.c_str());
				String^ description = gcnew String(desc.c_str());
				String^ userID = gcnew String(uID.c_str());
				String^ inviteID = gcnew String(iID.c_str());

				this->table->Rows->Add(eventTitle, startDate, endDate, description, userID, inviteID);
			}

	}
private: System::Void table_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {

}
};
}
