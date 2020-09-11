#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int narr[1000];
	int n;
	int sum = 0;
	cin >> n;

	for (int i = 0;i < n;i++)
	{
		cin >> narr[i];
	}

	sort(narr, narr + n);

	for (int i = 0;i < n;i++)
	{
		if (sum + 2 <= narr[i])
			break;
		sum += narr[i];
	}

	cout << sum + 1 << endl;
}