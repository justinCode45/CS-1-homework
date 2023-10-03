/* File Name:HW1_112652044.cpp
 * Author:陳柏瑄
 * Email Address:justin.sc12@nycu.edu.tw
 * HW Number:1
 * Description:Print a triangle formed by characters
 * Last Change:Sep.16,2023
 * Anything special?
 * 1.Ability to output triangles of different heights.
 * 2.Output text coloring.
 * 3.Clear the input stream and handle input errors.
 * 4.Sierpinski triangle (The height of the triangle needs to be larger)
 * Complier:gcc version 13.1.0 (Rev7, Built by MSYS2 project),201703
*/
#include <iostream>
#include <limits>
#include <string>
#include <random>
#include <math.h>

//clear istream
#define clearCin std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n')
//print ">>"
#define printLL cout<<color(">> ",SGR::brightYellow)

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

//Color text
string color(string in,SGR c){
    return "\x1b["+to_string((int)c)+'m'+in+"\x1b[0m";
}

//Print triangle
void printTriangle(char a,int h){
    for(int i=0;i<h;i++){
        for(int j=1;j<(h-i);j++){
            cout<<' ';
        }
        for(int j=0;j<(2*i+1);j++){
            cout<<a;
        }
        cout<<endl;
    }
}

//Rrint Sierpinski triangle
void printTriangleS(char a,int h){
    SGR outColor[h][2*h-1]={SGR::brightRed};
    int index=0;
    //Use chaos game to generate Sierpinski triangle
    int px=h/2;
    int py=(2*h-1)/2;
    for(int i=0;i<pow(h,2);i++){
        outColor[px][py]=SGR::red; 
        switch (rand()%3)
        {
        case 0:
            px=(px+0)/2;
            py=(py+(2*h-1)/2)/2;
            break;
        case 1:
            px=(px+h)/2;
            py=(py+0)/2;
            break;
        case 2:
            px=(px+h)/2;
            py=(py+(2*h-2))/2;
            break;
        }
    }
    //Output colored triangle
    for(int i=0;i<h;i++){
        for(int j=1;j<(h-i);j++){
            cout<<' ';
            index++;
        }
        for(int j=0;j<(2*i+1);j++){
            cout<<color(string(1,a),
                        outColor[index/(2*h-1)][index%(2*h-1)]);
            index++;
        }
        index+=(h-i-1);
        cout<<endl;
    }
}

//Get character
char getChar(){
    char temp;
    cout<<"Enter a character:"<<endl;
    printLL;
    cin>>temp;
    cout<<"["<<color("Echoing",SGR::green)<<"] "<<"You entered: "<<temp<<endl;
    return temp;
}

//Get the height of triangle
int getHeight(){
    int temp;
    cout<<"Choose the height of the triangle (positive integer):"<<endl;
    printLL;
    while(1){
        clearCin;
        cin>>temp;
        if(cin.fail()){
            cin.clear();
            cout<<"["<<color("Input error",SGR::brightRed)<<"] ";
            cout<<"Please enter a positive integer:"<<endl;
            printLL;
        }
        else if(temp<0){
            cout<<"["<<color("Input error",SGR::brightRed)<<"] ";
            cout<<"Please enter a positive integer:"<<endl;
            printLL;
        }else{
            break;
        } 
        
    }
    cout<<"["<<color("Echoing",SGR::green)<<"] "<<"You entered: "<<temp<<endl;
    return temp;
}

//Ask if user want to continue
bool again(){   
    char temp;
    cout<<"Do you want to continue?(Y/N) :"<<endl;;
    printLL;
    while(1){
        clearCin;
        cin>>temp;
        if     (temp=='y' || temp=='Y'){
            clearCin;
            return true;
        } 
        else if(temp=='n' || temp=='N'){
            clearCin;
            return false;
        } 
        else{
            cout<<"Do you want to continue?(Y/N) :"<<endl;;
            printLL;
        }
    }
}

int main(){
    cout<<"This program will ask you to enter a character and"<<endl;
    cout<<"it will output a triangle formed by that character."<<endl;
    srand(time(NULL));
    while(1){
        char triangleChar=getChar();
        int hight=getHeight();
        printTriangleS(triangleChar,hight);
        // printTriangle(triangleChar,hight);
        if(!again()) break;
    }
    return 0;
}