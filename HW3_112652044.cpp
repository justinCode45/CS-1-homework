/* File Name:HW3_112652044.cpp
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
 * @brief Converts uppercase letters to lowercase letters.
 *
 * @param in The character to be converted.
 * @return char The converted character.
 */
char alower(char in)
{
    if (in <= 'Z' && in >= 'A')
        return in - ('Z' - 'z');
    return in;
}
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

/// @brief Recommend hairstyle by answering questions form step.
class HairStyle
{
public:
    function<HairStyle *()> run;
    std::pair<string, string> result;
    HairStyle();
    HairStyle *getStep();

private:
    HairStyle *getSex();
    HairStyle *getSuperM();
    HairStyle *getSuperF();
    HairStyle *getFood();
    HairStyle *getMovie();
    HairStyle *nothing();
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

    cout << endl;
    for (int i = 0; i < n; i++)
    {

        HairStyle *style = new HairStyle();

        Step *getSex = style->getStep();
        Step *getSuper = getSex->run();
        Step *getLast = getSuper->run();
        Step *stop = getLast->run();

        cout << echo << "You entered: " << style->result.first << endl;
        cout << "The recommended haircut: "
             << color(style->result.second, SGR::brightCyan) << endl;
        cout << endl;

        delete style;
    }

    return 0;
}

HairStyle::HairStyle()
{
    run = std::bind(getSex, this);
}
HairStyle *HairStyle::getStep()
{
    return this;
}
HairStyle *HairStyle::getSex()
{
    string in = getInput<string>(
        [](string x) -> bool
        {
            std::transform(x.begin(), x.end(), x.begin(), alower);
            return x == "male" || x == "female";
        },
        color("Male", SGR::brightWhite) " or " color("Female", SGR::brightWhite) "? ",
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
HairStyle *HairStyle::getSuperM()
{
    string in = getInput<string>(
        [](string x) -> bool
        {
            std::transform(x.begin(), x.end(), x.begin(), alower);
            return x == "superhero" || x == "supervillain";
        },
        "Want to be a " color("Superhero", SGR::brightWhite) " or " color("Supervillain", SGR::brightWhite) "? ",
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
HairStyle *HairStyle::getSuperF()
{
    string in = getInput<string>(
        [](string x) -> bool
        {
            std::transform(x.begin(), x.end(), x.begin(), alower);
            return x == "superhero" || x == "supervillain";
        },
        "Want to be a " color("Superhero", SGR::brightWhite) " or " color("Supervillain", SGR::brightWhite) "? ",
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
HairStyle *HairStyle::getFood()
{
    string in = getInput<string>(
        [](string x) -> bool
        {
            std::transform(x.begin(), x.end(), x.begin(), alower);
            return x == "sushi" || x == "steak";
        },
        "Prefer eating " color("Steak", SGR::brightWhite) " or " color("Sushi", SGR::brightWhite) "? ",
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
HairStyle *HairStyle::getMovie()
{
    string in = getInput<string>(
        [](string x) -> bool
        {
            std::transform(x.begin(), x.end(), x.begin(), alower);
            return x == "anime" || x == "sitcom";
        },
        "Prefer " color("Anime", SGR::brightWhite) " or " color("Sitcom", SGR::brightWhite) "? ",
        "Prefer " color("Anime", SGR::brightRed) " or " color("Sitcom", SGR::brightRed) "? ");

    std::transform(in.begin(), in.end(), in.begin(), alower);

    if (in == "anime")
    {
        result = {"Female Suprehero anime", "bangs"};
        run = std::bind(nothing, this);
    }
    else if (in == "sitcom")
    {
        result = {"Male Suprehero sitcom", "bob"};
        run = std::bind(nothing, this);
    }
    return this;
}
HairStyle *HairStyle::nothing()
{
    run = std::bind(nothing, this);
    return this;
}
