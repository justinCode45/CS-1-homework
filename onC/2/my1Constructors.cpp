#include <iostream>

using namespace std;

class DayofYear
{
public:
    DayofYear();
    DayofYear(int m, int d);
    DayofYear(int m);
    void input();
    void output();
    int getMonth();
    int getDay();
    void setMonth(int m);
    void setDay(int d);
    bool operator==(DayofYear obj);

private:
    int month;
    int day;
    void checkDate();
};

int main()
{
    DayofYear day1, day2(12), today(12,8);
    cout << "After declaration:\n";
    cout << "day1 = ";
    day1.output();
    cout << "day2 = ";
    day2.output();
    cout << "today = ";
    today.output();

    day1 = DayofYear(2, 21);
    cout << "After day1 is changed:\n";
    day1.output();

    day2 = DayofYear();
    cout << "After day2 is changed:\n";
    day2.output();

    return 0;
}

DayofYear::DayofYear() : month(1), day(1)
{
}

DayofYear::DayofYear(int m, int d)
{
    month = m;
    day = d;
    checkDate();
}

DayofYear::DayofYear(int m)
{
    month = m;
    day = 1;
    checkDate();
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

bool DayofYear::operator==(DayofYear obj)
{
    return (month == obj.month && day == obj.day);
}