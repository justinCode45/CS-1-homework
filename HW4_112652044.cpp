/* File Name:HW4_112652044.cpp
 * Author:Justin Chen
 * Email Address:justin.sc12@nycu.edu.tw
 * HW Number:4
 * Description: The purpose of this program is to suggest hats,
 *              jackets, and waist sizes based on the input height and weight.
 * Last Change:Oct.21,2023
 * Anything special?
 * 1.Output text coloring.
 * 2.Input error detection.
 *
 *
 * Complier: g++ (Rev2, Built by MSYS2 project) 13.2.0 ,C++17
 *           g++ (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0 ,C++17
 *           g++ (tdm64-1) 9.2.0 ,C++17 (Embarcadero Dev-C++)
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
#include <sstream>
#include <csignal>
#include <thread>

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
 * @brief Reads input from the user and returns a tuple of the input values.
 *
 * @tparam T The types of the input values.
 * @param check A function that checks if the input values are valid.
 * @param prompt The prompt message to display to the user.
 * @param eprompt The error message to display if the input values are invalid.
 * @return tuple<T...> A tuple of the input values.
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

// handler for ctrl+c
void signalHandler(int signum);

void echoInput(double _height, double _weight, int _age);

int main()
{
    signal(SIGINT, signalHandler);

    cout << "The purpose of this program is to suggest hats, "
         << "jackets, and waist sizes based on the input height and weight." << endl;

    auto [n] = getInput<int>(
        (function<bool(tuple<int> &)>)[](tuple<int> x)->bool { return get<0>(x) > 0; },
        "Enter the maximum of repetitons (an int): ",
        "Enter the maximum of repetitons (" color("an int", SGR::brightRed) "): ");

    cout << endl;

    for (int i = 0; i < n; i++)
    {
        auto [height, weight, age] =
            getInput<double, double, int>(
                (function<bool(Tddi &)>)[](Tddi & in)->bool {
                    return get<0>(in) > 0 && get<1>(in) > 0 && get<2>(in) > 0;
                },
                "Enter " color("height", SGR::brightWhite) " (in cm) and " color("weight", SGR::brightWhite) " (in Kg) and " color("age", SGR::brightWhite) " (3 postive ints) :",
                "Enter " color("height", SGR::brightWhite) " (in cm) and " color("weight", SGR::brightWhite) " (in Kg) and " color("age", SGR::brightWhite) " (" color("3 postive ints", SGR::brightRed) ") :");

        echoInput(height, weight, age);
        auto p = make_unique<person>(height, weight, age);

        double hat = hatSize(p);
        double jacket = jacketSize(p);
        double waist = waistSize(p);

        cout << fixed << setprecision(2);
        cout << "Hat Size        : " << hat << endl
             << "Jacket Size     : " << jacket << endl
             << "Waist in inches : " << waist << endl;

        cout << endl;
    }

    return 0;
}

template <class... T>
tuple<T...> getInput(function<bool(tuple<T...> &)> check, string prompt, string eprompt)
{
    tuple<T...> inp;

    cout << prompt << flush;
    while (1)
    {
        stringstream ssin;
        string rawInput;

        cout << CSI + to_string((int)SGR::brightYellow) + "m" << flush;

        getline(cin, rawInput);
        ssin << rawInput;
        cout << CSI "0m" << flush;

        apply([&ssin](auto &...x)
              { (ssin >> ... >> x); },
              inp);

        this_thread::sleep_for(chrono::milliseconds(1));

        if (ssin.rdbuf()->in_avail() != 0 || ssin.fail() || !check(inp))
        {
            ssin.clear();
            cout << CSI "1F" CSI "0J" << eprompt << flush;
            continue;
        }
        break;
    }
    return inp;
}

void echoInput(double _height, double _weight, int _age)
{
    cout << resetiosflags(cout.flags());
    cout << echo << "you entered : "
         << _height << " "
         << _weight << " "
         << _age << endl;
}

void signalHandler(int signum)
{
    cout << CSI "0m" << endl;
    exit(signum);
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
