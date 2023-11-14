#include "../head/Token.hpp"
#include <string>
#include <iostream>
using std::cout;
using std::endl;
using std::string;
Token::Token(TokenType type, string value)
{
    this->type = type;
    this->value = value;
}

void Token::set(TokenType type, string value, int line)
{
    this->type = type;
    this->value = value;
    this->line = line;
}

// void Token::set(TokenType type, string value)
// {
//     this->type = type;
//     this->value = value;
// }

void Token::set(TokenType type, int line)
{
    this->type = type;
    this->value = "";
    this->line = line;
}
void Token::print()
{

    cout << "Token type: " << (int)this->type << endl;
    cout << "Token value: " << this->value << endl;
    cout << "-------------------------" << endl;
}
