#include <iostream>
using namespace std;
void HanoiTowerMove(int n,int from, int by, int to)
{
	if (n == 1)
	{
		cout << from << " " << to << "\n";
	}
	else
	{
		HanoiTowerMove(n - 1, from, to, by);
		cout << from << " " << to << "\n";
		HanoiTowerMove(n - 1, by, from, to);
	}
}
void HanoiNum(int x)
{
	int num = 1;
	while (--x)
	{
		num = num * 2 + 1;
	}
	cout << num << endl;
}
int main()
{
	int n;
	cin >> n;
	
	HanoiNum(n);
	HanoiTowerMove(n, 1, 2, 3);

	return 0;
}	