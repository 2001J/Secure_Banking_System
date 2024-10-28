//Customer.h
#ifndef SECURE_BANKING_SYSTEM_CUSTOMER_H
#define SECURE_BANKING_SYSTEM_CUSTOMER_H

#include <string>

class Customer {
private:
    int customerID;
    std::string firstName;
    std::string lastName;
    std::string email;
    std::string address;
    std::string phone;

public:
    Customer(int id, const std::string &fName, const std::string &lName, const std::string &mail,
             const std::string &addr, const std::string &ph);

    int getCustomerID() const;
    [[nodiscard]] std::string getFirstName() const;
    [[nodiscard]] std::string getLastName() const;
    [[nodiscard]] std::string getEmail() const;
    [[nodiscard]] std::string getAddress() const;
    [[nodiscard]] std::string getPhone() const;

    void setFirstName(const std::string &fName);
    void setLastName(const std::string &lName);
    void setEmail(const std::string &mail);
    void setAddress(const std::string &addr);
    void setPhone(const std::string &ph);
};


#endif //SECURE_BANKING_SYSTEM_CUSTOMER_H
