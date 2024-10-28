//Customer.cpp
#include "Customer.h"

Customer::Customer(int id, const std::string &fName, const std::string &lName, const std::string &mail,
                   const std::string &addr, const std::string &ph)
        : customerID(id), firstName(fName), lastName(lName), email(mail), address(addr), phone(ph) {}

int Customer::getCustomerID() const { return customerID; }
std::string Customer::getFirstName() const { return firstName; }
std::string Customer::getLastName() const { return lastName; }
std::string Customer::getEmail() const { return email; }
std::string Customer::getAddress() const { return address; }
std::string Customer::getPhone() const { return phone; }

void Customer::setFirstName(const std::string &fName) { firstName = fName; }
void Customer::setLastName(const std::string &lName) { lastName = lName; }
void Customer::setEmail(const std::string &mail) { email = mail; }
void Customer::setAddress(const std::string &addr) { address = addr; }
void Customer::setPhone(const std::string &ph) { phone = ph; }
