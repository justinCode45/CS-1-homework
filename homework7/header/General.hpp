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
    using std::flush;
    using std::function;
    using std::getline;
    using std::string;
    using std::stringstream;
    using std::to_string;
    using std::tuple;
    using std::endl;

    template <class... T>
    using funcTulp = function<bool(tuple<T...> &)>;

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
    concept isSGR = std::same_as<T, general::FSGR> || std::same_as<T, general::BSGR>;

    template <class... T>
    tuple<T...> getInput(function<bool(tuple<T...> &)> check, string prompt, string eprompt)
        requires(canInput<T> && ...);

    template <class... T>
    std::string color(std::string in, T... c)
        requires(isSGR<T> && ...);

    void sigHandler(int sig);
}
#include "General.tpp"

#endif