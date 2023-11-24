#ifndef UNITCHAR_HPP
#define UNITCHAR_HPP

#include <string>
#include <variant>
#include <sstream>
#include "General.hpp"


using std::string;
using std::variant;

#define CSI "\x1b["



class UnitChar
{
public:
    string c;
    variant<FSGR, int> colorF;
    variant<BSGR, int> colorB;
    UnitChar();
    void setColorF(int c256);
    void setColorF(FSGR x);
    void setColorF(variant<FSGR, int> x);
    void setColorB(int c256);
    void setColorB(BSGR x);
    void setColorB(variant<BSGR, int> x);
    string toString();
    void claer();
    void setChar(char c_);
};

#endif