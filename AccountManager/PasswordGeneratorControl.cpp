#include "PasswordGeneratorControl.h"
#include <stdexcept>
#include "Account.h"
using namespace AccountManager;


System::Void PasswordGeneratorControl::generateButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	std::string randomPassword;
	if (this->optionsTabControl->SelectedTab == this->option1TabPage) {
		uint8_t passwordLength = Convert::ToUInt16(this->passwordLengthNumericUpDown->Value);
		randomPassword = Account::generateRandomPassword(passwordLength, this->equalCharTypeDistribution->Checked);
	}
	else {
		uint8_t alphabeticChars, numericChars, specialChars;
		alphabeticChars = Convert::ToUInt16(this->alphabeticCharsNumericUpDown->Value);
		numericChars = Convert::ToUInt16(this->numericCharsNumericUpDown->Value);
		specialChars = Convert::ToUInt16(this->specialCharsNumericUpDown->Value);
		randomPassword = Account::generateRandomPassword(alphabeticChars, numericChars, specialChars);
	}
	this->passwordTextBox->Text = gcnew String(randomPassword.c_str());
}
