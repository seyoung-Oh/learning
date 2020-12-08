#include <iostream>

using namespace std;
int dp[1001] = { 0,1,0,1,1 };

void stone(int n)
{
	if (n > 4) {
		for (int i = 5;i <= n;i++) {
			if (dp[i - 1] + dp[i - 3] + dp[i - 4] < 3)
				dp[i] = 1;
			else
				dp[i] = 0;
		}

	}
}
int main()
{
	int n;
	cin >> n;
	stone(n);
	if (dp[n] == 1)
		cout << "SK" << endl;
	else
		cout << "CY" << endl;

	return 0;

}