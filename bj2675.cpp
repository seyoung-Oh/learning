#include<iostream>
#include <string>
using namespace std;
int main()
{
	int n;
	string s;
	int r;
	cin >> n;

	for (int i = 0;i < n;i++)
	{
		
		cin >> r;
		cin >> s;
		for (int j = 0;j < s.length();j++) {
			for (int q = 0;q < r;q++)
			{
				cout << s[j];
			}
		}
		cout << endl;

	}
	return 0;
}