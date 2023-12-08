#include <iostream>
#include <cstring>

using namespace std;

class MyString
{
public:
    MyString();
    MyString(const char *s);
    MyString(int size);
    ~MyString();
    int length() const;
    void inputLines(istream &ins);
    friend ostream& operator<<(ostream& outs, const MyString& s);
    // void operator=(const MyString &s);
private:
    int maxLen;
    char *str;
};

void conversation(int maxNameLen);

int main()
{
    conversation(30);

    cout << "End of program." << endl;

    return 0;
}

MyString::MyString()
{
    this->maxLen = 100;
    this->str = new char[this->maxLen + 1];
    str[0] = '\0';
}

MyString::MyString(int size)
{
    this->maxLen = size;
    this->str = new char[this->maxLen + 1];
    str[0] = '\0';
}

MyString::MyString(const char *s)
{
    this->maxLen = strlen(s);
    this->str = new char[this->maxLen + 1];
    strcpy(this->str, s);
}

MyString::~MyString()
{
    cout << "Destructor called." << endl;
    delete [] this->str;
}

int MyString::length() const
{
    return strlen(this->str);
}

void MyString::inputLines(istream &ins)
{
    ins.getline(this->str, this->maxLen + 1);
}

ostream& operator<<(ostream& outs, const MyString& s)
{
    outs << s.str;
    return outs;
}

void conversation(int maxNameLen)
{
    MyString yourName(maxNameLen), myName("Justin");
    cout << "What is your name? ";
    yourName.inputLines(cin);
    cout << "Hello, " << yourName << endl;
    cout << "My name is " << myName << endl;
}
