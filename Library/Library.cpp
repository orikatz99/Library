#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#include "Library.h"

// Parameterized constructor
Library::Library(const char* name, Administrator& admin, Member* memberArr, int memberCount, Book** booksArr, int bookCount, MemberEmployee* memberEmployeeArr, int memberEmployeeCount)
    : admin(admin), memberCount(memberCount), bookCount(bookCount), memberEmployeeCount(memberEmployeeCount)
{
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);

    this->memberArr = new Member[memberCount];
    for (int i = 0; i < memberCount; ++i) {
        this->memberArr[i] = memberArr[i];
    }

    this->booksArr = new Book * [bookCount];
    for (int i = 0; i < bookCount; ++i) {
        this->booksArr[i] = booksArr[i]->clone();
    }

    this->memberEmployeeArr = new MemberEmployee[memberEmployeeCount];
    for (int i = 0; i < memberEmployeeCount; ++i) {
        this->memberEmployeeArr[i] = memberEmployeeArr[i];
    }
}

// Copy constructor
Library::Library(const Library& other)
    : admin(other.admin), memberCount(other.memberCount), bookCount(other.bookCount), memberEmployeeCount(other.memberEmployeeCount)
{
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);

    memberArr = new Member[memberCount];
    for (int i = 0; i < memberCount; ++i) {
        memberArr[i] = other.memberArr[i];
    }

    booksArr = new Book * [bookCount];
    for (int i = 0; i < bookCount; ++i) {
        booksArr[i] = other.booksArr[i]->clone();
    }

    memberEmployeeArr = new MemberEmployee[memberEmployeeCount];
    for (int i = 0; i < memberEmployeeCount; ++i) {
        memberEmployeeArr[i] = other.memberEmployeeArr[i];
    }
}

// Move constructor
Library::Library(Library&& other) noexcept
    : name(other.name), admin(other.admin), memberArr(other.memberArr), memberCount(other.memberCount), booksArr(other.booksArr), bookCount(other.bookCount), memberEmployeeArr(other.memberEmployeeArr), memberEmployeeCount(other.memberEmployeeCount)
{
    other.name = nullptr;
    other.memberArr = nullptr;
    other.booksArr = nullptr;
    other.memberEmployeeArr = nullptr;
}

// Assignment operator
Library& Library::operator=(const Library& other)
{
    if (this == &other) {
        return *this;
    }

    delete[] name;
    delete[] memberArr;
    for (int i = 0; i < bookCount; ++i) {
        delete booksArr[i];
    }
    delete[] booksArr;
    delete[] memberEmployeeArr;

    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);

    memberCount = other.memberCount;
    bookCount = other.bookCount;
    memberEmployeeCount = other.memberEmployeeCount;

    memberArr = new Member[memberCount];
    for (int i = 0; i < memberCount; ++i) {
        memberArr[i] = other.memberArr[i];
    }

    booksArr = new Book * [bookCount];
    for (int i = 0; i < bookCount; ++i) {
        booksArr[i] = other.booksArr[i]->clone();
    }

    memberEmployeeArr = new MemberEmployee[memberEmployeeCount];
    for (int i = 0; i < memberEmployeeCount; ++i) {
        memberEmployeeArr[i] = other.memberEmployeeArr[i];
    }

    return *this;
}

// Destructor
Library::~Library()
{
    delete[] name;
    delete[] memberArr;
    for (int i = 0; i < bookCount; ++i) {
        delete booksArr[i];
    }
    delete[] booksArr;
    delete[] memberEmployeeArr;
}

// Getters
const char* Library::getName() const
{
    return name;
}
Administrator& Library::getAdmin()
{
    return admin;
}
Member* Library::getMembers() const
{
    return memberArr;
}
int Library::getMemberCount() const
{
    return memberCount;
}
Book** const Library::getBooks() const
{
    return booksArr;
}
int Library::getBookCount() const
{
    return bookCount;
}
MemberEmployee* Library::getMemberEmployees() const
{
    return memberEmployeeArr;
}
int Library::getMemberEmployeeCount() const
{
    return memberEmployeeCount;
}


// Setters
bool Library::setName(const char* name)
{
    if (name == nullptr)
        return false;

    delete[] this->name;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);

    return true;
}
bool Library::setMembers(const Member* newMemberArr, int newMemberCount)
{
    if (newMemberArr == nullptr)
        return false;

    delete[] memberArr;
    memberArr = new Member[newMemberCount];
    for (int i = 0; i < newMemberCount; ++i) {
        memberArr[i] = newMemberArr[i];
    }
    memberCount = newMemberCount;

    return true;
}
bool Library::setBooks(Book** newBooksArr, int newBookCount)
{
    if (newBooksArr == nullptr)
        return false;

    for (int i = 0; i < bookCount; ++i) {
        delete booksArr[i];
    }
    delete[] booksArr;

    booksArr = new Book * [newBookCount];
    for (int i = 0; i < newBookCount; ++i) {
        booksArr[i] = newBooksArr[i]->clone();
    }
    bookCount = newBookCount;

    return true;
}
bool Library::setMemberEmployees(const MemberEmployee* newMemberEmployeeArr, int newMemberEmployeeCount)
{
    if (newMemberEmployeeArr == nullptr)
        return false;

    delete[] memberEmployeeArr;
    memberEmployeeArr = new MemberEmployee[newMemberEmployeeCount];
    for (int i = 0; i < newMemberEmployeeCount; ++i) {
        memberEmployeeArr[i] = newMemberEmployeeArr[i];
    }
    memberEmployeeCount = newMemberEmployeeCount;

    return true;
}

