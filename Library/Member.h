#ifndef MEMBER_H
#define MEMBER_H

#include "Loan.h"

class Member {

protected:
	char* name;
	char* memberNumber;
	char* phoneNumber;
	Loan* memberLoan;

public:
	Member(); // Default constructor
	Member(const char* name, const char* memberNumber, const char* phoneNumber, Loan& memberLoan);
	Member(const Member& other);
	Member(Member&& other) noexcept;
	const Member& operator=(const Member& other);
	virtual ~Member();

	// getters
	const char* getName() const;
	const char* getMemNumber() const;
	const char* getPhoneNumber() const;
	Loan* getLoanMember() const;

	// setters
	bool setName(const char* name);
	bool setMemNumber(const char* memNumber);
	bool setPhoneNumber(const char* phoneNumber);

	void printMember() const;
};

#endif // MEMBER_H