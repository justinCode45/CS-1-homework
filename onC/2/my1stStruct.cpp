#include <iostream>

using namespace std;

struct Account
{
    int balance;
    double rate;
    int term;
};

void getData(Account &a)
{
    cout << "Enter balance: ";
    cin >> a.balance;
    cout << "Enter rate: ";
    cin >> a.rate;
    cout << "Enter term: ";
    cin >> a.term;
}

int main()
{
    Account account;
    getData(account);

    cout << "Balance: " << account.balance << endl;
    cout << "Rate: " << account.rate << endl;
    cout << "Term: " << account.term << endl;
    
    return 0;
}