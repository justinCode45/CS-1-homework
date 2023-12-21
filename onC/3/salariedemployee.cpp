#include "salariedemployee.h"

SalariedEmployee::SalariedEmployee() : Employee(), salary(0)
{
}

SalariedEmployee::SalariedEmployee(string _name, string _ssn, int _salary) : Employee(_name, _ssn), salary(_salary)
{
}

int SalariedEmployee::getSalary() const
{
    return salary;
}

void SalariedEmployee::setSalary(int _salary)
{
    salary = _salary;
}

void SalariedEmployee::printCheck()
{
    setPay(salary);
    cout << "\n________________________________________________\n";
    cout << "Pay to the order of " << getName() << endl;
    cout << "The sum of " << getPay() << " Dollars\n";
    cout << "_________________________________________________\n";
    cout << "Check Stub: NOT NEGOTIABLE\n";
    cout << "Employee Number: " << getSSN() << endl;
    cout << "Salaried Employee. Regular Pay: " << salary << endl;
    cout << "_________________________________________________\n";
}
