#ifndef _ERROR_HPP
#define _ERROR_HPP

#include <string>
#include <vector>
using std::string;
using std::vector;

enum ErrorType
{
    UNDEFINED,
    SYNTAX,

};

class Error
{
public:
    ErrorType type;
    string message;
    int line;
    Error(ErrorType type, string message);
    Error(ErrorType type, string message, int line);
    string errorMessage();
};

// vector<Error> errors;

#endif // !_ERROR_HPP