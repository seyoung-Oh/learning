#include <iostream>
using namespace std;

int main()
{
	int n;

	int min = 1000001;
	int max = -1000001;
	int num = 0;
	cin >> n;

	for (int i = 0;i < n; i++)
	{
		cin >> num;
		if (num < min)
			min = num;
		if (num > max)
			max = num;
	}

	cout << min << " " << max << endl;
	
}