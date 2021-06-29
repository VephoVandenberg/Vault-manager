#pragma once

#include "ManagerForm.h"
#include "CreateWindow.h"
#include "Hash.h"

namespace CppCLRWinformsProjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Zusammenfassung für Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzufügen.
			//
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ username;
	private: System::Windows::Forms::TextBox^ password;
	protected:

	protected:

	private: System::Windows::Forms::Label^ Label1;
	private: System::Windows::Forms::Label^ Label2;


	private: System::Windows::Forms::Button^ log_button;
	private: System::Windows::Forms::Button^ create_button;





	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->username = (gcnew System::Windows::Forms::TextBox());
			this->password = (gcnew System::Windows::Forms::TextBox());
			this->Label1 = (gcnew System::Windows::Forms::Label());
			this->Label2 = (gcnew System::Windows::Forms::Label());
			this->log_button = (gcnew System::Windows::Forms::Button());
			this->create_button = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// username
			// 
			this->username->Location = System::Drawing::Point(73, 29);
			this->username->Name = L"username";
			this->username->Size = System::Drawing::Size(241, 20);
			this->username->TabIndex = 0;
			// 
			// password
			// 
			this->password->Location = System::Drawing::Point(73, 70);
			this->password->Name = L"password";
			this->password->PasswordChar = '*';
			this->password->Size = System::Drawing::Size(241, 20);
			this->password->TabIndex = 1;
			// 
			// Label1
			// 
			this->Label1->AutoSize = true;
			this->Label1->Location = System::Drawing::Point(12, 32);
			this->Label1->Name = L"Label1";
			this->Label1->Size = System::Drawing::Size(55, 13);
			this->Label1->TabIndex = 2;
			this->Label1->Text = L"Username";
			// 
			// Label2
			// 
			this->Label2->AutoSize = true;
			this->Label2->Location = System::Drawing::Point(14, 73);
			this->Label2->Name = L"Label2";
			this->Label2->Size = System::Drawing::Size(53, 13);
			this->Label2->TabIndex = 3;
			this->Label2->Text = L"Password";
			// 
			// log_button
			// 
			this->log_button->Location = System::Drawing::Point(239, 106);
			this->log_button->Name = L"log_button";
			this->log_button->Size = System::Drawing::Size(75, 23);
			this->log_button->TabIndex = 4;
			this->log_button->Text = L"Log in";
			this->log_button->UseVisualStyleBackColor = true;
			this->log_button->Click += gcnew System::EventHandler(this, &Form1::log_button_Click);
			// 
			// create_button
			// 
			this->create_button->Location = System::Drawing::Point(144, 106);
			this->create_button->Name = L"create_button";
			this->create_button->Size = System::Drawing::Size(75, 23);
			this->create_button->TabIndex = 5;
			this->create_button->Text = L"Create user";
			this->create_button->UseVisualStyleBackColor = true;
			this->create_button->Click += gcnew System::EventHandler(this, &Form1::create_button_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(336, 141);
			this->Controls->Add(this->create_button);
			this->Controls->Add(this->log_button);
			this->Controls->Add(this->Label2);
			this->Controls->Add(this->Label1);
			this->Controls->Add(this->password);
			this->Controls->Add(this->username);
			this->Name = L"Form1";
			this->Text = L"Vault Manager";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	private: System::Void log_button_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		char* user = new char[username->Text->Length+5];
		char* pass = new char[password->Text->Length];

		for (int i = 0; i <= username->Text->Length; i++)
		{
			if (i == username->Text->Length)
			{
				user[i++] = '.';
				user[i++] = 't';
				user[i++] = 'x';
				user[i++] = 't';
				user[i] = '\0';
			}
			else
			{
				user[i] = username->Text[i];
			}
		}
		
		for (int i = 0; i <= password->Text->Length; i++)
		{
			if (i == password->Text->Length)
			{
				pass[i] = '\0';
			}
			else
			{
				pass[i] = password->Text[i];
			}
		}

		ifstream user_file(user);
		if (user_file.is_open())
		{
			char* hashed_password = hash_string(pass);
			char* user_password = new char[strlen(hashed_password)];
			user_file >> user_password;
			if (strncmp(user_password, hashed_password, strlen(hashed_password)) == 0)
			{
				char database_name[250] = "Database\\database_";
				strcat(database_name, user);
				VaultManager::ManagerForm^ manager_obj = gcnew VaultManager::ManagerForm(database_name);
				this->Hide();
				manager_obj->ShowDialog();
				Application::Exit();
			}
			else
			{
				String^ first_pass = gcnew String(hashed_password);
				String^ second_pass = gcnew String(user_password);
				MessageBox::Show(first_pass + " " + second_pass);
			}
		}
		else
		{
			MessageBox::Show("No such user");
		}
		user_file.close();
	}
		 	
	private: System::Void create_button_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		this->Hide();
		VaultManager::CreateWindow^ create_user_obj = gcnew VaultManager::CreateWindow();
		create_user_obj->ShowDialog();
		this->Show();
	}
};
}
