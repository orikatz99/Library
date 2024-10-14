#ifndef MEMBEREMPLOYEE_H
#define MEMBEREMPLOYEE_H

#include "Member.h"
#include "Employee.h"

class MemberEmployee : public Member, public Employee {

private:
    int numberOfBenefits;

public:
    MemberEmployee(); // Default constructor
    MemberEmployee(const char* name, const Member& member, const Employee& employee, int numberOfBenefits);
    const MemberEmployee& operator=(const MemberEmployee& other);

    //getters
    int getNumberOfBenefits() const;

    // setters
    bool setNumberOfBenefits(int numberOfBenefits);

    void printMemberEmployee() const;
};

#endif // MEMBEREMPLOYEE_H