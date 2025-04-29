#ifndef ACCOUNTS_FILE_HANDLER_H
#define ACCOUNTS_FILE_HANDLER_H

#include <fstream>
#include <string>
#include <array>
#include <vector>
#include <stdint.h>
#include "Account.h"



class AccountsFileHandler
{
public:
    static const std::array<std::string, 3> attributes;
    static constexpr uint8_t recordLength = Account::maxAccountNameLength + Account::maxIdLength + Account::maxPasswordLength;

private:
    std::string filename;
    std::fstream file;
    
    static uint32_t byteIndex(uint32_t recordIndex);

public:
    AccountsFileHandler(std::string filename);
    ~AccountsFileHandler();
    bool fileExists();
    void createFile();
    uint32_t fileSize();
    uint32_t noOfRecords();
    void moveFilePointer(uint32_t recordIndex);
    uint32_t currentRecordIndex();
    void write(const Account& account);
    void write(const Account& account, uint32_t recordIndex);
    void read(Account& account);
    void read(Account& account, uint32_t recordIndex);
    void insert(const Account& account, uint32_t recordIndex);
    void Delete(uint32_t recordIndex);
    void createCsvFile(char delimiter);
    void createFixedWidthTextFile();
};



#endif // ACCOUNTS_FILE_HANDLER_H
