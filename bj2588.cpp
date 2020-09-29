#include <iostream>

using namespace std;

int main()
{
	int a, b;

	cin >> a >> b;

	int b1, b2, b3;

	b1 = b / 100;
	b2 = b / 10 - b1 * 10;
	b3 = b % 10;
	cout << a * b3 << "\n";
	cout << a * b2 << "\n";
	cout << a * b1 << "\n";
	cout << a * b << "\n";
 	return 0;
}