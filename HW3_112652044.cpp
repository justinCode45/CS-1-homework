/* File Name:HW3_112652044.cpp
 * Author:Justin Chen
 * Email Address:justin.sc12@nycu.edu.tw
 * HW Number:3
 * Description:Calculate total loan repayment amount
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

// clear istream
#define clearCin std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
// define some common outputs
#define color(in, c) "\x1b[" + to_string((int)c) + 'm' + in + "\x1b[0m"
#define inputSign color(">> ", SGR::brightYellow)
#define echo "[" color("Echoing", SGR::green) "] "
#define inputError "[" color("Input error", SGR::brightRed) "] "
//--------------------------

using namespace std;

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

char alower(char in)
{
    if (in <= 'Z' && in >= 'A')
        return in - ('Z' - 'z');
    return in;
}
template <class T>
T getInput(function<bool(T)> check, string prompt, string eprompt)
{
    T inp;
    cout << prompt;
    while (1)
    {
        cin >> inp;
        if (cin.fail() || !check(inp))
        {
            cin.clear();
            cout << "\x1b[1F\x1b[0J" << eprompt;
            clearCin;
            continue;
        }
        clearCin;
        break;
    }
    return inp;
}

class HairStyle
{
public:
    function<HairStyle *()> run;
    std::pair<string, string> result;

    HairStyle()
    {
        run = std::bind(getSex, this);
    }
    HairStyle *getStep()
    {
        return this;
    }

private:
    HairStyle *getSex()
    {
        string in = getInput<string>(
            [](string x) -> bool
            {
                std::transform(x.begin(), x.end(), x.begin(), alower);
                return x == "male" || x == "female";
            },
            color("Male", SGR::brightYellow) " or " color("Female", SGR::brightYellow) "? ",
            color("Male", SGR::brightRed) " or " color("Female", SGR::brightRed) "? ");

        std::transform(in.begin(), in.end(), in.begin(), alower);

        if (in == "male")
        {
            run = std::bind(getSuperM, this);
        }
        else if (in == "female")
        {
            run = std::bind(getSuperF, this);
        }
        return this;
    }
    HairStyle *getSuperM()
    {
        string in = getInput<string>(
            [](string x) -> bool
            {
                std::transform(x.begin(), x.end(), x.begin(), alower);
                return x == "superhero" || x == "supervillain";
            },
            "Want to be a " color("Superhero", SGR::brightYellow) " or " color("Supervillain", SGR::brightYellow) "? ",
            "Want to be a " color("Superhero", SGR::brightRed) " or " color("Supervillain", SGR::brightRed) "? ");

        std::transform(in.begin(), in.end(), in.begin(), alower);

        if (in == "superhero")
        {
            run = std::bind(getFood, this);
        }
        else if (in == "supervillain")
        {
            result = {"Male Supreuillain", "mohawk"};
            run = std::bind(nothing, this);
        }
        return this;
    }
    HairStyle *getSuperF()
    {
        string in = getInput<string>(
            [](string x) -> bool
            {
                std::transform(x.begin(), x.end(), x.begin(), alower);
                return x == "superhero" || x == "supervillain";
            },
            "Want to be a " color("Superhero", SGR::brightYellow) " or " color("Supervillain", SGR::brightYellow) "? ",
            "Want to be a " color("Superhero", SGR::brightRed) " or " color("Supervillain", SGR::brightRed) "? ");

        std::transform(in.begin(), in.end(), in.begin(), alower);

        if (in == "superhero")
        {
            run = std::bind(getMovie, this);
        }
        else if (in == "supervillain")
        {
            result = {"Female Supreuillain", "mohawk"};
            run = std::bind(nothing, this);
        }
        return this;
    }
    HairStyle *getFood()
    {
        string in = getInput<string>(
            [](string x) -> bool
            {
                std::transform(x.begin(), x.end(), x.begin(), alower);
                return x == "sushi" || x == "steak";
            },
            "Prefer eating " color("Steak", SGR::brightYellow) " or " color("Sushi", SGR::brightYellow) "? ",
            "Prefer eating " color("Steak", SGR::brightRed) " or " color("Sushi", SGR::brightRed) "? ");
        std::transform(in.begin(), in.end(), in.begin(), alower);
        if (in == "steak")
        {
            result = {"Male Suprehero steak", "flat top"};
            run = std::bind(nothing, this);
        }
        else if (in == "sushi")
        {
            result = {"Male Suprehero sushi", "pompadour"};
            run = std::bind(nothing, this);
        }
        return this;
    }
    HairStyle *getMovie()
    {
        string in = getInput<string>(
            [](string x) -> bool
            {
                std::transform(x.begin(), x.end(), x.begin(), alower);
                return x == "anime" || x == "sitcom";
            },
            "Prefer " color("Anime", SGR::brightYellow) " or " color("Sitcom", SGR::brightYellow) "? ",
            "Prefer " color("Anime", SGR::brightRed) " or " color("Sitcom", SGR::brightRed) "? ");

        std::transform(in.begin(), in.end(), in.begin(), alower);

        if (in == "anime")
        {
            result = {"Female Suprehero anime", "bangs"};
            run = std::bind(nothing, this);
        }
        else if (in == "sticom")
        {
            result = {"Male Suprehero sticom", "bob"};
            run = std::bind(nothing, this);
        }
        return this;
    }
    HairStyle *nothing()
    {
        run = std::bind(nothing, this);
        return this;
    }
};

typedef HairStyle Step;

int main()
{

    cout << "The purpose of this program is to give hairstyle suggestions"
         << " through the user's answers to questions." << endl;

    int n = getInput<int>(
        [](int c) -> bool
        { return c > 0; },
        "Enter the maxmum number of repetitions (as postive int) : ",
        "Enter the maxmum number of repetitions (" color("as postive int", SGR::brightRed) ") : ");

    //--------
    cout << endl;
    for (int i = 0; i < n; i++)
    {

        HairStyle *style = new HairStyle();

        Step *getSex = style->getStep();
        Step *getSuper = getSex->run();
        Step *getLast = getSuper->run();
        Step *stop = getLast->run();

        cout << echo << "You entered: " << style->result.first << endl;
        cout << "The recommended haircut: " << color(style->result.second, SGR::brightCyan) << endl;
        cout << endl;

        delete style;
    }

    return 0;
}