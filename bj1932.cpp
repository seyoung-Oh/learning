#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <deque>
using namespace std;
int arr[501][501];
int result[501][501];
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	for (int i = 0; i< n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> arr[i][j];
		}
	}
	result[0][0] = arr[0][0];
	for (int i = 1; i <n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) {
				result[i][j] = result[i - 1][j] + arr[i][j];
			}
			else if (j == i) {
				result[i][j] = result[i - 1][j - 1] + arr[i][j];
			}
			else {
				result[i][j] = max(result[i - 1][j], result[i - 1][j - 1]) + arr[i][j];
			}
		}
	}
	sort(result[n - 1], result[n - 1] + n);
	cout << result[n - 1][n - 1];

	return 0;
}
