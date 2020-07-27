#include <iostream>

using namespace std;

int main()
{
	int numarr[100];
	int n, m;

	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
	{
		cin >> numarr[i];
	}

	int maxnum = 0;

	for (int i = 0; i < n - 2; i++)
	{
		for (int j = i+1; j < n - 1;j++)
		{
			for (int k = j+1; k < n; k++)
			{
				if (m - (numarr[i] + numarr[j] + numarr[k]) >= 0 && maxnum < numarr[i] + numarr[j] + numarr[k])
				{
					maxnum = numarr[i] + numarr[j] + numarr[k];
					
				}
			}
		}
	}

	cout << maxnum << endl;

	return 0;
}