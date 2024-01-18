#include <iostream>
#include <vector>
#include <string>
class Member : public Person {
private:
    int memberId;
    std:: vector<Book> booksLoaned;

    public: 
    Member(int memberID, std::string name, std::string address, std::string email)
    : Person(name, address, email), memberId(memberID) {}

    int getMemberID() const { return memberId; }
    const std::vector<Book>& getBooksBorrowed() const { return booksLoaned; }
    void setBooksBorrowed(const Book& book) { booksLoaned.push_back(book); }
};