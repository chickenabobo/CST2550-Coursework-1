#include <iostream>
#include <vector>
#include <string>
#include <books.h>
#include <member.h>
class Person {
public:
    Person(std::string name, std::string address, std::string email)
        : name(name), address(address), email(email) {}

    std::string getName() const { return name; }
    void setName(std::string newName) { name = newName; }

    std::string getAddress() const { return address; }
    void setAddress(std::string newAddress) { address = newAddress; }

    std::string getEmail() const { return email; }
    void setEmail(std::string newEmail) { email = newEmail; }

private:
    std::string name;
    std::string address;
    std::string email;
};