#include "Transaction.h"
#include "Account.h"
#include <iostream>

Transaction::Transaction(int id, int accNum, const std::string &t, double amt, const std::string &d)
        : transactionID(id), accountNumber(accNum), type(t), amount(amt), date(d) {}

int Transaction::getTransactionID() const { return transactionID; }
int Transaction::getAccountNumber() const { return accountNumber; }
std::string Transaction::getType() const { return type; }
double Transaction::getAmount() const { return amount; }
std::string Transaction::getDate() const { return date; }

std::string Transaction::getTransactionDetails() const {
    return "Transaction ID: " + std::to_string(transactionID) + ", Account Number: " + std::to_string(accountNumber) +
           ", Type: " + type + ", Amount: " + std::to_string(amount) + ", Date: " + date;
}

void Transaction::executeTransaction(Account *fromAccount, Account *toAccount) const {

    //print transactions details
    std::cout << "Executing transaction: " << getTransactionDetails() << std::endl;

    // Check if 'fromAccount' has sufficient balance
    if (fromAccount->getBalance() < amount) {
        std::cerr << "Transaction failed: Insufficient funds in source account." << std::endl;
        return;
    }

    // Check if 'toAccount' is valid and perform transaction
    if (toAccount != nullptr) {
        fromAccount->withdraw(amount);
        toAccount->deposit(amount);
        std::cout << "Transaction completed successfully." << std::endl;
    } else {
        std::cerr << "Invalid destination account." << std::endl;
    }
}
