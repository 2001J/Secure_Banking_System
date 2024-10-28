cmake_minimum_required(VERSION 3.29)
project(secure_banking_system)

set(CMAKE_CXX_STANDARD 20)

add_executable(secure_banking_system src/main.cpp
        src/Customer.cpp
        src/Customer.h
        src/Transaction.cpp
        src/Transaction.h
        src/Account.cpp
        src/Account.h
        src/BankingService.cpp
        src/BankingService.h)
