#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

#include "MemberEmployee.h"

// Default constructor
MemberEmployee::MemberEmployee() : Member(), Employee(), numberOfBenefits(0) {}

// Parameterized constructor
MemberEmployee::MemberEmployee(const char* name, const Member& member, const Employee& employee, int numberOfBenefits)
    : Member(name, member.getMemNumber(), member.getPhoneNumber(), *member.getLoanMember()),
    Employee(name, employee.getEmpNumber()),
    numberOfBenefits(numberOfBenefits) {}

// Assignment operator
const MemberEmployee& MemberEmployee::operator=(const MemberEmployee& other)
{
    if (this != &other) {
        // Assign base class parts
        Member::operator=(other);
        Employee::operator=(other);

        // Assign derived class part
        numberOfBenefits = other.numberOfBenefits;
    }
    return *this;
}

// getters
int MemberEmployee::getNumberOfBenefits() const
{

    return numberOfBenefits;
}

// setters
bool MemberEmployee::setNumberOfBenefits(int numberOfBenefits)
{
    if (numberOfBenefits < 0)
        return false;

    this->numberOfBenefits = numberOfBenefits;
    return true;
}

void MemberEmployee::printMemberEmployee() const
{

    Member::printMember();
    Employee::printEmployee();
    std::cout << "Number of Benefits: " << numberOfBenefits << std::endl;
}
