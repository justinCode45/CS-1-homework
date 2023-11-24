#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;


int main()
{
    vector<int> v;

    cout << "Enter a list of positive integers.\n";
    cout << "Enter a negative integers to end the list.\n";


    while (1)
    {
        int n;
        cin >> n;
        if (n < 0)
        {
            break;
        }
        v.push_back(n);
        cout << setw(10) << n <<"is added. v.size() = " << v.size() << endl;
    }
    cout << "v.capcity() = " << v.capacity() << endl;
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}