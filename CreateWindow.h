#pragma once

#include "Hash.h"
#include "RSA.h"

namespace VaultManager {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace std;
	/// <summary>
	/// Summary for CreateWindow
	/// </summary>
	public ref class CreateWindow : public System::Windows::Forms::Form
	{
	public:
		CreateWindow(void)
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
		~CreateWindow()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ username;

	private: System::Windows::Forms::TextBox^ password;
	private: System::Windows::Forms::TextBox^ password_confirm;



	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::CheckBox^ checkBox1;
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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->username = (gcnew System::Windows::Forms::TextBox());
			this->password = (gcnew System::Windows::Forms::TextBox());
			this->password_confirm = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(26, 31);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(90, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Master Username";
			this->label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(26, 67);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(87, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Master password";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(26, 101);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(90, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Confirm password";
			// 
			// username
			// 
			this->username->AcceptsReturn = true;
			this->username->Location = System::Drawing::Point(122, 28);
			this->username->Name = L"username";
			this->username->Size = System::Drawing::Size(235, 20);
			this->username->TabIndex = 3;
			// 
			// password
			// 
			this->password->Location = System::Drawing::Point(122, 64);
			this->password->Name = L"password";
			this->password->PasswordChar = '*';
			this->password->Size = System::Drawing::Size(235, 20);
			this->password->TabIndex = 4;
			// 
			// password_confirm
			// 
			this->password_confirm->Location = System::Drawing::Point(122, 98);
			this->password_confirm->Name = L"password_confirm";
			this->password_confirm->PasswordChar = '*';
			this->password_confirm->Size = System::Drawing::Size(235, 20);
			this->password_confirm->TabIndex = 5;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(282, 133);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 7;
			this->button1->Text = L"Create User";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &CreateWindow::button1_Click);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(137, 137);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(106, 17);
			this->checkBox1->TabIndex = 8;
			this->checkBox1->Text = L"Show passwords";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &CreateWindow::checkBox1_CheckedChanged);
			// 
			// CreateWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(387, 163);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->password_confirm);
			this->Controls->Add(this->password);
			this->Controls->Add(this->username);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"CreateWindow";
			this->Text = L"Create new user and database";
			this->Load += gcnew System::EventHandler(this, &CreateWindow::CreateWindow_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	private: System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) 
	{
		password->PasswordChar = (checkBox1->Checked) ? 0 : '*';
		password_confirm->PasswordChar = (checkBox1->Checked) ? 0 : '*';
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		ifstream check_file;
		char* filename = new char[username->Text->Length+5];

		for (int i = 0; i <= username->Text->Length; i++)
		{
			if (i == username->Text->Length)
			{
				filename[i++] = '.';
				filename[i++] = 't';
				filename[i++] = 'x';
				filename[i++] = 't';
				filename[i] = '\0';
			}
			else
			{
				filename[i] = username->Text[i];
			}
		}

		check_file.open(filename);

		if (!check_file.is_open() && username->Text->Length)
		{
			if (password->Text == password_confirm->Text)
			{
				int i;
				char* pass = new char[password->Text->Length];
				ofstream file_to_write(filename);
				
				Encryptor::RSA encryptor;
				encryptor.generate_keys();

				for (i = 0; i < password->Text->Length; i++)
				{
					pass[i] = password->Text[i];
				}
				pass[i] = '\0';

				// write hashed password
				file_to_write << hash_string(pass) << '\n';

				// create database file and write there keys
				char database_destenation[250] = "Database\\database_";
				strcat(database_destenation, filename);
				ofstream database_file(database_destenation);

				// write public and private keys at the begining of the database file
				database_file << encryptor.get_public_key().exponent << "\n";
				database_file << encryptor.get_public_key().modulus << "\n";

				database_file << encryptor.get_private_key().exponent << "\n";
				database_file << encryptor.get_private_key().modulus;

				file_to_write.close();
				database_file.close();
				MessageBox::Show("User has been created");
			}
			else
			{
				MessageBox::Show("You didn't confirm your password");
			}
		}
		else
		{
			if (!username->Text->Length)
			{
				MessageBox::Show("Empty username is not valid");
			}
			else
			{
				MessageBox::Show("Such user already exist");
			}
		}
	}
private: System::Void CreateWindow_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}
