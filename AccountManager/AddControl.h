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
	/// Summary for AddControl
	/// </summary>
	public ref class AddControl : public System::Windows::Forms::UserControl
	{
	private:
		Account* account;
		AccountsFileHandler* fileHandler;
		Form^ mainForm;
		PasswordGeneratorControl^ passwordGeneratorControl;

	public:
		AddControl(Account* account, AccountsFileHandler* fileHandler, Form^ mainForm)
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
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AddControl()
		{
			if (components)
			{
				delete components;
			}
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
	private: System::Windows::Forms::Button^ addButton;
	private: System::Windows::Forms::Button^ clearButton;
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
			this->positionLabel = (gcnew System::Windows::Forms::Label());
			this->positionTextBox = (gcnew System::Windows::Forms::TextBox());
			this->accountNameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->accountNameLabel = (gcnew System::Windows::Forms::Label());
			this->idTextBox = (gcnew System::Windows::Forms::TextBox());
			this->idLabel = (gcnew System::Windows::Forms::Label());
			this->passwordTextBox = (gcnew System::Windows::Forms::TextBox());
			this->passwordLabel = (gcnew System::Windows::Forms::Label());
			this->addButton = (gcnew System::Windows::Forms::Button());
			this->clearButton = (gcnew System::Windows::Forms::Button());
			this->positionErrorLabel = (gcnew System::Windows::Forms::Label());
			this->accountNameErrorLabel = (gcnew System::Windows::Forms::Label());
			this->idErrorLabel = (gcnew System::Windows::Forms::Label());
			this->passwordErrorLabel = (gcnew System::Windows::Forms::Label());
			this->showHideButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// positionLabel
			// 
			this->positionLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->positionLabel->Location = System::Drawing::Point(67, 357);
			this->positionLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->positionLabel->Name = L"positionLabel";
			this->positionLabel->Size = System::Drawing::Size(333, 25);
			this->positionLabel->TabIndex = 10;
			this->positionLabel->Text = L"Position (Optional):";
			this->positionLabel->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// positionTextBox
			// 
			this->positionTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->positionTextBox->Location = System::Drawing::Point(67, 388);
			this->positionTextBox->Margin = System::Windows::Forms::Padding(4);
			this->positionTextBox->Name = L"positionTextBox";
			this->positionTextBox->Size = System::Drawing::Size(332, 26);
			this->positionTextBox->TabIndex = 4;
			this->positionTextBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &AddControl::positionTextBox_KeyPress);
			// 
			// accountNameTextBox
			// 
			this->accountNameTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->accountNameTextBox->Location = System::Drawing::Point(67, 92);
			this->accountNameTextBox->Margin = System::Windows::Forms::Padding(4);
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
			this->accountNameLabel->TabIndex = 7;
			this->accountNameLabel->Text = L"Account Name:";
			this->accountNameLabel->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// idTextBox
			// 
			this->idTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->idTextBox->Location = System::Drawing::Point(67, 191);
			this->idTextBox->Margin = System::Windows::Forms::Padding(4);
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
			this->idLabel->TabIndex = 8;
			this->idLabel->Text = L"ID:";
			this->idLabel->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// passwordTextBox
			// 
			this->passwordTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->passwordTextBox->Location = System::Drawing::Point(67, 289);
			this->passwordTextBox->Margin = System::Windows::Forms::Padding(4);
			this->passwordTextBox->Name = L"passwordTextBox";
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
			this->passwordLabel->TabIndex = 9;
			this->passwordLabel->Text = L"Password:";
			this->passwordLabel->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// addButton
			// 
			this->addButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->addButton->Location = System::Drawing::Point(67, 468);
			this->addButton->Margin = System::Windows::Forms::Padding(4);
			this->addButton->Name = L"addButton";
			this->addButton->Size = System::Drawing::Size(107, 31);
			this->addButton->TabIndex = 5;
			this->addButton->Text = L"Add";
			this->addButton->UseVisualStyleBackColor = true;
			this->addButton->Click += gcnew System::EventHandler(this, &AddControl::addButton_Click);
			// 
			// clearButton
			// 
			this->clearButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->clearButton->Location = System::Drawing::Point(293, 468);
			this->clearButton->Margin = System::Windows::Forms::Padding(4);
			this->clearButton->Name = L"clearButton";
			this->clearButton->Size = System::Drawing::Size(107, 31);
			this->clearButton->TabIndex = 6;
			this->clearButton->Text = L"Clear";
			this->clearButton->UseVisualStyleBackColor = true;
			this->clearButton->Click += gcnew System::EventHandler(this, &AddControl::clearButton_Click);
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
			this->positionErrorLabel->TabIndex = 14;
			this->positionErrorLabel->Text = L"Position error label.";
			this->positionErrorLabel->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->positionErrorLabel->Visible = false;
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
			this->accountNameErrorLabel->TabIndex = 11;
			this->accountNameErrorLabel->Text = L"Account name error label.";
			this->accountNameErrorLabel->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->accountNameErrorLabel->Visible = false;
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
			this->idErrorLabel->TabIndex = 12;
			this->idErrorLabel->Text = L"ID error label.";
			this->idErrorLabel->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->idErrorLabel->Visible = false;
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
			this->passwordErrorLabel->TabIndex = 13;
			this->passwordErrorLabel->Text = L"Password error label.";
			this->passwordErrorLabel->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->passwordErrorLabel->Visible = false;
			// 
			// showHideButton
			// 
			this->showHideButton->Location = System::Drawing::Point(400, 287);
			this->showHideButton->Margin = System::Windows::Forms::Padding(4);
			this->showHideButton->Name = L"showHideButton";
			this->showHideButton->Size = System::Drawing::Size(67, 31);
			this->showHideButton->TabIndex = 3;
			this->showHideButton->Text = L"Hide";
			this->showHideButton->UseVisualStyleBackColor = true;
			this->showHideButton->Click += gcnew System::EventHandler(this, &AddControl::showHideButton_Click);
			// 
			// AddControl
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->showHideButton);
			this->Controls->Add(this->passwordErrorLabel);
			this->Controls->Add(this->idErrorLabel);
			this->Controls->Add(this->accountNameErrorLabel);
			this->Controls->Add(this->positionErrorLabel);
			this->Controls->Add(this->clearButton);
			this->Controls->Add(this->addButton);
			this->Controls->Add(this->passwordTextBox);
			this->Controls->Add(this->passwordLabel);
			this->Controls->Add(this->idTextBox);
			this->Controls->Add(this->idLabel);
			this->Controls->Add(this->accountNameTextBox);
			this->Controls->Add(this->accountNameLabel);
			this->Controls->Add(this->positionTextBox);
			this->Controls->Add(this->positionLabel);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"AddControl";
			this->Size = System::Drawing::Size(907, 640);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void positionTextBox_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
	{
		// Accepting numbers only.
		e->Handled = !System::Char::IsDigit(e->KeyChar) && !System::Char::IsControl(e->KeyChar);
	}
	private: System::Void clearButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		this->positionTextBox->Text = "";
		this->accountNameTextBox->Text = "";
		this->idTextBox->Text = "";
		this->passwordTextBox->Text = "";
		this->hideErrorLabels();
	}
	private: System::Void showHideButton_Click(System::Object^ sender, System::EventArgs^ e)
	{
		static bool visible = true;
		if (visible) {
			this->passwordTextBox->PasswordChar = '*';
			this->showHideButton->Text = "Show";
			visible = false;
		}
		else {
			this->passwordTextBox->PasswordChar = 0;
			this->showHideButton->Text = "Hide";
			visible = true;
		}
	}

	private:
		bool error()
		{
			return (this->accountNameErrorLabel->Visible || this->idErrorLabel->Visible
					|| this->passwordErrorLabel->Visible || this->positionErrorLabel->Visible);
		}
		System::Void hideErrorLabels()
		{
			this->accountNameErrorLabel->Visible = false;
			this->idErrorLabel->Visible = false;
			this->passwordErrorLabel->Visible = false;
			this->positionErrorLabel->Visible = false;
		}

	private: System::Void addButton_Click(System::Object^ sender, System::EventArgs^ e);

};
}


