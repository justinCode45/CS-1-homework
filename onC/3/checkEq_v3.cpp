#include <iostream>

using namespace std;

class DayofYear
{
public:
    void input();
    void output();
    int getMonth();
    int getDay();
    void setMonth(int m);
    void setDay(int d);

private:
    int month;
    int day;
    void checkDate();
};
bool equal(DayofYear &obj1, DayofYear &obj2);

int main()
{
    DayofYear today, birthday, testingDay;

    cout << "Enter today's date:\n";
    today.input();
    cout << "Today's date is ";
    today.output();

    birthday.setMonth(2);
    birthday.setDay(9);
    cout << "Birthday date is ";
    birthday.output();

    if (equal(today, birthday))
        cout << "Happy Birthday!\n";
    else
        cout << "Happy unbirthday!\n";

    testingDay = birthday;
    cout << "Testing day is ";
    testingDay.output();

    return 0;
}

void DayofYear::input()
{
    cout << "Enter the month as a number: ";
    cin >> month;
    cout << "Enter the day of the month: ";
    cin >> day;
    checkDate();
}

void DayofYear::output()
{
    cout << "month = " << month << ", day = " << day << endl;
}

int DayofYear::getMonth()
{
    return month;
}

int DayofYear::getDay()
{
    return day;
}

void DayofYear::setMonth(int m)
{
    month = m;
    checkDate();
}

void DayofYear::setDay(int d)
{
    day = d;
    checkDate();
}

void DayofYear::checkDate()
{
    if ((month < 1) || (month > 12) || (day < 1) || (day > 31))
    {
        cout << "Illegal date. Aborting program.\n";
        exit(1);
    }
}

bool equal(DayofYear &obj1, DayofYear &obj2)
{
    if (obj1.getMonth() == obj2.getMonth() && obj1.getDay() == obj2.getDay())
        return true;
    else
        return false;
}
