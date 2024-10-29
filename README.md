# Secure Banking System

## Overview
The Secure Banking System is a simple banking application that allows users to manage customers and accounts, perform transactions, and view account and customer details. The application uses file-based storage to persist data between sessions.

## Features
- Create, read, update, and delete (CRUD) operations for customers and accounts.
- Perform transactions: deposit, withdrawal, and transfer.
- View account and customer details.
- Persistent storage using files (`customers.txt` and `accounts.txt`).

## Project Structure
```
├── src
│   ├── Account.cpp
│   ├── Account.h
│   ├── BankingService.cpp
│   ├── BankingService.h
│   ├── Customer.cpp
│   ├── Customer.h
│   ├── Transaction.cpp
│   ├── Transaction.h
│   └── main.cpp
├── CMakeLists.txt
├── customers.txt
└── accounts.txt
```

## Setup Instructions

### Prerequisites
- C++ compiler (e.g., g++)
- CMake (optional, for easier compilation)

### Cloning the Repository
To clone the repository, use the following command:
```sh
git clone https://github.com/2001J/secure_banking_system.git
cd secure_banking_system
```

### Compilation

#### Using CMake
To compile the project using CMake, follow these steps:

1. **Create a build directory**:
  ```sh
  mkdir build
  cd build
  ```

2. **Run CMake to generate the build files**:
  ```sh
  cmake ..
  ```

3. **Build the project**:
  ```sh
  cmake --build .
  ```

#### Using g++
To compile the project directly using g++, follow these steps:

1. **Navigate to the src directory**:
  ```sh
  cd src
  ```
2. **Compile the project**:
  ```sh
  g++ -std=c++20 -o secure_banking_system main.cpp Account.cpp BankingService.cpp Customer.cpp Transaction.cpp
  ```

### Running the Application
After compilation, run the executable:
  ```sh
  ./secure_banking_system
  ```

## Usage
The application provides a menu-driven interface for interacting with the banking system. Follow the on-screen prompts to perform various operations.

### Menu Options
- **Create Customer**: Add a new customer to the system.
- **Create Account**: Add a new account for an existing customer.
- **Perform Transaction**: Perform a deposit, withdrawal, or transfer.
- **View Account Details**: View details of a specific account.
- **View Transactions**: View transaction history of a specific account.
- **Update Customer Details**: Update the details of an existing customer.
- **View Customer Details**: View details of a specific customer.
- **Delete Customer**: Delete a customer and their associated accounts.
- **Exit**: Save data and exit the application.

### Example Usage
**Create a Customer**:
```
Enter Customer ID: 1
Enter First Name: John
Enter Last Name: Doe
Enter Email: john.doe@example.com
Enter Address: 123 Elm Street
Enter Phone: 555-1234
```

**Create an Account**:
```
Enter Account Number: 1001
Enter Customer ID: 1
Enter Initial Balance: 5000.0
Enter Account Type: Savings
```

**Perform a Deposit**:
```
Enter Account Number: 1001
Enter Transaction Type: Deposit
Enter Amount: 1000.0
```

**View Account Details**:
```
Enter Account Number: 1001
```

## Data Persistence
**Data Files**:
- `customers.txt`: Stores customer information.
- `accounts.txt`: Stores account information.

**Data Loading**: Data is loaded from `customers.txt` and `accounts.txt` when the application starts.

**Data Saving**: Data is saved to `customers.txt` and `accounts.txt` when the application exits.

## Contributing
Contributions are welcome! Please fork the repository and submit a pull request for any improvements or bug fixes.

## License
This project is licensed under the MIT License. See the LICENSE file for details.

