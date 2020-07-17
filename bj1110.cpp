#include <iostream>
using namespace std;

int main()
{
	int num, fnum = 0;
	int a, b = 0;
	int count = 1;
	cin >> num;
	fnum = num;
	while (true)
	{
		if (num < 10)
		{
			a = 0;
			b = num;
		}
		else {
			a = num / 10;
			b = num % (a * 10);
		}
		num = (b * 10) + ((a + b) % 10);
		if (fnum == num)
			break;
		++count;
	}
	cout << count << endl;

	return 0;
}