void Library::printLibrary() const
{
    std::cout << "\nLibrary Name: " << name << std::endl;
    std::cout << "Administrator: " << admin.getName() << std::endl;
    std::cout << "Number of Members: " << memberCount << std::endl;
    std::cout << "Number of Employees: " << admin.getEmployeeCount() << std::endl;
    std::cout << "Number of Member Employees: " << memberEmployeeCount << std::endl;
    std::cout << "Number of Books: " << bookCount << std::endl;
}

void Library::showMembers() const
{
    if (memberCount == 0)
        std::cout << "\nThere are currently no members for the library" << std::endl;
    else
    {
        std::cout << "\nOur Library " << name << " has " << memberCount << " members:" << std::endl;
        for (int i = 0; i < memberCount; ++i) {
            std::cout << "#" << i + 1 << std::endl;
            memberArr[i].printMember();
            cout << "\n";
        }
    }
}

void Library::showBooks() const
{
    if (bookCount == 0)
        std::cout << "\nThere are currently no books for the library" << std::endl;
    else
    {
        std::cout << "\nOur Library " << name << " has the following books: " << std::endl;
        for (int i = 0; i < bookCount; ++i)
        {
            booksArr[i]->printBook();
            cout << "\n";
        }
    }
}

void Library::showMemberEmployees() const
{
    if (memberEmployeeCount==0)
        std::cout << "\nIn our library " << name << " there are no members who also employees" << std::endl;
    else
    {
        std::cout << "\nOur Library " << name << " has " << memberEmployeeCount << " members that are also employees:" << std::endl;
        for (int i = 0; i < memberEmployeeCount; ++i) 
        {
            std::cout << "#" << i + 1 << std::endl;
            memberEmployeeArr[i].printMemberEmployee();
            cout << "\n";
        }
    }
}

void Library::addBook(Book* newBook)
{
    Book** newBooksArr = new Book * [bookCount + 1];

    for (int i = 0; i < bookCount; ++i) {
        newBooksArr[i] = booksArr[i];
    }

    newBooksArr[bookCount] = newBook;

    delete[] booksArr;

    booksArr = newBooksArr;
    ++bookCount;
}

void Library::addMember(Member& newMember)
{
    // Check if an member with the same member number already exists
    for (int i = 0; i < memberCount; ++i)
    {
        if (strcmp(memberArr[i].getMemNumber(), newMember.getMemNumber()) == 0)
        {
            cout << "Member with the same member number already exists." << endl;
            return;
        }
    }

    Member* newArr = new Member[memberCount + 1];
    if (!newArr) {
        cout << "Memory allocation failed." << endl;
        return;
    }

    for (int i = 0; i < memberCount; ++i)
        newArr[i] = memberArr[i];

    newArr[memberCount] = newMember;

    delete[] memberArr;

    memberArr = newArr;
    ++memberCount;
}

void Library::addMemberEmployee(MemberEmployee& newMemberEmployee)
{
    // Check if an memberEmployee with the same member number already exists
    for (int i = 0; i < memberEmployeeCount; ++i)
    {
        if (strcmp(memberArr[i].getMemNumber(), newMemberEmployee.getMemNumber()) == 0)
        {
            cout << "Member Employee with the same member number already exists." << endl;
            return;
        }
    }

    MemberEmployee* newArr = new MemberEmployee[memberEmployeeCount + 1];
    if (!newArr) {
        cout << "Memory allocation failed." << endl;
        return;
    }

    for (int i = 0; i < memberEmployeeCount; ++i)
        newArr[i] = memberEmployeeArr[i];

    newArr[memberEmployeeCount] = newMemberEmployee;

    delete[] memberEmployeeArr;

    memberEmployeeArr = newArr;
    ++memberEmployeeCount;
}

Member* Library::findMemByNum(const char* num)
{
    for (int i = 0; i < memberCount; ++i)
    {
        if (strcmp(memberArr[i].getMemNumber(), num) == 0)
        {
            return &memberArr[i];
        }
    }
    return nullptr;
}

Member* Library::findMemByName(const char* name)
{
    for (int i = 0; i < memberCount; ++i)
    {
        if (strcmp(memberArr[i].getName(), name) == 0)
        {
            return &memberArr[i];
        }
    }
    return nullptr;
}

// Function to sort books by publication year
void Library::sortBooksByPublicationYear()
{
    std::sort(booksArr, booksArr + bookCount, [](const Book* a, const Book* b) {
        return a->getPublicationYear() < b->getPublicationYear();
        });
}

// Function to sort books by copies available
void Library::sortBooksByCopiesAvailable()
{
    std::sort(booksArr, booksArr + bookCount, [](const Book* a, const Book* b) {
        return a->getCopiesAvailable() < b->getCopiesAvailable();
        });
}

// Function to sort books by book name
void Library::sortBooksByBookName()
{
    std::sort(booksArr, booksArr + bookCount, [](const Book* a, const Book* b) {
        return strcmp(a->getBookName(), b->getBookName()) < 0;
        });
}

bool Library::copyAvailable() const
{
    for (int i = 0; i < bookCount; ++i)
    {
        if (booksArr[i]->getCopiesAvailable()!=0)
            return true;
    }
    return false;
}