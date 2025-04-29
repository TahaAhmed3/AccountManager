#include "AccountsFileHandler.h"
#include <stdexcept>
#include <filesystem> // Requires msvc compiler and C++17.
#include <string.h>



const std::array<std::string, 3> AccountsFileHandler::attributes = { "Account Name", "ID", "Password" };

AccountsFileHandler::AccountsFileHandler(std::string filename)
{
    this->filename = filename;
    if (!this->fileExists()) {
        this->createFile();
    }
    this->file.open(filename, std::ios::in | std::ios::out | std::ios::binary);
    if (!this->file.is_open()) {
        throw std::runtime_error("Error in opening file: " + filename);
    }
}


AccountsFileHandler::~AccountsFileHandler()
{
    this->file.close();
}


uint32_t AccountsFileHandler::byteIndex(uint32_t recordIndex)
{
    return recordIndex * recordLength;
}


bool AccountsFileHandler::fileExists()
{
    bool exists;
    this->file.open(this->filename, std::ios::in);
    exists = this->file.is_open();
    this->file.close();
    return exists;
}


void AccountsFileHandler::createFile()
{
    this->file.open(this->filename, std::ios::out);
    if (!this->file.is_open()) {
        throw std::runtime_error("Error in creating file: " + this->filename);
    }
    this->file.close();
}


uint32_t AccountsFileHandler::fileSize()
{
    uint32_t currentIndex, fileSize;
    currentIndex = this->file.tellg();
    this->file.seekg(0, std::ios::end);
    fileSize = this->file.tellg();
    this->file.seekg(currentIndex);
    return fileSize;
}


uint32_t AccountsFileHandler::noOfRecords()
{
    return fileSize() / recordLength;
}



void AccountsFileHandler::moveFilePointer(uint32_t recordIndex)
{
    uint32_t byteIndex = this->byteIndex(recordIndex);
    if (byteIndex > this->fileSize()) {
        throw std::out_of_range("Invalid index.");
    }
    this->file.seekg(byteIndex);
}


uint32_t AccountsFileHandler::currentRecordIndex()
{
    return this->file.tellg() / recordLength;
}


void AccountsFileHandler::write(const Account& account)
{
    // If length is less then max length then null character gets stored.
    // Otherwise null character is not stored.
    this->file.write(account.accountName, Account::maxAccountNameLength);
    this->file.write(account.id, Account::maxIdLength);
    this->file.write(account.password, Account::maxPasswordLength);
}


void AccountsFileHandler::write(const Account& account, uint32_t recordIndex)
{
    uint32_t byteIndex = this->byteIndex(recordIndex);
    if (byteIndex > this->fileSize()) {
        throw std::out_of_range("Invalid index.");
    }
    this->file.seekp(byteIndex);
    this->write(account);
}


void AccountsFileHandler::read(Account& account)
{
    if (this->file.tellg() >= this->fileSize()) {
        throw std::runtime_error("Cannot read beyond end of file.");
    }
    this->file.read(account.accountName, Account::maxAccountNameLength);
    this->file.read(account.id, Account::maxIdLength);
    this->file.read(account.password, Account::maxPasswordLength);

    // The following will have effect if max length was utilized.
    account.accountName[Account::maxAccountNameLength] = '\0';
    account.id[Account::maxIdLength] = '\0';
    account.password[Account::maxPasswordLength] = '\0';
}


void AccountsFileHandler::read(Account& account, uint32_t recordIndex)
{
    uint32_t byteIndex = this->byteIndex(recordIndex);
    if (byteIndex >= this->fileSize()) {
        throw std::out_of_range("Invalid index.");
    }
    this->file.seekg(byteIndex);
    this->read(account);
}


