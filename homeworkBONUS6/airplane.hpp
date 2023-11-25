#ifndef AIRPLANE_HPP
#define AIRPLANE_HPP

#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <unordered_map>
#include <set>
#include <functional>
#include <tuple>
#include <iostream>
#include <sstream>
#include <thread>
using std::function;
using std::ifstream;
using std::map;
using std::pair;
using std::set;
using std::string;
using std::unordered_map;
using std::vector;
using std::tuple;
using std::get;
using std::apply;
using std::cout;
using std::cin;
using std::to_string;
using std::endl;
using std::flush;
using std::stringstream;

#define CSI "\x1b["

enum class FSGR
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

enum class BSGR
{
    black = 40,
    red,
    green,
    yellow,
    blue,
    magenta,
    cyan,
    white,
    brightBlack = 100,
    brightRed,
    brightGreen,
    brightYellow,
    brightBlue,
    brightMagenta,
    brightCyan,
    brightWhite
};

template <class... T>
tuple<T...> getInput(function<bool(tuple<T...> &)> check, string prompt, string eprompt)
{
    tuple<T...> inp;

    cout << prompt << flush;
    while (1)
    {
        stringstream ssin;
        string rawInput;

        cout << CSI + to_string((int)FSGR::brightYellow) + "m" << flush;

        getline(cin, rawInput);
        ssin << rawInput;
        cout << CSI "0m" << flush;

        apply([&ssin](auto &...x)
              { (ssin >> ... >> x); },
              inp);

        std::this_thread::sleep_for(std::chrono::milliseconds(1));

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

template <class... T>
std::string color(std::string in, T... c)
{
    std::string out = CSI;
    ((out += std::to_string((int)c) + ';'), ...);
    out.pop_back();
    out += 'm' + in + CSI "0m";
    return out;
}
class Seat
{
public:
    bool havePeople;
    bool haveSeat;
    bool havePandemic;
    bool nearLavatory;
    Seat()
    {
        havePeople = false;
        haveSeat = true;
        havePandemic = false;
        nearLavatory = false;
    }
    bool available()
    {
        return !havePeople && haveSeat && !havePandemic && !nearLavatory;
    }
};

class Cabin
{
public:
    char aisle[2];
    string name;
    int rowStart;
    int row;
    int col;
    map<char, int> colMapci;
    map<int, char> colMapic;
    Seat **seats;
    Cabin()
    {
        seats = nullptr;
    }
    void load(ifstream &file, string &cabinName);
    bool reserveSeat(int rowC);
    string print();
};

class Airplane
{
public:
    string name;
    // vector<Cabin*> cabins;
    map<string, Cabin *> cabinMap;
    Airplane(string path)
    {
        load(path);
    }
    void load(string path);
    string getCabinList();
};

#endif
