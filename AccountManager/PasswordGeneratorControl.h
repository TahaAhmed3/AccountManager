#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace AccountManager {

	/// <summary>
	/// Summary for PasswordGeneratorControl
	/// </summary>
	public ref class PasswordGeneratorControl : public System::Windows::Forms::UserControl
	{
	private:
		TextBox^ passwordTextBox;

	public:
		PasswordGeneratorControl(TextBox^ passwordTextBox)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->passwordTextBox = passwordTextBox;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~PasswordGeneratorControl()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ randPassGenLabel;
	private: System::Windows::Forms::TabControl^ optionsTabControl;
	private: System::Windows::Forms::TabPage^ option1TabPage;
	private: System::Windows::Forms::NumericUpDown^ passwordLengthNumericUpDown;
	private: System::Windows::Forms::CheckBox^ equalCharTypeDistribution;
	private: System::Windows::Forms::Label^ passwordLengthLabel;
	private: System::Windows::Forms::TabPage^ option2TabPage;
	private: System::Windows::Forms::NumericUpDown^ specialCharsNumericUpDown;
	private: System::Windows::Forms::NumericUpDown^ numericCharsNumericUpDown;
	private: System::Windows::Forms::NumericUpDown^ alphabeticCharsNumericUpDown;
	private: System::Windows::Forms::Label^ specialCharsLabel;
	private: System::Windows::Forms::Label^ numericCharsLabel;
	private: System::Windows::Forms::Label^ alphabeticCharsLabel;

	private: System::Windows::Forms::Button^ generateButton;

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
			this->randPassGenLabel = (gcnew System::Windows::Forms::Label());
			this->optionsTabControl = (gcnew System::Windows::Forms::TabControl());
			this->option1TabPage = (gcnew System::Windows::Forms::TabPage());
			this->passwordLengthNumericUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->equalCharTypeDistribution = (gcnew System::Windows::Forms::CheckBox());
			this->passwordLengthLabel = (gcnew System::Windows::Forms::Label());
			this->option2TabPage = (gcnew System::Windows::Forms::TabPage());
			this->specialCharsNumericUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericCharsNumericUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->alphabeticCharsNumericUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->specialCharsLabel = (gcnew System::Windows::Forms::Label());
			this->numericCharsLabel = (gcnew System::Windows::Forms::Label());
			this->alphabeticCharsLabel = (gcnew System::Windows::Forms::Label());
			this->generateButton = (gcnew System::Windows::Forms::Button());
			this->optionsTabControl->SuspendLayout();
			this->option1TabPage->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->passwordLengthNumericUpDown))->BeginInit();
			this->option2TabPage->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->specialCharsNumericUpDown))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericCharsNumericUpDown))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->alphabeticCharsNumericUpDown))->BeginInit();
			this->SuspendLayout();
			// 
			// randPassGenLabel
			// 
			this->randPassGenLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->randPassGenLabel->Location = System::Drawing::Point(10, 10);
			this->randPassGenLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->randPassGenLabel->Name = L"randPassGenLabel";
			this->randPassGenLabel->Size = System::Drawing::Size(267, 25);
			this->randPassGenLabel->TabIndex = 0;
			this->randPassGenLabel->Text = L"Random Password Generator";
			// 
			// optionsTabControl
			// 
			this->optionsTabControl->Controls->Add(this->option1TabPage);
			this->optionsTabControl->Controls->Add(this->option2TabPage);
			this->optionsTabControl->Location = System::Drawing::Point(10, 45);
			this->optionsTabControl->Margin = System::Windows::Forms::Padding(4);
			this->optionsTabControl->Name = L"optionsTabControl";
			this->optionsTabControl->SelectedIndex = 0;
			this->optionsTabControl->Size = System::Drawing::Size(400, 185);
			this->optionsTabControl->TabIndex = 1;
			// 
			// option1TabPage
			// 
			this->option1TabPage->Controls->Add(this->passwordLengthNumericUpDown);
			this->option1TabPage->Controls->Add(this->equalCharTypeDistribution);
			this->option1TabPage->Controls->Add(this->passwordLengthLabel);
			this->option1TabPage->Location = System::Drawing::Point(4, 25);
			this->option1TabPage->Margin = System::Windows::Forms::Padding(4);
			this->option1TabPage->Name = L"option1TabPage";
			this->option1TabPage->Padding = System::Windows::Forms::Padding(4);
			this->option1TabPage->Size = System::Drawing::Size(392, 156);
			this->option1TabPage->TabIndex = 0;
			this->option1TabPage->Text = L"Option1";
			this->option1TabPage->UseVisualStyleBackColor = true;
			// 
			// passwordLengthNumericUpDown
			// 
			this->passwordLengthNumericUpDown->Location = System::Drawing::Point(153, 25);
			this->passwordLengthNumericUpDown->Margin = System::Windows::Forms::Padding(4);
			this->passwordLengthNumericUpDown->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, 0 });
			this->passwordLengthNumericUpDown->Name = L"passwordLengthNumericUpDown";
			this->passwordLengthNumericUpDown->Size = System::Drawing::Size(93, 22);
			this->passwordLengthNumericUpDown->TabIndex = 0;
			// 
			// equalCharTypeDistribution
			// 
			this->equalCharTypeDistribution->Location = System::Drawing::Point(13, 86);
			this->equalCharTypeDistribution->Margin = System::Windows::Forms::Padding(4);
			this->equalCharTypeDistribution->Name = L"equalCharTypeDistribution";
			this->equalCharTypeDistribution->Size = System::Drawing::Size(247, 25);
			this->equalCharTypeDistribution->TabIndex = 1;
			this->equalCharTypeDistribution->Text = L"Equal Character Type Distribution";
			this->equalCharTypeDistribution->UseVisualStyleBackColor = true;
			// 
			// passwordLengthLabel
			// 
			this->passwordLengthLabel->Location = System::Drawing::Point(13, 25);
			this->passwordLengthLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->passwordLengthLabel->Name = L"passwordLengthLabel";
			this->passwordLengthLabel->Size = System::Drawing::Size(133, 25);
			this->passwordLengthLabel->TabIndex = 2;
			this->passwordLengthLabel->Text = L"Password Length:";
			this->passwordLengthLabel->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// option2TabPage
			// 
			this->option2TabPage->Controls->Add(this->specialCharsNumericUpDown);
			this->option2TabPage->Controls->Add(this->numericCharsNumericUpDown);
			this->option2TabPage->Controls->Add(this->alphabeticCharsNumericUpDown);
			this->option2TabPage->Controls->Add(this->specialCharsLabel);
			this->option2TabPage->Controls->Add(this->numericCharsLabel);
			this->option2TabPage->Controls->Add(this->alphabeticCharsLabel);
			this->option2TabPage->Location = System::Drawing::Point(4, 25);
			this->option2TabPage->Margin = System::Windows::Forms::Padding(4);
			this->option2TabPage->Name = L"option2TabPage";
			this->option2TabPage->Padding = System::Windows::Forms::Padding(4);
			this->option2TabPage->Size = System::Drawing::Size(392, 156);
			this->option2TabPage->TabIndex = 1;
			this->option2TabPage->Text = L"Option 2";
			this->option2TabPage->UseVisualStyleBackColor = true;
			// 
			// specialCharsNumericUpDown
			// 
			this->specialCharsNumericUpDown->Location = System::Drawing::Point(140, 105);
			this->specialCharsNumericUpDown->Margin = System::Windows::Forms::Padding(4);
			this->specialCharsNumericUpDown->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, 0 });
			this->specialCharsNumericUpDown->Name = L"specialCharsNumericUpDown";
			this->specialCharsNumericUpDown->Size = System::Drawing::Size(93, 22);
			this->specialCharsNumericUpDown->TabIndex = 2;
			// 
			// numericCharsNumericUpDown
			// 
			this->numericCharsNumericUpDown->Location = System::Drawing::Point(140, 62);
			this->numericCharsNumericUpDown->Margin = System::Windows::Forms::Padding(4);
			this->numericCharsNumericUpDown->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, 0 });
			this->numericCharsNumericUpDown->Name = L"numericCharsNumericUpDown";
			this->numericCharsNumericUpDown->Size = System::Drawing::Size(93, 22);
			this->numericCharsNumericUpDown->TabIndex = 1;
			// 
			// alphabeticCharsNumericUpDown
			// 
			this->alphabeticCharsNumericUpDown->Location = System::Drawing::Point(140, 18);
			this->alphabeticCharsNumericUpDown->Margin = System::Windows::Forms::Padding(4);
			this->alphabeticCharsNumericUpDown->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 50, 0, 0, 0 });
			this->alphabeticCharsNumericUpDown->Name = L"alphabeticCharsNumericUpDown";
			this->alphabeticCharsNumericUpDown->Size = System::Drawing::Size(93, 22);
			this->alphabeticCharsNumericUpDown->TabIndex = 0;
			// 
			// specialCharsLabel
			// 
			this->specialCharsLabel->Location = System::Drawing::Point(13, 105);
			this->specialCharsLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->specialCharsLabel->Name = L"specialCharsLabel";
			this->specialCharsLabel->Size = System::Drawing::Size(120, 25);
			this->specialCharsLabel->TabIndex = 5;
			this->specialCharsLabel->Text = L"Special Chars:";
			this->specialCharsLabel->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// numericCharsLabel
			// 
			this->numericCharsLabel->Location = System::Drawing::Point(13, 62);
			this->numericCharsLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->numericCharsLabel->Name = L"numericCharsLabel";
			this->numericCharsLabel->Size = System::Drawing::Size(120, 25);
			this->numericCharsLabel->TabIndex = 4;
			this->numericCharsLabel->Text = L"Numeric Chars:";
			this->numericCharsLabel->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// alphabeticCharsLabel
			// 
			this->alphabeticCharsLabel->Location = System::Drawing::Point(13, 18);
			this->alphabeticCharsLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->alphabeticCharsLabel->Name = L"alphabeticCharsLabel";
			this->alphabeticCharsLabel->Size = System::Drawing::Size(120, 25);
			this->alphabeticCharsLabel->TabIndex = 3;
			this->alphabeticCharsLabel->Text = L"Alphabetic Chars:";
			this->alphabeticCharsLabel->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// generateButton
			// 
			this->generateButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->generateButton->Location = System::Drawing::Point(10, 245);
			this->generateButton->Margin = System::Windows::Forms::Padding(4);
			this->generateButton->Name = L"generateButton";
			this->generateButton->Size = System::Drawing::Size(133, 31);
			this->generateButton->TabIndex = 3;
			this->generateButton->Text = L"Generate";
			this->generateButton->UseVisualStyleBackColor = true;
			this->generateButton->Click += gcnew System::EventHandler(this, &PasswordGeneratorControl::generateButton_Click);
			// 
			// PasswordGeneratorControl
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->randPassGenLabel);
			this->Controls->Add(this->optionsTabControl);
			this->Controls->Add(this->generateButton);
			this->Name = L"PasswordGeneratorControl";
			this->Size = System::Drawing::Size(420, 286);
			this->optionsTabControl->ResumeLayout(false);
			this->option1TabPage->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->passwordLengthNumericUpDown))->EndInit();
			this->option2TabPage->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->specialCharsNumericUpDown))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericCharsNumericUpDown))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->alphabeticCharsNumericUpDown))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void generateButton_Click(System::Object^ sender, System::EventArgs^ e);


};
}
