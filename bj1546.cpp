#include <iostream>
using namespace std;

int main()
{
	int N;
	int highscore = 0;
	double total =0;
	int average;
	double doubscore[1000];
	cin >> N;

	int score[1000];

	for (int i = 0;i < N;i++)
	{
		cin >> score[i];
		if (score[i] > highscore) {
			highscore = score[i];
		}
	}

	for (int i = 0;i < N;i++)
	{
		doubscore[i] = ((score[i] / (double)highscore)) * 100;
		total += doubscore[i];
	}

	cout.precision(10);
	cout << total / (double)N << endl;

}