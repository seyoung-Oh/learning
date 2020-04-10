#include <iostream>
#include <time.h>
using namespace std;

int main(void)
{
	srand((unsigned int)time(0));

	int iNumber[9] = {};

	for (int i = 0;i < 9;++i) {
		iNumber[i] = i + 1;
	}

	int iTemp, idx1, idx2;
	for (int i = 0; i < 100;++i) {
		idx1 = rand() % 9;
		idx2 = rand() % 9;

		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;
	}

	cout << " * \t* \t* \t" << endl;

	int iStrike = 0, iBall = 0;
	int iInput[3];
	int iGamecount = 1;
	while (true)
	{
		cout << iGamecount << " 회" << endl;
		cout << "1 ~9사이의 숫자 3개를 입력하세요(0:종료) : ";
		cin >> iInput[0] >> iInput[1] >> iInput[2];

		if (iInput[0] == 0 || iInput[1] == 0 || iInput[2] == 0)
			break;
		else if (iInput[0] < 0 || iInput[0] > 9 || iInput[1] < 0 || iInput[1] > 9 || iInput[2] < 0 || iInput[2] > 9)
		{
			cout << "잘못된 숫자를 입력하였습니다. " << endl;
			continue;
		}
		else if (iInput[0] == iInput[1] || iInput[1] == iInput[2] || iInput[2] == iInput[0]) {
			cout << "중복된 숫자를 입력하였습니다. " << endl;
			continue;
		}

		iStrike = iBall = 0;

		for (int i = 0;i < 3;++i) {
			for (int j = 0;j < 3;++j) {
				if (iNumber[i] == iInput[j]) {
					if (i == j)
						++iStrike;
					else
						++iBall;
					/*
					입력받은 숫자와 맞춰야 할 숫자를 비교할 떄 같은 수가 있으면 이 뒤로는 더이상 같은 수가 없으므로 다음 맞춰야할 숫자로 바로 비교하면 된다.
					break사용해서 jfor문을 빠져나가고 ++i가 된 후 다음 맞춰야할 숫자와 다시 비교하게 한다.
					*/
					break;
				}
			}
		}
		if (iStrike == 3) {
			cout << "숫자를 모두 맞췄습니다" << endl;
			break;
		}
		else if (iStrike == 0 && iBall == 0)
			cout << "out" << endl;
		else
			cout << iStrike << " strike " << iBall << " ball " << endl;
		++iGamecount;
	}
	return 0;	

}

