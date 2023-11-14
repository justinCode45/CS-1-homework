#include "../head/Parser.hpp"
#include <string>
#include "../head/Shash.hpp"

#define matchSemicolon()                                                    \
    if (currentToken.type != TokenType::SEMICOLON)                          \
    {                                                                       \
        strbuffer += ";";                                                   \
        currentToken = nextToken();                                         \
    }                                                                       \
    else                                                                    \
    {                                                                       \
        this->errors.push_back(                                             \
            Error(ErrorType::SYNTAX, "Expected \";\"", currentToken.line)); \
        skipError();                                                        \
    }

int Parser::findVar(string name)
{
    for (int i = 0; i < varName.size(); i++)
    {
        if (varName[i].identifier == name)
        {
            return i;
        }
    }
    return -1;
}

Parser::Parser(Scanner *scanner, ofstream *file)
{
    this->scanner = scanner;
    this->currentToken = scanner->nextToken();
    this->lookahedConsumed = true;
    this->file = file;
    this->tab = 0;
    this->varName.push_back({"stream", "cin"});
    this->varName.push_back({"stream", "cout"});
    this->varName.push_back({"streamOp", "endl"});
}

Parser::Parser(ifstream *inFile, ofstream *outFile)
{
    std::stringstream reader;
    reader << inFile->rdbuf();
    this->scanner = new Scanner(reader.str());

    this->currentToken = scanner->nextToken();
    this->lookahedConsumed = true;
    this->file = outFile;
    this->tab = 0;
    this->varName.push_back({"stream", "cin"});
    this->varName.push_back({"stream", "cout"});
    this->varName.push_back({"streamOp", "endl"});
}

Token Parser::nextToken()
{
    if (lookahedConsumed)
    {
        currentToken = scanner->nextToken();
        return currentToken;
    }
    else
    {
        currentToken = lookahedToken;
        lookahedConsumed = true;
        return currentToken;
    }
}

Token Parser::lookahed()
{
    if (lookahedConsumed)
    {
        lookahedToken = scanner->nextToken();
        lookahedConsumed = false;
        return lookahedToken;
    }
    else
    {
        return lookahedToken;
    }
}

void Parser::skipError()
{
    while (!(currentToken.type == TokenType::SEMICOLON ||
             currentToken.type == TokenType::NONE ||
             currentToken.type == TokenType::NEWLINE ||
             currentToken.type == TokenType::NEOF))
    {
        currentToken = nextToken();
    }
}

void Parser::autoFoemat(string in, bool needtab = true)
{
    if (needtab)
        for (int i = 0; i < this->tab; i++)
        {
            *(this->file) << "\t";
        }
    *(this->file) << in;
}

void Parser::parserUSING()
{

    string strbuffer = "using ";
    if (this->lookahed().type == TokenType::IDENTIFIER && this->lookahed().value == "namespace")
    {
        this->nextToken();
        strbuffer += "namespace ";

        if (this->lookahed().type == TokenType::IDENTIFIER && this->lookahed().value == "std")
        {
            this->nextToken();
            strbuffer += "std";
        }
        else
        {
            strbuffer += this->lookahed().value;
            this->errors.push_back(
                Error(ErrorType::SYNTAX, "Expected identifier \"std\"", this->lookahed().line));
            skipError();
        }
    }
    else
    {
        this->errors.push_back(
            Error(ErrorType::SYNTAX, "Expected identifier \"namespace\"", this->lookahed().line));
        skipError();
    }
    matchSemicolon();
    autoFoemat(strbuffer);
}

void Parser::parserTYPE()
{

    string strbuffer = this->currentToken.value;
    strbuffer += " ";
    if (this->lookahed().type == TokenType::IDENTIFIER)
    {
        strbuffer += this->lookahed().value;
    }
    else
    {
        this->errors.push_back(
            Error(ErrorType::SYNTAX, "Expected identifier", this->lookahed().line));
        skipError();
    }
    string type = this->currentToken.value;
    varName.push_back({this->currentToken.value, this->lookahed().value});
    this->nextToken();

    switch (this->lookahed().type)
    {
    case TokenType::LPAREN:
    {
        this->nextToken();
        strbuffer += "(";
        if (this->lookahed().type == TokenType::RPAREN)
        {
            strbuffer += ")";
            this->nextToken();
            this->autoFoemat(strbuffer);
            if (this->lookahed().type == TokenType::NEWLINE)
            {
                this->nextToken();
            }
            else
            {
                this->autoFoemat("\n");
            }
            if (this->lookahed().type == TokenType::LBRACE)
            {
                this->parserExpression(); //
                if (currentToken.type == TokenType::RBRACE)
                {
                    this->autoFoemat("}");
                }
                else
                {
                    this->errors.push_back(
                        Error(ErrorType::SYNTAX, "Expected \"}\"", this->lookahed().line));
                    skipError();
                }
            }
            else
            {
                this->errors.push_back(
                    Error(ErrorType::SYNTAX, "Expected \"{\"", this->lookahed().line));
                skipError();
            }
        }
        else
        {
            this->errors.push_back(
                Error(ErrorType::SYNTAX, "Expected \")\"", this->lookahed().line));
            skipError();
        }

        break;
    }
    case TokenType::SEMICOLON:
        this->nextToken();
        strbuffer += ";";
        this->autoFoemat(strbuffer);
        break;
    case TokenType::COMMA:
        this->autoFoemat(strbuffer);
        parserVar(type);
        break;
    default:
        this->errors.push_back(
            Error(ErrorType::SYNTAX, "Expected \",\" or \";\"", this->lookahed().line));
        break;
    }
}

