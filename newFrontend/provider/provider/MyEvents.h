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

	protected:





	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ deleteBtn;
	private: System::Windows::Forms::Button^ editBtn;
	private: System::Windows::Forms::Button^ createBtn;



	private: System::Windows::Forms::TextBox^ inviteID;









	private: System::Windows::Forms::Label^ label10;


	private: System::Windows::Forms::DataGridView^ table;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ eventTitle;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ startDate;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ endDate;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ description;
	private: System::Windows::Forms::Button^ inviteBtn;




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
			this->inviteID = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->table = (gcnew System::Windows::Forms::DataGridView());
			this->eventTitle = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->startDate = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->endDate = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->description = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->inviteBtn = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->table))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->label1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label1->Location = System::Drawing::Point(200, 31);
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
			// inviteID
			// 
			this->inviteID->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->inviteID->Location = System::Drawing::Point(308, 348);
			this->inviteID->Name = L"inviteID";
			this->inviteID->Size = System::Drawing::Size(75, 20);
			this->inviteID->TabIndex = 18;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->BackColor = System::Drawing::Color::Transparent;
			this->label10->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label10->Location = System::Drawing::Point(305, 333);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(103, 13);
			this->label10->TabIndex = 19;
			this->label10->Text = L"Id of person to invite";
			// 
			// table
			// 
			this->table->AllowUserToOrderColumns = true;
			this->table->BackgroundColor = System::Drawing::SystemColors::Highlight;
			this->table->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->table->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->eventTitle, this->startDate,
					this->endDate, this->description
			});
			this->table->Location = System::Drawing::Point(21, 72);
			this->table->Name = L"table";
			this->table->Size = System::Drawing::Size(443, 182);
			this->table->TabIndex = 21;
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
			this->inviteBtn->Location = System::Drawing::Point(389, 348);
			this->inviteBtn->Name = L"inviteBtn";
			this->inviteBtn->Size = System::Drawing::Size(75, 20);
			this->inviteBtn->TabIndex = 22;
			this->inviteBtn->Text = L"Invite";
			this->inviteBtn->UseVisualStyleBackColor = true;
			// 
			// MyEvents
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(488, 383);
			this->Controls->Add(this->inviteBtn);
			this->Controls->Add(this->table);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->inviteID);
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
}
private: System::Void radioButton2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label12_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void inviteBtn_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
