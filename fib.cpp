#include<iostream>

using namespace std;

int main() {

	int T = 0;
	
	int fib0[41] = { 1,0,1 };
	int fib1[41] = { 0,1,1 };

	cin >> T;

	for (int i = 3;i <= 41; ++i)
	{
		fib0[i] = fib0[i - 1] + fib0[i - 2];
		fib1[i] = fib1[i - 1] + fib1[i - 2];
	}

	for (int i = 0; i < T; ++i)
	{
		int n = 0;
		cin >> n;
		cout << fib0[n] << " " << fib1[n] << endl;
	}

	return 0;
}
