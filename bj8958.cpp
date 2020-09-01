#include <iostream>
using namespace std;

int main()
{
	int t;
	char urs[80] = { 0, };
	int count, sum;
	cin >> t;

	for (int i = 0;i < t;i++)
	{
		count = 0;
		sum = 0;
		cin >> urs;
		for (int j = 0;urs[j] != 0;j++)
		{
			if (urs[j]=='O')
			{
				count++;
				sum += count;
			}
			else
			{
				count = 0;
			}
		}
		cout << sum << endl;
	}

	return 0;
}	