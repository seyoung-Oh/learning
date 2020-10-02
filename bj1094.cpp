#include <iostream>

using namespace std;

int main()
{
	int count = 0;
	int x;
	cin >> x;

	while (x !=0)
	{
		if (x % 2 == 1)
			count++;
		x /= 2;
	}
	cout << count << endl;
 	return 0;
}