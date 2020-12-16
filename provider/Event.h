#pragma once

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




	private: System::Windows::Forms::Label^ description;
	private: System::Windows::Forms::TextBox^ description2;
	private: System::Windows::Forms::Button^ editEventBtn;






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
			this->description = (gcnew System::Windows::Forms::Label());
			this->description2 = (gcnew System::Windows::Forms::TextBox());
			this->editEventBtn = (gcnew System::Windows::Forms::Button());
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
			this->startDate->Location = System::Drawing::Point(43, 128);
			this->startDate->Name = L"startDate";
			this->startDate->Size = System::Drawing::Size(200, 20);
			this->startDate->TabIndex = 2;
			this->startDate->ValueChanged += gcnew System::EventHandler(this, &Event::startDate_ValueChanged);
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
			// 
			// description
			// 
			this->description->AutoSize = true;
			this->description->BackColor = System::Drawing::Color::Transparent;
			this->description->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->description->Location = System::Drawing::Point(96, 219);
			this->description->Name = L"description";
			this->description->Size = System::Drawing::Size(102, 13);
			this->description->TabIndex = 8;
			this->description->Text = L"Describe your event";
			this->description->Click += gcnew System::EventHandler(this, &Event::label5_Click);
			// 
			// description2
			// 
			this->description2->Location = System::Drawing::Point(43, 235);
			this->description2->Multiline = true;
			this->description2->Name = L"description2";
			this->description2->Size = System::Drawing::Size(200, 20);
			this->description2->TabIndex = 9;
			// 
			// editEventBtn
			// 
			this->editEventBtn->Location = System::Drawing::Point(150, 261);
			this->editEventBtn->Name = L"editEventBtn";
			this->editEventBtn->Size = System::Drawing::Size(75, 23);
			this->editEventBtn->TabIndex = 10;
			this->editEventBtn->Text = L"Ediit";
			this->editEventBtn->UseVisualStyleBackColor = true;
			this->editEventBtn->Click += gcnew System::EventHandler(this, &Event::button2_Click);
			// 
			// Event
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(284, 331);
			this->Controls->Add(this->editEventBtn);
			this->Controls->Add(this->description2);
			this->Controls->Add(this->description);
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
	private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void startDate_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
