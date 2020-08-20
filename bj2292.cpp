#include <iostream>
using namespace std;

int main()
{
	int N,i;
	cin >> N;
	int movenum = 1;
	for (i = 1;i <= N;i++)
	{	
		movenum += (i - 1) * 6;
		if (N <= movenum)
			break;
	}
	cout << i << endl;

	return 0;

}	