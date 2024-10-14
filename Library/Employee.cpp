#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

#include "Employee.h"

Employee::Employee(const char* name, const char* employeeNumber)
{

    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);

    this->employeeNumber = new char[strlen(employeeNumber) + 1];
    strcpy(this->employeeNumber, employeeNumber);
}

// Copy constructor
Employee::Employee(const Employee& other)
{

    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);

    employeeNumber = new char[strlen(other.employeeNumber) + 1];
    strcpy(employeeNumber, other.employeeNumber);
}

// Move constructor
Employee::Employee(Employee&& other) noexcept
    : name(other.name), employeeNumber(other.employeeNumber)
{
    other.name = nullptr;
    other.employeeNumber = nullptr;
}

// assignment operator
const Employee& Employee::operator=(const Employee& other)
{

    if (this != &other) {
        delete[] name;
        delete[] employeeNumber;

        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);

        employeeNumber = new char[strlen(other.employeeNumber) + 1];
        strcpy(employeeNumber, other.employeeNumber);
    }
    return *this;
}

// Destructor
Employee::~Employee()
{

    delete[] name;
    delete[] employeeNumber;
}

// getters
const char* Employee::getName() const
{
    return name;
}
const char* Employee::getEmpNumber() const
{
    return employeeNumber;
}

// setters
bool Employee::setName(const char* name)
{
    if (name == nullptr)
        return false;

    delete[] this->name;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);

    return true;
}
bool Employee::setEmpNumber(const char* empNumber)
{
    if (empNumber == nullptr)
        return false;

    delete[] this->employeeNumber;
    this->employeeNumber = new char[strlen(empNumber) + 1];
    strcpy(this->employeeNumber, empNumber);

    return true;
}

void Employee::printEmployee() const
{

    std::cout << "Name: " << name << "\n"
        << "Employee Number: " << employeeNumber << std::endl;
}