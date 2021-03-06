#pragma once
#include "Api.h"
#include "json.hpp"
#include <string>
#include <iostream>
#include "Event.h"
#include <msclr\marshal_cppstd.h>
#include <fstream>
#include <windows.h>
#include "DeleteEvent.h"
#include "EditEvent.h"
#include "Invite.h"
#include <ctime>

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

	private: System::Windows::Forms::DataGridViewTextBoxColumn^ eventTitle;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ startDate;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ endDate;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ description;

	private: System::Windows::Forms::DataGridViewTextBoxColumn^ userID;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ inviteID;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ eventID;
	private: System::Windows::Forms::Button^ createBtn;
	private: System::Windows::Forms::Button^ deleteBtn;
	private: System::Windows::Forms::Button^ editBtn;
	private: System::Windows::Forms::DataGridView^ table;
	private: System::Windows::Forms::Button^ inviteBtn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Today;
	private: System::Windows::Forms::Button^ allEventsBtn;
	private: System::Windows::Forms::Button^ TodaysEventsBtn;

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
			this->table = (gcnew System::Windows::Forms::DataGridView());
			this->eventTitle = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->startDate = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->endDate = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->description = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->userID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->inviteID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->eventID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Today = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->createBtn = (gcnew System::Windows::Forms::Button());
			this->deleteBtn = (gcnew System::Windows::Forms::Button());
			this->editBtn = (gcnew System::Windows::Forms::Button());
			this->inviteBtn = (gcnew System::Windows::Forms::Button());
			this->allEventsBtn = (gcnew System::Windows::Forms::Button());
			this->TodaysEventsBtn = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->table))->BeginInit();
			this->SuspendLayout();
			//
			// label1
			//
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->label1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label1->Location = System::Drawing::Point(342, 31);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(104, 25);
			this->label1->TabIndex = 8;
			this->label1->Text = L"My Events";
			//
			// table
			//
			this->table->AccessibleName = L"dataGridView";
			this->table->AllowUserToAddRows = false;
			this->table->AllowUserToDeleteRows = false;
			this->table->AllowUserToOrderColumns = true;
			this->table->AllowUserToResizeColumns = false;
			this->table->AllowUserToResizeRows = false;
			this->table->BackgroundColor = System::Drawing::SystemColors::Highlight;
			this->table->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->table->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(8) {
				this->eventTitle, this->startDate,
					this->endDate, this->description, this->userID, this->inviteID, this->eventID, this->Today
			});
			this->table->Location = System::Drawing::Point(12, 80);
			this->table->MultiSelect = false;
			this->table->Name = L"table";
			this->table->ReadOnly = true;
			this->table->Size = System::Drawing::Size(843, 182);
			this->table->TabIndex = 21;
			this->table->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MyEvents::table_CellContentClick);
			//
			// eventTitle
			//
			this->eventTitle->HeaderText = L"Event name";
			this->eventTitle->Name = L"eventTitle";
			this->eventTitle->ReadOnly = true;
			//
			// startDate
			//
			this->startDate->HeaderText = L"Start date";
			this->startDate->Name = L"startDate";
			this->startDate->ReadOnly = true;
			//
			// endDate
			//
			this->endDate->HeaderText = L"End date";
			this->endDate->Name = L"endDate";
			this->endDate->ReadOnly = true;
			//
			// description
			//
			this->description->HeaderText = L"Description";
			this->description->Name = L"description";
			this->description->ReadOnly = true;
			//
			// userID
			//
			this->userID->HeaderText = L"User id";
			this->userID->Name = L"userID";
			this->userID->ReadOnly = true;
			//
			// inviteID
			//
			this->inviteID->HeaderText = L"Invite id";
			this->inviteID->Name = L"inviteID";
			this->inviteID->ReadOnly = true;
			//
			// eventID
			//
			this->eventID->HeaderText = L"Event id";
			this->eventID->Name = L"eventID";
			this->eventID->ReadOnly = true;
			//
			// Today
			//
			this->Today->HeaderText = L"Today";
			this->Today->Name = L"Today";
			this->Today->ReadOnly = true;
			//
			// createBtn
			//
			this->createBtn->Location = System::Drawing::Point(17, 348);
			this->createBtn->Name = L"createBtn";
			this->createBtn->Size = System::Drawing::Size(75, 23);
			this->createBtn->TabIndex = 24;
			this->createBtn->Text = L"Create";
			this->createBtn->UseVisualStyleBackColor = true;
			this->createBtn->Click += gcnew System::EventHandler(this, &MyEvents::createBtn_Click);
			//
			// deleteBtn
			//
			this->deleteBtn->Location = System::Drawing::Point(99, 348);
			this->deleteBtn->Name = L"deleteBtn";
			this->deleteBtn->Size = System::Drawing::Size(75, 23);
			this->deleteBtn->TabIndex = 25;
			this->deleteBtn->Text = L"Delete";
			this->deleteBtn->UseVisualStyleBackColor = true;
			this->deleteBtn->Click += gcnew System::EventHandler(this, &MyEvents::deleteBtn_Click);
			//
			// editBtn
			//
			this->editBtn->Location = System::Drawing::Point(181, 348);
			this->editBtn->Name = L"editBtn";
			this->editBtn->Size = System::Drawing::Size(75, 23);
			this->editBtn->TabIndex = 26;
			this->editBtn->Text = L"Edit";
			this->editBtn->UseVisualStyleBackColor = true;
			this->editBtn->Click += gcnew System::EventHandler(this, &MyEvents::editBtn_Click);
			//
			// inviteBtn
			//
			this->inviteBtn->Location = System::Drawing::Point(262, 348);
			this->inviteBtn->Name = L"inviteBtn";
			this->inviteBtn->Size = System::Drawing::Size(75, 23);
			this->inviteBtn->TabIndex = 27;
			this->inviteBtn->Text = L"Invite";
			this->inviteBtn->UseVisualStyleBackColor = true;
			this->inviteBtn->Click += gcnew System::EventHandler(this, &MyEvents::inviteBtn_Click);
			//
			// allEventsBtn
			//
			this->allEventsBtn->Location = System::Drawing::Point(12, 51);
			this->allEventsBtn->Name = L"allEventsBtn";
			this->allEventsBtn->Size = System::Drawing::Size(75, 23);
			this->allEventsBtn->TabIndex = 28;
			this->allEventsBtn->Text = L"All Events";
			this->allEventsBtn->UseVisualStyleBackColor = true;
			this->allEventsBtn->Click += gcnew System::EventHandler(this, &MyEvents::allEventsBtn_Click);
			//
			// TodaysEventsBtn
			//
			this->TodaysEventsBtn->Location = System::Drawing::Point(93, 51);
			this->TodaysEventsBtn->Name = L"TodaysEventsBtn";
			this->TodaysEventsBtn->Size = System::Drawing::Size(96, 23);
			this->TodaysEventsBtn->TabIndex = 29;
			this->TodaysEventsBtn->Text = L"Todays Events";
			this->TodaysEventsBtn->UseVisualStyleBackColor = true;
			this->TodaysEventsBtn->Click += gcnew System::EventHandler(this, &MyEvents::TodaysEventsBtn_Click);
			//
			// MyEvents
			//
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(866, 383);
			this->Controls->Add(this->TodaysEventsBtn);
			this->Controls->Add(this->allEventsBtn);
			this->Controls->Add(this->inviteBtn);
			this->Controls->Add(this->editBtn);
			this->Controls->Add(this->deleteBtn);
			this->Controls->Add(this->createBtn);
			this->Controls->Add(this->table);
			this->Controls->Add(this->label1);
			this->Name = L"MyEvents";
			this->Text = L"MyEvents";
			this->Load += gcnew System::EventHandler(this, &MyEvents::MyEvents_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->table))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion

	private: System::Void radioButton2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label12_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void table_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		if (e->RowIndex >= 0) {
			DataGridViewRow^ row = table->Rows[e->RowIndex];

			String^ eID = row->Cells["eventID"]->Value->ToString();

			msclr::interop::marshal_context context;
			extern std::string eventID;
			eventID = context.marshal_as<std::string>(eID);

			std::cout << "\n" << "eventID: " << eventID;
		}
	}
	private: System::Void MyEvents_Load(System::Object^ sender, System::EventArgs^ e) {
		table->Rows->Clear();

		Api api;
		extern std::string apiKey;
		extern std::string userID;
		std::string invitedEvents = api.sendData("/api/event/invite_event.php", "", apiKey + "&userID=" + userID);

		nlohmann::json invjson = nlohmann::json::parse(invitedEvents);

		char titleInv[]{ ":" };

		int lengthInv = static_cast<int>(std::count(invitedEvents.begin(), invitedEvents.end(), titleInv[0]));

		int real_lengthInv = (lengthInv - 1) / 7;

		for (int i = 0; i < real_lengthInv; i++) {
			std::string titleInv = invjson["data"][i]["eventTitle"];
			std::string sDateInv = invjson["data"][i]["startDate"];
			std::string eDateInv = invjson["data"][i]["endDate"];
			std::string descInv = invjson["data"][i]["description"];
			std::string uIDInv = invjson["data"][i]["userID"];
			std::string iIDInv = invjson["data"][i]["inviteID"];
			std::string eIDInv = invjson["data"][i]["eventID"];

			String^ eventTitleInv = gcnew String(titleInv.c_str());
			String^ startDateInv = gcnew String(sDateInv.c_str());
			String^ endDateInv = gcnew String(eDateInv.c_str());
			String^ descriptionInv = gcnew String(descInv.c_str());
			String^ userIDInv = gcnew String(uIDInv.c_str());
			String^ inviteIDInv = gcnew String(iIDInv.c_str());
			String^ eventIDInv = gcnew String(eIDInv.c_str());
			std::time_t rawtimeInv;
			std::tm* timeinfoInv;
			char bufferInv[80];

			std::time(&rawtimeInv);
			timeinfoInv = std::localtime(&rawtimeInv);

			std::strftime(bufferInv, 80, "%Y-%m-%d", timeinfoInv);

			std::string tConvertInv(bufferInv);
			String^ todayDateInv = gcnew String(tConvertInv.c_str());

			if (todayDateInv == startDateInv) {
				int insertInv = this->table->Rows->Add(eventTitleInv, startDateInv, endDateInv, descriptionInv, userIDInv, inviteIDInv, eventIDInv, "true");
			}
		}

		std::string eventInfo = api.sendData("/api/event/read_event.php", "", apiKey + "&userID=" + userID);

		nlohmann::json strjson = nlohmann::json::parse(eventInfo);

		char title[]{ ":" };

		int length = static_cast<int>(std::count(eventInfo.begin(), eventInfo.end(), title[0]));

		int real_length = (length - 1) / 7;

		for (int i = 0; i < real_length; i++) {
			std::string title = strjson["data"][i]["eventTitle"];
			std::string sDate = strjson["data"][i]["startDate"];
			std::string eDate = strjson["data"][i]["endDate"];
			std::string desc = strjson["data"][i]["description"];
			std::string uID = strjson["data"][i]["userID"];
			std::string iID = strjson["data"][i]["inviteID"];
			std::string eID = strjson["data"][i]["eventID"];

			String^ eventTitle = gcnew String(title.c_str());
			String^ startDate = gcnew String(sDate.c_str());
			String^ endDate = gcnew String(eDate.c_str());
			String^ description = gcnew String(desc.c_str());
			String^ userID = gcnew String(uID.c_str());
			String^ inviteID = gcnew String(iID.c_str());
			String^ eventID = gcnew String(eID.c_str());

			std::time_t rawtime;
			std::tm* timeinfo;
			char buffer[80];

			std::time(&rawtime);
			timeinfo = std::localtime(&rawtime);

			std::strftime(buffer, 80, "%Y-%m-%d", timeinfo);

			std::string tConvert(buffer);
			String^ todayDate = gcnew String(tConvert.c_str());

			if (todayDate == startDate) {
				int insert = this->table->Rows->Add(eventTitle, startDate, endDate, description, userID, inviteID, eventID, "true");
			}
		}
	}
	private: System::Void createBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		Event^ Me = gcnew Event();
		Me->ShowDialog();
	}

	private: System::Void deleteBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		DeleteEvent^ De = gcnew DeleteEvent();
		De->ShowDialog();
	}
	private: System::Void editBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		EditEvent^ Ee = gcnew EditEvent();
		Ee->ShowDialog();
	}
	private: System::Void inviteBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		Invite^ In = gcnew Invite();
		In->ShowDialog();
	}
	private: System::Void allEventsBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		table->Rows->Clear();

		Api api;
		extern std::string apiKey;
		extern std::string userID;
		std::string invitedEvents = api.sendData("/api/event/invite_event.php", "", apiKey + "&userID=" + userID);

		nlohmann::json invjson = nlohmann::json::parse(invitedEvents);

		char titleInv[]{ ":" };

		int lengthInv = static_cast<int>(std::count(invitedEvents.begin(), invitedEvents.end(), titleInv[0]));

		int real_lengthInv = (lengthInv - 1) / 7;

		for (int i = 0; i < real_lengthInv; i++) {
			std::string titleInv = invjson["data"][i]["eventTitle"];
			std::string sDateInv = invjson["data"][i]["startDate"];
			std::string eDateInv = invjson["data"][i]["endDate"];
			std::string descInv = invjson["data"][i]["description"];
			std::string uIDInv = invjson["data"][i]["userID"];
			std::string iIDInv = invjson["data"][i]["inviteID"];
			std::string eIDInv = invjson["data"][i]["eventID"];

			String^ eventTitleInv = gcnew String(titleInv.c_str());
			String^ startDateInv = gcnew String(sDateInv.c_str());
			String^ endDateInv = gcnew String(eDateInv.c_str());
			String^ descriptionInv = gcnew String(descInv.c_str());
			String^ userIDInv = gcnew String(uIDInv.c_str());
			String^ inviteIDInv = gcnew String(iIDInv.c_str());
			String^ eventIDInv = gcnew String(eIDInv.c_str());
			std::time_t rawtimeInv;
			std::tm* timeinfoInv;
			char bufferInv[80];

			std::time(&rawtimeInv);
			timeinfoInv = std::localtime(&rawtimeInv);

			std::strftime(bufferInv, 80, "%Y-%m-%d", timeinfoInv);

			std::string tConvertInv(bufferInv);
			String^ todayDateInv = gcnew String(tConvertInv.c_str());

			if (todayDateInv == startDateInv) {
				int insertInv = this->table->Rows->Add(eventTitleInv, startDateInv, endDateInv, descriptionInv, userIDInv, inviteIDInv, eventIDInv, "true");
			}
			else {
				int insertInv = this->table->Rows->Add(eventTitleInv, startDateInv, endDateInv, descriptionInv, userIDInv, inviteIDInv, eventIDInv, "false");
			}
		}

		std::string eventInfo = api.sendData("/api/event/read_event.php", "", apiKey + "&userID=" + userID);

		nlohmann::json strjson = nlohmann::json::parse(eventInfo);

		char title[]{ ":" };

		int length = static_cast<int>(std::count(eventInfo.begin(), eventInfo.end(), title[0]));

		int real_length = (length - 1) / 7;

		for (int i = 0; i < real_length; i++) {
			std::string title = strjson["data"][i]["eventTitle"];
			std::string sDate = strjson["data"][i]["startDate"];
			std::string eDate = strjson["data"][i]["endDate"];
			std::string desc = strjson["data"][i]["description"];
			std::string uID = strjson["data"][i]["userID"];
			std::string iID = strjson["data"][i]["inviteID"];
			std::string eID = strjson["data"][i]["eventID"];

			String^ eventTitle = gcnew String(title.c_str());
			String^ startDate = gcnew String(sDate.c_str());
			String^ endDate = gcnew String(eDate.c_str());
			String^ description = gcnew String(desc.c_str());
			String^ userID = gcnew String(uID.c_str());
			String^ inviteID = gcnew String(iID.c_str());
			String^ eventID = gcnew String(eID.c_str());
			std::time_t rawtime;
			std::tm* timeinfo;
			char buffer[80];

			std::time(&rawtime);
			timeinfo = std::localtime(&rawtime);

			std::strftime(buffer, 80, "%Y-%m-%d", timeinfo);

			std::string tConvert(buffer);
			String^ todayDate = gcnew String(tConvert.c_str());

			if (todayDate == startDate) {
				int insert = this->table->Rows->Add(eventTitle, startDate, endDate, description, userID, inviteID, eventID, "true");
			}
			else {
				int insert = this->table->Rows->Add(eventTitle, startDate, endDate, description, userID, inviteID, eventID, "false");
			}
		}
	}
	private: System::Void TodaysEventsBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		table->Rows->Clear();

		Api api;
		extern std::string apiKey;
		extern std::string userID;
		std::string invitedEvents = api.sendData("/api/event/invite_event.php", "", apiKey + "&userID=" + userID);

		nlohmann::json invjson = nlohmann::json::parse(invitedEvents);

		char titleInv[]{ ":" };

		int lengthInv = static_cast<int>(std::count(invitedEvents.begin(), invitedEvents.end(), titleInv[0]));

		int real_lengthInv = (lengthInv - 1) / 7;

		for (int i = 0; i < real_lengthInv; i++) {
			std::string titleInv = invjson["data"][i]["eventTitle"];
			std::string sDateInv = invjson["data"][i]["startDate"];
			std::string eDateInv = invjson["data"][i]["endDate"];
			std::string descInv = invjson["data"][i]["description"];
			std::string uIDInv = invjson["data"][i]["userID"];
			std::string iIDInv = invjson["data"][i]["inviteID"];
			std::string eIDInv = invjson["data"][i]["eventID"];

			String^ eventTitleInv = gcnew String(titleInv.c_str());
			String^ startDateInv = gcnew String(sDateInv.c_str());
			String^ endDateInv = gcnew String(eDateInv.c_str());
			String^ descriptionInv = gcnew String(descInv.c_str());
			String^ userIDInv = gcnew String(uIDInv.c_str());
			String^ inviteIDInv = gcnew String(iIDInv.c_str());
			String^ eventIDInv = gcnew String(eIDInv.c_str());
			std::time_t rawtimeInv;
			std::tm* timeinfoInv;
			char bufferInv[80];

			std::time(&rawtimeInv);
			timeinfoInv = std::localtime(&rawtimeInv);

			std::strftime(bufferInv, 80, "%Y-%m-%d", timeinfoInv);

			std::string tConvertInv(bufferInv);
			String^ todayDateInv = gcnew String(tConvertInv.c_str());

			if (todayDateInv == startDateInv) {
				int insertInv = this->table->Rows->Add(eventTitleInv, startDateInv, endDateInv, descriptionInv, userIDInv, inviteIDInv, eventIDInv, "true");
			}
		}

		std::string eventInfo = api.sendData("/api/event/read_event.php", "", apiKey + "&userID=" + userID);

		nlohmann::json strjson = nlohmann::json::parse(eventInfo);

		char title[]{ ":" };

		int length = static_cast<int>(std::count(eventInfo.begin(), eventInfo.end(), title[0]));

		int real_length = (length - 1) / 7;

		for (int i = 0; i < real_length; i++) {
			std::string title = strjson["data"][i]["eventTitle"];
			std::string sDate = strjson["data"][i]["startDate"];
			std::string eDate = strjson["data"][i]["endDate"];
			std::string desc = strjson["data"][i]["description"];
			std::string uID = strjson["data"][i]["userID"];
			std::string iID = strjson["data"][i]["inviteID"];
			std::string eID = strjson["data"][i]["eventID"];

			String^ eventTitle = gcnew String(title.c_str());
			String^ startDate = gcnew String(sDate.c_str());
			String^ endDate = gcnew String(eDate.c_str());
			String^ description = gcnew String(desc.c_str());
			String^ userID = gcnew String(uID.c_str());
			String^ inviteID = gcnew String(iID.c_str());
			String^ eventID = gcnew String(eID.c_str());
			std::time_t rawtime;
			std::tm* timeinfo;
			char buffer[80];

			std::time(&rawtime);
			timeinfo = std::localtime(&rawtime);

			std::strftime(buffer, 80, "%Y-%m-%d", timeinfo);

			std::string tConvert(buffer);
			String^ todayDate = gcnew String(tConvert.c_str());

			if (todayDate == startDate) {
				int insert = this->table->Rows->Add(eventTitle, startDate, endDate, description, userID, inviteID, eventID, "true");
			}
		}
	}
	};
}
