#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee {

protected:
	char* name;
	char* employeeNumber;

public:
	Employee() : name(nullptr), employeeNumber(nullptr) {} // Default constructor
	Employee(const char* name, const char* employeeNumber);
	Employee(const Employee& other);
	Employee(Employee&& other) noexcept;
	const Employee& operator=(const Employee& other);
	virtual ~Employee();

	// getters
	const char* getName() const;
	const char* getEmpNumber() const;

	// setters
	bool setName(const char* name);
	bool setEmpNumber(const char* empNumber);

	void printEmployee() const;
};

#endif // EMPLOYEE_H