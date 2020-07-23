#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	int T;
	cin >> T;
	int temp = 0;
	int *arr = new int[T];
	int *dp = new int[T];

	for (int i = 0; i < T; ++i)
	{
		cin >> arr[i];
	}

	dp[0] = arr[0];
	dp[1] = max(arr[0] + arr[1], arr[1]);
	dp[2] = max(arr[0] + arr[2], arr[1] + arr[2]);

	for (int i = 3; i < T;i++)
	{
		dp[i] = max(dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i]);
	}
	cout << dp[T - 1] << endl;

	delete[] arr;

	return 0;

}
