#include <iostream>
using namespace std;

int main()
{
	int n, x;

	cin >> n >> x;

	int arr[10000];

	for (int i = 0;i < n;i++)
	{
		cin >> arr[i];
	}

	for (int i = 0;i < n;i++)
	{
		if (arr[i] < x)
			cout << arr[i]  << " ";
	}
	cout << "\n";

	return 0;
}	