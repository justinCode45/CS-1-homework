#include <iostream>
#include <functional>
#include <tuple>
#include <sstream>
#include <csignal>
#include <windows.h>
using namespace std;

template <typename... T>
double avg(T... x)
{
	int num = sizeof...(x);
	int sum = (x + ...);
	double ans = (double)sum / (double)num;
	return ans;
}
void test(int &&k)
{
	cout << k << endl;
}
int main()
{
	test(10 + 23);

	return 0;
}
