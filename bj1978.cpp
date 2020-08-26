#include <iostream>
using namespace std;

int main()
{
	int n, i, j;
	cin >> n;
	int num;
	int count = 0;
	int f = 0;
	for (i = 0;i < n;i++)
	{
		cin >> num;
		f = 0;
		if (num == 1)
			continue;

		for (j = 2;j < num;j++)
		{
			if (num % j == 0)
				f=1;
		}
		if (f == 0)
			count++;
	}
	cout << count << "\n";
	return 0;
}	