void Parser::parserVar(string type)
{
    string strbuffer = "";
    while (this->lookahed().type == TokenType::COMMA)
    {
        strbuffer += ", ";
        this->nextToken();
        if (this->lookahed().type == TokenType::IDENTIFIER)
        {
            strbuffer += this->lookahed().value;
            varName.push_back({type, this->lookahed().value});
            this->nextToken();
        }
        else
        {
            this->errors.push_back(
                Error(ErrorType::SYNTAX, "Expected identifier", this->lookahed().line));
            skipError();
        }
    }
    matchSemicolon();
    this->autoFoemat(strbuffer, false);
}

void Parser::parserCIN()
{
    // std::cout << "INCIN" << std::endl;
    string strbuffer = "";
    bool run = 1;
    while (run)
    {
        // this->currentToken.print();
        switch (this->lookahed().type)
        {
        case TokenType::SHIFT_RIGHT:
            this->nextToken();
            strbuffer += ">> ";
            break;
        case TokenType::IDENTIFIER:
        {
            // std::cout << "Iden in cin " << std::endl;
            if (this->lookahed().value == "cout" || this->lookahed().value == "cin")
            {
                run = 0;
                this->errors.push_back(Error(ErrorType::SYNTAX, "Expected \";\"", this->lookahed().line));
                break;
            }
            int ops = findVar(this->lookahed().value);
            if (ops == -1)
            {
                this->errors.push_back(
                    Error(ErrorType::SYNTAX, "Identifier not defined \"" + this->lookahed().value + "\"", this->lookahed().line));
            }
            strbuffer += this->lookahed().value;
            strbuffer += " ";
            this->nextToken();
            break;
        }
        case TokenType::SEMICOLON:
            this->nextToken();
            strbuffer.erase(strbuffer.end() - 1);
            strbuffer += ";";
            run = 0;
            break;
        case TokenType::NEWLINE:
        {
            run = 0;
            this->errors.push_back(
                Error(ErrorType::SYNTAX, "Expected \";\"", this->lookahed().line));
            break;
        }
        case TokenType::SHIFT_LEFT:
        {
            this->errors.push_back(
                Error(ErrorType::SYNTAX, "Expected \">>\"", this->lookahed().line));
            this->nextToken();
            strbuffer += ">> ";
            break;
        }
        default:
            run = 0;
            break;
        }
    }
    this->autoFoemat(strbuffer, false);
}

string Parser::parserRVALUE()
{
    // std::cout << "cout" << std::endl;

    string strbuffer = "";
    bool closing = 1;
    bool hasLparen = 0;
    bool run = 1;
    if (this->lookahed().type == TokenType::LPAREN)
    {
        hasLparen = 1;
        strbuffer += "(";
        this->nextToken();
        closing = 0;
    }
    while (run)
    {
        // std::cout<<"lookahed().type ";
        // this->lookahed().print();
        // std::cout<<std::endl;
        switch (this->lookahed().type)
        {
        case TokenType::IDENTIFIER:
        {
            int ops = findVar(this->lookahed().value);
            if (ops == -1)
            {
                this->errors.push_back(
                    Error(ErrorType::SYNTAX, "Identifier not defined \"" + this->lookahed().value + "\"", this->lookahed().line));
            }
            strbuffer += this->lookahed().value;
            strbuffer += " ";
            this->nextToken();
            break;
        }
        case TokenType::STR:
        {
            strbuffer += this->lookahed().value;
            strbuffer += " ";
            this->nextToken();
            break;
        }
        case TokenType::PLUS:
        {
            strbuffer += "+ ";
            this->nextToken();
            break;
        }
        case TokenType::MINUS:
        {
            strbuffer += "- ";
            this->nextToken();
            break;
        }
        case TokenType::MUL:
        {
            strbuffer += "* ";
            this->nextToken();
            break;
        }
        case TokenType::DIV:
        {
            strbuffer += "/ ";
            this->nextToken();
            break;
        }
        case TokenType::RPAREN:
        {

            strbuffer.erase(strbuffer.end() - 1);
            if (!hasLparen) 
            {
                this->errors.push_back(
                    Error(ErrorType::SYNTAX, "Expected \"(\"", this->lookahed().line));
            }
            strbuffer += ") ";
            this->nextToken();
            closing = 1;
            run = 0;
            break;
        }
        default:
            run = 0;
            break;
        }
    }

    if (!closing && hasLparen)
    {
        this->errors.push_back(
            Error(ErrorType::SYNTAX, "Expected \")\"", this->lookahed().line));
    }

    // this->autoFoemat(strbuffer, false);
    return strbuffer;
}

