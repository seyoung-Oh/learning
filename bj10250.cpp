#include <iostream>
using namespace std;

int main()
{
	int T;
	cin >> T;
	int h, w, n,count,roomnum;
	for (int i = 0;i < T;i++)
	{
		cin >> h >> w >> n;
		count = 0;
		for (int j = 1;j <= w;j++)
		{
			for (int k = 1; k <= h;k++)
			{
				count++;
				if (count == n)
				{
					roomnum = k * 100 + j;
					break;
				}
			}
		}
		cout << roomnum << endl;
	}
}	