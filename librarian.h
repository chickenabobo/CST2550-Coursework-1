#include <iostream>
#include <vector>
#include <string>
#include <person.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <person.h> 

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

    
private:
    int staffID;
    int salary;
};
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