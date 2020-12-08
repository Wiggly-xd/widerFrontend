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
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ description;
	private: System::Windows::Forms::TextBox^ textBox1;

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
			this->eventTitle = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->startDate = (gcnew System::Windows::Forms::DateTimePicker());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->endDate = (gcnew System::Windows::Forms::DateTimePicker());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->description = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
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
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->label1->Location = System::Drawing::Point(74, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(151, 25);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Create an event";
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
			this->label2->Location = System::Drawing::Point(96, 64);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(103, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Enter name of event";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
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
			this->label4->Location = System::Drawing::Point(96, 165);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(119, 13);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Enter end date of event";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(99, 261);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 7;
			this->button1->Text = L"Create";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// description
			// 
			this->description->AutoSize = true;
			this->description->Location = System::Drawing::Point(96, 219);
			this->description->Name = L"description";
			this->description->Size = System::Drawing::Size(102, 13);
			this->description->TabIndex = 8;
			this->description->Text = L"Describe your event";
			this->description->Click += gcnew System::EventHandler(this, &Event::label5_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(43, 235);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(200, 20);
			this->textBox1->TabIndex = 9;
			// 
			// Event
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 331);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->description);
			this->Controls->Add(this->button1);
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
};
}
