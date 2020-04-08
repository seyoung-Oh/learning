#include <iostream>
#include <time.h>
using namespace std;

int main(void)
{

	srand((unsigned int)time(0));

	int iLotto[45] = {};

	//1~45 까지의 숫자를 차례대로 보여준다. 
	for (int i = 0; i < 45; ++i) 
	{
		iLotto[i] = i + 1;
	}

	//Shuffle swap 알고리즘
	int iTemp, idx1, idx2; 

	for (int i = 0;i < 100;++i) {
		idx1 = rand() % 45;
		idx2 = rand() % 45;

		iTemp = iLotto[idx1];
		iLotto[idx1] = iLotto[idx2];
		iLotto[idx2] = iTemp;
	}

	for (int i = 0; i < 6; ++i)
	{
		cout << iLotto[i] << "\t";
	}

	cout << "보너스 번호 : " << iLotto[6] << endl;


	return 0;

}
