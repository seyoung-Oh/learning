#include<iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;

	int num[10003] = { 0, };
	int arr[10003] = { 0, };
	int fin = 0;
	cin >> n;

	for (int i = 3;i < n+3;i++)
	{
		cin >> num[i];
	}


	for (int i = 3;i < n+3;i++)
	{
		arr[i] = max(arr[i - 3] + num[i - 1] + num[i], arr[i - 2] + num[i]);
		arr[i] = max(arr[i - 1], arr[i]);
		fin = max(fin, arr[i]);
	}

	cout << fin << endl;

	return 0;
}