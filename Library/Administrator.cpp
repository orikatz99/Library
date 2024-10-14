#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

#include "Administrator.h"

Administrator::Administrator(const Employee& employee)
    : Employee(employee), permissionLevel(1), employeeArr(nullptr), employeeCount(0) {}

// Copy constructor
Administrator::Administrator(const Administrator& other)
    : Employee(other), permissionLevel(other.permissionLevel), employeeArr(nullptr), employeeCount(other.employeeCount)
{
    if (other.employeeArr) {
        employeeArr = new Employee[employeeCount];
        for (int i = 0; i < employeeCount; ++i) {
            employeeArr[i] = other.employeeArr[i];
        }
    }
}

// Move constructor
Administrator::Administrator(Administrator&& other) noexcept
    : Employee(std::move(other)), permissionLevel(other.permissionLevel), employeeArr(other.employeeArr), employeeCount(other.employeeCount)
{
    other.employeeArr = nullptr;
    other.employeeCount = 0;
}

Administrator& Administrator::operator=(const Administrator& other)
{
    if (this != &other) {
        Employee::operator=(other);
        permissionLevel = other.permissionLevel;

        Employee* newEmployeeArr = nullptr;
        if (other.employeeArr) {
            newEmployeeArr = new Employee[other.employeeCount];
            for (int i = 0; i < other.employeeCount; ++i) {
                newEmployeeArr[i] = other.employeeArr[i];
            }
        }
        delete[] employeeArr;

        employeeArr = newEmployeeArr;
        employeeCount = other.employeeCount;
    }
    return *this;
}

// Destructor
Administrator::~Administrator()
{
    delete[] employeeArr;
}

// Getters
int Administrator::getPermissionLevel() const
{
    return permissionLevel;
}
Employee* Administrator::getEmployeeArr() const
{
    return employeeArr;
}
int Administrator::getEmployeeCount() const
{
    return employeeCount;
}

// Setters
bool Administrator::setPermissionLevel(int permissionLevel)
{
    this->permissionLevel = permissionLevel;
    return true;
}
bool Administrator::setEmployeeArr(const Employee* newEmployeeArr, int newEmployeeCount)
{
    if (newEmployeeArr == nullptr) {
        return false;
    }

    delete[] employeeArr;

    employeeArr = new Employee[newEmployeeCount];
    for (int i = 0; i < newEmployeeCount; ++i) {
        employeeArr[i] = newEmployeeArr[i];
    }
    employeeCount = newEmployeeCount;

    return true;
}
bool Administrator::setEmployeeCount(int newEmployeeCount)
{
    if (newEmployeeCount < 0) {
        return false;
    }
    employeeCount = newEmployeeCount;
    return true;
}

void Administrator::printAdministrator() const
{
    printEmployee();
    std::cout << "Permission Level: " << permissionLevel << std::endl;
}

Administrator Administrator::addAdministrator(const Employee& employee)
{
    return Administrator(employee);
}

void Administrator::addEmployee(const Employee& newEmployee)
{
    // Check if an employee with the same employee number already exists
    for (int i = 0; i < employeeCount; ++i) {
        if (strcmp(employeeArr[i].getEmpNumber(), newEmployee.getEmpNumber()) == 0) {
            cout << "Employee with the same employee number already exists." << endl;
            return;
        }
    }

    Employee* newArr = new Employee[employeeCount + 1];
    if (!newArr) {
        cout << "Memory allocation failed." << endl;
        return;
    }

    for (int i = 0; i < employeeCount; ++i) {
        newArr[i] = employeeArr[i];
    }
    newArr[employeeCount] = newEmployee;

    delete[] employeeArr;

    employeeArr = newArr;
    ++employeeCount;
}

void Administrator::showEmployees() const
{
    if (employeeCount == 0)
        std::cout << "\nThere are currently no employees for the library" << std::endl;
    else
    {
        std::cout << "Our Library has " << employeeCount << " employees:" << std::endl;
        for (int i = 0; i < employeeCount; ++i)
        {
            std::cout << "#" << i + 1 << std::endl;
            employeeArr[i].printEmployee();
            cout << "\n";
        }
    }
}

Employee* Administrator::findEmployeeByName(Employee* EmployeeArr, int count, const char* name) const
{
    for (int i = 0; i < count; ++i)
    {
        if (strcmp(EmployeeArr[i].getName(), name) == 0)
        {
            return &EmployeeArr[i]; // Return a clone to avoid object slicing
        }
    }
    return nullptr;
}