void AccountsFileHandler::insert(const Account& account, uint32_t recordIndex)
{
    Account tempAcc;
    uint32_t byteIndex = this->byteIndex(recordIndex);
    if (byteIndex > this->fileSize()) {
        throw std::out_of_range("Invalid index.");
    }
    this->file.seekp(0, std::ios::end);

    while (file.tellp() != byteIndex) {
        this->file.seekp(-recordLength, std::ios::cur);
        this->read(tempAcc);
        this->file.seekp(file.tellp()); // ??? msvc requires this.
        this->write(tempAcc);
        this->file.seekp(-2 * recordLength, std::ios::cur);
    }
    this->write(account);
}



void AccountsFileHandler::Delete(uint32_t recordIndex)
{
    Account tempAcc;
    // newFileSize is also the index of the first byte of last record.
    int64_t newFileSize = this->fileSize() - recordLength;
    uint32_t byteIndex = this->byteIndex(recordIndex);
    if (byteIndex >= this->fileSize()) {
        throw std::out_of_range("Invalid index.");
    }
    this->file.seekg(byteIndex);

    while (this->file.tellg() != newFileSize) {
        this->file.seekg(recordLength, std::ios::cur);
        this->read(tempAcc);
        this->file.seekg(-2 * recordLength, std::ios::cur);
        this->write(tempAcc);
    }
    this->file.close();
    std::filesystem::resize_file(this->filename, newFileSize);
    this->file.open(filename, std::ios::in | std::ios::out | std::ios::binary);
}


void AccountsFileHandler::createCsvFile(char delimiter)
{
    std::ofstream csvFile;
    std::string csvFilename;
    size_t dotIndex = this->filename.find_last_of(".");
    // If filename has extension.
    if (dotIndex != std::string::npos) {
        csvFilename = this->filename.substr(0, dotIndex);
    }
    else {
        csvFilename = this->filename;
    }
    csvFilename += ".csv";

    csvFile.open(csvFilename, std::ios::out);
    if (csvFile.is_open()) {
        uint32_t i = 0;
        for (; i < attributes.size() - 1; i++) {
            csvFile << attributes[i] << delimiter;
        }
        csvFile << attributes[i] << '\n';

        Account tempAcc;
        uint32_t fileSize = this->fileSize();
        this->file.seekg(0);
        while (this->file.tellg() < fileSize) {
            this->read(tempAcc);
            csvFile << tempAcc.getAccountName() << delimiter;
            csvFile << tempAcc.getId() << delimiter;
            csvFile << tempAcc.getPassword() << '\n';
        }
        csvFile.close();
    }
    else {
        throw std::runtime_error("Failed to create CSV file.");
    }
}


void AccountsFileHandler::createFixedWidthTextFile()
{
    std::ofstream txtFile;
    std::string txtFilename;
    size_t dotIndex = this->filename.find_last_of(".");
    // If filename has extension.
    if (dotIndex != std::string::npos) {
        txtFilename = this->filename.substr(0, dotIndex);
    }
    else {
        txtFilename = this->filename;
    }
    txtFilename += ".txt";

    // Space between columns.
    uint8_t space = 5;

    txtFile.open(txtFilename, std::ios::out);
    if (txtFile.is_open()) {
        txtFile << std::setw(Account::maxAccountNameLength + space) << std::left << attributes[0];
        txtFile << std::setw(Account::maxIdLength + space) << std::left << attributes[1];
        txtFile << std::setw(Account::maxPasswordLength + space) << std::left << attributes[2];
        txtFile << '\n';

        Account tempAcc;
        uint32_t fileSize = this->fileSize();
        this->file.seekg(0);
        while (this->file.tellg() < fileSize) {
            this->read(tempAcc);
            txtFile << std::setw(Account::maxAccountNameLength + space) << std::left << tempAcc.getAccountName();
            txtFile << std::setw(Account::maxIdLength + space) << std::left << tempAcc.getId();
            txtFile << std::setw(Account::maxPasswordLength + space) << std::left << tempAcc.getPassword();
            txtFile << '\n';
        }
        txtFile.close();
    }
    else {
        throw std::runtime_error("Failed to create text file.");
    }
}

