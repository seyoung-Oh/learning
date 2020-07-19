#include<iostream>
#include<algorithm>
using namespace std;
int d[1000001], n;
int main() {
	cin >> n;
	d[1] = 0;
	for (int i = 2; i <= n; i++) {
		d[i] = d[i - 1] + 1;
		if (i % 2 == 0) 
			d[i] = min(d[i / 2] + 1, d[i]);
		if (i % 3 == 0) 
			d[i] = min(d[i / 3] + 1, d[i]);
	}
	cout << d[n] << endl;
	return 0;
}
