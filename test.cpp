#include <iostream>
#include <functional>

using namespace std;

void t(function<void(int)> h){
    h(11);
}

int main(){

    auto p =[](int x)->void {cout<<( x>10);};
    
    // cout<<p(11)<<endl;
    t(p);
    return 0;
}

