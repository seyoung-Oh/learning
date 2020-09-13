#include <iostream>
using namespace std;

char shape[3000][3000];
void init(){
	for (int i = 0; i < 3000; ++i) {
		for (int j = 0; j < 3000; ++j) {
			shape[i][j] = ' ';
		}
	}
}
void star(int n, int x, int y) {
	int div = n / 3;
	if (n == 1) 
	{
		shape[x][y] = '*';
		return;
	}

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (i == 1 && j == 1) {
				continue;
			}
			//cout << "star( " << div << " , " << x + (div*i) << " , " << y + (div*j) << ") \n";
			star(div, x + (div * i), y + (div * j));
		}
	}
	return;
}

void print(int n)
{
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << shape[i][j];
		}
		cout << endl;
	}
}

int main()
{
	int n;
	cin >> n;
	init();
	star(n, 0, 0);
	print(n);

	return 0;
}