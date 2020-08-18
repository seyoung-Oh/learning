#include <iostream>
using namespace std;

int main()
{
	int H, M;

	cin >> H >> M;

	if (M >= 45) {
		M = M - 45;
	}
	else {
		if (H != 0) {
			H = H - 1;
			M = 15 + M;
		}
		else {
			H = 23;
			M = 15 + M;
		}
	}
	cout << H << " " << M << endl;

}	