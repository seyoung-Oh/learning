#include <iostream>

using namespace std;

int main()
{	
	int numarr[9];
	int maxnum = 0;
	int maxnumidx;

	for (int i = 0; i < 9;i++)
	{
		cin >> numarr[i];
		if (numarr[i] > maxnum)
		{
			maxnum = numarr[i];
			maxnumidx = i + 1;
		}
	}

	cout << maxnum << endl;
	cout << maxnumidx << endl;

	return 0;

}