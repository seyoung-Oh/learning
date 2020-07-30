#include <iostream>

using namespace std;

int main()
{	
	int n, total = 1;

	int buf[10] = { 0,0,0,0,0,0,0,0,0,0 };

	for (int i = 0; i < 3;i++)
	{
		cin >> n;
		total = total * n;
	}

	for (int i = 0; total > 0; i++)
	{
		n = total % 10;
		buf[n] += 1;
		total = total / 10;
	}

	for (int i = 0;i < 10;i++)
	{
		cout << buf[i] << endl;
	}
}