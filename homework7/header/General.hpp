#ifndef GENGRAL_HPP
#define GENGRAL_HPP

#define CSI "\x1b["
#include <string>
#include <tuple>
#include <functional>
#include <thread>
#include <concepts>
#include <signal.h>
#include <iostream>
#include <sstream>

namespace general
{

    using std::apply;
    using std::cin;
    using std::cout;
    using std::endl;
    using std::flush;
    using std::function;
    using std::getline;
    using std::string;
    using std::stringstream;
    using std::to_string;
    using std::tuple;

    template <class... T>
    using funcTulp = function<bool(tuple<T...> &)>;

    enum class SGRC
    {
        reset = 0,
        bold = 1,
        underline = 4,
        blink = 5,
        reverse = 7,
        conceal = 8,
        crossed = 9
    };

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
        brightBlack = 100,
        brightRed,
        brightGreen,
        brightYellow,
        brightBlue,
        brightMagenta,
        brightCyan,
        brightWhite
    };

    template <class T>
    concept canInput = requires(T x) {
        {
            cin >> x
        } -> std::same_as<decltype(cin) &>;
    };

    template <class T>
    concept isSGR = std::same_as<T, general::FSGR> || std::same_as<T, general::BSGR> || std::same_as<T, general::SGRC>;

    
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
        requires(canInput<T> && ...);


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
        requires(isSGR<T> && ...);

    /**
     * @brief Signal handler function.
     *
     * This function is responsible for handling signals.
     * Inorder to close SGR.
     * 
     * @param sig The signal number.
     * 
     * */
    void sigHandler(int sig);
}
#include "General.tpp"

#endif