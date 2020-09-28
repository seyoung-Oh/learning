#include <iostream>

using namespace std;

int main()
{
	int num[5];
	int total = 0;
	for (int i = 0;i < 5;i++)
	{
		cin >> num[i];
		total += num[i] * num[i];
	}

	cout << total % 10 << "\n";

	return 0;
}