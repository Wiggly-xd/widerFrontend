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
	/// Summary for Event
	/// </summary>
	public ref class Event : public System::Windows::Forms::Form
	{
	public:
		Event(void)
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
		~Event()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ eventTitle;
	protected:

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::DateTimePicker^ startDate;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::DateTimePicker^ endDate;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ createEventBtn;
	private: System::Windows::Forms::Label^ descriptionText;
	private: System::Windows::Forms::TextBox^ description;






	private: System::Windows::Forms::Button^ editEventBtn;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker1;
	private: System::Windows::Forms::Button^ back;














	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Event::typeid));
			this->eventTitle = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->startDate = (gcnew System::Windows::Forms::DateTimePicker());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->endDate = (gcnew System::Windows::Forms::DateTimePicker());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->createEventBtn = (gcnew System::Windows::Forms::Button());
			this->descriptionText = (gcnew System::Windows::Forms::Label());
			this->description = (gcnew System::Windows::Forms::TextBox());
			this->editEventBtn = (gcnew System::Windows::Forms::Button());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->back = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// eventTitle
			// 
			this->eventTitle->Location = System::Drawing::Point(43, 80);
			this->eventTitle->Name = L"eventTitle";
			this->eventTitle->Size = System::Drawing::Size(200, 20);
			this->eventTitle->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->label1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label1->Location = System::Drawing::Point(114, 25);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(62, 25);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Event";
			// 
			// startDate
			// 
			this->startDate->CustomFormat = L"";
			this->startDate->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->startDate->Location = System::Drawing::Point(43, 128);
			this->startDate->Name = L"startDate";
			this->startDate->Size = System::Drawing::Size(200, 20);
			this->startDate->TabIndex = 2;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label2->Location = System::Drawing::Point(96, 64);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(103, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Enter name of event";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label3->Location = System::Drawing::Point(96, 112);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(121, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Enter start date of event";
			// 
			// endDate
			// 
			this->endDate->CustomFormat = L"";
			this->endDate->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->endDate->Location = System::Drawing::Point(43, 181);
			this->endDate->Name = L"endDate";
			this->endDate->Size = System::Drawing::Size(200, 20);
			this->endDate->TabIndex = 5;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label4->Location = System::Drawing::Point(96, 165);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(119, 13);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Enter end date of event";
			// 
			// createEventBtn
			// 
			this->createEventBtn->Location = System::Drawing::Point(63, 261);
			this->createEventBtn->Name = L"createEventBtn";
			this->createEventBtn->Size = System::Drawing::Size(75, 23);
			this->createEventBtn->TabIndex = 7;
			this->createEventBtn->Text = L"Create";
			this->createEventBtn->UseVisualStyleBackColor = true;
			this->createEventBtn->Click += gcnew System::EventHandler(this, &Event::createEventBtn_Click);
			// 
			// descriptionText
			// 
			this->descriptionText->AutoSize = true;
			this->descriptionText->BackColor = System::Drawing::Color::Transparent;
			this->descriptionText->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->descriptionText->Location = System::Drawing::Point(96, 219);
			this->descriptionText->Name = L"descriptionText";
			this->descriptionText->Size = System::Drawing::Size(102, 13);
			this->descriptionText->TabIndex = 8;
			this->descriptionText->Text = L"Describe your event";
			// 
			// description
			// 
			this->description->Location = System::Drawing::Point(43, 235);
			this->description->Multiline = true;
			this->description->Name = L"description";
			this->description->Size = System::Drawing::Size(200, 20);
			this->description->TabIndex = 9;
			// 
			// editEventBtn
			// 
			this->editEventBtn->Location = System::Drawing::Point(150, 261);
			this->editEventBtn->Name = L"editEventBtn";
			this->editEventBtn->Size = System::Drawing::Size(75, 23);
			this->editEventBtn->TabIndex = 10;
			this->editEventBtn->Text = L"Edit";
			this->editEventBtn->UseVisualStyleBackColor = true;
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Location = System::Drawing::Point(287, 335);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(23, 20);
			this->dateTimePicker1->TabIndex = 11;
			// 
			// back
			// 
			this->back->Location = System::Drawing::Point(200, 296);
			this->back->Name = L"back";
			this->back->Size = System::Drawing::Size(75, 23);
			this->back->TabIndex = 12;
			this->back->Text = L"Close";
			this->back->UseVisualStyleBackColor = true;
			this->back->Click += gcnew System::EventHandler(this, &Event::back_Click);
			// 
			// Event
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(287, 331);
			this->Controls->Add(this->back);
			this->Controls->Add(this->dateTimePicker1);
			this->Controls->Add(this->editEventBtn);
			this->Controls->Add(this->description);
			this->Controls->Add(this->descriptionText);
			this->Controls->Add(this->createEventBtn);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->endDate);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->startDate);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->eventTitle);
			this->Name = L"Event";
			this->Text = L"Event";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void createEventBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		System::String^ Title = eventTitle->Text;
		System::String^ start = startDate->Text;
		System::String^ end = endDate->Text;
		System::String^ desc = description->Text;

		msclr::interop::marshal_context context;
		std::string eventTitle = context.marshal_as<std::string>(Title);
		std::string startDate = context.marshal_as<std::string>(start);
		std::string endDate = context.marshal_as<std::string>(end);
		std::string description = context.marshal_as<std::string>(desc);

		std::cout << "startDate: " << startDate << "\n";
		std::cout << "endDate: " << endDate << "\n";

		extern std::string userID;
		nlohmann::json j;
		j["startDate"] = startDate;
		j["eventTitle"] = eventTitle;
		j["description"] = description;
		j["endDate"] = endDate;
		j["userID"] = userID;
		std::string json{ j.dump() };

		std::cout << json;

		Api api;
		extern std::string apiKey;
		std::string response = api.sendData("/api/event/create_event.php", json, apiKey);
	}
private: System::Void back_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
}
};
}
