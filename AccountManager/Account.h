#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <stdint.h>



class AccountsFileHandler;

class Account
{
    friend class AccountsFileHandler;

public:
    static constexpr uint8_t maxAccountNameLength = 20;
    static constexpr uint8_t maxIdLength = 50;
    static constexpr uint8_t maxPasswordLength = 50;

private:
    // +1 is for null character.
    char accountName[maxAccountNameLength + 1];
    char id[maxIdLength + 1];
    char password[maxPasswordLength + 1];

public:
    Account();
    Account(std::string accountName, std::string id, std::string password);
    void setAccountName(std::string accountName);
    void setId(std::string id);
    void setPassword(std::string password);
    std::string getAccountName() const;
    std::string getId() const;
    std::string getPassword() const;
    void setRandomPassword(uint8_t noOfAlphabeticChars, uint8_t noOfNumericChars, uint8_t noOfSpecialChars);
    void setRandomPassword(uint8_t passwordLength = maxPasswordLength, bool equalCharTypeDistribution = false);

    static std::string generateRandomPassword(uint8_t noOfAlphabeticChars, uint8_t noOfNumericChars, uint8_t noOfSpecialChars);
    static std::string generateRandomPassword(uint8_t passwordLength = maxPasswordLength, bool equalCharTypeDistribution = false);
};



#endif // ACCOUNT_H
