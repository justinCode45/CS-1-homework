#include <iostream>

using namespace std;

class Money
{
public:
    Money();
    Money(int _dollars);
    int getDollars() const;
    void setDollars(int _dollars);

    friend Money operator+(const Money &amount1, const Money &amount2);
    Money operator+(int n);
    friend Money operator+(int n, const Money &amount);

    friend Money operator-(const Money &amount);

    friend istream &operator>>(istream &ins, Money &amount);
    friend ostream &operator<<(ostream &outs, const Money &amount);

    ostream &operator<<(ostream &outs);

private:
    int dollars;
};

int main()
{
    Money m1, m2, m;
    cout << "Enter m1: ";
    cin >> m1;
    cout << "Enter m2: ";
    cin >> m2;
    cout << "Enter m: ";
    cin >> m;

    cout << "m1 + m2 = " << m1 + m2 << endl;
    cout << "m1 + 5 = " << m1 + 5 << endl;
    cout << "5 + m1 = " << 5 + m1 << endl;

    (m1 + m2).operator<<(cout) << endl;
    (m1+300).operator<<(cout) << endl;
    (300+m1).operator<<(cout) << endl;

    (m1+m2) << cout << endl;
    (m1+300) << cout << endl;
    (300+m1) << cout << endl;

    return 0;
}

Money::Money()
{
    dollars = 0;
}

Money::Money(int _dollars)
{
    dollars = _dollars;
}

int Money::getDollars() const
{
    return dollars;
}

void Money::setDollars(int _dollars)
{
    dollars = _dollars;
}

Money operator+(const Money &amount1, const Money &amount2)
{
    Money temp(amount1.dollars + amount2.dollars);
    return temp;
}

Money Money::operator+(int n)
{
    Money temp(this->dollars + n);
    return temp;
}

Money operator+(int n, const Money &amount)
{
    Money temp(amount.dollars + n);
    return temp;
}

Money operator-(const Money &amount)
{
    Money temp(-amount.dollars);

    return temp;
}

istream &operator>>(istream &ins, Money &amount)
{
    ins >> amount.dollars;
    return ins;
}

ostream &operator<<(ostream &outs, const Money &amount)
{
    outs << amount.dollars;
    return outs;
}

ostream &Money::operator<<(ostream &outs)
{
    outs << this->dollars;
    return outs;
}