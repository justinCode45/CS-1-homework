#include <iostream>
#include "hourlyemployee.h"
#include "salariedemployee.h"

using namespace std;

int main()
{
    HourlyEmployee joe;
    SalariedEmployee boss("Mr. Big Shot", "987-65-4321", 10500);

    joe.setName("Mighty Joe");
    joe.setSSN("123-45-6789");
    joe.setRate(158);
    joe.setHours(40);

    cout << "Check for " << joe.getName() << " for " << joe.getHours() << " hours.\n";
    joe.printCheck();
    cout << endl;

    cout << "Check for " << boss.getName() << endl;
    boss.printCheck();
    cout << endl;

    return 0;
}