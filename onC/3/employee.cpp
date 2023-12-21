#include "employee.h"
#include <iostream>
#include <string>

using namespace std;

Employee::Employee() : name("No name yet"), ssn("No number yet"), pay(0)
{
}

Employee::Employee(string _name, string _ssn) : name(_name), ssn(_ssn), pay(0)
{
}

string Employee::getName() const
{
    return name;
}

string Employee::getSSN() const
{
    return ssn;
}

int Employee::getPay() const
{
    return pay;
}

void Employee::setName(string _name)
{
    name = _name;
}

void Employee::setSSN(string _ssn)
{
    ssn = _ssn;
}

void Employee::setPay(int _pay)
{
    pay = _pay;
}

void Employee::printCheck() const
{
    cout << "\nERROR: printCheck FUNCTION CALLED FOR AN \n"
         << "UNDIFFERENTIATED EMPLOYEE. Aborting the program.\n"
         << "Check with the author of the program about this bug.\n";
    exit(1);
}
