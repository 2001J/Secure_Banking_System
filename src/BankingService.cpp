#include "BankingService.h"
#include <iostream>
#include <fstream>

void BankingService::createCustomer(int id, const std::string &fName, const std::string &lName, const std::string &mail,
                                    const std::string &addr, const std::string &ph) {
    customers.emplace(id, Customer(id, fName, lName, mail, addr, ph));
}

void BankingService::createAccount(int accNum, int custID, double bal, const std::string &accType) {
    accounts.emplace(accNum, Account(accNum, custID, bal, accType));
}

void BankingService::performTransaction(int accNum, const std::string &type, double amount, int toAccNum) {
    auto it = accounts.find(accNum);
    if (it != accounts.end()) {
        Account *fromAccount = &it->second;
        Account *toAccount = nullptr;

        if (type == "Transfer" && toAccNum != -1) {
            auto toIt = accounts.find(toAccNum);
            if (toIt != accounts.end()) {
                toAccount = &toIt->second;
            } else {
                std::cout << "Destination account not found" << std::endl;
                return;
            }
        }

        if (type == "Deposit") {
            fromAccount->deposit(amount);
        } else if (type == "Withdrawal") {
            fromAccount->withdraw(amount);
        } else if (type == "Transfer") {
            fromAccount->transfer(amount, *toAccount);
        } else {
            std::cout << "Invalid transaction type" << std::endl;
        }
    } else {
        std::cout << "Account not found" << std::endl;
    }
}

void BankingService::viewAccountDetails(int accNum) const {
    auto it = accounts.find(accNum);
    if (it != accounts.end()) {
        std::cout << it->second.getAccountDetails() << std::endl;
    } else {
        std::cout << "Account not found" << std::endl;
    }
}

void BankingService::viewTransactions(int accNum) const {
    auto it = accounts.find(accNum);
    if (it != accounts.end()) {
        it->second.viewTransactions();
    } else {
        std::cout << "Account not found" << std::endl;
    }
}

void BankingService::viewCustomerDetails(int custID) const {
    auto it = customers.find(custID);
    if (it != customers.end()) {
        const Customer &customer = it->second;
        std::cout << "Customer ID: " << customer.getCustomerID() << std::endl;
        std::cout << "First Name: " << customer.getFirstName() << std::endl;
        std::cout << "Last Name: " << customer.getLastName() << std::endl;
        std::cout << "Email: " << customer.getEmail() << std::endl;
        std::cout << "Address: " << customer.getAddress() << std::endl;
        std::cout << "Phone: " << customer.getPhone() << std::endl;
    } else {
        std::cout << "Customer not found" << std::endl;
    }
}

void BankingService::deleteCustomer(int custID) {
    auto it = customers.find(custID);
    if (it != customers.end()) {
        // Remove all accounts associated with the customer
        for (auto accIt = accounts.begin(); accIt != accounts.end();) {
            if (accIt->second.getCustomerID() == custID) {
                accIt = accounts.erase(accIt);
            } else {
                ++accIt;
            }
        }
        // Remove the customer
        customers.erase(it);
        std::cout << "Customer and associated accounts deleted successfully!" << std::endl;
    } else {
        std::cout << "Customer not found!" << std::endl;
    }
}

void BankingService::saveData() const {
    std::ofstream customerFile("customers.txt");
    for (const auto &pair : customers) {
        const Customer &customer = pair.second;
        customerFile << customer.getCustomerID() << " "
                     << customer.getFirstName() << " "
                     << customer.getLastName() << " "
                     << customer.getEmail() << " "
                     << customer.getAddress() << " "
                     << customer.getPhone() << std::endl;
    }
    customerFile.close();

    std::ofstream accountFile("accounts.txt");
    for (const auto &pair : accounts) {
        const Account &account = pair.second;
        accountFile << account.getAccountNumber() << " "
                    << account.getCustomerID() << " "
                    << account.getBalance() << " "
                    << account.getAccountType() << std::endl;
    }
    accountFile.close();
}

void BankingService::loadData() {
    std::ifstream customerFile("customers.txt");
    if (customerFile.is_open()) {
        int id;
        std::string fName, lName, email, address, phone;
        while (customerFile >> id >> fName >> lName >> email >> address >> phone) {
            customers.emplace(id, Customer(id, fName, lName, email, address, phone));
        }
        customerFile.close();
    }

    std::ifstream accountFile("accounts.txt");
    if (accountFile.is_open()) {
        int accNum, custID;
        double balance;
        std::string accType;
        while (accountFile >> accNum >> custID >> balance >> accType) {
            accounts.emplace(accNum, Account(accNum, custID, balance, accType));
        }
        accountFile.close();
    }
}