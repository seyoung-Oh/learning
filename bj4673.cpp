#include<iostream>
using namespace std;
int num[10001];
int selfnum(int n)
{
	int num = n;
	while (n != 0)
	{
		num += n % 10;
		n = n / 10;
	}
	return num;
}
int main()
{
	int temp;
	for (int i = 1;i < 10001;i++)
	{
		temp = selfnum(i);
		if (temp < 10001)
			num[temp] = 1;
	}
	for (int i = 1;i < 10001;i++)
	{
		if (num[i] != 1)
			cout << i << "\n";
	}
	
	return 0;
}