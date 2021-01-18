#pragma once
#include "Api.h"
#include "json.hpp"
#include <string>
#include <iostream>
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
	/// Summary for EditEvent
	/// </summary>
	public ref class EditEvent : public System::Windows::Forms::Form
	{
	public:
		EditEvent(void)
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
		~EditEvent()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ eventTitle;
	private: System::Windows::Forms::TextBox^ description;
	protected:

	protected:

	private: System::Windows::Forms::Label^ EditEventLabel;
	private: System::Windows::Forms::DateTimePicker^ startDate;
	private: System::Windows::Forms::DateTimePicker^ endDate;


	private: System::Windows::Forms::Button^ editBtn;
	private: System::Windows::Forms::Button^ editCancelBtn;
	private: System::Windows::Forms::TextBox^ inviteID;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(EditEvent::typeid));
			this->eventTitle = (gcnew System::Windows::Forms::TextBox());
			this->description = (gcnew System::Windows::Forms::TextBox());
			this->EditEventLabel = (gcnew System::Windows::Forms::Label());
			this->startDate = (gcnew System::Windows::Forms::DateTimePicker());
			this->endDate = (gcnew System::Windows::Forms::DateTimePicker());
			this->editBtn = (gcnew System::Windows::Forms::Button());
			this->editCancelBtn = (gcnew System::Windows::Forms::Button());
			this->inviteID = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// eventTitle
			// 
			this->eventTitle->Location = System::Drawing::Point(52, 64);
			this->eventTitle->Name = L"eventTitle";
			this->eventTitle->Size = System::Drawing::Size(200, 20);
			this->eventTitle->TabIndex = 0;
			// 
			// description
			// 
			this->description->Location = System::Drawing::Point(52, 202);
			this->description->Name = L"description";
			this->description->Size = System::Drawing::Size(200, 20);
			this->description->TabIndex = 1;
			// 
			// EditEventLabel
			// 
			this->EditEventLabel->AutoSize = true;
			this->EditEventLabel->BackColor = System::Drawing::Color::Transparent;
			this->EditEventLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->EditEventLabel->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->EditEventLabel->Location = System::Drawing::Point(99, 9);
			this->EditEventLabel->Name = L"EditEventLabel";
			this->EditEventLabel->Size = System::Drawing::Size(100, 25);
			this->EditEventLabel->TabIndex = 2;
			this->EditEventLabel->Text = L"Edit Event";
			// 
			// startDate
			// 
			this->startDate->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->startDate->Location = System::Drawing::Point(52, 110);
			this->startDate->Name = L"startDate";
			this->startDate->Size = System::Drawing::Size(200, 20);
			this->startDate->TabIndex = 3;
			this->startDate->Value = System::DateTime(2021, 1, 19, 0, 0, 0, 0);
			this->startDate->ValueChanged += gcnew System::EventHandler(this, &EditEvent::startDate_ValueChanged);
			// 
			// endDate
			// 
			this->endDate->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->endDate->Location = System::Drawing::Point(52, 156);
			this->endDate->Name = L"endDate";
			this->endDate->Size = System::Drawing::Size(200, 20);
			this->endDate->TabIndex = 4;
			this->endDate->Value = System::DateTime(2021, 1, 20, 0, 0, 0, 0);
			// 
			// editBtn
			// 
			this->editBtn->Location = System::Drawing::Point(177, 274);
			this->editBtn->Name = L"editBtn";
			this->editBtn->Size = System::Drawing::Size(75, 23);
			this->editBtn->TabIndex = 5;
			this->editBtn->Text = L"Edit";
			this->editBtn->UseVisualStyleBackColor = true;
			this->editBtn->Click += gcnew System::EventHandler(this, &EditEvent::editBtn_Click);
			// 
			// editCancelBtn
			// 
			this->editCancelBtn->Location = System::Drawing::Point(52, 274);
			this->editCancelBtn->Name = L"editCancelBtn";
			this->editCancelBtn->Size = System::Drawing::Size(75, 23);
			this->editCancelBtn->TabIndex = 6;
			this->editCancelBtn->Text = L"Cancel";
			this->editCancelBtn->UseVisualStyleBackColor = true;
			this->editCancelBtn->Click += gcnew System::EventHandler(this, &EditEvent::editCancelBtn_Click);
			// 
			// inviteID
			// 
			this->inviteID->Location = System::Drawing::Point(52, 248);
			this->inviteID->Name = L"inviteID";
			this->inviteID->Size = System::Drawing::Size(200, 20);
			this->inviteID->TabIndex = 7;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label1->Location = System::Drawing::Point(48, 41);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(83, 20);
			this->label1->TabIndex = 8;
			this->label1->Text = L"Event Title";
			this->label1->Click += gcnew System::EventHandler(this, &EditEvent::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label2->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label2->Location = System::Drawing::Point(48, 87);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(80, 20);
			this->label2->TabIndex = 9;
			this->label2->Text = L"Start date";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label3->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label3->Location = System::Drawing::Point(48, 133);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(74, 20);
			this->label3->TabIndex = 10;
			this->label3->Text = L"End date";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label4->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label4->Location = System::Drawing::Point(48, 179);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(89, 20);
			this->label4->TabIndex = 11;
			this->label4->Text = L"Description";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label5->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label5->Location = System::Drawing::Point(48, 225);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(68, 20);
			this->label5->TabIndex = 12;
			this->label5->Text = L"Invite ID";
			// 
			// EditEvent
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(309, 331);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->inviteID);
			this->Controls->Add(this->editCancelBtn);
			this->Controls->Add(this->editBtn);
			this->Controls->Add(this->endDate);
			this->Controls->Add(this->startDate);
			this->Controls->Add(this->EditEventLabel);
			this->Controls->Add(this->description);
			this->Controls->Add(this->eventTitle);
			this->Name = L"EditEvent";
			this->Text = L"Edit Event";
			this->Load += gcnew System::EventHandler(this, &EditEvent::EditEvent_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void editBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		System::String^ Title = eventTitle->Text;
		System::String^ start = startDate->Text;
		System::String^ end = endDate->Text;
		System::String^ desc = description->Text;
		System::String^ invID = inviteID->Text;

		msclr::interop::marshal_context context;
		std::string eventTitle = context.marshal_as<std::string>(Title);
		std::string startDate = context.marshal_as<std::string>(start);
		std::string endDate = context.marshal_as<std::string>(end);
		std::string description = context.marshal_as<std::string>(desc);
		std::string inviteID = context.marshal_as<std::string>(invID);

		if (endDate < startDate) {
			MessageBox::Show("Timeframe: not allowed!");
			this->Hide();
		}else{
		if (eventTitle.length() == 0 || startDate.length() == 0 || endDate.length() == 0 || description.length() == 0) {
			MessageBox::Show("Dont leave any blank fields!");
			this->Hide();
		}
		else {

			Api api;
			extern std::string apiKey;
			extern std::string eventID;
			extern std::string userID;

			nlohmann::json j;
			j["startDate"] = startDate;
			j["eventTitle"] = eventTitle;
			j["description"] = description;
			j["endDate"] = endDate;
			j["userID"] = userID;
			j["eventID"] = eventID;
			j["inviteID"] = inviteID;
			std::string json{ j.dump() };

			std::string eventEdited{ api.sendData("/api/event/update_event.php", json, apiKey) };
			std::string value = "Event Updated";

			if (apiKey.find(value) == std::string::npos) {
				MessageBox::Show("Event update: Successful!");
			}
			else {
				MessageBox::Show("Event update: Failed!");
			}
		}
		}
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void EditEvent_Load(System::Object^ sender, System::EventArgs^ e) {
		Api api;
		extern std::string apiKey;
		extern std::string eventID;
		std::string singleEvent = api.sendData("/api/event/read_single_event.php", "", apiKey + "&eventID=" + eventID);
		nlohmann::json strjson = nlohmann::json::parse(singleEvent);

			std::string title = strjson["eventTitle"];
			std::string sDate = strjson["startDate"];
			std::string eDate = strjson["endDate"];
			std::string desc = strjson["description"];
			std::string iID = strjson["inviteID"];

			String^ eventTitle = gcnew String(title.c_str());

			String^ startDate = gcnew String(sDate.c_str());

			String^ endDate = gcnew String(eDate.c_str());

			String^ description = gcnew String(desc.c_str());

			String^ inviteID = gcnew String(iID.c_str());

		this->eventTitle->Text = eventTitle;
		this->startDate->Text = startDate;
		this->endDate->Text = endDate;
		this->description->Text = description;
		this->inviteID->Text = inviteID;
	}
private: System::Void editCancelBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
}
private: System::Void startDate_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}