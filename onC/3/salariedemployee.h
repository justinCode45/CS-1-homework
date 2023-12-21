#ifndef SALARIEDEMPLOYEE_H
#define SALARIEDEMPLOYEE_H

#include "employee.h"
#include <iostream>
class SalariedEmployee : public Employee
{
public:
    SalariedEmployee();
    SalariedEmployee(string _name, string _ssn, int _salary);
    int getSalary() const;
    void setSalary(int _salary);
    void printCheck();
private:
    int salary;
};

#endif