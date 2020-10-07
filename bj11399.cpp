#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	const int max = 1000;
	int n;
	int person[max];

	cin >> n;

	for (int i = 0;i < n;i++)
	{
		cin >> person[i];
	}

	sort(person, person + n);

	int time = 0;
	for (int i = 0;i < n;i++)
		for (int j = 0;j <= i;j++)
			time += person[j];

	cout << time << endl;

	return 0;
}