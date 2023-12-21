#ifndef HOURLYEMPLOYEE_H
#define HOURLYEMPLOYEE_H

#include "employee.h"
#include <string>
#include <iostream>

class HourlyEmployee : public Employee
{
public:
    HourlyEmployee();
    HourlyEmployee(string _name, string _ssn, int _rate, int _hours);
    int getRate() const;
    int getHours() const;
    void setRate(int _rate);
    void setHours(int _hours);
    void printCheck();
private:
    int rate;
    int hours;
};

#endif