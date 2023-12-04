#define CSI "\x1b["
#include <string>
#include <tuple>
#include <functional>
#include <thread>
#include <sstream>
#include <iostream>

namespace general
{
    /**
     * @brief Gets input from the user and checks if it satisfies the given condition.
     *
     * @tparam T The types of the elements in the tuple.
     * @param check A function that checks if the input satisfies a condition.
     * @param prompt The prompt message to display to the user.
     * @param eprompt The error message to display if the input does not satisfy the condition.
     * @return tuple<T...> The input values as a tuple.
     */
    template <class... T>
    tuple<T...> getInput(function<bool(tuple<T...> &)> check, string prompt, string eprompt)
        requires(canInput<T> && ...)
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

    /**
     * Applies color formatting to the input string.
     *
     * @param in The input string to apply color formatting to.
     * @param c The color codes to apply. Must be of type SGR (Select Graphic Rendition).
     * @return The input string with color formatting applied.
     *
     * @requires The color codes must be of type SGR (Select Graphic Rendition).
     */
    template <class... T>
    std::string color(std::string in, T... c)
        requires(isSGR<T> && ...)
    {
        std::string out = CSI;
        ((out += std::to_string((int)c) + ';'), ...);
        out.pop_back();
        out += 'm' + in + CSI "0m";
        return out;
    }
} // namespace
