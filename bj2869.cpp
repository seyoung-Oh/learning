#include <iostream>
using namespace std;

int main()
{
	int a, b, v;

	cin >> a >> b >> v;

	int days;
	if ((v - a) % (a - b) == 0)
	{
		days = (v - a) / (a - b);
	}
	else
	{
		days = (v - a) / (a - b) + 1;
	}

	days++;

	cout << days << endl;

	return 0;

}	