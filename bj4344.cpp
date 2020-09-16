#include<iostream>
#include <memory.h>
using namespace std;

int main()
{
	int c;
	cin >> c;

	int n;
	int arr[1000];
	int sum, count;
	float average;

	for (int i = 0;i < c;i++)
	{
		cin >> n;
		sum = 0;
		for (int j = 0;j < n;j++)
		{
			cin >> arr[j];
			sum += arr[j];
		}

		average = sum / n;
		count = 0;
		for (int j = 0;j < n;j++)
		{
			if (average < arr[j])
				count++;
		}
		cout << fixed;
		cout.precision(3);
		cout << (float)count / n*100 << "%" << endl;
	}
	return 0;
}