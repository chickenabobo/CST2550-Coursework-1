#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <ctime>
#include "librarian.h"
#include "member.h"
#include "person.h"
#include "books.h"
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

class Librarian : public Person {
public:
    Librarian(int staffID, std::string name, std::string address, std::string email, int salary)
        : Person(name, address, email), staffID(staffID), salary(salary) {}

    int getStaffID() const { return staffID; }
    void setStaffID(int newStaffID) { staffID = newStaffID; }

    int getSalary() const { return salary; }
    void setSalary(int newSalary) { salary = newSalary; }

    void addMember(std::vector<Member>& members, int memberID, std::string name, std::string address, std::string email);
    void issueBook(std::vector<Book>& books, std::vector<Member>& members, int memberID, int bookID);
    void returnBook(std::vector<Book>& books, std::vector<Member>& members, int memberID, int bookID);
    void displayBorrowedBooks(const std::vector<Member>& members, int memberID);
    void calculateFine(const std::vector<Member>& members, int memberID);

    void display_books_from_csv(const std::string& file_path);

    void librarian_menu() {
    std::cout << "Welcome to the library s system:" << std::endl;
    std::cout << "1. Option 1 display books to csv file" << std::endl;
    std::cout << "2. Option 2" << std::endl;
    std::cout << "3. Option 3" << std::endl;
    // Different options that the librarian has. each option has a different function

    std::string choice;
    std::cout << "Enter your choice (1, 2, or 3): ";
    std::getline(std::cin, choice);

    if (choice == "1") {
        std::string file_path;
        std::cout << "Enter the path of the CSV file: ";
        // The librarian will have to enter the csv file "library_books.csv" to display all the books in that file
        std::getline(std::cin, file_path);
        display_books_from_csv(file_path);
    } else if (choice == "2") {
        std::  cout << " You have selected choice 2";
        // Choice 2 is where the librarian would issue a book to the user through the csv file 
    } else if (choice == "3") {
        std::  cout << " You have selected choice 3";
        // Choice 3 is where the librarian would return a book to the member
    } else {
        std::cout << "Invalid choice. Please enter 1, 2, or 3." << std::endl;
    }
};
private:
    int staffID;
    int salary;
};

    void display_books_from_csv(const std::string& file_path) {
    try {
        std::ifstream file(file_path);
        if (file.is_open()) {
            std::string line;
            while (std::getline(file, line)) {
                std::cout << line << std::endl;
            }
            file.close();
        } else {
            std::cout << "Error: Unable to open file at " << file_path << std::endl;
        }
    } catch (const std::exception& e) {
        std::cout << "An error occurred: " << e.what() << std::endl;
    }
}
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
int main() {
    Librarian librarian(1, "LibrarianName", "LibrarianAddress", "LibrarianEmail", 50000);
    librarian.librarian_menu(); 
    return 0;
};