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
	/// Summary for DeleteEvent
	/// </summary>
	public ref class DeleteEvent : public System::Windows::Forms::Form
	{
	public:
		DeleteEvent(void)
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
		~DeleteEvent()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ yesBtn;
	private: System::Windows::Forms::Button^ noBtn;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(DeleteEvent::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->yesBtn = (gcnew System::Windows::Forms::Button());
			this->noBtn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10));
			this->label1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label1->Location = System::Drawing::Point(2, 78);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(281, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Are you sure you want to delete this event\?";
			// 
			// yesBtn
			// 
			this->yesBtn->Location = System::Drawing::Point(38, 122);
			this->yesBtn->Name = L"yesBtn";
			this->yesBtn->Size = System::Drawing::Size(75, 23);
			this->yesBtn->TabIndex = 1;
			this->yesBtn->Text = L"Yes";
			this->yesBtn->UseVisualStyleBackColor = true;
			this->yesBtn->Click += gcnew System::EventHandler(this, &DeleteEvent::yesBtn_Click);
			// 
			// noBtn
			// 
			this->noBtn->Location = System::Drawing::Point(171, 122);
			this->noBtn->Name = L"noBtn";
			this->noBtn->Size = System::Drawing::Size(75, 23);
			this->noBtn->TabIndex = 2;
			this->noBtn->Text = L"No";
			this->noBtn->UseVisualStyleBackColor = true;
			this->noBtn->Click += gcnew System::EventHandler(this, &DeleteEvent::noBtn_Click);
			// 
			// DeleteEvent
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->noBtn);
			this->Controls->Add(this->yesBtn);
			this->Controls->Add(this->label1);
			this->Name = L"DeleteEvent";
			this->Text = L"DeleteEvent";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void yesBtn_Click(System::Object^ sender, System::EventArgs^ e) {

		Api api;
		extern std::string apiKey;
		extern std::string eventID;

		std::cout << "\n" << "delete_eventID: " << eventID;
		std::string eventInfo = api.sendData("/api/event/delete_event.php", "", apiKey + "&eventID=" + eventID);
		std::string value = "Event Deleted";

		if (apiKey.find(value) == std::string::npos) {
			MessageBox::Show("Event deletion: Successful!");
		}
		else {
			MessageBox::Show("Event deletion: Failed!");
		}
	}
	private: System::Void noBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
	}
};
}
