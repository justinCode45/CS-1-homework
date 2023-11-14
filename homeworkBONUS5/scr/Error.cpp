#include "../head/Error.hpp"
// #include <string>
#define CSI "\x1b["
#define color(in, c) CSI + std::to_string((int)c) + 'm' + in + CSI "0m"
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

Error::Error(ErrorType type, string message)
{
    this->type = type;
    this->message = message;
}

Error::Error(ErrorType type, string message, int line)
{
    this->type = type;
    this->message = message;
    this->line = line;
}

string Error::errorMessage()
{
    string err;
    switch (this->type)
    {
    case ErrorType::UNDEFINED:
        err = "[" color("Undefined Error",SGR::brightRed)"]";
        break;
    case ErrorType::SYNTAX:
        err = "[" color("Syntax Error",SGR::brightRed)"]";
        break;
    default:
        err = "[" color("Undefined Error",SGR::brightRed)"]";
        break;
    }
    return err + " at line " + std::to_string(this->line) + ": " + this->message;
}