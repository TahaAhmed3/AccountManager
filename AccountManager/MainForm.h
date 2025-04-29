#pragma once
#include "AccountsControl.h"
#include "AddControl.h"
#include "EditControl.h"
#include "Account.h"
#include "AccountsFileHandler.h"



static const char* lockDriveBatchFilePath = "LockDrive.bat";

static void ClearClipboard()
{
	// It does not clear the clipboard history.
	// Clipboard::Clear();
	
	system("powershell Restart-Service -Name \"cbdhsvc*\" -force");
}



namespace AccountManager {
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	private:
		AccountsControl^ accountsControl;
		AddControl^ addControl;
		EditControl^ editControl;
	
		Account* account;
		AccountsFileHandler* fileHandler;

	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->account = new Account();
			this->fileHandler = new AccountsFileHandler("accounts.dat");

			this->accountsControl = gcnew AccountsControl(this->account, this->fileHandler, this);
			this->addControl = gcnew AddControl(this->account, this->fileHandler, this);
			this->editControl = gcnew EditControl(this->account, this->fileHandler, this);

			this->accountsControl->Dock = DockStyle::Fill;
			this->addControl->Dock = DockStyle::Fill;
			this->editControl->Dock = DockStyle::Fill;
			
			this->addUserControl(accountsControl);
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
			delete fileHandler;
			delete account;
			ClearClipboard();
		}
	private: System::Windows::Forms::Panel^ buttonsPanel;
	private: System::Windows::Forms::Button^ accountsButton;
	private: System::Windows::Forms::Panel^ userControlsPanel;

	private: System::Windows::Forms::Button^ editButton;
	private: System::Windows::Forms::Button^ addButton;
	private: System::Windows::Forms::Button^ lockDriveAndExitButton;

	private: System::Windows::Forms::Label^ activeButtonLabel;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->buttonsPanel = (gcnew System::Windows::Forms::Panel());
			this->activeButtonLabel = (gcnew System::Windows::Forms::Label());
			this->lockDriveAndExitButton = (gcnew System::Windows::Forms::Button());
			this->editButton = (gcnew System::Windows::Forms::Button());
			this->addButton = (gcnew System::Windows::Forms::Button());
			this->accountsButton = (gcnew System::Windows::Forms::Button());
			this->userControlsPanel = (gcnew System::Windows::Forms::Panel());
			this->buttonsPanel->SuspendLayout();
			this->SuspendLayout();
			// 
			// buttonsPanel
			// 
			this->buttonsPanel->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->buttonsPanel->Controls->Add(this->activeButtonLabel);
			this->buttonsPanel->Controls->Add(this->lockDriveAndExitButton);
			this->buttonsPanel->Controls->Add(this->editButton);
			this->buttonsPanel->Controls->Add(this->addButton);
			this->buttonsPanel->Controls->Add(this->accountsButton);
			this->buttonsPanel->Dock = System::Windows::Forms::DockStyle::Top;
			this->buttonsPanel->Location = System::Drawing::Point(0, 0);
			this->buttonsPanel->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->buttonsPanel->Name = L"buttonsPanel";
			this->buttonsPanel->Size = System::Drawing::Size(912, 49);
			this->buttonsPanel->TabIndex = 0;
			// 
			// activeButtonLabel
			// 
			this->activeButtonLabel->BackColor = System::Drawing::Color::OrangeRed;
			this->activeButtonLabel->Location = System::Drawing::Point(0, 46);
			this->activeButtonLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->activeButtonLabel->Name = L"activeButtonLabel";
			this->activeButtonLabel->Size = System::Drawing::Size(133, 4);
			this->activeButtonLabel->TabIndex = 0;
			// 
			// lockDriveAndExitButton
			// 
			this->lockDriveAndExitButton->BackColor = System::Drawing::Color::Tomato;
			this->lockDriveAndExitButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->lockDriveAndExitButton->Location = System::Drawing::Point(819, 0);
			this->lockDriveAndExitButton->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->lockDriveAndExitButton->Name = L"lockDriveAndExitButton";
			this->lockDriveAndExitButton->Size = System::Drawing::Size(93, 49);
			this->lockDriveAndExitButton->TabIndex = 3;
			this->lockDriveAndExitButton->Text = L"Lock Drive and Exit";
			this->lockDriveAndExitButton->UseVisualStyleBackColor = false;
			this->lockDriveAndExitButton->Click += gcnew System::EventHandler(this, &MainForm::lockDriveAndExitButton_Click);
			// 
			// editButton
			// 
			this->editButton->Enabled = false;
			this->editButton->FlatAppearance->BorderColor = System::Drawing::Color::Blue;
			this->editButton->FlatAppearance->BorderSize = 0;
			this->editButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->editButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->editButton->Location = System::Drawing::Point(267, 0);
			this->editButton->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->editButton->Name = L"editButton";
			this->editButton->Size = System::Drawing::Size(133, 49);
			this->editButton->TabIndex = 2;
			this->editButton->Text = L"Edit";
			this->editButton->UseVisualStyleBackColor = true;
			// 
			// addButton
			// 
			this->addButton->FlatAppearance->BorderColor = System::Drawing::Color::Blue;
			this->addButton->FlatAppearance->BorderSize = 0;
			this->addButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->addButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->addButton->Location = System::Drawing::Point(133, 0);
			this->addButton->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->addButton->Name = L"addButton";
			this->addButton->Size = System::Drawing::Size(133, 49);
			this->addButton->TabIndex = 1;
			this->addButton->Text = L"Add";
			this->addButton->UseVisualStyleBackColor = true;
			this->addButton->Click += gcnew System::EventHandler(this, &MainForm::addButton_Click);
			// 
			// accountsButton
			// 
			this->accountsButton->FlatAppearance->BorderColor = System::Drawing::Color::Blue;
			this->accountsButton->FlatAppearance->BorderSize = 0;
			this->accountsButton->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->accountsButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->accountsButton->Location = System::Drawing::Point(0, 0);
			this->accountsButton->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->accountsButton->Name = L"accountsButton";
			this->accountsButton->Size = System::Drawing::Size(133, 49);
			this->accountsButton->TabIndex = 0;
			this->accountsButton->Text = L"Accounts";
			this->accountsButton->UseVisualStyleBackColor = true;
			this->accountsButton->Click += gcnew System::EventHandler(this, &MainForm::accountsButton_Click);
			// 
			// userControlsPanel
			// 
			this->userControlsPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->userControlsPanel->Location = System::Drawing::Point(0, 49);
			this->userControlsPanel->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->userControlsPanel->Name = L"userControlsPanel";
			this->userControlsPanel->Size = System::Drawing::Size(912, 641);
			this->userControlsPanel->TabIndex = 1;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(912, 690);
			this->Controls->Add(this->userControlsPanel);
			this->Controls->Add(this->buttonsPanel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->MaximizeBox = false;
			this->Name = L"MainForm";
			this->Text = L"Account Manager";
			this->buttonsPanel->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void accountsButton_Click(System::Object^ sender, System::EventArgs^ e) {
		addUserControl(this->accountsControl);
	}
	private: System::Void addButton_Click(System::Object^ sender, System::EventArgs^ e) {
		addUserControl(this->addControl);
	}

	public:
		System::Void addUserControl(UserControl^ userControl)
		{
			this->userControlsPanel->Controls->Clear();
			this->userControlsPanel->Controls->Add(userControl);
			this->editButton->Visible = false;
			if (userControl->Name == "AccountsControl") {
				this->activeButtonLabel->Location = Point(0, 37);
			}
			else if (userControl->Name == "AddControl") {
				this->activeButtonLabel->Location = Point(100, 37);
			}
			else if (userControl->Name == "EditControl") {
				this->activeButtonLabel->Location = Point(200, 37);
				this->editButton->Visible = true;
				this->editControl->hideErrorLabels();
				this->editControl->hidePassword();
			}
		}

		AccountsControl^ getAccountsControl()
		{
			return this->accountsControl;
		}

		AddControl^ getAddControl()
		{
			return this->addControl;
		}

		EditControl^ getEditControl()
		{
			return this->editControl;
		}
		
		private: System::Void lockDriveAndExitButton_Click(System::Object^ sender, System::EventArgs^ e) {
			AccountManager::MainForm::~MainForm();
			system(lockDriveBatchFilePath);
			Application::Exit();
		}
};
}


