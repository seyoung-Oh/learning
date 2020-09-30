#include <iostream>

using namespace std;

int main()
{
	int intrain[4];
	int outtrain[4];
	int cur = 0;
	int max = 0;

	for (int i = 0;i < 4;i++)
	{
		cin >> outtrain[i] >>intrain[i];
		cur = cur + intrain[i] - outtrain[i];
		if (max < cur)
			max = cur;
	}

	cout << max << "\n";

 	return 0;
}