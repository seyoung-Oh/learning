#include<iostream>
using namespace std;

int main()
{
	int n;
	long long int fib[91] = { 0, };

	fib[1] = 1;

	cin >> n;

	for (int i = 2;i <= n;i++)
	{
		fib[i] = fib[i - 2] + fib[i - 1];
	}

	cout << fib[n] << endl;
}