#include "EditControl.h"
#include <stdexcept>
#include <vector>
#include "MainForm.h"
#include "StringConversion.h"
using namespace AccountManager;



System::Void EditControl::saveButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	uint32_t position;
	std::string accountName, id, password;
	bool empty = false;
	DialogResult userResponse;

	this->hideErrorLabels();
	if (this->accountNameTextBox->Text == "") {
		empty = true;
	}
	if (this->idTextBox->Text == "") {
		empty = true;
	}
	if (this->passwordTextBox->Text == "") {
		empty = true;
	}

	accountName = toStdString(accountNameTextBox->Text);
	id = toStdString(idTextBox->Text);
	password = toStdString(passwordTextBox->Text);

	try {
		this->account->setAccountName(accountName);
	}
	catch (std::length_error e) {
		this->accountNameErrorLabel->Text = gcnew String(e.what());
		this->accountNameErrorLabel->Visible = true;
	}
	try {
		this->account->setId(id);
	}
	catch (std::length_error e) {
		this->idErrorLabel->Text = gcnew String(e.what());
		this->idErrorLabel->Visible = true;
	}
	try {
		this->account->setPassword(password);
	}
	catch (std::length_error e) {
		this->passwordErrorLabel->Text = gcnew String(e.what());
		this->passwordErrorLabel->Visible = true;
	}
	if (System::Text::RegularExpressions::Regex::IsMatch(this->positionTextBox->Text, "[^0-9]")) {
		this->positionErrorLabel->Text = "Position should contain digits only.";
		this->positionErrorLabel->Visible = true;
	}
	else if (this->positionTextBox->Text == "") {
		position = this->prevPosition;
	}
	else {
		position = Convert::ToUInt32(this->positionTextBox->Text);
		if (position < 1 || position > this->fileHandler->noOfRecords()) {
			this->positionErrorLabel->Text = "Position should be between 1 and " + Convert::ToString(this->fileHandler->noOfRecords()) + ".";
			this->positionErrorLabel->Visible = true;
		}
	}

	if (this->error()) {
		return;
	}
	if (empty) {
		userResponse = MessageBox::Show("There is an empty field.\nDo you want to continue?", "Warning",
			MessageBoxButtons::YesNo, MessageBoxIcon::Warning);
		if (userResponse == DialogResult::No) {
			return;
		}
	}
	
	// Searching for accounts other than the account being edited with same password.
	std::string accountNames = "";
	Account tempAcc;
	uint32_t noOfRecords = this->fileHandler->noOfRecords();
	this->fileHandler->moveFilePointer(0);
	for (uint32_t i = 0; i < noOfRecords; i++) {
		this->fileHandler->read(tempAcc);
		if (tempAcc.getAccountName() != *this->prevAccountName && tempAcc.getPassword() == password) {
			accountNames += tempAcc.getAccountName() + ", ";
		}
	}

	if (!accountNames.empty()) {
		// Removing last two characters ", ".
		accountNames.erase(accountNames.size() - 2, 2);
		userResponse = MessageBox::Show(gcnew String((accountNames + " also have the same password.\nDo you want to continue?").c_str()), "Warning",
										MessageBoxButtons::YesNo, MessageBoxIcon::Warning);
		if (userResponse == DialogResult::No) {
			return;
		}
	}

	MainForm^ mainForm = (MainForm^)this->mainForm;
	if (position == this->prevPosition) {
		this->fileHandler->write(*this->account, position - 1);
		if (!mainForm->getAccountsControl()->Searched()) {
			mainForm->getAccountsControl()->updateRow(position - 1, accountName, id);
		}
	}
	else {
		this->fileHandler->Delete(this->prevPosition - 1);
		this->fileHandler->insert(*this->account, position - 1);
		if (!mainForm->getAccountsControl()->Searched()) {
			mainForm->getAccountsControl()->deleteRow(this->prevPosition - 1);
			mainForm->getAccountsControl()->insertRow(position - 1, position - 1, accountName, id);
		}
	}
	mainForm->addUserControl(mainForm->getAccountsControl());
}


