#include <iostream>
#include "./dtime.h"

using namespace std;

int main()
{
    DTime clock, oldClock;
    cin >> clock;
    oldClock = clock;
    clock.advance(15);

    if (clock == oldClock)
        cout << "Something is wrong.";
    cout << "You entered " << oldClock << endl;
    cout << "15 minutes later the time will be " << clock << endl;
    
    clock.advance(2, 15);
    cout << "2 hours and 15 minutes later the time will be " << clock << endl;
    return 0;
}