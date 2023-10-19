/* File Name:HW4_112652044.cpp
 * Author:Justin Chen
 * Email Address:justin.sc12@nycu.edu.tw
 * HW Number:3
 * Description: The purpose of this program is to give hairstyle suggestions
 *               through the user's answers to questions.
 * Last Change:Sep.23,2023
 * Anything special?
 * 1.Output text coloring.
 * 2.Input error detection.
 * Complier:gcc version 13.1.0 (Rev7, Built by MSYS2 project),201703
 */
#include <iostream>
#include <limits>
#include <string>
#include <cmath>
#include <tuple>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <memory>

// clear istream
#define clearCin std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
// define some common outputs
#define CSI "\x1b["
#define color(in, c) CSI + to_string((int)c) + 'm' + in + CSI "0m"
#define inputSign color(">> ", SGR::brightYellow)
#define echo "[" color("Echoing", SGR::green) "] "
#define inputError "[" color("Input error", SGR::brightRed) "] "
//--------------------------
using namespace std;

// age height weight
typedef tuple<int, double, double> Tidd;
const double CM_PRE_INCH = 2.54;
const double KG_PRE_POUND = 0.454;
// ANSI SGR
enum class SGR
{
    black = 30,
    red,
    green,
    yellow,
    blue,
    magenta,
    cyan,
    white,
    brightBlack = 90,
    brightRed,
    brightGreen,
    brightYellow,
    brightBlue,
    brightMagenta,
    brightCyan,
    brightWhite
};

/**
 * @brief A template function that takes a function object, a prompt message, and an error message as input.
 *        It prompts the user to input a value of type T, checks if the input is valid using the provided function object,
 *        and returns the input if it is valid. If the input is invalid, it displays the error message and prompts the user again.
 *
 * @tparam T The type of the input value.
 * @param check A function object that takes a value of type T as input and returns a boolean indicating whether the input is valid or not.
 * @param prompt The prompt message to display to the user.
 * @param eprompt The error message to display if the input is invalid.
 * @return T The valid input value of type T.
 */
template <class T>
T getInput(function<bool(T)> check, string prompt, string eprompt)
{
    T inp;
    cout << prompt;
    while (1)
    {
        cout << CSI + to_string((int)SGR::brightYellow) + "m";
        cin >> inp;
        cout << CSI "0m";

        if (cin.fail() || !check(inp))
        {
            cin.clear();
            cout << CSI "1F" CSI "0J" << eprompt;
            clearCin;
            continue;
        }
        clearCin;
        break;
    }
    return inp;
}

struct person
{
    int age;
    double height;
    double weight;
    person(Tidd x)
    {
        age = get<0>(x);
        height = get<1>(x)/CM_PRE_INCH;
        weight = get<2>(x)/KG_PRE_POUND;
    }
};

double hatSize(unique_ptr<person> &p);
double jacketSize(unique_ptr<person> &p);
double waistSize(unique_ptr<person> &p);
Tidd userInput();
void echoInput(Tidd in);

int main()
{
    cout << "purpose" << endl;

    int n;
    n = getInput<int>(
        [](int x) -> bool
        { return x > 0; },
        "Enter the maximum of repetitons (an int): ",
        "Enter the maximum of repetitons (" color("an int", SGR::brightRed) "): ");

    for (int i = 0; i < n; i++)
    {
        Tidd data = userInput();
        echoInput(data);
        auto p = make_unique<person>(data);

        double hat = hatSize(p);
        double jacket = jacketSize(p);
        double waist = waistSize(p);

        cout << fixed << setprecision(2);
        cout << "Hat Size=" << hat << ","
             << "Jacket Size=" << jacket << ","
             << "Waist in inches=" << waist
             << endl;
    }

    return 0;
}

Tidd userInput()
{
    auto check = [](Tidd &in) -> bool
    {
        return get<0>(in) > 0 && get<1>(in) > 0 && get<2>(in);
    };

    Tidd in;
    cout << "Enter height (int cm) and weight (in Kg) and age (three ints) :";
    while (1)
    {
        cout << CSI + to_string((int)SGR::brightYellow) + "m";
        cin >> get<1>(in) >> get<2>(in) >> get<0>(in);
        cout << CSI "0m";
        if (cin.fail() || check(in))
        {
            cin.clear();
            cout << CSI "1F" CSI "0J"
                 << "Enter height (int cm) and weight (in Kg) and age (" color("three ints", SGR::brightRed) ") :";
            clearCin;
            continue;
        }
        clearCin;
        break;
    }
    return in;
}
void echoInput(Tidd in)
{
    cout << echo << "you entered:"
         << get<0>(in) << " "
         << get<1>(in) << " "
         << get<2>(in) << endl;
}

double hatSize(unique_ptr<person> &p)
{
    
}
double jacketSize(unique_ptr<person> &p)
{
}
double waistSize(unique_ptr<person> &p)
{
}