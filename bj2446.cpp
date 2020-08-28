#include <iostream>
using namespace std;

int main()
{
	int n;
	int i, j, k;
	cin >> n;

	for (i = 0;i <n;i++)
	{
		for ( j = 0; j < i;j++)
			cout << " ";

		for ( k = 2 * (n - i - 1);k >= 0;k--)
			cout << "*";

		cout << "\n";
	}
	for ( i = 2;i <= n;i++)
	{
		for ( j = 1;j <= n - i;j++)
			cout << " ";

		for ( k = 0;k <= 2 * (i - 1);k++)
			cout << "*";

		cout << "\n";
	}
}	