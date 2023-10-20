/* File Name:HW4_112652044.cpp
 * Author:Justin Chen
 * Email Address:justin.sc12@nycu.edu.tw
 * HW Number:4
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

//  height weight age
typedef tuple<double, double, int> Tddi;
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
 * @brief This function takes a function object, a prompt message, and an error message as input.
 *        It prompts the user to input values of type T..., and checks if the input values satisfy the condition specified by the function object.
 *        If the input values do not satisfy the condition, it prompts the user to input again until the condition is satisfied.
 * @tparam T The types of the input values.
 * @param check A function object that takes a tuple of type T... as input and returns a bool indicating whether the input values satisfy a certain condition.
 * @param prompt A string that represents the prompt message.
 * @param eprompt A string that represents the error message.
 * @return A tuple of type T... that contains the input values that satisfy the condition specified by the function object.
 */
template <class... T>
tuple<T...> getInput(function<bool(tuple<T...> &)> check, string prompt, string eprompt);

struct person
{
    int age;
    double height;
    double weight;
    person(double _height, double _weight, int _age)
    {
        age = _age;
        height = _height / CM_PRE_INCH;
        weight = _weight / KG_PRE_POUND;
    }
};

double hatSize(const unique_ptr<person> &p);
double jacketSize(const unique_ptr<person> &p);
double waistSize(const unique_ptr<person> &p);

void echoInput(double _height, double _weight, int _age);

int main()
{
    cout << "The purpose of this program is to suggest hats, "
         << "jackets, and waist sizes based on the input height and weight." << endl;

    auto [n] = getInput<int>(
        (function<bool(tuple<int> &)>)[](tuple<int> x)->bool { return get<0>(x) > 0; },
        "Enter the maximum of repetitons (an int): ",
        "Enter the maximum of repetitons (" color("an int", SGR::brightRed) "): ");

    cout<<endl;
    
    for (int i = 0; i < n; i++)
    {
        auto [height, weight, age] = getInput<double, double, int>(
            (function<bool(Tddi &)>)[](Tddi & in)->bool {
                return get<0>(in) > 0 && get<1>(in) > 0 && get<2>(in) > 0;
            },
            "Enter height (int cm) and weight (in Kg) and age (3 postive ints) :",
            "Enter height (int cm) and weight (in Kg) and age (" color("three ints", SGR::brightRed) ") :");

        echoInput(height, weight, age);
        auto p = make_unique<person>(height, weight, age);

        double hat = hatSize(p);
        double jacket = jacketSize(p);
        double waist = waistSize(p);

        cout << fixed << setprecision(2);
        cout << "Hat Size=" << hat << ","
             << "Jacket Size=" << jacket << ","
             << "Waist in inches=" << waist
             << endl;

        cout << endl;
    }

    return 0;
}

template <class... T>
tuple<T...> getInput(function<bool(tuple<T...> &)> check, string prompt, string eprompt)
{
    tuple<T...> inp;
    cout << prompt;
    while (1)
    {
        cout << CSI + to_string((int)SGR::brightYellow) + "m";
        apply([](auto &...x)
              { (cin >> ... >> x); },
              inp);

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

void echoInput(double _height, double _weight, int _age)
{
    cout << echo << "you entered:"
         << _height << " "
         << _weight << " "
         << _age << endl;
}

double hatSize(const unique_ptr<person> &p)
{
    return (p->weight / p->height) * 2.9;
}

double jacketSize(const unique_ptr<person> &p)
{
    return (p->height * p->weight) / 288.f + (p->age - 30) / 10 * 0.125;
}

double waistSize(const unique_ptr<person> &p)
{
    return p->weight / 5.7 + (p->age - 28) / 2 * 0.1;
}