#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Base.h"

class Employee : public Base {
private:
    int salary;

public:
    Employee() : salary(0) {}

    void SetSalary(int newSalary) {
        salary = newSalary;
    }

    virtual void DisplayRecord() const override {
        std::cout << "Employee Name: " << GetName() << ", Salary: $" << salary << std::endl;
    }
};

#endif // EMPLOYEE_H
