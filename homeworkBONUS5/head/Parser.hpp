#ifndef _PARSER_HPP
#define _PARSER_HPP

#include "Scanner.hpp"
#include "Token.hpp"
#include "Error.hpp"
#include <vector>
#include <fstream>
#include <set>

using std::ofstream;
using std::ifstream;
using std::vector;
    
struct VarNode
{
    string type;
    string identifier;
};

class Parser
{

public:
    vector<Error> errors;

    Parser(Scanner *scanner, ofstream *file);
    Parser(ifstream* inFile, ofstream *outfile);
    void parseing();
    Scanner *scanner;

private:
    Token currentToken;
    Token lookahedToken;
    std::vector<VarNode> varName;
    ofstream *file;
    int tab;
    bool lookahedConsumed;

    Token nextToken();
    Token lookahed();

    void parserExpression();
    void autoFoemat(string in, bool needtab);
    void skipError();
    // void matchSemicolon();
    void parserUSING();
    void parserTYPE();
    void parserVar(string type);
    void parserIDENTIFIER();
    void parserCOUT();
    void parserCIN();
    string parserRVALUE();
    int findVar(string);
};

#endif // !_PARSER_HPP