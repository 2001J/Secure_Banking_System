#include <iostream>
#include "BankingService.h"

void displayMenu() {
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "  Welcome to the Secure Banking System  " << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "Please select an option from the menu below:" << std::endl;
    std::cout << "1. Create Customer" << std::endl;
    std::cout << "2. Create Account" << std::endl;
    std::cout << "3. Perform Transaction" << std::endl;
    std::cout << "4. View Account Details" << std::endl;
    std::cout << "5. View Transactions" << std::endl;
    std::cout << "6. Update Customer Details" << std::endl;
    std::cout << "7. View Customer Details" << std::endl;
    std::cout << "8. Delete Customer" << std::endl;
    std::cout << "9. Exit" << std::endl;
    std::cout << "Enter your choice: ";
}

void createCustomer(BankingService &bankingService) {
    int id;
    std::string fName, lName, email, address, phone;
    std::cout << "Enter Customer ID: ";
    std::cin >> id;
    std::cin.ignore(); // Ignore the newline character left in the buffer
    std::cout << "Enter First Name: ";
    std::getline(std::cin, fName);
    std::cout << "Enter Last Name: ";
    std::getline(std::cin, lName);
    std::cout << "Enter Email: ";
    std::getline(std::cin, email);
    std::cout << "Enter Address: ";
    std::getline(std::cin, address);
    std::cout << "Enter Phone: ";
    std::getline(std::cin, phone);
    bankingService.createCustomer(id, fName, lName, email, address, phone);
    std::cout << "Customer created successfully!" << std::endl;
}

void createAccount(BankingService &bankingService) {
    int accNum, custID;
    double balance;
    std::string accType;
    std::cout << "Enter Account Number: ";
    std::cin >> accNum;
    std::cout << "Enter Customer ID: ";
    std::cin >> custID;
    std::cout << "Enter Initial Balance: ";
    std::cin >> balance;
    std::cin.ignore(); // Ignore the newline character left in the buffer
    std::cout << "Enter Account Type: ";
    std::getline(std::cin, accType);
    bankingService.createAccount(accNum, custID, balance, accType);
    std::cout << "Account created successfully!" << std::endl;
}

void performTransaction(BankingService &bankingService) {
    int accNum, toAccNum;
    double amount;
    std::string type;
    std::cout << "Enter Account Number: ";
    std::cin >> accNum;
    std::cin.ignore(); // Ignore the newline character left in the buffer
    std::cout << "Enter Transaction Type (Deposit/Withdrawal/Transfer): ";
    std::getline(std::cin, type);
    std::cout << "Enter Amount: ";
    std::cin >> amount;
    if (type == "Transfer") {
        std::cout << "Enter Destination Account Number: ";
        std::cin >> toAccNum;
        bankingService.performTransaction(accNum, type, amount, toAccNum);
    } else {
        bankingService.performTransaction(accNum, type, amount);
    }
    std::cout << "Transaction performed successfully!" << std::endl;
}

void viewAccountDetails(BankingService &bankingService) {
    int accNum;
    std::cout << "Enter Account Number: ";
    std::cin >> accNum;
    bankingService.viewAccountDetails(accNum);
}

void viewTransactions(BankingService &bankingService) {
    int accNum;
    std::cout << "Enter Account Number: ";
    std::cin >> accNum;
    bankingService.viewTransactions(accNum);
}

void updateCustomerDetails(BankingService &bankingService) {
    int id;
    std::string fName, lName, email, address, phone;
    std::cout << "Enter Customer ID: ";
    std::cin >> id;
    std::cin.ignore(); // Ignore the newline character left in the buffer
    std::cout << "Enter New First Name: ";
    std::getline(std::cin, fName);
    std::cout << "Enter New Last Name: ";
    std::getline(std::cin, lName);
    std::cout << "Enter New Email: ";
    std::getline(std::cin, email);
    std::cout << "Enter New Address: ";
    std::getline(std::cin, address);
    std::cout << "Enter New Phone: ";
    std::getline(std::cin, phone);

    auto it = bankingService.customers.find(id);
    if (it != bankingService.customers.end()) {
        it->second.setFirstName(fName);
        it->second.setLastName(lName);
        it->second.setEmail(email);
        it->second.setAddress(address);
        it->second.setPhone(phone);
        std::cout << "Customer details updated successfully!" << std::endl;
    } else {
        std::cout << "Customer not found!" << std::endl;
    }
}

void viewCustomerDetails(BankingService &bankingService) {
    int custID;
    std::cout << "Enter Customer ID: ";
    std::cin >> custID;
    bankingService.viewCustomerDetails(custID);
}

void deleteCustomer(BankingService &bankingService) {
    int custID;
    std::cout << "Enter Customer ID: ";
    std::cin >> custID;
    bankingService.deleteCustomer(custID);
}

int main() {
    BankingService bankingService;
    bankingService.loadData(); // Load data at the start

    int choice;

    do {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                createCustomer(bankingService);
                break;
            case 2:
                createAccount(bankingService);
                break;
            case 3:
                performTransaction(bankingService);
                break;
            case 4:
                viewAccountDetails(bankingService);
                break;
            case 5:
                viewTransactions(bankingService);
                break;
            case 6:
                updateCustomerDetails(bankingService);
                break;
            case 7:
                viewCustomerDetails(bankingService);
                break;
            case 8:
                deleteCustomer(bankingService);
                break;
            case 9:
                std::cout << "Exiting the application." << std::endl;
                bankingService.saveData(); // Save data before exiting
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 9);

    return 0;
}