#include <iostream>
using namespace std;

int main()
{
	int N;
	int sum = 0;
	cin >> N;

	char arr[100];

	for (int i = 1; i <= N;i++)
	{
		cin >> arr[i];
		sum += arr[i] - '0';
	}

	cout << sum << endl;

	return 0;
}