void Parser::parserCOUT()
{
    string strbuffer = "";
    bool run = 1;
    while (run)
    {
        // this->currentToken.print();
        switch (this->lookahed().type)
        {
        case TokenType::SHIFT_LEFT:
            this->nextToken();
            strbuffer += "<< ";
            break;
        case TokenType::STR:
            strbuffer += ("\"" + this->lookahed().value + "\"");
            strbuffer += " ";
            this->nextToken();
            break;
        case TokenType::LPAREN:
        case TokenType::IDENTIFIER:
        {
            if (this->lookahed().value == "cout" || this->lookahed().value == "cin")
            {
                run = 0;
                this->errors.push_back(Error(ErrorType::SYNTAX, "Expected \";\"", this->lookahed().line));
                break;
            }
            strbuffer += parserRVALUE();
            break;
        }
        case TokenType::SEMICOLON:
            this->nextToken();
            strbuffer.erase(strbuffer.end() - 1);
            strbuffer += ";";
            run = 0;
            break;
        case TokenType::NEWLINE:
        {
            run = 0;
            this->errors.push_back(
                Error(ErrorType::SYNTAX, "Expected \";\"", this->lookahed().line));
            break;
        }
        case TokenType::SHIFT_RIGHT:
        {
            this->errors.push_back(
                Error(ErrorType::SYNTAX, "Expected \"<<\"", this->lookahed().line));
            this->nextToken();
            strbuffer += "<< ";
            break;
        }
        default:
            run = 0;
            break;
        }
    }
    this->autoFoemat(strbuffer, false);
}

void Parser::parserIDENTIFIER()
{
    // std::cout << "IDENTIFIER  " << currentToken.value << std::endl;

    string strbuffer = this->currentToken.value;
    string nowIdentifier = this->currentToken.value;
    strbuffer += " ";
    int ops = findVar(this->currentToken.value);

    if (ops == -1)
    {
        this->errors.push_back(
            Error(ErrorType::SYNTAX, "Identifier not defined \"" + this->lookahed().value + "\"", this->currentToken.line));
    }

    this->autoFoemat(strbuffer);
    strbuffer = "";
    // this->nextToken();

    switch (Shash_(nowIdentifier))
    {
    case "cin"_hash:
        parserCIN();
        break;
    case "cout"_hash:
        parserCOUT();
        break;
    default:
        break;
    }
    if (this->lookahed().type != TokenType::NEWLINE)
    {
        this->autoFoemat("\n");
    }
    // matchSemicolon();
    // this->autoFoemat(strbuffer);
}

void Parser::parseing()
{

    parserExpression();

    int x = findVar("main");
    if (x == -1)
    {
        this->errors.push_back(
            Error(ErrorType::SYNTAX, "No main function", this->lookahed().line));
    }
}

void Parser::parserExpression()
{
    while (currentToken.type != TokenType::NEOF && currentToken.type != TokenType::RBRACE)
    {

        switch (currentToken.type)
        {
        case TokenType::LBRACE:
            autoFoemat("{");
            this->tab++;
            break;
        case TokenType::NEWLINE:
            autoFoemat("\n");
            break;
        case TokenType::MARK:
            autoFoemat(currentToken.value);
            break;
        case TokenType::PREPRO:
            autoFoemat(currentToken.value);
            break;
        case TokenType::KEYWORD:
        {
            switch (Shash_(currentToken.value))
            {
            case "using"_hash:
            {
                parserUSING();
                break;
            }
            case "return"_hash:
            {
                autoFoemat("return 0;");
                break;
            }
            }
            break;
        }
        case TokenType::TYPENAME:
        {
            parserTYPE();
            break;
        }
        case TokenType::IDENTIFIER:
        {

            parserIDENTIFIER();
            break;
        }
        }

        this->nextToken();
    }
    this->tab--;
}