#include <iostream>
using namespace std;

int main()
{
	int n;
	int arr[1000];
	int temp;
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		cin >> arr[i];
	}
	for (int i = 0;i < n;i++)
	{
		for (int j = i+1;j < n;j++) {
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
	for (int i = 0;i < n;i++)
	{
		if (i + 1 < n && arr[i] == arr[i + 1])
			continue;
		cout << arr[i] << "\n";
	}

	return 0;
}	