//BankingService.h
#ifndef SECURE_BANKING_SYSTEM_BANKINGSERVICE_H
#define SECURE_BANKING_SYSTEM_BANKINGSERVICE_H

#include <unordered_map>
#include "Customer.h"
#include "Account.h"

class BankingService {
private:
    std::unordered_map<int, Customer> customers;
    std::unordered_map<int, Account> accounts;

public:
    void createCustomer(int id, const std::string &fName, const std::string &lName, const std::string &mail,
                        const std::string &addr, const std::string &ph);
    void createAccount(int accNum, int custID, double bal, const std::string &accType);
    void performTransaction(int accNum, const std::string &type, double amount, int toAccNum = -1);
    void viewAccountDetails(int accNum) const;
    void viewTransactions(int accNum) const;
};



#endif //SECURE_BANKING_SYSTEM_BANKINGSERVICE_H
