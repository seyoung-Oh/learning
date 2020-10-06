#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int cyresult[1010];

	cyresult[1] = 1;
	cyresult[2] = 0;
	cyresult[3] = 1;

	for (int i = 4;i <= n;i++)
	{
		if (cyresult[i - 1] == 0 || cyresult[i - 3] == 0)
			cyresult[i] = 1;
		else
			cyresult[i] = 0;
	}

	if (cyresult[n] == 1)
		cout << "CY\n";
	else
		cout << "SK\n";
	

	return 0;
}