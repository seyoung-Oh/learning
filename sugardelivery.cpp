#include<iostream>

using namespace std;

int main() {

	int n;
	cin >> n;
	int bag = -1;
	
	for (int i = 0; i < n; i++)
	{
		for(int j = 0; j<n;j++)
		{
			if (n == 5 * i + 3 * j) {
				bag = i + j;
				break;
			}
		}
	}

	cout << bag << endl;
}
