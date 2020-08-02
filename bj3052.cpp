#include <iostream>
using namespace std;

int main()
{
	int innum;
	int divarr[42] = { 0. };
	int divnum = 0;
	
	for (int i = 0;i < 10;i++)
	{
		cin >> innum;
		if (divarr[innum % 42] == 0)
		{
			divarr[innum % 42] = 1;
			divnum++;
		}
	}

	cout << divnum << endl;

}