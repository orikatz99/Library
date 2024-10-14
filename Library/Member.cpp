#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

#include "Member.h"

// Default constructor
Member::Member() : name(nullptr), memberNumber(nullptr), phoneNumber(nullptr), memberLoan(nullptr) {}

// Parameterized constructor
Member::Member(const char* name, const char* memberNumber, const char* phoneNumber, Loan& memberLoan)
{
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);

    this->memberNumber = new char[strlen(memberNumber) + 1];
    strcpy(this->memberNumber, memberNumber);

    this->phoneNumber = new char[strlen(phoneNumber) + 1];
    strcpy(this->phoneNumber, phoneNumber);

    this->memberLoan = new Loan(memberLoan);

}

// Copy constructor
Member::Member(const Member& other)
{
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);

    memberNumber = new char[strlen(other.memberNumber) + 1];
    strcpy(memberNumber, other.memberNumber);

    phoneNumber = new char[strlen(other.phoneNumber) + 1];
    strcpy(phoneNumber, other.phoneNumber);

    memberLoan = new Loan(*other.memberLoan);
}

// Move constructor
Member::Member(Member&& other) noexcept
    : name(other.name), memberNumber(other.memberNumber), phoneNumber(other.phoneNumber), memberLoan(other.memberLoan)
{

    other.name = nullptr;
    other.memberNumber = nullptr;
    other.phoneNumber = nullptr;
    other.memberLoan = nullptr;
}

// assignment operator
const Member& Member::operator=(const Member& other)
{

    if (this != &other) {
        delete[] name;
        delete[] memberNumber;
        delete[] phoneNumber;
        delete memberLoan;

        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);

        memberNumber = new char[strlen(other.memberNumber) + 1];
        strcpy(memberNumber, other.memberNumber);

        phoneNumber = new char[strlen(other.phoneNumber) + 1];
        strcpy(phoneNumber, other.phoneNumber);

        memberLoan = new Loan(*other.memberLoan);
    }
    return *this;
}

// Destructor
Member::~Member()
{

    delete[] name;
    delete[] memberNumber;
    delete[] phoneNumber;
    delete memberLoan;
}

// getters
const char* Member::getName() const
{

    return name;
}
const char* Member::getMemNumber() const
{

    return memberNumber;
}
Loan* Member::getLoanMember() const
{
    return memberLoan;
}
const char* Member::getPhoneNumber() const
{

    return phoneNumber;
}

// setters
bool Member::setName(const char* name)
{
    if (name == nullptr)
        return false;

    delete[] this->name;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);

    return true;
}
bool Member::setMemNumber(const char* memNumber)
{
    if (memNumber == nullptr)
        return false;

    delete[] this->memberNumber;
    this->memberNumber = new char[strlen(memNumber) + 1];
    strcpy(this->memberNumber, memNumber);

    return true;
}
bool Member::setPhoneNumber(const char* phoneNumber)
{
    if (phoneNumber == nullptr)
        return false;

    delete[] this->phoneNumber;
    this->phoneNumber = new char[strlen(phoneNumber) + 1];
    strcpy(this->phoneNumber, phoneNumber);

    return true;
}

void Member::printMember() const
{
    std::cout << "Name: " << name << "\n"
        << "Member Number: " << memberNumber << "\n"
        << "Phone Number: " << phoneNumber << std::endl;
    cout << "Member loan: ";
    if(memberLoan->getNumOfBook()>0)
        memberLoan->printLoan();
    else
        cout << "Books have not yet been borrowed\n";
}