#include <iostream>
#include <time.h>
using namespace std;

int main(void)
{
	cout << "야구 게임 시작 ! " << endl;
	srand((unsigned int)time(0));

	int iBaseball[9] = {};

	for (int i = 0; i < 9;++i) {
		iBaseball[i] = i + 1;
	}

	int iTemp, idx1, idx2;

	for (int i = 0; i < 100; i++) {
		idx1 = rand() % 9;
		idx2 = rand() % 9;

		iTemp = iBaseball[idx1];
		iBaseball[idx1] = iBaseball[idx2];
		iBaseball[idx2] = iTemp;
	}
	
	cout << "  *  *  *  " << endl;
	
	int iArray[3];
	int iCount = 0;

	while(true){
		cin >> iArray[0] >> iArray[1] >> iArray[2];
		iCount += 1;
		int iStrike = 0;
		int iBall = 0;
		
		if (iArray[0] == 0 || iArray[1] == 0 || iArray[2] == 0) {
			cout << "Game End";
			break;
		}
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < 3;++j) {
				if (iBaseball[i] == iArray[j]) {
					if (i == j) {
						iStrike += 1;
					}
					else {
						iBall += 1;
					}
				}
			}
		}
		
		if (iStrike == 3) {
			cout << "3 strike you win!" << endl;
			cout << iCount << "번째 시도 만에 성공" << endl;
			break;
		}
		
		else {
			if (iStrike != 0 || iBall != 0) {
				cout << iStrike << " strike , " << iBall << " ball" << endl;
			}
			else {
				cout << " out " << endl;
			}
		}
		cout << iCount << "번째 시도 " << endl;
		
	}

	return 0;

}

