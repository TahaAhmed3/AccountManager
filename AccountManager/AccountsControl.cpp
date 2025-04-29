#include "AccountsControl.h"
#include "MainForm.h"
#include "EditControl.h"
#include "StringConversion.h"
#include <algorithm>
using namespace AccountManager;



System::Void AccountsControl::insertRow(uint32_t rowIndex, uint32_t recordIndex, std::string accountName, std::string id)
{
	DataGridViewRow^ newRow = gcnew DataGridViewRow();
	newRow->CreateCells(this->dataGridView);
	newRow->Height = rowHeight;
	newRow->HeaderCell->Value = Convert::ToString(rowIndex + 1);
	newRow->Cells[recordIndexColIndex]->Value = recordIndex;
	newRow->Cells[accountNameColumnIndex]->Value = gcnew String(accountName.c_str());
	newRow->Cells[idColumnIndex]->Value = gcnew String(id.c_str());

	newRow->Cells[copyColumnIndex]->Value = this->iconsImageList->Images[0];
	newRow->Cells[editColumnIndex]->Value = this->iconsImageList->Images[1];
	newRow->Cells[deleteColumnIndex]->Value = this->iconsImageList->Images[2];

	// RowCount = no of data rows + 1
	for (uint32_t i = rowIndex; i < this->dataGridView->RowCount - 1; i++) {
		this->dataGridView->Rows[i]->HeaderCell->Value = Convert::ToString(i + 2);
		this->dataGridView->Rows[i]->Cells[recordIndexColIndex]->Value = i + 1;
	}

	this->dataGridView->Rows->Insert(rowIndex, newRow);
}


System::Void AccountsControl::deleteRow(uint32_t rowIndex)
{
	for (uint32_t i = rowIndex + 1; i < this->dataGridView->RowCount - 1; i++) {
		this->dataGridView->Rows[i]->HeaderCell->Value = Convert::ToString(i);
		this->dataGridView->Rows[i]->Cells[recordIndexColIndex]->Value = i - 1;
	}

	this->dataGridView->Rows->RemoveAt(rowIndex);
}


System::Void AccountsControl::updateRow(uint32_t rowIndex, std::string accountName, std::string id)
{
	DataGridViewRow^ row = this->dataGridView->Rows[rowIndex];
	row->Cells[1]->Value = gcnew String(accountName.c_str());
	row->Cells[2]->Value = gcnew String(id.c_str());
}





System::Void AccountsControl::displayTable()
{
	this->dataGridView->Rows->Clear();
	this->dataGridView->RowHeadersWidth = rowHeaderWidth;
	for (uint8_t i = 0; i < this->dataGridView->ColumnCount; i++) {
		this->dataGridView->Columns[i]->DisplayIndex = i;
		this->dataGridView->Columns[i]->Width = columnWidths[i];
	}
	uint32_t noOfRecords = this->fileHandler->noOfRecords();
	this->fileHandler->moveFilePointer(0);
	for (uint32_t i = 0; i < noOfRecords; i++) {
		this->fileHandler->read(*this->account);
		this->insertRow(i, i, account->getAccountName(), account->getId());
	}

	this->dataGridView->ClearSelection();
	// This is to remove x images in the last empty row.
	this->dataGridView->Rows[this->dataGridView->RowCount - 1]->Cells[copyColumnIndex]->Value = gcnew Bitmap(1, 1);
	this->dataGridView->Rows[this->dataGridView->RowCount - 1]->Cells[editColumnIndex]->Value = gcnew Bitmap(1, 1);
	this->dataGridView->Rows[this->dataGridView->RowCount - 1]->Cells[deleteColumnIndex]->Value = gcnew Bitmap(1, 1);
}


System::Void AccountsControl::copyId(uint32_t rowIndex)
{
	uint32_t recordIndex = Convert::ToUInt32(this->dataGridView->Rows[rowIndex]->Cells[recordIndexColIndex]->Value);
	this->fileHandler->read(*this->account, recordIndex);
	String^ id = gcnew String(this->account->getId().c_str());
	if (id == "") {
		Clipboard::SetText("\0");
	}
	else {
		Clipboard::SetText(id);
	}
}


System::Void AccountsControl::copyPassword(uint32_t rowIndex)
{
	uint32_t recordIndex = Convert::ToUInt32(this->dataGridView->Rows[rowIndex]->Cells[recordIndexColIndex]->Value);
	this->fileHandler->read(*this->account, recordIndex);
	String^ password = gcnew String(this->account->getPassword().c_str());
	if (password == "") {
		Clipboard::SetText("\0");
	}
	else {
		Clipboard::SetText(password);
	}
}





System::Void AccountsControl::editAccount(uint32_t rowIndex)
{
	MainForm^ mainForm = (MainForm^)this->mainForm;
	mainForm->addUserControl(mainForm->getEditControl());

	uint32_t recordIndex = Convert::ToUInt32(this->dataGridView->Rows[rowIndex]->Cells[recordIndexColIndex]->Value);
	this->fileHandler->read(*this->account, recordIndex);
	(mainForm->getEditControl())->setTextBoxes(std::to_string(recordIndex + 1), this->account->getAccountName(),
												this->account->getId(), this->account->getPassword());
}


