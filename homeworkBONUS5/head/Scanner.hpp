#ifndef _SCANNER_HPP
#define _SCANNER_HPP

#include <string>
#include <sstream>
#include "Error.hpp"
#include "Token.hpp"

using std::string;
using std::stringstream;



enum class StateS
{
    START,
    IDENTIFIER,
    SLASH,
    STR,

};
class Scanner
{
public:
    stringstream reader;
    StateS state;
    Token currentToken;
    int currentLine;
    Scanner(string reader);
    Scanner(){}
    Token nextToken();
private:
    Token returnToken(TokenType type, string value);
    Token returnToken(TokenType type);
    
};



#endif // !_SCANNER_HPP