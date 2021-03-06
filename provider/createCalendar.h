#pragma once
#include "Api.h"
#include "json.hpp"
#include <string>
#include <iostream>
#include "MyEvents.h"
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
	/// Summary for createCalendar
	/// </summary>
	public ref class createCalendar : public System::Windows::Forms::Form
	{
	public:
		createCalendar(void)
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
		~createCalendar()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ serviceTitle;
	private: System::Windows::Forms::Button^ createCalendarBtn;





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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(createCalendar::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->serviceTitle = (gcnew System::Windows::Forms::TextBox());
			this->createCalendarBtn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->label1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label1->Location = System::Drawing::Point(68, 67);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(156, 25);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Create Calendar";
			this->label1->Click += gcnew System::EventHandler(this, &createCalendar::label1_Click);
			// 
			// serviceTitle
			// 
			this->serviceTitle->Location = System::Drawing::Point(39, 114);
			this->serviceTitle->Name = L"serviceTitle";
			this->serviceTitle->Size = System::Drawing::Size(211, 20);
			this->serviceTitle->TabIndex = 1;
			// 
			// createCalendarBtn
			// 
			this->createCalendarBtn->Location = System::Drawing::Point(96, 152);
			this->createCalendarBtn->Name = L"createCalendarBtn";
			this->createCalendarBtn->Size = System::Drawing::Size(97, 33);
			this->createCalendarBtn->TabIndex = 2;
			this->createCalendarBtn->Text = L"Create";
			this->createCalendarBtn->UseVisualStyleBackColor = true;
			this->createCalendarBtn->Click += gcnew System::EventHandler(this, &createCalendar::createCalendarBtn_Click);
			// 
			// createCalendar
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(297, 258);
			this->Controls->Add(this->createCalendarBtn);
			this->Controls->Add(this->serviceTitle);
			this->Controls->Add(this->label1);
			this->Name = L"createCalendar";
			this->Text = L"createCalendar";
			this->Load += gcnew System::EventHandler(this, &createCalendar::createCalendar_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void createCalendarBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		System::String^ Title = serviceTitle->Text;

		msclr::interop::marshal_context context;
		std::string calTitle = context.marshal_as<std::string>(Title);

		extern std::string userID;
		nlohmann::json j;
		j["serviceTitle"] = calTitle;
		j["serviceType"] = 2;
		j["publish"] = 1;
		j["userID"] = userID;
		std::string json{ j.dump() };

		Api api;
		extern std::string apiKey;
		std::string response = api.sendData("/api/pages/create_service.php", json, apiKey);
		std::string incorrect("Wrong API");

		if (response.find(incorrect) == std::string::npos) {
			MessageBox::Show("Calendar creation: Successful!");
			this->Hide();
			MyEvents^ Me = gcnew MyEvents();
			Me->ShowDialog();
		}
		else {
			MessageBox::Show("Calendar creation: Failed!");
		}
	}

private: System::Void createCalendar_Load(System::Object^ sender, System::EventArgs^ e) {

	Api api;
	extern std::string userID;
	extern std::string apiKey;
	std::string exist = api.sendData("/api/pages/read_service_based_on_userID.php", "", apiKey + "&userID=" + userID);

	nlohmann::json jsonData = nlohmann::json::parse(exist);

	char type[]{ ":" };

	int length = static_cast<int>(std::count(exist.begin(), exist.end(), type[0]));

	int real_length = (length - 1) / 3;

	for (int i = 0; i < real_length; i++) {
		std::string serviceType = jsonData["data"][i]["serviceType"];

		if (serviceType == "2") {
			this->Close();
			MyEvents^ Me = gcnew MyEvents();
			Me->ShowDialog();
		}
	}

}
};
}
