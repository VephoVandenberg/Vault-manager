#pragma once

namespace VaultManager {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for VaultManager
	/// </summary>
	public ref class VaultManager : public System::Windows::Forms::Form
	{
	public:
		VaultManager(void)
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
		~VaultManager()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(226, 226);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(105, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Confirm database";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(226, 197);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(105, 23);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Delete database";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(12, 226);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(162, 23);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Open password genereator";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &VaultManager::button3_Click);
			// 
			// VaultManager
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(343, 261);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"VaultManager";
			this->Text = L"VaultManager";
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e)
	{
		PasswordGenereator^ password_generator_obj = gcnew PasswordGenerator();
		password_generator_obj->ShowDialog();
	}

	};
}
