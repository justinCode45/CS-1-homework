#ifndef EMPLOYEE_H
#define EMPLOYEE_H


#include <string>
using namespace std;

class Employee
{
public:
    Employee();
    Employee(string _name, string ssn);
    string getName() const;
    string getSSN() const;
    int getPay() const;
    void setName(string _name);
    void setSSN(string _ssn);
    void setPay(int _pay);
    void printCheck() const;
private:
    string name;
    string ssn;
    int pay;
};



#endif