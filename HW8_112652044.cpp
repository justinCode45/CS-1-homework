/* Author:Justin Chen
 * Email Address:justin.sc12@nycu.edu.tw
 * HW Number:8
 * Description: A implementation of complex number.
 * Last Change: Dec 14, 2023
 * Anything special?
 *  1. implement +, -, *, /, - operator
 *  2. implement +=, -=, *=, /= operator
 *  3. can get real part, imaginary part, magnitude, argument, conjugate of a complex number
 *  4. implement pow function
 *  5. there is no unnecessary + in output
 *
 * Complier: g++ (Rev2, Built by MSYS2 project) 13.2.0 ,C++20
 *
 */
#define _USE_MATH_DEFINES // for M_PI
#include <iostream>
#include <cmath>

using namespace std;

class Complex
{
public:
    Complex(double _real, double _imag);
    Complex(double _real);
    Complex(const Complex &rhs);
    Complex();
    double real() const;
    double imag() const;
    double magnitude() const;
    double arg() const;
    Complex conj() const;
    void setReal(double _real);
    void setImag(double _imag);
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
    friend Complex pow(const Complex &base, int exp);

    // These are redundant, but I still put them in order to complete the homework requirements.
    // friend Complex operator+(const Complex &lhs, double rhs);
    // friend Complex operator+(const Complex &lhs, const Complex &rhs);
    //-------

private:
    double _real;
    double _imag;
};

Complex i(0, 1);

int main()
{
    Complex c1, c2(4), c3(3, 5), c4, c5, c6, c7, c8, c9;
    cout << "This program demonstrates the use of the Complex class." << endl;
    cout << "Enter a complex number: ";
    cin >> c4;
    cout << "\nOutput part 1:" << endl;
    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;
    cout << "c3 = " << c3 << endl;
    cout << "c4 = " << c4 << endl;
    cout << "c5 = " << c5 << endl;
    cout << "c6 = " << c6 << endl;
    cout << "c7 = " << c7 << endl;
    cout << "c8 = " << c8 << endl;
    cout << "c9 = " << c9 << endl;
    c5 = c1 + c2;  // scenario 1
    c6 = c3 + 20;  // scenario 2
    c7 = 100 + c4; // scenario 3
    c8 = c6 * c7;
    c9 = c8 * i;
    cout << "\nOutput part 2:" << endl;
    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;
    cout << "c3 = " << c3 << endl;
    cout << "c4 = " << c4 << endl;
    cout << "c5 = " << c5 << endl;
    cout << "c6 = " << c6 << endl;
    cout << "c7 = " << c7 << endl;
    cout << "c8 = " << c8 << endl;
    cout << "c9 = " << c9 << endl;
    cout << "\nOutput part 3:" << endl;
    if (c1 == c4)
        cout << "c1 and c4 are equal" << endl;
    else
        cout << "c1 and c4 are different" << endl;
    return 0;
}

Complex::Complex(double _real, double _imag) : _real(_real), _imag(_imag) {}

Complex::Complex(double _real) : _real(_real), _imag(0) {}

Complex::Complex() : _real(0), _imag(0) {}

Complex::Complex(const Complex &rhs) : _real(rhs._real), _imag(rhs._imag) {}

Complex Complex::operator+(const Complex &rhs) const
{
    return Complex(_real + rhs._real, _imag + rhs._imag);
}

Complex Complex::operator-(const Complex &rhs) const
{
    return Complex(_real - rhs._real, _imag - rhs._imag);
}

Complex Complex::operator*(const Complex &rhs) const
{
    return Complex(_real * rhs._real - _imag * rhs._imag, _real * rhs._imag + _imag * rhs._real);
}

Complex Complex::operator/(const Complex &rhs) const
{
    return Complex((_real * rhs._real + _imag * rhs._imag) / (rhs._real * rhs._real + rhs._imag * rhs._imag),
                   (_imag * rhs._real - _real * rhs._imag) / (rhs._real * rhs._real + rhs._imag * rhs._imag));
}

double Complex::real() const
{
    return _real;
}

double Complex::imag() const
{
    return _imag;
}

