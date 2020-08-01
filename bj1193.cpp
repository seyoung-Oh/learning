#include <iostream>
#define MAX_10000
using namespace std;

int main()
{
	int X;
	
	cin >> X;
	int i = 1;
	int s = 0;

	while (true)
	{
		if (X - i <= 0)
			break;
		X -= i;
		i++;
		s++;
		cout << X << " " << i << " " << s << " " << endl;
	}

	if (s % 2 == 0)
	{
		cout << s + 2 - X << "/" << X;
	}
	else
		cout << X << "/" << s + 2 - X;

	return 0;
}