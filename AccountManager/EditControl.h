#pragma once
#include "Account.h"
#include "AccountsFileHandler.h"
#include "PasswordGeneratorControl.h"


using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace AccountManager {

	/// <summary>
	/// Summary for EditControl
	/// </summary>
	public ref class EditControl : public System::Windows::Forms::UserControl
	{
	private:
		Account* account;
		AccountsFileHandler* fileHandler;
		Form^ mainForm;
		PasswordGeneratorControl^ passwordGeneratorControl;

		uint32_t prevPosition;
		std::string* prevAccountName;

		bool isPasswordVisible = false;


	public:
		EditControl(Account* account, AccountsFileHandler* fileHandler, Form^ mainForm)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->account = account;
			this->fileHandler = fileHandler;
			this->mainForm = mainForm;

			this->passwordGeneratorControl = gcnew PasswordGeneratorControl(this->passwordTextBox);
			this->passwordGeneratorControl->Location = Point(350, 150);
			this->Controls->Add(this->passwordGeneratorControl);

			this->prevAccountName = new std::string();
			this->isPasswordVisible = false;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~EditControl()
		{
			if (components)
			{
				delete components;
			}
			delete this->prevAccountName;
		}

	private: System::Windows::Forms::Label^ accountNameLabel;
	private: System::Windows::Forms::TextBox^ accountNameTextBox;
	private: System::Windows::Forms::Label^ accountNameErrorLabel;
	private: System::Windows::Forms::Label^ idLabel;
	private: System::Windows::Forms::TextBox^ idTextBox;
	private: System::Windows::Forms::Label^ idErrorLabel;
	private: System::Windows::Forms::Label^ passwordLabel;
	private: System::Windows::Forms::TextBox^ passwordTextBox;
	private: System::Windows::Forms::Label^ passwordErrorLabel;
	private: System::Windows::Forms::Label^ positionLabel;
	private: System::Windows::Forms::TextBox^ positionTextBox;
	private: System::Windows::Forms::Label^ positionErrorLabel;
	private: System::Windows::Forms::Button^ saveButton;
	private: System::Windows::Forms::Button^ showHideButton;


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
			this->saveButton = (gcnew System::Windows::Forms::Button());
			this->passwordTextBox = (gcnew System::Windows::Forms::TextBox());
			this->passwordLabel = (gcnew System::Windows::Forms::Label());
			this->idTextBox = (gcnew System::Windows::Forms::TextBox());
			this->idLabel = (gcnew System::Windows::Forms::Label());
			this->accountNameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->accountNameLabel = (gcnew System::Windows::Forms::Label());
			this->positionTextBox = (gcnew System::Windows::Forms::TextBox());
			this->positionLabel = (gcnew System::Windows::Forms::Label());
			this->passwordErrorLabel = (gcnew System::Windows::Forms::Label());
			this->idErrorLabel = (gcnew System::Windows::Forms::Label());
			this->accountNameErrorLabel = (gcnew System::Windows::Forms::Label());
			this->positionErrorLabel = (gcnew System::Windows::Forms::Label());
			this->showHideButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// saveButton
			// 
			this->saveButton->Location = System::Drawing::Point(67, 468);
			this->saveButton->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->saveButton->Name = L"saveButton";
			this->saveButton->Size = System::Drawing::Size(107, 31);
			this->saveButton->TabIndex = 5;
			this->saveButton->Text = L"Save";
			this->saveButton->UseVisualStyleBackColor = true;
			this->saveButton->Click += gcnew System::EventHandler(this, &EditControl::saveButton_Click);
			// 
			// passwordTextBox
			// 
			this->passwordTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->passwordTextBox->Location = System::Drawing::Point(67, 289);
			this->passwordTextBox->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->passwordTextBox->Name = L"passwordTextBox";
			this->passwordTextBox->PasswordChar = '*';
			this->passwordTextBox->Size = System::Drawing::Size(332, 26);
			this->passwordTextBox->TabIndex = 2;
			// 
			// passwordLabel
			// 
			this->passwordLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->passwordLabel->Location = System::Drawing::Point(67, 258);
			this->passwordLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->passwordLabel->Name = L"passwordLabel";
			this->passwordLabel->Size = System::Drawing::Size(333, 25);
			this->passwordLabel->TabIndex = 8;
			this->passwordLabel->Text = L"Password:";
			this->passwordLabel->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// idTextBox
			// 
			this->idTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->idTextBox->Location = System::Drawing::Point(67, 191);
			this->idTextBox->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->idTextBox->Name = L"idTextBox";
			this->idTextBox->Size = System::Drawing::Size(332, 26);
			this->idTextBox->TabIndex = 1;
			// 
			// idLabel
			// 
			this->idLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->idLabel->Location = System::Drawing::Point(67, 160);
			this->idLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->idLabel->Name = L"idLabel";
			this->idLabel->Size = System::Drawing::Size(333, 25);
			this->idLabel->TabIndex = 7;
			this->idLabel->Text = L"ID:";
			this->idLabel->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// accountNameTextBox
			// 
			this->accountNameTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->accountNameTextBox->Location = System::Drawing::Point(67, 92);
			this->accountNameTextBox->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->accountNameTextBox->Name = L"accountNameTextBox";
			this->accountNameTextBox->Size = System::Drawing::Size(332, 26);
			this->accountNameTextBox->TabIndex = 0;
			// 
			// accountNameLabel
			// 
			this->accountNameLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->accountNameLabel->Location = System::Drawing::Point(67, 62);
			this->accountNameLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->accountNameLabel->Name = L"accountNameLabel";
			this->accountNameLabel->Size = System::Drawing::Size(333, 25);
			this->accountNameLabel->TabIndex = 6;
			this->accountNameLabel->Text = L"Account Name:";
			this->accountNameLabel->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// positionTextBox
			// 
			this->positionTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->positionTextBox->Location = System::Drawing::Point(67, 388);
			this->positionTextBox->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->positionTextBox->Name = L"positionTextBox";
			this->positionTextBox->Size = System::Drawing::Size(332, 26);
			this->positionTextBox->TabIndex = 4;
			this->positionTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &EditControl::positionTextBox_KeyPress);
			// 
			// positionLabel
			// 
			this->positionLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->positionLabel->Location = System::Drawing::Point(67, 357);
			this->positionLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->positionLabel->Name = L"positionLabel";
			this->positionLabel->Size = System::Drawing::Size(333, 25);
			this->positionLabel->TabIndex = 9;
			this->positionLabel->Text = L"Position (Optional):";
			this->positionLabel->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// passwordErrorLabel
			// 
			this->passwordErrorLabel->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->passwordErrorLabel->ForeColor = System::Drawing::Color::Red;
			this->passwordErrorLabel->Location = System::Drawing::Point(67, 320);
			this->passwordErrorLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->passwordErrorLabel->Name = L"passwordErrorLabel";
			this->passwordErrorLabel->Size = System::Drawing::Size(333, 25);
			this->passwordErrorLabel->TabIndex = 12;
			this->passwordErrorLabel->Text = L"Password error label.";
			this->passwordErrorLabel->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->passwordErrorLabel->Visible = false;
			// 
			// idErrorLabel
			// 
			this->idErrorLabel->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->idErrorLabel->ForeColor = System::Drawing::Color::Red;
			this->idErrorLabel->Location = System::Drawing::Point(67, 222);
			this->idErrorLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->idErrorLabel->Name = L"idErrorLabel";
			this->idErrorLabel->Size = System::Drawing::Size(333, 25);
			this->idErrorLabel->TabIndex = 11;
			this->idErrorLabel->Text = L"ID error label.";
			this->idErrorLabel->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->idErrorLabel->Visible = false;
			// 
			// accountNameErrorLabel
			// 
			this->accountNameErrorLabel->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->accountNameErrorLabel->ForeColor = System::Drawing::Color::Red;
			this->accountNameErrorLabel->Location = System::Drawing::Point(67, 123);
			this->accountNameErrorLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->accountNameErrorLabel->Name = L"accountNameErrorLabel";
			this->accountNameErrorLabel->Size = System::Drawing::Size(333, 25);
			this->accountNameErrorLabel->TabIndex = 10;
			this->accountNameErrorLabel->Text = L"Account name error label.";
			this->accountNameErrorLabel->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->accountNameErrorLabel->Visible = false;
			// 
			// positionErrorLabel
			// 
			this->positionErrorLabel->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->positionErrorLabel->ForeColor = System::Drawing::Color::Red;
			this->positionErrorLabel->Location = System::Drawing::Point(67, 418);
			this->positionErrorLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->positionErrorLabel->Name = L"positionErrorLabel";
			this->positionErrorLabel->Size = System::Drawing::Size(333, 25);
			this->positionErrorLabel->TabIndex = 13;
			this->positionErrorLabel->Text = L"Position error label.";
			this->positionErrorLabel->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->positionErrorLabel->Visible = false;
			// 
			// showHideButton
			// 
			this->showHideButton->Location = System::Drawing::Point(400, 287);
			this->showHideButton->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->showHideButton->Name = L"showHideButton";
			this->showHideButton->Size = System::Drawing::Size(67, 31);
			this->showHideButton->TabIndex = 3;
			this->showHideButton->Text = L"Show";
			this->showHideButton->UseVisualStyleBackColor = true;
			this->showHideButton->Click += gcnew System::EventHandler(this, &EditControl::showHideButton_Click);
			// 
			// EditControl
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->showHideButton);
			this->Controls->Add(this->passwordErrorLabel);
			this->Controls->Add(this->idErrorLabel);
			this->Controls->Add(this->accountNameErrorLabel);
			this->Controls->Add(this->positionErrorLabel);
			this->Controls->Add(this->saveButton);
			this->Controls->Add(this->passwordTextBox);
			this->Controls->Add(this->passwordLabel);
			this->Controls->Add(this->idTextBox);
			this->Controls->Add(this->idLabel);
			this->Controls->Add(this->accountNameTextBox);
			this->Controls->Add(this->accountNameLabel);
			this->Controls->Add(this->positionTextBox);
			this->Controls->Add(this->positionLabel);
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->Name = L"EditControl";
			this->Size = System::Drawing::Size(907, 640);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void positionTextBox_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
	{
		// Accepting only numbers.
		e->Handled = !System::Char::IsDigit(e->KeyChar) && !System::Char::IsControl(e->KeyChar);
	}
	private: System::Void showHideButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (this->isPasswordVisible) {
			this->hidePassword();
		}
		else {
			this->showPassword();
		}
	}

	public: 
		System::Void hidePassword()
		{
			this->passwordTextBox->PasswordChar = '*';
			this->showHideButton->Text = "Show";
			this->isPasswordVisible = false;
		}

	private:
		System::Void showPassword()
		{
			this->passwordTextBox->PasswordChar = 0;
			this->showHideButton->Text = "Hide";
			this->isPasswordVisible = true;
		}

		bool error()
		{
			return (this->accountNameErrorLabel->Visible || this->idErrorLabel->Visible
					|| this->passwordErrorLabel->Visible || this->positionErrorLabel->Visible);
		}

	public:
		System::Void hideErrorLabels()
		{
			this->accountNameErrorLabel->Visible = false;
			this->idErrorLabel->Visible = false;
			this->passwordErrorLabel->Visible = false;
			this->positionErrorLabel->Visible = false;
		}

		System::Void setTextBoxes(std::string position, std::string accountName, std::string id, std::string password)
		{
			this->accountNameTextBox->Text = gcnew System::String(accountName.c_str());
			this->idTextBox->Text = gcnew System::String(id.c_str());
			this->passwordTextBox->Text = gcnew System::String(password.c_str());
			this->positionTextBox->Text = gcnew System::String(position.c_str());

			this->prevPosition = Convert::ToUInt32(this->positionTextBox->Text);
			*this->prevAccountName = accountName;
		}

	private: System::Void saveButton_Click(System::Object^ sender, System::EventArgs^ e);

};
}
