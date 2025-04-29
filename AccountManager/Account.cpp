#include "Account.h"
#include <vector>
#include <stdexcept>
#include <random>
#include <cstring>



Account::Account()
{
    accountName[0] = '\0';
    id[0] = '\0';
    password[0] = '\0';
}


Account::Account(std::string accountName, std::string id, std::string password)
{
    this->setAccountName(accountName);
    this->setId(id);
    this->setPassword(password);
}


void Account::setAccountName(std::string accountName)
{
    if (accountName.length() > maxAccountNameLength) {
        throw std::length_error("Account name cannot be of more than " + std::to_string(maxAccountNameLength) + " characters.");
    }
    strcpy(this->accountName, accountName.c_str());
}


void Account::setId(std::string id)
{
    if (id.length() > maxIdLength) {
        throw std::length_error("ID cannot be of more than " + std::to_string(maxIdLength) + " characters.");
    }
    strcpy(this->id, id.c_str());
}


void Account::setPassword(std::string password)
{
    if (password.length() > maxPasswordLength) {
        throw std::length_error("Password cannot be of more than " + std::to_string(maxPasswordLength) + " characters.");
    }
    strcpy(this->password, password.c_str());
}


std::string Account::getAccountName() const
{
    return std::string(this->accountName);
}


std::string Account::getId() const
{
    return std::string(this->id);
}


std::string Account::getPassword() const
{
    return std::string(this->password);
}



// Returns a random integer in the range [lowerLimit, upperLimit].
int randomInt(int lowerLimit, int upperLimit)
{
    std::random_device rd;
    std::uniform_int_distribution<int> dist(lowerLimit, upperLimit);
    return dist(rd);
}


void Account::setRandomPassword(uint8_t noOfAlphabeticChars, uint8_t noOfNumericChars, uint8_t noOfSpecialChars)
{
    if (noOfAlphabeticChars + noOfNumericChars + noOfSpecialChars > maxPasswordLength) {
        throw std::length_error("Password cannot be of more than " + std::to_string(maxPasswordLength) + " characters.");
    }
    std::string randomPassword = generateRandomPassword(noOfAlphabeticChars, noOfNumericChars, noOfSpecialChars);
    strcpy(this->password, randomPassword.c_str());
}


void Account::setRandomPassword(uint8_t passwordLength, bool equalCharTypeDistribution)
{
    if (passwordLength > maxPasswordLength) {
        throw std::length_error("Password cannot be of more than " + std::to_string(maxPasswordLength) + " characters.");
    }
    std::string randomPassword = generateRandomPassword(passwordLength, equalCharTypeDistribution);
    strcpy(this->password, randomPassword.c_str());
}


std::string Account::generateRandomPassword(uint8_t noOfAlphabeticChars, uint8_t noOfNumericChars, uint8_t noOfSpecialChars)
{
    uint8_t passwordLength = noOfAlphabeticChars + noOfNumericChars + noOfSpecialChars;
    std::string password;
    password.reserve(passwordLength);
    
    std::string alphabeticChars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string numericChars = "0123456789";
    std::string specialChars = "`~!@#$%^&*()-_=+[{]}\\|;:'\",<.>/?";

    // 0 is for alphabetic character
    // 1 is for numeric character
    // 2 is for special character
    std::vector<uint8_t> turns;
    if (noOfAlphabeticChars != 0) {
        turns.push_back(0);
    }
    if (noOfNumericChars != 0) {
        turns.push_back(1);
    }
    if (noOfSpecialChars != 0) {
        turns.push_back(2);
    }
    std::vector<uint8_t>::iterator it;
    uint8_t turnIndex;
    while (noOfAlphabeticChars != 0 || noOfNumericChars != 0 || noOfSpecialChars != 0) {
        turnIndex = randomInt(0, turns.size() - 1);
        if (turns[turnIndex] == 0) {
            password.push_back(alphabeticChars[randomInt(0, alphabeticChars.length() - 1)]);
            noOfAlphabeticChars--;
            if (noOfAlphabeticChars == 0) {
                it = turns.begin();
                while (*it != 0) {
                    it++;
                }
                turns.erase(it);
            }
        }
        else if (turns[turnIndex] == 1) {
            password.push_back(numericChars[randomInt(0, numericChars.length() - 1)]);
            noOfNumericChars--;
            if (noOfNumericChars == 0) {
                it = turns.begin();
                while (*it != 1) {
                    it++;
                }
                turns.erase(it);
            }
        }
        else {
            password.push_back(specialChars[randomInt(0, specialChars.length() - 1)]);
            noOfSpecialChars--;
            if (noOfSpecialChars == 0) {
                it = turns.begin();
                while (*it != 2) {
                    it++;
                }
                turns.erase(it);
            }
        }
    }
    return password;
}


std::string Account::generateRandomPassword(uint8_t passwordLength, bool equalCharTypeDistribution)
{
    uint8_t alphabeticChars, numericChars, specialChars, remaining;

    if (equalCharTypeDistribution) {
        alphabeticChars = numericChars = specialChars = passwordLength / 3;
        remaining = passwordLength % 3;
        switch (remaining)
        {
        case 1:
            alphabeticChars += 1;
            break;
        case 2:
            alphabeticChars += 1;
            numericChars += 1;
            break;
        }
    }
    else {
        alphabeticChars = randomInt(passwordLength / 3, 2 * passwordLength / 3);
        remaining = passwordLength - alphabeticChars;
        numericChars = randomInt(remaining / 3, 2 * remaining / 3);
        specialChars = remaining - numericChars;
    }

    return generateRandomPassword(alphabeticChars, numericChars, specialChars);
}




