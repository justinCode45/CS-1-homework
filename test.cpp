#include <iostream>
#include <functional>
#include <tuple>
using namespace std;

int main()
{
    tuple<int, int> t;
    t = make_tuple(1, 2);
    int m = get<0>(t);
    cout << m << endl;
    apply([](auto &...x)
          { ( (cout << ... << x) << " "); },
          t);
    cout<<endl;
    m+=1;
    cout << m << endl;
    apply([](auto &...x)
          { ( (cout << ... << x) << " "); },
          t);
    get<0>(t) = 3;
    cout << m << endl;
    apply([](auto &...x)
          { ( (cout << ... << x) << " "); },
          t);


    return 0;
}
