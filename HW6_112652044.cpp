/* File Name:HW6_112652044.cpp
 * Author:Justin Chen
 * Email Address:justin.sc12@nycu.edu.tw
 * HW Number:6
 * Description: The purpose of the program is to help user reserve the seat on Airbus A380.
 * Last Change: Nov.9,2023
 * Anything special?
 *  1. color output
 *  2. More specical functions are in other file.
 *
 * Complier: g++ (Rev2, Built by MSYS2 project) 13.2.0 ,C++17
 *           g++ (Ubuntu 11.4.0-1ubuntu1~22.04) 11.4.0 ,C++17
 *           g++ (tdm64-1) 9.2.0 ,C++17 (Embarcadero Dev-C++)
 *
 * Translated Support:112652033
 */
#include <iostream>
#include <string>
#include <tuple>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <memory>
#include <sstream>
#include <csignal>
#include <thread>
#include <fstream>

#define CSI "\x1b["

// #define color(in, c) CSI + to_string((int)c) + 'm' + in + CSI "0m"

#define echo "[" + color("Echoing", FSGR::green) + "] "

using namespace std;

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

template <class... T>
string color(string in, T... c)
{
    string out = CSI;
    ((out += to_string((int)c) + ';'), ...);
    out.pop_back();
    out += 'm' + in + CSI "0m";
    return out;
}

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

int charTOindex(char c)
{
    if (c <= 'H')
        return c - 'A';
    else
        return c - 'A' - 1;
}

char indexTOchar(int c)
{
    if (c <= 7)
        return c + 'A';
    else
        return c + 'A' + 1;
}

void loadSeat(Seat **seat, int row, int col);

void printSeat(Seat **seat, int row, int col);

bool again();

int main()
{
    cout << "The purpose of the program is to help user reserve the seat on Airbus A380." << endl;

    int row = 32;
    int col = 10;
    Seat **seat;
    seat = new Seat *[row];
    for (int i = 0; i < row; i++)
    {
        seat[i] = new Seat[col];
    }

    loadSeat(seat, row, col);

    while (1)
    {
        cout << endl;
        auto [seatNumber] = getInput<int>(
            (function<bool(tuple<int> &)>)
                [](tuple<int> x)
                    ->bool { return get<0>(x) == 1 || get<0>(x) == 2; },
            "How many seat do you want to reserve (1 or 2): ",
            "How many seat do you want to reserve (" + color("1 or 2", FSGR::brightRed) + "): ");

        cout << echo << "You entered: " << seatNumber << endl;
        cout << endl;
        for (int i = 0; i < seatNumber; i++)
        {
            bool reserved = false;

            auto [rowChoose] = getInput<int>(
                (function<bool(tuple<int> &)>)
                    [](tuple<int> x)
                        ->bool { return get<0>(x) >= 28 && get<0>(x) <= 59; },
                "Enter the seat row (28 <= r <= 59): ",
                "Enter the seat row (" + color("28 <= r <= 59", FSGR::brightRed) + "): ");

            cout << echo << "You entered: " << rowChoose << endl;

            for (int i = 0; i < col; i++)
            {
                if (seat[rowChoose - 28][i].available())
                {
                    seat[rowChoose - 28][i].havePeople = true;
                    reserved = true;

                    if (rowChoose - 29 >= 0)
                        seat[rowChoose - 29][i].havePandemic = true;
                    if (rowChoose - 27 < row)
                        seat[rowChoose - 27][i].havePandemic = true;
                    if (i - 1 >= 0)
                        seat[rowChoose - 28][i - 1].havePandemic = true;
                    if (i + 1 < col)
                        seat[rowChoose - 28][i + 1].havePandemic = true;
                    break;
                }
            }
            if (!reserved)
            {
                cout << color("No available seat.", FSGR::brightRed) << endl;
                cout << "Please choose another seat." << endl;
                cout << endl;
                i--;
                continue;
            }
            printSeat(seat, row, col);
            cout << endl;
        }
        if (!again())
        {
            break;
        }
    }

    delete[] seat;
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

        cout << CSI + to_string((int)FSGR::brightYellow) + "m" << flush;

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

void loadSeat(Seat **seat, int row, int col)
{
    // I afraid that the file will be lost, so I use stringstream instead of ifstream.

    // ifstream file;
    // file.open("noSeatTable.txt");
    // if (file.fail())
    // {
    //     cout << "Input file opening failed." << endl;
    //     exit(1);
    // }

    stringstream file;
    file << "28D 28E 28F 28G 28H 28J 28K \
             29D 29E 29F 29G 29H 29J 29K \
             41D 41E 41F 41G \
             46D \
             0Z \
             28A 28B 28C \
             29A 29B 29C \
             40A 40B 40C 40D 40E 40F 40G 40H 40J 40K \
             43A 43B 43C 43D 43E 43F 43G 43H 43J 43K \
             42A 42B 42C 42D 42E 42F 42G 42H 42J 42K \
             58A 58B 58C 58D 58E 58F 58G 58H 58J 58K \
             59A 59B 59C 59D 59E 59F 59G 59H 59J 59K \
             41A 41B 41C 41I 41J 41K \
             0Z";

    while (1)
    {
        int r;
        char c;
        file >> r >> c;
        if (file.eof() || (r == 0 && c == 'Z'))
        {
            break;
        }
        seat[r - 28][charTOindex(c)].haveSeat = false;
    }

    while (1)
    {
        int r;
        char c;
        file >> r >> c;
        if (file.eof() || (r == 0 && c == 'Z'))
        {
            break;
        }
        seat[r - 28][charTOindex(c)].nearLavatory = true;
    }

    // file.close();
}

void printSeat(Seat **seat, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        cout << i + 28 << "  ";
        for (int j = 0; j < col; j++)
        {
            if (seat[i][j].haveSeat)
            {
                if (seat[i][j].havePeople)
                {
                    cout << color("X", BSGR::brightGreen, FSGR::brightWhite) << " ";
                }
                else if (seat[i][j].nearLavatory)
                {
                    cout << color(string(1, indexTOchar(j)), BSGR::brightCyan) << " ";
                }
                else if (seat[i][j].havePandemic)
                {
                    cout << color(string(1, indexTOchar(j)), BSGR::brightRed, FSGR::black) << " ";
                }
                else
                {
                    cout << indexTOchar(j) << " ";
                }
            }
            else
            {
                cout << "  ";
            }

            if (j == 'C' - 'A')
            {
                cout << "  ";
            }
            if (j == 'G' - 'A')
            {
                cout << "  ";
            }
        }
        cout << endl;
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
