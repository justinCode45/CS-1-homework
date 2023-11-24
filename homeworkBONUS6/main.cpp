#include <iostream>
#include "airplane.hpp"
#include <vector>
#include <tuple>
#include <functional>
#include <thread>
#include <sstream>

#define CSI "\x1b["
#define SHEIGHT 50
#define SWIDTH 150

using namespace std;

#define echo "[" + color("Echoing", FSGR::green) + "] "

bool again();

int main()
{
    cout << "The purpose of the program is to help user reserve the seat on airplane" << endl;

    auto [airplaneName] = getInput<string>(
        (function<bool(tuple<string> &)>)
            [](tuple<string> x)
                ->bool { return get<0>(x) == "B747" || get<0>(x) == "A380"; },
        "Please enter the name of the airplane (B747 or A380) :",
        "Please enter the name of the airplane " + color("(B747 or A380)", FSGR::brightRed) + " :");

    cout << echo << "You entered :" << airplaneName << endl;

    Airplane airplane(airplaneName + ".txt");
    cout << endl;
    while (1)
    {
        auto [cabinName] = getInput<string>(
            (function<bool(tuple<string> &)>)
                [&airplane](tuple<string> x)
                    ->bool { return airplane.cabinMap.count(get<0>(x)); },
            "Please enter the name of the cabin (" + airplane.getCabinList() + ") :",
            "Please enter the name of the cabin (" + color(airplane.getCabinList(), FSGR::brightRed) + ") :");

        auto [seatNum] = getInput<int>(
            (function<bool(tuple<int> &)>)
                [](tuple<int> x)
                    ->bool { return get<0>(x) == 1 || get<0>(x) == 2; },
            "Please enter the number of seats you want to reserve (1 or 2) :",
            "Please enter the number of seats you want to reserve " + color("(1 or 2)", FSGR::brightRed) + " :");

        cout << echo << "You entered :" << cabinName << ", " << seatNum << endl;

        Cabin *cabin = airplane.cabinMap[cabinName];
        int rowStart = cabin->rowStart;
        int rowEnd = cabin->rowStart + cabin->row - 1;

        cout << endl;
        for (int i = 0; i < seatNum; i++)
        {
            auto [seatRow] = getInput<int>(
                (function<bool(tuple<int> &)>)
                    [&rowStart, &rowEnd ](tuple<int> x)
                        ->bool { return get<0>(x) >= rowStart && get<0>(x) <= rowEnd; },
                "Please enter the row number of the seat you want to reserve (" + to_string(rowStart) + "~" + to_string(rowEnd) + ") :",
                "Please enter the row number of the seat you want to reserve (" + color(to_string(rowStart) + "~" + to_string(rowEnd), FSGR::brightRed) + ") :");

            cout << echo << "You entered :" << seatRow << endl;

            bool reserved = cabin->reserveSeat(seatRow);
            if (!reserved)
            {
                i--;
                cout << color("No available seat.", FSGR::brightRed) << endl;
                cout << "Please choose another seat." << endl;
                continue;
            }
            cout << cabin->print() << endl;
        }

        if (!again())
        {
            break;
        }
    }
}

bool again()
{
    auto [temp] = getInput<char>(
        (function<bool(tuple<char> &)>)
            [](tuple<char> x)
                ->bool { return get<0>(x) == 'y' || get<0>(x) == 'Y' || get<0>(x) == 'n' || get<0>(x) == 'N'; },
        "Do you want to continue?(Y/N) :",
        "Do you want to continue?(" + color("Y/N", FSGR::brightRed) + ") :");

    return temp == 'y' || temp == 'Y';
}
