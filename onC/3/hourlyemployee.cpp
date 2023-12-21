#include "hourlyemployee.h"

HourlyEmployee::HourlyEmployee() : Employee(), rate(0), hours(0)
{
}

HourlyEmployee::HourlyEmployee(string _name, string _ssn, int _rate, int _hours) : Employee(_name, _ssn), rate(_rate), hours(_hours)
{
}

int HourlyEmployee::getRate() const
{
    return rate;
}

int HourlyEmployee::getHours() const
{
    return hours;
}

void HourlyEmployee::setRate(int _rate)
{
    rate = _rate;
}

void HourlyEmployee::setHours(int _hours)
{
    hours = _hours;
}

void HourlyEmployee::printCheck()
{
    setPay(rate * hours);
    cout << "\n________________________________________________\n";
    cout << "Pay to the order of " << getName() << endl;
    cout << "The sum of " << getPay() << " Dollars\n";
    cout << "_________________________________________________\n";
    cout << "Check Stub: NOT NEGOTIABLE\n";
    cout << "Employee Number: " << getSSN() << endl;
    cout << "Hourly Employee. \nHours worked: " << hours << " Rate: " << rate << " Pay: " << getPay() << endl;
    cout << "_________________________________________________\n";
}