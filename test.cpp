#include<iostream>
#include<cstdlib>
#include<ctime>
#include<iomanip>

using namespace std;

volatile sig_atomic_t stop = 0;
void signalHandler(int signum)
{
	cout<<"in signal handler"<<endl;
	stop = 1;
}

int main()
{
	
	signal(SIGINT, signalHandler);
	for (int i = 0; !stop; i++)
	{
		string s ="12";
		getline(cin, s);
		cout << s << endl;
	}

	return 0;
}