bool operator==(const Complex &lhs, const Complex &rhs)
{
    return (lhs._real == rhs._real) && (lhs._imag == rhs._imag);
}

ostream &operator<<(ostream &os, const Complex &rhs)
{
    if (rhs._imag == 0)
    {
        os << rhs._real;
        return os;
    }
    else if (rhs._real == 0)
    {
        os << rhs._imag << "i";
        return os;
    }
    else if (rhs._imag < 0)
    {
        os << rhs._real << " - " << -rhs._imag << "i";
        return os;
    }
    os << rhs._real << " + " << rhs._imag << "i";
    return os;
}

istream &operator>>(istream &is, Complex &rhs)
{
    is >> rhs._real >> rhs._imag;
    return is;
}

Complex operator+(double lhs, const Complex &rhs)
{
    return Complex(lhs + rhs._real, rhs._imag);
}

Complex operator-(double lhs, const Complex &rhs)
{
    return Complex(lhs - rhs._real, rhs._imag);
}

Complex operator*(double lhs, const Complex &rhs)
{
    return Complex(lhs * rhs._real, lhs * rhs._imag);
}

Complex operator/(double lhs, const Complex &rhs)
{
    return Complex(lhs * rhs._real / (rhs._real * rhs._real + rhs._imag * rhs._imag),
                   -lhs * rhs._imag / (rhs._real * rhs._real + rhs._imag * rhs._imag));
}

bool operator==(double lhs, const Complex &rhs)
{
    return (lhs == rhs._real) && (rhs._imag == 0);
}

Complex &Complex::operator=(const Complex &rhs)
{
    _real = rhs._real;
    _imag = rhs._imag;
    return *this;
}

Complex Complex::operator-() const
{
    return Complex(-_real, -_imag);
}

Complex &Complex::operator+=(const Complex &rhs)
{
    _real += rhs._real;
    _imag += rhs._imag;
    return *this;
}

Complex &Complex::operator-=(const Complex &rhs)
{
    _real -= rhs._real;
    _imag -= rhs._imag;
    return *this;
}

Complex &Complex::operator*=(const Complex &rhs)
{
    double temp = _real;
    _real = _real * rhs._real - _imag * rhs._imag;
    _imag = temp * rhs._imag + _imag * rhs._real;
    return *this;
}

Complex &Complex::operator/=(const Complex &rhs)
{
    double temp = _real;
    _real = (_real * rhs._real + _imag * rhs._imag) / (rhs._real * rhs._real + rhs._imag * rhs._imag);
    _imag = (_imag * rhs._real - temp * rhs._imag) / (rhs._real * rhs._real + rhs._imag * rhs._imag);
    return *this;
}

Complex pow(const Complex &base, int exp)
{
    if (exp == 0)
    {
        return Complex(1);
    }
    Complex result = base;
    for (int i = 1; i < exp; i++)
    {
        result *= base;
    }
    return result;
}

double Complex::magnitude() const
{
    return sqrt(_real * _real + _imag * _imag);
}

double Complex::arg() const
{
    if (_real == 0)
    {
        if (_imag > 0)
        {
            return M_PI / 2;
        }
        else if (_imag < 0)
        {
            return -M_PI / 2;
        }
        else
        {
            return 0;
        }
    }
    else if (_real > 0)
    {
        return atan(_imag / _real);
    }
    else
    {
        if (_imag >= 0)
        {
            return atan(_imag / _real) + M_PI;
        }
        else
        {
            return atan(_imag / _real) - M_PI;
        }
    }
}

Complex Complex::conj() const
{
    return Complex(_real, -_imag);
}

void Complex::setReal(double _real)
{
    this->_real = _real;
}

void Complex::setImag(double _imag)
{
    this->_imag = _imag;
}

// These are redundant, but I still put them in order to complete the homework requirements.
// Complex operator+(const Complex &lhs, double rhs)
// {
//     return Complex(lhs._real + rhs, lhs._imag);
// }

// Complex operator+(const Complex &lhs, const Complex &rhs)
// {
//     return Complex(lhs._real + rhs._real, lhs._imag + rhs._imag);
// }
//-------