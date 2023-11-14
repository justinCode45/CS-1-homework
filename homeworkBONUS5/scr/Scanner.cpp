#include "../head/Scanner.hpp"
#include "../head/Shash.hpp"


// using Shash::Shash_;
// using Shash::operator"" _hash;

Scanner::Scanner(string reader)
{
    this->reader = stringstream(reader);
    this->state = StateS::START;
    this->currentLine = 1;
}

Token Scanner::returnToken(TokenType type, string value)
{
    this->currentToken.set(type, value,this->currentLine);
    return this->currentToken;
}

Token Scanner::returnToken(TokenType type)
{
    this->currentToken.set(type,this->currentLine);
    return this->currentToken;
}



Token Scanner::nextToken()
{
    string bufferstr;
    while (1)
    {
        // std::cout<<"x"<<std::endl;
        switch (this->state)
        {
        case StateS::START:
        {
            char c = this->reader.get();
            if(reader.eof())
            {
                return returnToken(TokenType::NEOF);
            }
            if ((c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A'))
            {
                bufferstr = c;
                this->state = StateS::IDENTIFIER;
                continue;
            }
            switch (c)
            {
            case '#':
            {   
                bufferstr = "#";
                char d = this->reader.get();
                while(d != '\n')
                {
                    bufferstr += d;
                    d = this->reader.get();
                }
                this->reader.unget();
                return returnToken(TokenType::PREPRO,bufferstr);
            }
            case ',':
                return returnToken(TokenType::COMMA,",");
            case '{':
                return returnToken(TokenType::LBRACE,"{");
            case '}':
                return returnToken(TokenType::RBRACE,"}");
            case '(':
                return returnToken(TokenType::LPAREN,"(");
            case ')':
                return returnToken(TokenType::RPAREN,")");
            case ';':
                return returnToken(TokenType::SEMICOLON,";");
            case '<':
            {
                char d = this->reader.get();
                if( d == '<')
                    return returnToken(TokenType::SHIFT_LEFT,"<<");
                else 
                    this->reader.unget();
                return returnToken(TokenType::LESS);
            }
            case '>':
            {
                char e = this->reader.get();
                if (e == '>')
                    return returnToken(TokenType::SHIFT_RIGHT,">>");
                else
                    this->reader.unget();
                return returnToken(TokenType::GREATER);
            }
            case '+':
                return returnToken(TokenType::PLUS);
            case '-':
                return returnToken(TokenType::MINUS);
            case -1:
                return returnToken(TokenType::NONE);
            case '\n':
                this->currentLine++;
                return returnToken(TokenType::NEWLINE);
            case '/':
                this->state = StateS::SLASH;
                break;
            case '\"':
                this->state = StateS::STR;
                break;
            default:
                break;
            }
            break;
        }
        case StateS::IDENTIFIER:
        {
            char c = this->reader.get();
            if ((c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A'))
            {
                bufferstr += c;
            }
            else
            {
                this->reader.unget();
                this->state = StateS::START;
                switch (Shash_(bufferstr))
                {
                case "int"_hash:
                case "char"_hash:
                case "float"_hash:
                case "double"_hash:
                    // std::cout<<bufferstr<<std::endl;
                    return returnToken(TokenType::TYPENAME, bufferstr);
                case "if"_hash:
                    return returnToken(TokenType::IF);
                case "using"_hash:
                    return returnToken(TokenType::KEYWORD, "using");
                case "return"_hash:
                    return returnToken(TokenType::KEYWORD, "return");
                /*...*/
                default:
                    return returnToken(TokenType::IDENTIFIER, bufferstr);
                }
            }
            break;
        }
        case StateS::SLASH:
        {
            char c = this->reader.get();
            if (c == '/')
            {
                bufferstr = "//";
                char d = this->reader.get();
                if (d != '\n')
                {
                    while (d != '\n')
                    {
                        bufferstr += d;
                        d = this->reader.get();
                    }
                    this->reader.unget();
                }
                this->state = StateS::START;
                return returnToken(TokenType::MARK, bufferstr);
            }
            else
            {
                this->reader.unget();
                this->state = StateS::START;
                return returnToken(TokenType::DIV);
            }
            break;
        }
        case StateS::STR:
        {
            bufferstr = "";
            char c = this->reader.get();
            while (c != '\"')
            {
                bufferstr += c;
                c = this->reader.get();
            }
            this->state = StateS::START;
            return returnToken(TokenType::STR, bufferstr);
        }
        }
    }
}
