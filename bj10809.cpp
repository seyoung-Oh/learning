#include<iostream>
using namespace std;
int main()
{
	char s[101] = { NULL };
	int num[26] = { 0, };

	cin >> s;

	for (int i = 'a';i <= 'z';i++)
	{
		for(int j = 0;j<100;j++)
		{
			if (s[j] == i) {
				num[i - 97] = j + 1;
				break;
			}
		}
	}
	for (int i = 0;i < 26;i++)
	{
		cout << num[i] - 1 << " "; 
	}

	cout << "\n";
}