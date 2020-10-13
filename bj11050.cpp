#include <iostream>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	int fac[11];
	fac[0] = 1;
	fac[1] = 1;
	fac[2] = 2;
	for (int i = 3;i < 11;i++)
	{
		fac[i] = i * fac[i - 1];
	}

	cout << fac[n] / fac[n - k] / fac[k] << endl;
	return 0;
}
