/* Author:Justin Chen
 * Email Address:justin.sc12@nycu.edu.tw
 * HW Number:7
 * Description: .
 * Last Change: Nov.9,2023
 * Anything special?
 *  1. color output
 *  2. More specical functions are in other file.
 *
 * Complier: g++ (Rev2, Built by MSYS2 project) 13.2.0 ,C++20
 * 
 */
#include <iostream>

using namespace std;

class Complex
{
public:
    Complex(double _real, double _imag);
    Complex(double _real);
    Complex(const Complex &rhs);
    Complex();
    double getReal() const ;
    double getImag() const ;
    Complex operator+(const Complex &rhs) const;
    Complex operator-(const Complex &rhs) const;
    Complex operator*(const Complex &rhs) const;
    Complex operator/(const Complex &rhs) const;
    Complex operator-() const;
    
    Complex &operator+=(const Complex &rhs);
    Complex &operator-=(const Complex &rhs);
    Complex &operator*=(const Complex &rhs);
    Complex &operator/=(const Complex &rhs);

    Complex &operator=(const Complex &rhs);

    friend bool operator==(const Complex &lhs, const Complex &rhs);

    friend ostream &operator<<(ostream &os, const Complex &rhs);
    friend istream &operator>>(istream &is, Complex &rhs);
    friend Complex operator+(double lhs, const Complex &rhs);
    friend Complex operator-(double lhs, const Complex &rhs);
    friend Complex operator*(double lhs, const Complex &rhs);
    friend Complex operator/(double lhs, const Complex &rhs);
    friend bool operator==(double lhs, const Complex &rhs);

private:
    double real;
    double imag;
};

Complex i(0, 1);

int main()
{
    Complex a(1, 2);
    Complex b(3, 4);
    Complex c = b + 5 * i;
    b = a / 10;
    b = 10 / a;
    b = 10 + a;
    b = a + 10;
    cout << a << endl;
    cout << b << endl;
    cout << c << endl;

    return 0;
}

Complex::Complex(double _real, double _imag) : real(_real), imag(_imag) {}

Complex::Complex(double _real) : real(_real), imag(0) {}

Complex::Complex() : real(0), imag(0) {}

Complex::Complex(const Complex &rhs) : real(rhs.real), imag(rhs.imag) {}

Complex Complex::operator+(const Complex &rhs) const
{
    return Complex(real + rhs.real, imag + rhs.imag);
}

Complex Complex::operator-(const Complex &rhs) const
{
    return Complex(real - rhs.real, imag - rhs.imag);
}

Complex Complex::operator*(const Complex &rhs) const
{
    return Complex(real * rhs.real - imag * rhs.imag, real * rhs.imag + imag * rhs.real);
}

Complex Complex::operator/(const Complex &rhs) const
{
    return Complex((real * rhs.real + imag * rhs.imag) / (rhs.real * rhs.real + rhs.imag * rhs.imag),
                   (imag * rhs.real - real * rhs.imag) / (rhs.real * rhs.real + rhs.imag * rhs.imag));
}

double Complex::getReal() const
{
    return real;
}

double Complex::getImag() const
{
    return imag;
}

bool operator==(const Complex &lhs, const Complex &rhs)
{
    return (lhs.real == rhs.real) && (lhs.imag == rhs.imag);
}

ostream &operator<<(ostream &os, const Complex &rhs)
{
    if (rhs.imag == 0)
    {
        os << rhs.real;
        return os;
    }
    else if (rhs.real == 0)
    {
        os << rhs.imag << "i";
        return os;
    }
    else if (rhs.imag < 0)
    {
        os << rhs.real << " - " << -rhs.imag << "i";
        return os;
    }
    os << rhs.real << " + " << rhs.imag << "i";
    return os;
}

istream &operator>>(istream &is, Complex &rhs)
{
    is >> rhs.real >> rhs.imag;
    return is;
}

Complex operator+(double lhs, const Complex &rhs)
{
    return Complex(lhs + rhs.real, rhs.imag);
}

Complex operator-(double lhs, const Complex &rhs)
{
    return Complex(lhs - rhs.real, rhs.imag);
}

Complex operator*(double lhs, const Complex &rhs)
{
    return Complex(lhs * rhs.real, lhs * rhs.imag);
}

Complex operator/(double lhs, const Complex &rhs)
{
    return Complex(lhs * rhs.real / (rhs.real * rhs.real + rhs.imag * rhs.imag),
                   -lhs * rhs.imag / (rhs.real * rhs.real + rhs.imag * rhs.imag));
}

bool operator==(double lhs, const Complex &rhs)
{
    return (lhs == rhs.real) && (rhs.imag == 0);
}

Complex &Complex::operator=(const Complex &rhs)
{
    real = rhs.real;
    imag = rhs.imag;
    return *this;
}

Complex Complex::operator-() const
{
    return Complex(-real, -imag);
}

Complex &Complex::operator+=(const Complex &rhs)
{
    real += rhs.real;
    imag += rhs.imag;
    return *this;
}

Complex &Complex::operator-=(const Complex &rhs)
{
    real -= rhs.real;
    imag -= rhs.imag;
    return *this;
}

Complex &Complex::operator*=(const Complex &rhs)
{
    double temp = real;
    real = real * rhs.real - imag * rhs.imag;
    imag = temp * rhs.imag + imag * rhs.real;
    return *this;
}

Complex &Complex::operator/=(const Complex &rhs)
{
    double temp = real;
    real = (real * rhs.real + imag * rhs.imag) / (rhs.real * rhs.real + rhs.imag * rhs.imag);
    imag = (imag * rhs.real - temp * rhs.imag) / (rhs.real * rhs.real + rhs.imag * rhs.imag);
    return *this;
}