System::Void AccountsControl::deleteAccount(uint32_t rowIndex)
{
	uint32_t recordIndex = Convert::ToUInt32(this->dataGridView->Rows[rowIndex]->Cells[recordIndexColIndex]->Value);
	String^ accountName = this->dataGridView->Rows[rowIndex]->Cells[accountNameColumnIndex]->Value->ToString();
	DialogResult userResponse;
	userResponse = MessageBox::Show("Are you sure you want to delete account: " + accountName + "?", "Warning",
		MessageBoxButtons::YesNo, MessageBoxIcon::Warning);
	if (userResponse == DialogResult::Yes) {
		this->deleteRow(rowIndex);
		this->fileHandler->Delete(recordIndex);
	}
}





System::Void AccountsControl::searchTextBox_Enter(System::Object^ sender, System::EventArgs^ e)
{
	if (this->searchTextBox->Text == "Search") {
		this->searchTextBox->Text = "";
		this->searchTextBox->ForeColor = Color::Black;
	}
}


System::Void AccountsControl::searchTextBox_Leave(System::Object^ sender, System::EventArgs^ e)
{
	if (String::IsNullOrEmpty(this->searchTextBox->Text)) {
		this->searchTextBox->Text = "Search";
		this->searchTextBox->ForeColor = Color::DimGray;
	}
}


System::Void AccountsControl::searchTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	if (String::IsNullOrEmpty(this->searchTextBox->Text) || (this->searchTextBox->Text == "Search")) {
		this->reloadButton_Click(sender, e);
		return;
	}

	this->searched = true;
	this->dataGridView->Rows->Clear();
	std::string accountName = toStdString(this->searchTextBox->Text->ToLower());
	std::string currAccountName;

	uint32_t noOfRecords = this->fileHandler->noOfRecords();
	this->fileHandler->moveFilePointer(0);
	uint32_t rowIndex = 0;
	for (uint32_t i = 0; i < noOfRecords; i++) {
		this->fileHandler->read(*this->account);
		currAccountName = this->account->getAccountName();
		std::transform(currAccountName.begin(), currAccountName.end(), currAccountName.begin(), ::tolower);
		if (currAccountName.find(accountName) != std::string::npos) {
			this->insertRow(rowIndex, i, this->account->getAccountName(), this->account->getId());
			rowIndex++;
		}
	}

	this->dataGridView->ClearSelection();
	// This is to remove x images in the last empty row.
	this->dataGridView->Rows[this->dataGridView->RowCount - 1]->Cells[copyColumnIndex]->Value = gcnew Bitmap(1, 1);
	this->dataGridView->Rows[this->dataGridView->RowCount - 1]->Cells[editColumnIndex]->Value = gcnew Bitmap(1, 1);
	this->dataGridView->Rows[this->dataGridView->RowCount - 1]->Cells[deleteColumnIndex]->Value = gcnew Bitmap(1, 1);
}


System::Void AccountsControl::reloadButton_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->searched = false;
	this->displayTable();
}


System::Void AccountsControl::dataGridView_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
	if (e->RowIndex < 0 || e->RowIndex >= this->dataGridView->RowCount - 1) {
		return;
	}
	if (e->ColumnIndex == idColumnIndex) {
		this->copyId(e->RowIndex);
	}
	else if (e->ColumnIndex == copyColumnIndex) {
		this->copyPassword(e->RowIndex);
	}
	else if (e->ColumnIndex == editColumnIndex) {
		this->editAccount(e->RowIndex);
	}
	else if (e->ColumnIndex == deleteColumnIndex) {
		this->deleteAccount(e->RowIndex);
	}
}


System::Void AccountsControl::csvFileButton_Click(System::Object^ sender, System::EventArgs^ e) {
	char delimiter;
	if (this->delimiterComboBox->Text == "Comma") {
		delimiter = ',';
	}
	else if (this->delimiterComboBox->Text == "Semicolon") {
		delimiter = ';';
	}
	else if (this->delimiterComboBox->Text == "Pipe") {
		delimiter = '|';
	}
	else if (this->delimiterComboBox->Text == "Space") {
		delimiter = ' ';
	}
	else {
		delimiter = '\t';
	}
	try {
		this->fileHandler->createCsvFile(delimiter);
		MessageBox::Show("CSV file created.");
	}
	catch (std::exception e) {
		MessageBox::Show(gcnew String(e.what()));
	}
}


System::Void AccountsControl::textFileButton_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		this->fileHandler->createFixedWidthTextFile();
		MessageBox::Show("Text file created.");
	}
	catch (std::exception e) {
		MessageBox::Show(gcnew String(e.what()));
	}
}

