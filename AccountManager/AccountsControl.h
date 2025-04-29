#pragma once
#include <string>
#include "Account.h"
#include "AccountsFileHandler.h"



using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace AccountManager {

	/// <summary>
	/// Summary for AccountsControl
	/// </summary>
	public ref class AccountsControl : public System::Windows::Forms::UserControl
	{
	private:
		Account* account;
		AccountsFileHandler* fileHandler;
		Form^ mainForm;

		bool searched;

		static constexpr uint8_t recordIndexColIndex = 0;
		static constexpr uint8_t accountNameColumnIndex = 1;
		static constexpr uint8_t idColumnIndex = 2;
		static constexpr uint8_t copyColumnIndex = 3;
		static constexpr uint8_t editColumnIndex = 4;
		static constexpr uint8_t deleteColumnIndex = 5;

		static constexpr uint8_t rowHeight = 30;
		static constexpr uint8_t rowHeaderWidth = 50;
		static const cli::array<const uint8_t>^ columnWidths = gcnew cli::array<const uint8_t>(6) { 60, 125, 215, 70, 50, 50 };

	public:
		AccountsControl(Account* account, AccountsFileHandler* fileHandler, Form^ mainForm)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->account = account;
			this->fileHandler = fileHandler;
			this->mainForm = mainForm;

			this->searched = false;
			// Setting first item to be selected by default.
			this->delimiterComboBox->SelectedIndex = 0;
			this->displayTable();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AccountsControl()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ searchTextBox;
	private: System::Windows::Forms::Button^ csvFileButton;
	private: System::Windows::Forms::Label^ delimiterLabel;
	private: System::Windows::Forms::ComboBox^ delimiterComboBox;
	private: System::Windows::Forms::Button^ textFileButton;
	private: System::Windows::Forms::DataGridView^ dataGridView;

	private: System::Windows::Forms::Button^ reloadButton;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ recordIndexColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ accountNameColumn;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ idColumn;
	private: System::Windows::Forms::DataGridViewImageColumn^ copyColumn;
	private: System::Windows::Forms::DataGridViewImageColumn^ editColumn;
	private: System::Windows::Forms::DataGridViewImageColumn^ deleteColumn;

	private: System::Windows::Forms::ImageList^ iconsImageList;
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AccountsControl::typeid));
			this->searchTextBox = (gcnew System::Windows::Forms::TextBox());
			this->csvFileButton = (gcnew System::Windows::Forms::Button());
			this->delimiterComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->delimiterLabel = (gcnew System::Windows::Forms::Label());
			this->dataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->recordIndexColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->accountNameColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->idColumn = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->copyColumn = (gcnew System::Windows::Forms::DataGridViewImageColumn());
			this->editColumn = (gcnew System::Windows::Forms::DataGridViewImageColumn());
			this->deleteColumn = (gcnew System::Windows::Forms::DataGridViewImageColumn());
			this->reloadButton = (gcnew System::Windows::Forms::Button());
			this->iconsImageList = (gcnew System::Windows::Forms::ImageList(this->components));
			this->textFileButton = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->BeginInit();
			this->SuspendLayout();
			// 
			// searchTextBox
			// 
			this->searchTextBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->searchTextBox->ForeColor = System::Drawing::Color::DimGray;
			this->searchTextBox->Location = System::Drawing::Point(67, 62);
			this->searchTextBox->Margin = System::Windows::Forms::Padding(4);
			this->searchTextBox->Name = L"searchTextBox";
			this->searchTextBox->Size = System::Drawing::Size(332, 23);
			this->searchTextBox->TabIndex = 0;
			this->searchTextBox->Text = L"Search";
			this->searchTextBox->TextChanged += gcnew System::EventHandler(this, &AccountsControl::searchTextBox_TextChanged);
			this->searchTextBox->Enter += gcnew System::EventHandler(this, &AccountsControl::searchTextBox_Enter);
			this->searchTextBox->Leave += gcnew System::EventHandler(this, &AccountsControl::searchTextBox_Leave);
			// 
			// csvFileButton
			// 
			this->csvFileButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->csvFileButton->Location = System::Drawing::Point(267, 528);
			this->csvFileButton->Margin = System::Windows::Forms::Padding(4);
			this->csvFileButton->Name = L"csvFileButton";
			this->csvFileButton->Size = System::Drawing::Size(160, 28);
			this->csvFileButton->TabIndex = 4;
			this->csvFileButton->Text = L"Create CSV File";
			this->csvFileButton->UseVisualStyleBackColor = true;
			this->csvFileButton->Click += gcnew System::EventHandler(this, &AccountsControl::csvFileButton_Click);
			// 
			// delimiterComboBox
			// 
			this->delimiterComboBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->delimiterComboBox->FormattingEnabled = true;
			this->delimiterComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"Tab", L"Comma", L"Semicolon", L"Pipe",
					L"Space"
			});
			this->delimiterComboBox->Location = System::Drawing::Point(153, 529);
			this->delimiterComboBox->Margin = System::Windows::Forms::Padding(4);
			this->delimiterComboBox->Name = L"delimiterComboBox";
			this->delimiterComboBox->Size = System::Drawing::Size(99, 25);
			this->delimiterComboBox->TabIndex = 3;
			this->delimiterComboBox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &AccountsControl::delimiterComboBox_KeyPress);
			// 
			// delimiterLabel
			// 
			this->delimiterLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->delimiterLabel->Location = System::Drawing::Point(67, 529);
			this->delimiterLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->delimiterLabel->Name = L"delimiterLabel";
			this->delimiterLabel->Size = System::Drawing::Size(80, 26);
			this->delimiterLabel->TabIndex = 2;
			this->delimiterLabel->Text = L"Delimiter:";
			this->delimiterLabel->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// dataGridView
			// 
			this->dataGridView->AllowUserToOrderColumns = true;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->recordIndexColumn,
					this->accountNameColumn, this->idColumn, this->copyColumn, this->editColumn, this->deleteColumn
			});
			this->dataGridView->EditMode = System::Windows::Forms::DataGridViewEditMode::EditProgrammatically;
			this->dataGridView->Location = System::Drawing::Point(67, 123);
			this->dataGridView->Margin = System::Windows::Forms::Padding(4);
			this->dataGridView->Name = L"dataGridView";
			this->dataGridView->RowHeadersWidth = 50;
			this->dataGridView->Size = System::Drawing::Size(773, 370);
			this->dataGridView->TabIndex = 6;
			this->dataGridView->CellClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &AccountsControl::dataGridView_CellClick);
			this->dataGridView->CellMouseEnter += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &AccountsControl::dataGridView_CellMouseEnter);
			this->dataGridView->CellMouseLeave += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &AccountsControl::dataGridView_CellMouseLeave);
			// 
			// recordIndexColumn
			// 
			this->recordIndexColumn->HeaderText = L"Record Index";
			this->recordIndexColumn->MinimumWidth = 6;
			this->recordIndexColumn->Name = L"recordIndexColumn";
			this->recordIndexColumn->ReadOnly = true;
			this->recordIndexColumn->Visible = false;
			this->recordIndexColumn->Width = 60;
			// 
			// accountNameColumn
			// 
			this->accountNameColumn->HeaderText = L"Account Name";
			this->accountNameColumn->MinimumWidth = 6;
			this->accountNameColumn->Name = L"accountNameColumn";
			this->accountNameColumn->ReadOnly = true;
			this->accountNameColumn->Width = 115;
			// 
			// idColumn
			// 
			this->idColumn->HeaderText = L"ID";
			this->idColumn->MinimumWidth = 6;
			this->idColumn->Name = L"idColumn";
			this->idColumn->ReadOnly = true;
			this->idColumn->ToolTipText = L"Click on a cell to copy ID.";
			this->idColumn->Width = 225;
			// 
			// copyColumn
			// 
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle2->NullValue = L"System.Drawing.Bitmap";
			this->copyColumn->DefaultCellStyle = dataGridViewCellStyle2;
			this->copyColumn->HeaderText = L"Copy Password";
			this->copyColumn->MinimumWidth = 6;
			this->copyColumn->Name = L"copyColumn";
			this->copyColumn->ReadOnly = true;
			this->copyColumn->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->copyColumn->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Automatic;
			this->copyColumn->Width = 70;
			// 
			// editColumn
			// 
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle3->NullValue = L"System.Drawing.Bitmap";
			this->editColumn->DefaultCellStyle = dataGridViewCellStyle3;
			this->editColumn->HeaderText = L"Edit";
			this->editColumn->MinimumWidth = 6;
			this->editColumn->Name = L"editColumn";
			this->editColumn->ReadOnly = true;
			this->editColumn->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->editColumn->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Automatic;
			this->editColumn->Width = 50;
			// 
			// deleteColumn
			// 
			this->deleteColumn->HeaderText = L"Delete";
			this->deleteColumn->MinimumWidth = 6;
			this->deleteColumn->Name = L"deleteColumn";
			this->deleteColumn->ReadOnly = true;
			this->deleteColumn->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->deleteColumn->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Automatic;
			this->deleteColumn->Width = 50;
			// 
			// reloadButton
			// 
			this->reloadButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->reloadButton->Location = System::Drawing::Point(747, 60);
			this->reloadButton->Margin = System::Windows::Forms::Padding(4);
			this->reloadButton->Name = L"reloadButton";
			this->reloadButton->Size = System::Drawing::Size(93, 28);
			this->reloadButton->TabIndex = 1;
			this->reloadButton->Text = L"Reload";
			this->reloadButton->UseVisualStyleBackColor = true;
			this->reloadButton->Click += gcnew System::EventHandler(this, &AccountsControl::reloadButton_Click);
			// 
			// iconsImageList
			// 
			this->iconsImageList->ImageStream = (cli::safe_cast<System::Windows::Forms::ImageListStreamer^>(resources->GetObject(L"iconsImageList.ImageStream")));
			this->iconsImageList->TransparentColor = System::Drawing::Color::Transparent;
			this->iconsImageList->Images->SetKeyName(0, L"copy.png");
			this->iconsImageList->Images->SetKeyName(1, L"edit.png");
			this->iconsImageList->Images->SetKeyName(2, L"delete.png");
			// 
			// textFileButton
			// 
			this->textFileButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textFileButton->Location = System::Drawing::Point(680, 528);
			this->textFileButton->Margin = System::Windows::Forms::Padding(4);
			this->textFileButton->Name = L"textFileButton";
			this->textFileButton->Size = System::Drawing::Size(160, 28);
			this->textFileButton->TabIndex = 5;
			this->textFileButton->Text = L"Create Text File";
			this->textFileButton->UseVisualStyleBackColor = true;
			this->textFileButton->Click += gcnew System::EventHandler(this, &AccountsControl::textFileButton_Click);
			// 
			// AccountsControl
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->textFileButton);
			this->Controls->Add(this->reloadButton);
			this->Controls->Add(this->dataGridView);
			this->Controls->Add(this->delimiterLabel);
			this->Controls->Add(this->delimiterComboBox);
			this->Controls->Add(this->csvFileButton);
			this->Controls->Add(this->searchTextBox);
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"AccountsControl";
			this->Size = System::Drawing::Size(907, 640);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		
		private: System::Void delimiterComboBox_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e)
		{
			// Preventing from typing in the combo box.
			e->Handled = true;
		}
		private: System::Void dataGridView_CellMouseEnter(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
		{
			if (e->RowIndex < 0 || e->RowIndex >= this->dataGridView->RowCount - 1) {
				return;
			}
			if (e->ColumnIndex >= idColumnIndex) {
				this->dataGridView->Rows[e->RowIndex]->Cells[e->ColumnIndex]->Style->BackColor = Color::CadetBlue;
			}
		}
		private: System::Void dataGridView_CellMouseLeave(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
		{
			if (e->RowIndex < 0 || e->RowIndex >= this->dataGridView->RowCount - 1) {
				return;
			}
			if (e->ColumnIndex >= idColumnIndex) {
				this->dataGridView->Rows[e->RowIndex]->Cells[e->ColumnIndex]->Style->BackColor = Color::White;
			}
		}

		public:
			bool Searched()
			{
				return this->searched;
			}
			System::Void insertRow(uint32_t rowIndex, uint32_t recordIndex, std::string accountName, std::string id);
			System::Void deleteRow(uint32_t rowIndex);
			System::Void updateRow(uint32_t rowIndex, std::string accountName, std::string id);

		private:
			System::Void displayTable();
			System::Void copyId(uint32_t rowIndex);
			System::Void copyPassword(uint32_t rowIndex);
			System::Void editAccount(uint32_t rowIndex);
			System::Void deleteAccount(uint32_t rowIndex);

		private: System::Void searchTextBox_Enter(System::Object^ sender, System::EventArgs^ e);
		private: System::Void searchTextBox_Leave(System::Object^ sender, System::EventArgs^ e);
		private: System::Void searchTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e);
		private: System::Void dataGridView_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e);
		private: System::Void reloadButton_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void csvFileButton_Click(System::Object^ sender, System::EventArgs^ e);
		private: System::Void textFileButton_Click(System::Object^ sender, System::EventArgs^ e);
};
}


