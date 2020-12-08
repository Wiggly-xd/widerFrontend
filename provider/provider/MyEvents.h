#pragma once

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
	private: System::Windows::Forms::Label^ label3;
	protected:
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::RadioButton^ Corona;
	private: System::Windows::Forms::RadioButton^ Meeting;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::RadioButton^ radioButton1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::RadioButton^ radioButton2;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;

	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Button^ Invite;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label14;
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
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->Corona = (gcnew System::Windows::Forms::RadioButton());
			this->Meeting = (gcnew System::Windows::Forms::RadioButton());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->radioButton1 = (gcnew System::Windows::Forms::RadioButton());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->radioButton2 = (gcnew System::Windows::Forms::RadioButton());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->Invite = (gcnew System::Windows::Forms::Button());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(23, 139);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(56, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Start date:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(23, 152);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(53, 13);
			this->label4->TabIndex = 3;
			this->label4->Text = L"End date:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(205, 139);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(56, 13);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Start date:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(205, 152);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(53, 13);
			this->label6->TabIndex = 5;
			this->label6->Text = L"End date:";
			// 
			// Corona
			// 
			this->Corona->AutoSize = true;
			this->Corona->Location = System::Drawing::Point(67, 65);
			this->Corona->Name = L"Corona";
			this->Corona->Size = System::Drawing::Size(59, 17);
			this->Corona->TabIndex = 6;
			this->Corona->TabStop = true;
			this->Corona->Text = L"Corona";
			this->Corona->UseVisualStyleBackColor = true;
			// 
			// Meeting
			// 
			this->Meeting->AutoSize = true;
			this->Meeting->Location = System::Drawing::Point(251, 65);
			this->Meeting->Name = L"Meeting";
			this->Meeting->Size = System::Drawing::Size(63, 17);
			this->Meeting->TabIndex = 7;
			this->Meeting->TabStop = true;
			this->Meeting->Text = L"Meeting";
			this->Meeting->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->label1->Location = System::Drawing::Point(143, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(104, 25);
			this->label1->TabIndex = 8;
			this->label1->Text = L"My Events";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(217, 319);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 9;
			this->button1->Text = L"Delete";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyEvents::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(298, 319);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 10;
			this->button2->Text = L"Edit";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyEvents::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(12, 319);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(100, 23);
			this->button3->TabIndex = 11;
			this->button3->Text = L"Create new event";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyEvents::button3_Click);
			// 
			// radioButton1
			// 
			this->radioButton1->AutoSize = true;
			this->radioButton1->Location = System::Drawing::Point(67, 168);
			this->radioButton1->Name = L"radioButton1";
			this->radioButton1->Size = System::Drawing::Size(52, 17);
			this->radioButton1->TabIndex = 12;
			this->radioButton1->TabStop = true;
			this->radioButton1->Text = L"Skola";
			this->radioButton1->UseVisualStyleBackColor = true;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(23, 229);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(56, 13);
			this->label2->TabIndex = 13;
			this->label2->Text = L"Start date:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(23, 243);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(53, 13);
			this->label7->TabIndex = 14;
			this->label7->Text = L"End date:";
			// 
			// radioButton2
			// 
			this->radioButton2->AutoSize = true;
			this->radioButton2->Location = System::Drawing::Point(251, 168);
			this->radioButton2->Name = L"radioButton2";
			this->radioButton2->Size = System::Drawing::Size(70, 17);
			this->radioButton2->TabIndex = 15;
			this->radioButton2->TabStop = true;
			this->radioButton2->Text = L"Inlämning";
			this->radioButton2->UseVisualStyleBackColor = true;
			this->radioButton2->CheckedChanged += gcnew System::EventHandler(this, &MyEvents::radioButton2_CheckedChanged);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(205, 229);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(56, 13);
			this->label8->TabIndex = 16;
			this->label8->Text = L"Start date:";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(205, 243);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(53, 13);
			this->label9->TabIndex = 17;
			this->label9->Text = L"End date:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(217, 293);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(75, 20);
			this->textBox1->TabIndex = 18;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(214, 277);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(165, 13);
			this->label10->TabIndex = 19;
			this->label10->Text = L"Enter username you wish to invite";
			// 
			// Invite
			// 
			this->Invite->Location = System::Drawing::Point(298, 293);
			this->Invite->Name = L"Invite";
			this->Invite->Size = System::Drawing::Size(75, 23);
			this->Invite->TabIndex = 20;
			this->Invite->Text = L"Invite";
			this->Invite->UseVisualStyleBackColor = true;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(23, 85);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(147, 13);
			this->label11->TabIndex = 21;
			this->label11->Text = L"How long will corona last omg";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(205, 85);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(131, 13);
			this->label12->TabIndex = 22;
			this->label12->Text = L"Meeting with morgan soon";
			this->label12->Click += gcnew System::EventHandler(this, &MyEvents::label12_Click);
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(205, 188);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(143, 13);
			this->label13->TabIndex = 23;
			this->label13->Text = L"Inlämmning på denna uppgift";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(23, 188);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(94, 13);
			this->label14->TabIndex = 24;
			this->label14->Text = L"Nedräkning till lov!";
			// 
			// MyEvents
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(385, 354);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->Invite);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->radioButton2);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->radioButton1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Meeting);
			this->Controls->Add(this->Corona);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Name = L"MyEvents";
			this->Text = L"MyEvents";
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
}
private: System::Void radioButton2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label12_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
