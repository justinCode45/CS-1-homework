#include <iostream>
using namespace std;
class DTime
{
public:
    DTime();
    DTime(int _hour, int _minute);
    void advance(int _hour, int _minute);
    void advance(int _minute);
    friend bool operator==(const DTime& t1, const DTime& t2);
    friend ostream& operator<<(ostream& out, const DTime& t);
    friend istream& operator>>(istream& in, DTime& t);
private:
    int hour;
    int minute;
};
