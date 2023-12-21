#include "./dtime.h"

using namespace std;

DTime::DTime() : hour(0), minute(0)
{
}

DTime::DTime(int _hour, int _minute) : hour(_hour), minute(_minute)
{
}

void DTime::advance(int _hour, int _minute)
{
    minute += _minute;
    hour += _hour + minute / 60;
    minute %= 60;
    hour %= 24;
}

void DTime::advance(int _minute)
{
    advance(0, _minute);
}

bool operator==(const DTime& t1, const DTime& t2)
{
    return t1.hour == t2.hour && t1.minute == t2.minute;
}

ostream& operator<<(ostream& out, const DTime& t)
{
    if (t.hour < 10)
        out << "0";
    out << t.hour << ":";
    if (t.minute < 10)
        out << "0";
    out << t.minute;

    return out;
}

istream& operator>>(istream& in, DTime& t)
{   
    int base = '0';
    char h1, h2, c, m1, m2;
    cout << "Enter time in format HH:MM: ";
    in >> h1 >> h2 >> c >> m1 >> m2;
    t.hour = (h1 - base) * 10 + (h2 - base);
    t.minute = (m1 - base) * 10 + (m2 - base);
    return in;
}
