#include<iostream>
#include<algorithm>
#include <string>
using namespace std;
int main()
{
	string line;
	int arr[26] = { 0, };

	int maxcount = 0;
	int index = 0;
	int count = 0;

	cin >> line;

	transform(line.begin(), line.end(), line.begin(), ::toupper);

	for (int i = 0;i < line.length();i++)
	{
		int n = line[i];
		if(n<97)
			arr[n - 65]++;
	}

	for (int i = 0;i < 26;i++)
	{
		if (arr[i] > maxcount)
		{
			maxcount = arr[i];
			index = i;
		}
	}
	
	for (int i = 0;i < 26;i++)
	{
		if (arr[i] == maxcount)
		{
			count++;
			if (count >= 2)
			{
				cout << "?" << endl;
				return 0;
			}
		}
	}

	cout << (char)(index + 65) << endl;

	return 0;
}