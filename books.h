#include <iostream>
#include <vector>
#include <string>
#include <member.h>
class Book {
public:
    Book(int bookID, std::string bookName, int pageCount, std::string authorFirstName, std::string authorLastName, std::string bookType)
        : bookID(bookID), bookName(bookName), pageCount(pageCount), authorFirstName(authorFirstName), authorLastName(authorLastName), bookType(bookType) {}

    int getBookID() const { return bookID; }
    std::string getBookName() const { return bookName; }
    int getPageCount() const { return pageCount; }
    std::string getAuthorFirstName() const { return authorFirstName; }
    std::string getAuthorLastName() const { return authorLastName; }

    void borrowBook(Member& borrower, time_t dueDate);
    void returnBook();
    int calculateFine() const;
    using time_t = std::time_t;
private:
    int bookID;
    std::string bookName;
    int pageCount;
    std::string authorFirstName;
    std::string authorLastName;
    std::string bookType;
    time_t dueDate;
    Member* borrower;
};