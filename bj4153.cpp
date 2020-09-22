#include<iostream>
#include <algorithm>
using namespace std;
int main()
{
	int tri[3];

	while (true)
	{
		cin >> tri[0] >> tri[1] >> tri[2];
		sort(tri,tri+3);
		if (tri[0] == 0 && tri[1] == 0 && tri[2] == 0)
		{
			break;
		}
		
		if (tri[0]*tri[0] + tri[1] * tri[1] == tri[2] * tri[2])
		{
			cout << "right" << endl;
		}
		else
		{
			cout << "wrong" << endl;
		}
	}
	return 0;
}