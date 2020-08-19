#include <iostream>
using namespace std;

int main()
{
	int A, B, C;

	cin >> A >> B >> C;

	int n;

	if (B >= C)
		n = -1;
	else
		n = A / (C - B) + 1;

	cout << n << endl;
}	