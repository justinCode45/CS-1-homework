/* File Name:HW3_112652044.cpp
 * Author:Justin Chen
 * Email Address:justin.sc12@nycu.edu.tw
 * HW Number:3
 * Description:Calculate total loan repayment amount
 * Last Change:Sep.23,2023
 * Anything special?
 * 1.Output text coloring.
 * 2.Input error detection.
 * Complier:gcc version 13.1.0 (Rev7, Built by MSYS2 project),201703
*/
#include <iostream>
#include <limits>
#include <string>
#include <cmath>
#include <tuple>
#include <iomanip>

//clear istream
#define clearCin std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
//define some common outputs
#define color(in,c)     "\x1b["+to_string((int)c)+'m'+in+"\x1b[0m"
#define inputSign        color(">> ",SGR::brightYellow)
#define echo            "["<<color("Echoing",SGR::green)<<"] "
#define inputError      "["<<color("Input error",SGR::brightRed)<<"] "
//--------------------------
#define Male            0b1
#define Female          0b0
#define Superhero       0b10
#define Supervillain    0b00
#define Steak           0b100
#define Sushi           0b000
#define Anime           0b100
#define Sitocm          0b000
#define flat            0b111
#define Pompadour       0b011
#define bangs           0b110
#define bob             0b010
//----------------------------
typedef short HAIR;

using namespace std;

//ANSI SGR
enum class SGR{
    black=30,
    red,
    green,
    yellow,
    blue,
    magenta,
    cyan,
    white,
    brightBlack	=90,
    brightRed	,
    brightGreen	,
    brightYellow,
    brightBlue	,
    brightMagenta,
    brightCyan,
    brightWhite
};


double getAmount(){
    double temp;
    cout<<"\x1b[s"<<left<<setw(49)<<setfill('_')
        <<"Enter the amount needed (an int)"<<":";
    while(1){
        cin>>temp;
        if(cin.fail()){
            cin.clear();
            cout<<"\x1b[u\x1b[0J\x1b[s"<<left<<setw(58)<<setfill('_')
                <<"Enter the amount needed"+(string)color(" (an int)",SGR::brightRed)<<":";
        }
        else if(temp<0){
            cout<<"\x1b[u\x1b[0J\x1b[s"<<left<<setw(58)<<setfill('_')
                <<"Enter the amount needed"+(string)color(" (an int)",SGR::brightRed)<<":";
        }else{
            clearCin;
            break;
        } 
        clearCin;
    }
    return temp;
}
double getRate(){
    double temp;
    cout<<"\x1b[s"<<left<<setw(49)<<setfill('_')
        <<"Enter the interest rate (a real)"<<":";
    while(1){
        cin>>temp;
        if(cin.fail()){
            cin.clear();
            cout<<"\x1b[u\x1b[0J\x1b[s"<<left<<setw(58)<<setfill('_')
                <<"Enter the interest rate"+(string)color(" (a real)",SGR::brightRed)<<":";
        }
        else if(temp<0){
            cout<<"\x1b[u\x1b[0J\x1b[s"<<left<<setw(58)<<setfill('_')
                <<"Enter the interest rate"+(string)color(" (a real)",SGR::brightRed)<<":";
        }else{
            clearCin;
            break;
        } 
        clearCin;
    }
    return temp;
}
int getmonth(){
    double temp;
    cout<<"\x1b[s"<<"Enter the duration of the load in months (an int):";
    while(1){
        cin>>temp;
        if(cin.fail()){
            cin.clear();
            cout<<"\x1b[u\x1b[0J\x1b[s"
                <<"Enter the duration of the load in months"
                <<color(" (an int)",SGR::brightRed)<<":";
        }
        else if(temp<0){
            cout<<"\x1b[u\x1b[0J\x1b[s"
                <<"Enter the duration of the load in months"
                <<color(" (an int)",SGR::brightRed)<<":";
        }else{
            clearCin;
            break;
        } 
        clearCin;
    }
    return temp;
}
void getSex(HAIR& style){
    string in;
    if(in=="Male")      style|=Male;
    if(in=="Female")    style|=Female;
}

tuple<int,int,bool>compute(double amount,double rate,int month){
    tuple<int,int,bool> temp; //faceValue monthiyPayment Warraing
    double faceValue =(amount)/(1-rate*0.01*month*(1.f/12.f));
    double monPayment=faceValue/((double)month);
    if(faceValue>(1.5*amount)){
        get<2>(temp)=1;
    }
    get<0>(temp)=round(faceValue);
    get<1>(temp)=round(monPayment);
    return temp;
}
//Ask if user want to continue
bool again(){   
    char temp;
    cout<<"Do you want to continue?(Y/N) :"<<endl;;
    while(1){
        cout<<inputSign;
        cin>>temp;
        if     (temp=='y' || temp=='Y') return true;
        else if(temp=='n' || temp=='N') return false;
        else    cout<<"Do you want to continue?(Y/N) :"<<endl;
        clearCin;
    }
    
}

int main(){
    
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        





    }

    return 0;
}