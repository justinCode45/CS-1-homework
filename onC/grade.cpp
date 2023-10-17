#include <iostream>

using namespace std;


int main()
{
    char grade;
    cout<<"Enter your grade(a char in A, B, C, D, F):";
    cin>>grade;
    switch (grade)
    {
    case 'A':
        cout<<"Excellent!"<<endl;
        break;
    case 'B':
        cout<<"Good!"<<endl;
        break;
    case 'C':
        cout<<"Passing!"<<endl;
        break;
    case 'D':
    case 'F':
        cout<<"Not Good!"<<endl;
        break;
    default:
        cout<<"Invalid grade!"<<endl;
        break;
    }
    

    return 0;
}