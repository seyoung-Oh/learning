#include <iostream>
#include <time.h>

enum AI_MODE {
	AM_EASY = 1, 
	AM_HARD
};

using namespace std;

int main() {
	
	srand((unsigned int)time(0));
	int iNumber[25] = {};
	int iAiNumber[25] = {};

	for (int i = 0;i < 25;++i) {
		iNumber[i] = 1 + i;
		iAiNumber[i] = 1 + i;
	}
	int iTemp, idx1, idx2;

	for (int i = 0;i < 100;++i) {
		idx1 = rand() % 25;
		idx2 = rand() % 25;

		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;
		
		idx1 = rand() % 25;
		idx2 = rand() % 25;

		iTemp = iAiNumber[idx1];
		iAiNumber[idx1] = iAiNumber[idx2];
		iAiNumber[idx2] = iTemp;
	}
	 
	int iBingo = 0 , iAiBingo = 0;
	int iAIMode;
	//Ai난이도를 선택한다.
	while (true) {
		system("cls");
		cout << " 1, Easy " << endl;
		cout << " 2, Hard " << endl;
		cout << "AI모드를 선택하세요 : ";
		cin >> iAIMode;

		if (iAIMode >= AM_EASY || iAIMode <= AM_HARD)
			break;
	}
	/*
	AI이지모드는 현재 AI숫자 목록중 *로 바뀌지 않은 숫자 목록을 만들어서 그 목록 중 하나를 선택하게 한다
	*/

	int iNoneSelect[25] = {};

	int iNoneSelectCount = 0;
	while (true)
	{
		system("cls");

		cout << "==============Player================" << endl;
		for (int i = 0; i < 5; ++i) {
			for (int j = 0;j < 5;++j) {
				if (iNumber[i * 5 + j] == INT_MAX)
					cout << "*\t";
				else 
					cout << iNumber[i * 5 + j] << "\t";
			}
			cout << endl;
		}
		cout << "Bingo Line : " << iBingo << endl << endl;
		cout << "====================Ai==================" << endl;

		switch (iAIMode) {
		case AM_EASY:
			cout << "AIEASY MODE" << endl;
			break;
		case AM_HARD:
			cout << "AIHARD MODE" << endl;
			break;
		}
		for (int i = 0; i < 5; ++i) {
			for (int j = 0;j < 5;++j) {
				if (iAiNumber[i * 5 + j] == INT_MAX)
					cout << "*\t";
				else
					cout << iAiNumber[i * 5 + j] << "\t";
			}
			cout << endl;
		}
		cout << "AIBingo Line : " << iAiBingo << endl;
		//줄수가 5 이상인 경우 게임을 종료한다. 
		if (iBingo >= 5) {
			cout << "Player 승리" << endl;
			break;
		}
		else if (iAiBingo >= 5) {
			cout << "Ai 승리" << endl;
			break;
		}
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
		//중복이 아니라면 ai의 숫자도 찾아서 *로 바꿔주기
		for (int i = 0;i < 25;++i) {
			if (iInput == iAiNumber[i]) {
				iAiNumber[i] = INT_MAX;//*로 변경하기 위한 특수한 값
				break;
			}
		}
		//빙고 줄 수를 체크하는 것 매번 숫자를 입력할 때마다 처음부터 새로 카운트
		switch (iAIMode) {
		case AM_EASY:
			iNoneSelectCount = 0;
			for (int i = 0;i < 25;++i) {
				if (iAiNumber[i] != INT_MAX) {
					iNoneSelect[iNoneSelectCount] = iAiNumber[i];
					++iNoneSelectCount;
				}
			}
			iInput = iNoneSelect[rand() % iNoneSelectCount];
			break;
		case AM_HARD:
			break;
		}

		for (int i = 0;i < 25;++i) {
			if (iInput == iNumber[i]) {
				iNumber[i] = INT_MAX;//*로 변경하기 위한 특수한 값
				break;
			}
		}

		for (int i = 0;i < 25;++i) {
			if (iInput == iAiNumber[i]) {
				iAiNumber[i] = INT_MAX;//*로 변경하기 위한 특수한 값
				break;
			}
		}
		iBingo = 0;
		iAiBingo = 0;

		//가로 세로 줄 수를 구하기
		int iStar1 = 0, iStar2 = 0; //star1은 가로 ,star2는 세로 별 개수
		int iAIStar1 = 0, iAIStar2 = 0;
		for (int i = 0; i < 5;++i) {
			iStar1 = iStar2 = 0;
			iAIStar1 = iAIStar2 = 0;
			for (int j = 0;j < 5;++j) {
				if (iNumber[i * 5 + j] == INT_MAX)
					++iStar1;
				if (iNumber[j * 5 + i] == INT_MAX)
					++iStar2;
				if (iAiNumber[i * 5 + j] == INT_MAX)
					++iAIStar1;
				if (iAiNumber[j * 5 + i] == INT_MAX)
					++iAIStar2;
			}
			//j for문을 빠져나오면 가로 별 개수가 몇개인지 star1변수에 들어가게 됨
			if (iStar1 == 5)
				++iBingo;

			if (iStar2 == 5)
				++iBingo;

			if (iAIStar1 == 5)
				++iAiBingo;

			if (iAIStar2 == 5)
				++iAiBingo;
		}
		//왼쪽 상단 -> 오른쪽 하단 대각선 체크
		iStar1 = 0;
		iAIStar1 = 0;
		for (int i = 0;i < 25;i += 6) {
			if (iNumber[i] == INT_MAX)
				++iStar1;
			if (iAiNumber[i] == INT_MAX)
				++iAIStar1;
		}
		if (iStar1 == 5)
			++iBingo;
		if (iAIStar1 == 5)
			++iAiBingo;
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