#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include "Employee.h"

class Administrator : public Employee {

private:
    int permissionLevel;
    Employee* employeeArr;
    int employeeCount;

public:
    Administrator(const Employee& employee);
    Administrator(const Administrator& other);
    Administrator(Administrator&& other) noexcept;
    Administrator& operator=(const Administrator& other);
    ~Administrator();

    // Getters
    int getPermissionLevel() const;
    Employee* getEmployeeArr() const;
    int getEmployeeCount() const;

    // Setters
    bool setPermissionLevel(const int permissionLevel);
    bool setEmployeeArr(const Employee* newEmployeeArr, int newEmployeeCount);
    bool setEmployeeCount(int newEmployeeCount);

    void printAdministrator() const;
    static Administrator addAdministrator(const Employee& employee);
    Employee* findEmployeeByName(Employee* EmployeeArr, int count, const char* name) const;

    void addEmployee(const Employee& newEmployee);
    void showEmployees() const;
};

#endif // ADMINISTRATOR_H

