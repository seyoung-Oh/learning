#include <iostream>

using namespace std;

int main()
{

	int sum;
	int price[9];

	cin >> sum;
	for (int i = 0;i < 9;i++)
	{
		cin >> price[i];
		sum -= price[i];
	}
	
	cout << sum << endl;

	return 0;
}