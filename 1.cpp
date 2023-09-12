#include <iostream>

using namespace std;

int main(){
    int a,b;
    char ans;
    
    cout<<"The purpose of this program is to cout smaller one of integers a and b."<<endl;
    cout<<"If a<=b,then cout a;otherwise,cout b."<<endl;

    do{
        cout<<endl<<"Enter a and b: ";
        cin>>a>>b;
        cout<<"Echoing- you entered: "<<a<<" "<<b<<endl;
        
        if(a<=b) cout<<"The smaller is "<<a<<endl;
        else cout<<"The smaller is "<<b<<endl;
        
        cout<<"Do you want to continue?Press y for yes,n for no:";
        cin>>ans; 
        
    }while(ans=='y' || ans=='Y');
    
    
    return 0;
}