
#include "PasswordGenerator.h"
#include "RSA.h"
#include "DataForm.h"

#include <string>

namespace VaultManager {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace std;
	/// <summary>
	/// Summary for ManagerForm
	/// </summary>
	public ref class ManagerForm : public System::Windows::Forms::Form
	{
	public:
		ManagerForm(char *base_name)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			records = new data_form[MAX_SIZE];
			encryptor = new Encryptor::RSA();
			database_name = base_name;
			main_record_iterator = 0;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ManagerForm()
		{
			if (components)
			{
				delete components;
				delete records;
				delete encryptor;
			}
		}
	private: System::Windows::Forms::Button^ confirm;
	protected:

	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::ListBox^ recs;
	private: System::Windows::Forms::TextBox^ record_name;
	private: System::Windows::Forms::TextBox^ url;
	private: System::Windows::Forms::TextBox^ username;




	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ password;

	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::Button^ change_record;

	private: System::Windows::Forms::Button^ create_record;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

		data_form *records;
		Encryptor::RSA *encryptor;
		char* database_name;
		int main_record_iterator;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->confirm = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->recs = (gcnew System::Windows::Forms::ListBox());
			this->record_name = (gcnew System::Windows::Forms::TextBox());
			this->url = (gcnew System::Windows::Forms::TextBox());
			this->username = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->password = (gcnew System::Windows::Forms::TextBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->change_record = (gcnew System::Windows::Forms::Button());
			this->create_record = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// confirm
			// 
			this->confirm->Location = System::Drawing::Point(12, 242);
			this->confirm->Name = L"confirm";
			this->confirm->Size = System::Drawing::Size(102, 23);
			this->confirm->TabIndex = 0;
			this->confirm->Text = L"Confirm database";
			this->confirm->UseVisualStyleBackColor = true;
			this->confirm->Click += gcnew System::EventHandler(this, &ManagerForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(12, 215);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(102, 24);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Delete database";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &ManagerForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(120, 215);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(102, 50);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Open password generator";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &ManagerForm::button3_Click);
			// 
			// recs
			// 
			this->recs->FormattingEnabled = true;
			this->recs->Location = System::Drawing::Point(12, 12);
			this->recs->Name = L"recs";
			this->recs->Size = System::Drawing::Size(210, 186);
			this->recs->TabIndex = 5;
			this->recs->SelectedIndexChanged += gcnew System::EventHandler(this, &ManagerForm::recs_SelectedIndexChanged);
			// 
			// record_name
			// 
			this->record_name->Location = System::Drawing::Point(316, 16);
			this->record_name->Name = L"record_name";
			this->record_name->Size = System::Drawing::Size(233, 20);
			this->record_name->TabIndex = 6;
			// 
			// url
			// 
			this->url->Location = System::Drawing::Point(316, 66);
			this->url->Name = L"url";
			this->url->Size = System::Drawing::Size(233, 20);
			this->url->TabIndex = 7;
			// 
			// username
			// 
			this->username->Location = System::Drawing::Point(316, 123);
			this->username->Name = L"username";
			this->username->Size = System::Drawing::Size(233, 20);
			this->username->TabIndex = 8;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(239, 19);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(71, 13);
			this->label1->TabIndex = 9;
			this->label1->Text = L"Record name";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(256, 69);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(29, 13);
			this->label2->TabIndex = 10;
			this->label2->Text = L"URL";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(239, 126);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(55, 13);
			this->label3->TabIndex = 11;
			this->label3->Text = L"Username";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(241, 185);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(53, 13);
			this->label4->TabIndex = 12;
			this->label4->Text = L"Password";
			// 
			// password
			// 
			this->password->Location = System::Drawing::Point(316, 182);
			this->password->Name = L"password";
			this->password->PasswordChar = '*';
			this->password->Size = System::Drawing::Size(233, 20);
			this->password->TabIndex = 13;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(448, 233);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(101, 17);
			this->checkBox1->TabIndex = 14;
			this->checkBox1->Text = L"Show password";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &ManagerForm::checkBox1_CheckedChanged);
			// 
			// change_record
			// 
			this->change_record->Location = System::Drawing::Point(316, 212);
			this->change_record->Name = L"change_record";
			this->change_record->Size = System::Drawing::Size(126, 27);
			this->change_record->TabIndex = 15;
			this->change_record->Text = L"Change record";
			this->change_record->UseVisualStyleBackColor = true;
			this->change_record->Click += gcnew System::EventHandler(this, &ManagerForm::button4_Click);
			// 
			// create_record
			// 
			this->create_record->Location = System::Drawing::Point(316, 245);
			this->create_record->Name = L"create_record";
			this->create_record->Size = System::Drawing::Size(126, 27);
			this->create_record->TabIndex = 16;
			this->create_record->Text = L"Create record";
			this->create_record->UseVisualStyleBackColor = true;
			this->create_record->Click += gcnew System::EventHandler(this, &ManagerForm::create_record_Click);
			// 
			// ManagerForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(571, 277);
			this->Controls->Add(this->create_record);
			this->Controls->Add(this->change_record);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->password);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->username);
			this->Controls->Add(this->url);
			this->Controls->Add(this->record_name);
			this->Controls->Add(this->recs);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->confirm);
			this->Name = L"ManagerForm";
			this->Text = L"Vault Manager";
			this->Load += gcnew System::EventHandler(this, &ManagerForm::ManagerForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e)
	{
		VaultManager::PasswordGenerator^ generator_obj = gcnew VaultManager::PasswordGenerator();
		generator_obj->ShowDialog();
	}

	private: System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
	{
		password->PasswordChar = (checkBox1->Checked) ? 0 : '*';
	}

	private: System::Void ManagerForm_Load(System::Object^ sender, System::EventArgs^ e)
	{
		ifstream database_file(database_name);
		
		if (database_file.is_open())
		{
			string temp;

			long long private_exponent;
			long long private_modulus;

			long long public_exponent;
			long long public_modulus;

			getline(database_file, temp);
			public_exponent = stoll(temp);

			getline(database_file, temp);
			public_modulus = stoll(temp);

			getline(database_file, temp);
			private_exponent = stoll(temp);
			
			getline(database_file, temp);
			private_modulus = stoll(temp);

			encryptor->set_private_key(private_exponent, private_modulus);
			encryptor->set_public_key(public_exponent, public_modulus);

			while (!database_file.eof())
			{
				/*
				database_file >> records[main_record_iterator].record_name;
				database_file >> records[main_record_iterator].url;
				database_file >> records[main_record_iterator].username;
				database_file >> records[main_record_iterator].password;
				*/
				/*
				getline(database_file, temp);
				strcpy(records[main_record_iterator].record_name, temp.c_str());
				
				getline(database_file, temp);
				strcpy(records[main_record_iterator].url , temp.c_str());

				getline(database_file, temp);
				strcpy(records[main_record_iterator].username, temp.c_str());

				getline(database_file, temp);
				strcpy(records[main_record_iterator].password, temp.c_str());
				*/

				encryptor->deserialize(&database_file, records[main_record_iterator].record_name);
				encryptor->deserialize(&database_file, records[main_record_iterator].url);
				encryptor->deserialize(&database_file, records[main_record_iterator].username);
				encryptor->deserialize(&database_file, records[main_record_iterator].password);

				recs->Items->Add(gcnew String(records[main_record_iterator].record_name));
				main_record_iterator++;
			}
		}
		else
		{
			MessageBox::Show("Could not open" + gcnew String(database_name));
		}
	}
	private: System::Void create_record_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (username->Text->Length &&
			password->Text->Length &&
			record_name->Text->Length &&
			url->Text->Length)
		{
			
			int i;
			for (i = 0; i < username->Text->Length; i++)
			{
				records[main_record_iterator].username[i] = username->Text[i];
			}
			records[main_record_iterator].username[i] = '\0';

			for (i = 0; i < password->Text->Length; i++)
			{
				records[main_record_iterator].password[i] = password->Text[i];
			}
			records[main_record_iterator].password[i] = '\0';

			for (i = 0; i < record_name->Text->Length; i++)
			{
				records[main_record_iterator].record_name[i] = record_name->Text[i];
			}
			records[main_record_iterator].record_name[i] = '\0';

			for (i = 0; i < url->Text->Length; i++)
			{
				records[main_record_iterator].url[i] = url->Text[i];
			}
			records[main_record_iterator].url[i] = '\0';

			// Check if such record already exist
			bool record_exist = false;
			for (i = 0; i < main_record_iterator; i++)
			{
				if (strncmp(records[i].record_name, records[main_record_iterator].record_name, strlen(records[i].record_name)) == 0 &&
					strlen(records[i].record_name) == strlen(records[main_record_iterator].record_name))
				{
					record_exist = true;
					break;
				}
			}

			if (!record_exist)
			{
				recs->Items->Add(gcnew String(records[main_record_iterator].record_name));
				main_record_iterator++;
			}
			else
			{
				MessageBox::Show("Such record already exist, if you want a record with this record name, then change the record itself");
			}
		}
		else
		{
			MessageBox::Show("You have to fill every textbox");
		}
	}

	private: System::Void recs_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e)
	{
		int i;
		if (recs->SelectedItem)
		{
			String^ record_string = recs->SelectedItem->ToString();
			char* recname = new char[record_string->Length];

			for (i = 0; i < record_string->Length; i++)
			{
				recname[i] = record_string[i];
			}
			recname[i] = '\0';

			for (i = 0; i < main_record_iterator; i++)
			{
				if (strncmp(recname, records[i].record_name, strlen(recname)) == 0)
				{
					username->Text = gcnew String(records[i].username);
					password->Text = gcnew String(records[i].password);
					url->Text = gcnew String(records[i].url);
					record_name->Text = gcnew String(records[i].record_name);

					break;
				}
			}
		}
	}

	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e)
	{
		int i;
		int v;

		char* recname = new char[record_name->Text->Length];
		for (i = 0; i < record_name->Text->Length; i++)
		{
			recname[i] = record_name->Text[i];
		}
		recname[i] = '\0';

		bool not_found = true;
		for (i = 0; i < main_record_iterator; i++)
		{
			if (strncmp(records[i].record_name, recname, strlen(records[i].record_name)) == 0 &&
				strlen(records[i].record_name) == strlen(recname))
			{
				int v;
				for (v = 0; v < username->Text->Length; v++)
				{
					records[i].username[v] = username->Text[v];
				}
				records[i].username[v] = '\0';

				for (v = 0; v < password->Text->Length; v++)
				{
					records[i].password[v] = password->Text[v];
				}
				records[i].password[v] = '\0';

				for (v = 0; v < url->Text->Length; v++)
				{
					records[i].url[v] = url->Text[v];
				}
				records[i].url[v] = '\0';
				not_found = false;

				MessageBox::Show("User has been changed");
				break;
			}
		}

		if (not_found)
		{
			MessageBox::Show("You want to change the user that doesn't exist");
		}
	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		ofstream database_file(database_name);

		if (database_file.is_open())
		{
			database_file << encryptor->get_public_key().exponent << '\n';
			database_file << encryptor->get_public_key().modulus << '\n';

			database_file << encryptor->get_private_key().exponent << '\n';
			database_file << encryptor->get_private_key().modulus << '\n';
			
			int i;
			for (i = 0; i < main_record_iterator; i++)
			{
				/*
				database_file << records[i].record_name << '\n';
				database_file << records[i].url << '\n';
				database_file << records[i].username << '\n';
				database_file << records[i].password;
				
				if (i + 1 != main_record_iterator)
				{
					database_file << '\n';
				}
				*/
				encryptor->serialize(&database_file, records[i].record_name, false);
				encryptor->serialize(&database_file, records[i].url, false);
				encryptor->serialize(&database_file, records[i].username, false);
				if (i + 1 != main_record_iterator)
				{
					encryptor->serialize(&database_file, records[i].password, false);
				}
				else
				{
					encryptor->serialize(&database_file, records[i].password, true);
				}
			}

			MessageBox::Show("Changes have been saved");
		}
	}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		delete[] records;
		main_record_iterator = 0;
		recs->Items->Clear();

		records = new data_form[MAX_SIZE];
	}
};
};