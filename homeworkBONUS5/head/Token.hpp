#ifndef _TOKEN_HPP
#define _TOKEN_HPP

#include <iostream>

enum class TokenType
{
    NONE,
    NEWLINE,
    PREPRO,
    IDENTIFIER,
    TYPENAME ,
    KEYWORD,
    LBRACE,
    RBRACE,
    LPAREN,
    RPAREN,
    COMMA,
    NEOF,
    SEMICOLON ,
    IF,
    ELSE,
    WHILE,
    FOR,
    MARK,
    STR,
    DIV,
    PLUS,
    MINUS,
    MUL,
    LESS,
    GREATER,
    SHIFT_LEFT,
    SHIFT_RIGHT,
};
using std::string;
class Token
{
public:
    TokenType type;
    string value;
    int line;
    Token(TokenType type, string value);
    Token() : type(TokenType::NONE), value(""){};
    void set(TokenType type, string value, int line);
    // void set(TokenType type, string value);
    void set(TokenType type, int line);
    void print();
};

#endif // !_TOKEN_HPP