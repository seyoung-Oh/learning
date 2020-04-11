#include <iostream>
#include <time.h>

using namespace std;

int main() {
	
	srand((unsigned int)time(0));
	int iNumber[25] = {};
	for (int i = 0;i < 25;++i) {
		iNumber[i] = 1 + i;
	}
	int iTemp, idx1, idx2;

	for (int i = 0;i < 100;++i) {
		idx1 = rand() % 25;
		idx2 = rand() % 25;

		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;
	}
	 
	int iBingo = 0;
	while (true)
	{
		system("cls");

		for (int i = 0; i < 5; ++i) {
			for (int j = 0;j < 5;++j) {
				if (iNumber[i * 5 + j] == INT_MAX)
					cout << "*\t";
				else 
					cout << iNumber[i * 5 + j] << "\t";
			}
			cout << endl;
		}
		cout << "Bingo Line : " << iBingo << endl;
		//줄수가 5 이상인 경우 게임을 종료한다. 
		if (iBingo >= 5)
			break;
		cout << "숫자를 입력하세요(0 : 종료) : ";
		int iInput;
		cin >> iInput;

		if (iInput == 0)
			break;

		else if (iInput > 25 || iInput < 0)
			continue;

		bool bAcc = true;//중복입력 체크 변수
		for (int i = 0;i < 25;++i) {
			if (iInput == iNumber[i]) {
				bAcc = false;

				iNumber[i] = INT_MAX;//*로 변경하기 위한 특수한 값
				break;
			}
		}
		if (bAcc)
			continue;

		//빙고 줄 수를 체크하는 것 매번 숫자를 입력할 때마다 처음부터 새로 카운트

		iBingo = 0;

		//가로 세로 줄 수를 구하기
		int iStar1 = 0, iStar2 = 0; //star1은 가로 ,star2는 세로 별 개수
		for (int i = 0; i < 5;++i) {
			iStar1 = iStar2 = 0;

			for (int j = 0;j < 5;++j) {
				if (iNumber[i * 5 + j] == INT_MAX)
					++iStar1;
				if (iNumber[j * 5 + i] == INT_MAX)
					++iStar2;
			}
			//j for문을 빠져나오면 가로 별 개수가 몇개인지 star1변수에 들어가게 됨
			if (iStar1 == 5)
				++iBingo;

			if (iStar2 == 5)
				++iBingo;
		}
		//왼쪽 상단 -> 오른쪽 하단 대각선 체크
		iStar1 = 0;
		for (int i = 0;i < 25;i += 6) {
			if (iNumber[i] == INT_MAX)
				++iStar1;
		}
		if (iStar1 == 5)
			++iBingo;
		//오른쪽 상단 -> 왼쪽 하단 대각선 체크
		iStar1 = 0;
		for (int i = 4;i <= 20;i += 4) {
			if (iNumber[i] == INT_MAX)
				++iStar1;
		if (iStar1 == 5)
			++iBingo;
		}
	}

	return 0;
}