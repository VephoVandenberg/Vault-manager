#pragma once

#include "Generator.h"

namespace VaultManager {
		
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for PasswordGenerator
	/// </summary>
	public ref class PasswordGenerator : public System::Windows::Forms::Form
	{
	public:
		PasswordGenerator(void)
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
		~PasswordGenerator()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ password_place;
	protected:

	private: System::Windows::Forms::CheckBox^ lowercase;
	private: System::Windows::Forms::CheckBox^ uppercase;
	private: System::Windows::Forms::CheckBox^ brackets;



	private: System::Windows::Forms::CheckBox^ numbers;
	private: System::Windows::Forms::CheckBox^ specials;
	private: System::Windows::Forms::NumericUpDown^ length;



	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button1;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->password_place = (gcnew System::Windows::Forms::TextBox());
			this->lowercase = (gcnew System::Windows::Forms::CheckBox());
			this->uppercase = (gcnew System::Windows::Forms::CheckBox());
			this->brackets = (gcnew System::Windows::Forms::CheckBox());
			this->numbers = (gcnew System::Windows::Forms::CheckBox());
			this->specials = (gcnew System::Windows::Forms::CheckBox());
			this->length = (gcnew System::Windows::Forms::NumericUpDown());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->length))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 28);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(105, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Generated password";
			// 
			// password_place
			// 
			this->password_place->Location = System::Drawing::Point(123, 25);
			this->password_place->Name = L"password_place";
			this->password_place->Size = System::Drawing::Size(299, 20);
			this->password_place->TabIndex = 1;
			// 
			// lowercase
			// 
			this->lowercase->AutoSize = true;
			this->lowercase->Location = System::Drawing::Point(201, 64);
			this->lowercase->Name = L"lowercase";
			this->lowercase->Size = System::Drawing::Size(96, 17);
			this->lowercase->TabIndex = 2;
			this->lowercase->Text = L"Use lowercase";
			this->lowercase->UseVisualStyleBackColor = true;
			// 
			// uppercase
			// 
			this->uppercase->AutoSize = true;
			this->uppercase->Location = System::Drawing::Point(303, 64);
			this->uppercase->Name = L"uppercase";
			this->uppercase->Size = System::Drawing::Size(98, 17);
			this->uppercase->TabIndex = 3;
			this->uppercase->Text = L"Use uppercase";
			this->uppercase->UseVisualStyleBackColor = true;
			// 
			// brackets
			// 
			this->brackets->AutoSize = true;
			this->brackets->Location = System::Drawing::Point(303, 96);
			this->brackets->Name = L"brackets";
			this->brackets->Size = System::Drawing::Size(89, 17);
			this->brackets->TabIndex = 4;
			this->brackets->Text = L"Use brackets";
			this->brackets->UseVisualStyleBackColor = true;
			// 
			// numbers
			// 
			this->numbers->AutoSize = true;
			this->numbers->Location = System::Drawing::Point(201, 96);
			this->numbers->Name = L"numbers";
			this->numbers->Size = System::Drawing::Size(88, 17);
			this->numbers->TabIndex = 5;
			this->numbers->Text = L"Use numbers";
			this->numbers->UseVisualStyleBackColor = true;
			// 
			// specials
			// 
			this->specials->AutoSize = true;
			this->specials->Location = System::Drawing::Point(243, 125);
			this->specials->Name = L"specials";
			this->specials->Size = System::Drawing::Size(86, 17);
			this->specials->TabIndex = 6;
			this->specials->Text = L"Use specials";
			this->specials->UseVisualStyleBackColor = true;
			// 
			// length
			// 
			this->length->Location = System::Drawing::Point(123, 64);
			this->length->Name = L"length";
			this->length->Size = System::Drawing::Size(72, 20);
			this->length->TabIndex = 7;
			this->length->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(32, 66);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(85, 13);
			this->label2->TabIndex = 8;
			this->label2->Text = L"Password length";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(54, 121);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(130, 23);
			this->button1->TabIndex = 9;
			this->button1->Text = L"Genereate password";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &PasswordGenerator::button1_Click);
			// 
			// PasswordGenerator
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(434, 158);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->length);
			this->Controls->Add(this->specials);
			this->Controls->Add(this->numbers);
			this->Controls->Add(this->brackets);
			this->Controls->Add(this->uppercase);
			this->Controls->Add(this->lowercase);
			this->Controls->Add(this->password_place);
			this->Controls->Add(this->label1);
			this->Name = L"PasswordGenerator";
			this->Text = L"PasswordGenerator";
			this->Load += gcnew System::EventHandler(this, &PasswordGenerator::PasswordGenerator_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->length))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) 
{
	bool check_for_any_symbol = lowercase->Checked |
		uppercase->Checked | numbers->Checked | brackets->Checked | specials->Checked;
	if (check_for_any_symbol)
	{
		unsigned int password_length = length->Value.ToInt32(length->Value);
		char* generated_password = new char[password_length];

		generated_password = generate_password(password_length, lowercase->Checked,
			uppercase->Checked, numbers->Checked, brackets->Checked, specials->Checked);
		
		password_place->Text = gcnew String(generated_password);
		
	}
	else
	{
		MessageBox::Show("You should choose any checkbox to generate a password");
	}
}

private: System::Void PasswordGenerator_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
};

