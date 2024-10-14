#ifndef LIBRARY_H
#define LIBRARY_H

#include <cstring>
#include "Administrator.h"
#include "Member.h"
#include "Book.h"
#include "MemberEmployee.h"

class Library {
private:
    char* name;
    Administrator admin;
    Member* memberArr;
    int memberCount;
    Book** booksArr;
    int bookCount;
    MemberEmployee* memberEmployeeArr;
    int memberEmployeeCount;


public:
    Library(const char* name, Administrator& admin, Member* memberArr, int memberCount, Book** booksArr, int bookCount, MemberEmployee* memberEmployeeArr, int memberEmployeeCount);
    Library(const Library& other);
    Library(Library&& other) noexcept;
    Library& operator=(const Library& other);
    ~Library();

    // getters
    const char* getName() const;
    Administrator& getAdmin();
    Member* getMembers() const;
    int getMemberCount() const;
    Book** const getBooks() const;
    int getBookCount() const;
    MemberEmployee* getMemberEmployees() const;
    int getMemberEmployeeCount() const;

    // setters
    bool setName(const char* name);
    bool setMembers(const Member* memberArr, int memberCount);
    bool setBooks(Book** booksArr, int bookCount);
    bool setMemberEmployees(const MemberEmployee* newMemberEmployeeArr, int newMemberEmployeeCount);

    void printLibrary() const;
    void showMembers() const;
    void showBooks() const;
    void showMemberEmployees() const;
    void addBook(Book* newBook);
    void addMember(Member& newMember);
    void addMemberEmployee(MemberEmployee& newMemberEmployee);
    Member* findMemByNum(const char* num);
    Member* findMemByName(const char* name);

    void sortBooksByPublicationYear();
    void sortBooksByCopiesAvailable();
    void sortBooksByBookName();

    bool copyAvailable() const;

};

#endif // LIBRARY_H
