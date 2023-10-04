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
#include <functional>

//clear istream
#define clearCin std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
//define some common outputs
#define color(in,c)     "\x1b["+to_string((int)c)+'m'+in+"\x1b[0m"
#define inputSign        color(">> ",SGR::brightYellow)
#define echo            "["<<color("Echoing",SGR::green)<<"] "
#define inputError      "["<<color("Input error",SGR::brightRed)<<"] "
//--------------------------



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


class HairStyle{
public:
    
    function<HairStyle*()> run ;
    std::pair<string,string> result;
    HairStyle(){
        run=std::bind(getSex,this);
    }
    HairStyle* getSex(){
        string in ;
        cin>>in;
        if (in=="Male"){
            run=std::bind(getSuperM,this);    
        }
        else if (in=="Female"){
            run=std::bind(getSuperF,this);
        }
        return this;
    }
    HairStyle* getSuperM(){
        string in ;
        cin>>in;
        if (in=="Superhero"){ 
            run=std::bind(getFood,this);    
        }
        else if (in=="Supervillain") {
            result={"Male Supreuillain","mohawk"};
            run=std::bind(nothing,this);
        }
        return this;
    }
    HairStyle* getSuperF(){
        string in ;
        cin>>in;
        if (in=="Superhero"){
            run=std::bind(getMovie,this);    
        }
        else if (in=="Supervillain") {
            result={"Female Supreuillain","mohawk"};
            run=std::bind(nothing,this);
        }
        return this;
    }
    HairStyle* getFood(){
        string in ;
        cin>>in;
        if ( in == "Steak" ){
            result={"Male Suprehero steak","flat top"};
            run=std::bind(nothing,this);    
        }
        else if ( in == "Sushi" ){
            result={"Male Suprehero sushi","pompadour"};
            run=std::bind(nothing,this);    
        }
        return this;
    }
    HairStyle* getMovie(){
        string in ;
        cin>>in;
        if ( in == "anime" ){
            result={"Female Suprehero anime","bangs"};
            run=std::bind(nothing,this);    
        }
        else if ( in == "Sticom" ){
            result={"Male Suprehero sticom","bob"};
            run=std::bind(nothing,this);    
        }
        return this;
    }
    HairStyle* nothing(){
        run=std::bind(nothing,this);
        return this;
    }
    HairStyle* getStep(){
        return this;
    }


};

template<typename T>
T getInput(function<bool(T)> check){
    T inp;
    while(1){
        cin>>inp;
        if(cin.fail()){
            cin.clear();
            
            cout<<"\x1b[u\x1b[0J\x1b[s"
                <<"Enter the duration of the load in months"
                <<color(" (an int)",SGR::brightRed)<<":";
            
            clearCin;
            continue;
        }
        if(!check(inp)){
            
            cout<<"\x1b[u\x1b[0J\x1b[s"
                <<"Enter the duration of the load in months"
                <<color(" (an int)",SGR::brightRed)<<":";
            
            clearCin;
            continue;
        }
        
        clearCin;
        break;
    }
    return inp;
}



typedef HairStyle Step;

int main(){
    
    int n;
        
    cin>>n;
    for(int i=0;i<n;i++){

        HairStyle* style=new HairStyle();
        
        Step* getSex=style->getStep();
        auto getSuper = getSex->run();
        auto getLast  = getSuper->run();
        auto stop     = getLast->run();


        cout<<style->result.first<<" "<<style->result.second<<endl;
        
        delete style;
    }

    return 0;
}