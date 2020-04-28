#include <iostream>
#include <time.h>

enum AI_MODE {
	AM_EASY = 1,
	AM_HARD
};

enum LINE_NUMBER
{
	LN_H1,
	LN_H2,
	LN_H3,
	LN_H4,
	LN_H5,
	LN_V1,
	LN_V2,
	LN_V3,
	LN_V4,
	LN_V5,
	LN_LT,
	LN_RT
};

//함수는 선언과 정의 부분으로 나눌 수 있다. 
void SetNumber(int *pArray);
void Shuffle(int *pArray);
AI_MODE SelectAIMode();
void OutputNumber(int *pArray, int iBingo);
bool ChangeNumber(int *pArray, int iInput);
int SelectAINumber(int *pArray, AI_MODE eMode);
int BingoCounting(int *pArray);
int BingoCountingH(int *pArray);
int BingoCountingV(int *pArray);
int BingoCountingLTD(int *pArray);
int BingoCountingRTD(int *pArray);

using namespace std;

int main() {

	srand((unsigned int)time(0));
	int iNumber[25] = {};
	int iAiNumber[25] = {};

	SetNumber(iNumber);
	SetNumber(iAiNumber);

	Shuffle(iNumber);
	Shuffle(iAiNumber);

	int iBingo = 0, iAiBingo = 0;
	AI_MODE eAIMode = SelectAIMode();
	
	while (true)
	{
		system("cls");

		cout << "==============Player================" << endl;
		OutputNumber(iNumber, iBingo);

		cout << "====================Ai==================" << endl;

		switch (eAIMode) {
		case AM_EASY:
			cout << "AIEASY MODE" << endl;
			break;
		case AM_HARD:
			cout << "AIHARD MODE" << endl;
			break;
		}
		OutputNumber(iAiNumber, iAiBingo);

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

		bool bAcc = ChangeNumber(iNumber, iInput);//중복입력 체크 변수

		if (bAcc)
			continue;

		//중복이 아니라면 ai의 숫자도 찾아서 *로 바꿔주기
		ChangeNumber(iAiNumber, iInput);

		iInput = SelectAINumber(iAiNumber, eAIMode);

		ChangeNumber(iNumber, iInput);

		ChangeNumber(iAiNumber, iInput);

		iBingo = BingoCounting(iNumber);
		iAiBingo = BingoCounting(iAiNumber);

	}

	return 0;
}
void SetNumber(int *pArray) 
{
	for (int i = 0;i < 25;++i) 
	{
			pArray[i] = i + 1;
	}
}
void Shuffle(int *pArray) {
	int iTemp, idx1, idx2;

	for (int i = 0;i < 100;++i) {
		idx1 = rand() % 25;
		idx2 = rand() % 25;

		iTemp = pArray[idx1];
		pArray[idx1] = pArray[idx2];
		pArray[idx2] = iTemp;
	}
}
AI_MODE SelectAIMode() {
	int iAIMode;
	while (true) {
		system("cls");
		cout << " 1, Easy " << endl;
		cout << " 2, Hard " << endl;
		cout << "AI모드를 선택하세요 : ";
		cin >> iAIMode;

		if (iAIMode >= AM_EASY || iAIMode <= AM_HARD)
			break;
	}
	return (AI_MODE)iAIMode;
}

void OutputNumber(int *pArray, int iBingo) {
	for (int i = 0; i < 5; ++i) {
		for (int j = 0;j < 5;++j) {
			if (pArray[i * 5 + j] == INT_MAX)
				cout << "*\t";
			else
				cout << pArray[i * 5 + j] << "\t";
		}
		cout << endl;
	}

	cout << "Bingo Line : " << iBingo << endl << endl;
}

bool ChangeNumber(int *pArray, int iInput)
{
	for (int i = 0;i < 25;++i) {
		if (iInput == pArray[i]) {
			pArray[i] = INT_MAX;//*로 변경하기 위한 특수한 값
			return false;
		}
	}
	return true;
}
int SelectAINumber(int *pArray, AI_MODE eMode) {

	int iNoneSelect[25] = {};

	int iNoneSelectCount = 0;
	switch (eMode) {
	case AM_EASY:
		iNoneSelectCount = 0;
		for (int i = 0;i < 25;++i) {
			if (pArray[i] != INT_MAX) {
				iNoneSelect[iNoneSelectCount] = pArray[i];
				++iNoneSelectCount;
			}
		}
		return iNoneSelect[rand() % iNoneSelectCount];
	case AM_HARD: //현재 숫자 중 빙고줄 완성 가능성이 가장 높은 줄을 찾는다
		int iLine = 0;
		int iStarCount = 0;
		int iSaveCount = 0;
		for (int i = 0;i < 5;++i) {
			for (int j = 0;j < 5;++j) {
				if (pArray[i * 5 + j] == INT_MAX)
					++iStarCount;
			}
			//별이 5개 미만이여야 빙고 줄 아니고 기존에 가장 많은 라인의 별 보다 커야 
			//가장 별이 많은 라인이므로 라인을 교체해주고 저장된 별 수를 교체한다.
			if (iStarCount < 5 && iSaveCount < iStarCount)
			{//가로 라인 중 가장 별이 많은 자리를 체크
				iLine = i;
				iSaveCount = iStarCount;
			}

		}
		//가로 라인중 가장 별이 많은 라인은 이미 구함 
		// 이 값과 세로라인들을 비교하여 별이 가장 많은 라인을 구한다.
		for (int i = 0;i < 5;++i) {
			iStarCount = 0;
			for (int j = 0;j < 5;++j) {
				if (pArray[i * 5 + j] == INT_MAX)
					++iStarCount;
			}
			if (iStarCount < 5 && iSaveCount < iStarCount)
			{//세로 라인은 5 ~ 9
				iLine = i + 5;
				iSaveCount = iStarCount;
			}
		}
		iStarCount = 0;
		for (int i = 0;i < 25;i += 6) {
			if (pArray[i] == INT_MAX)
				++iStarCount;
		}
		if (iStarCount < 5 && iSaveCount < iStarCount)
		{
			iLine = LN_LT;
			iSaveCount = iStarCount;
		}
		//오른쪽 -> 왼쪽 대각선 체크
		iStarCount = 0;
		for (int i = 4;i <= 20;i += 4) {
			if (pArray[i] == INT_MAX)
				++iStarCount;
		}
		if (iStarCount < 5 && iSaveCount < iStarCount)
		{
			iLine = LN_RT;
			iSaveCount = iStarCount;
		}
		//모든 라인 조사 후 iLine에 가능성이 가장 높은 줄 번호가 저장됨.
		if (iLine <= LN_H5)
		{
			//가로줄일 경우 iLine이 0~4사이의 값
			for (int i = 0; i < 5;i++) {
				if (pArray[iLine * 5 + i] != INT_MAX)
				{
					return pArray[iLine * 5 + i];
				}
			}
		}
		else if (iLine <= LN_V5)
		{//세로줄일 경우 iLine 5~9
			for (int i = 0; i < 5;i++) {
				if (pArray[i * 5 + (iLine - 5)] != INT_MAX)
				{
					return pArray[i * 5 + (iLine - 5)];
				}
			}
		}

		else if (iLine == LN_LT)
		{
			for (int i = 0;i < 25;i += 6) {
				if (pArray[i] != INT_MAX) {
					return pArray[i];
				}
			}
		}

		else if (iLine == LN_RT)
		{
			for (int i = 0;i < 20;i += 4) {
				if (pArray[i] != INT_MAX) {
					return pArray[i];
				}
			}
		}
		break;
	}
	return -1;
}
int BingoCounting(int *pArray) {
	int iBingo = 0;

	iBingo += BingoCountingH(pArray);
	iBingo += BingoCountingV(pArray);
	iBingo += BingoCountingLTD(pArray);
	iBingo += BingoCountingRTD(pArray);

	return iBingo;

}
int BingoCountingH(int *pArray) {
	int iStar1 = 0, iBingo = 0;
	for (int i = 0; i < 5;++i) {
		iStar1 = 0;
		for (int j = 0;j < 5;++j) {
			if (pArray[i * 5 + j] == INT_MAX)
				++iStar1;
		}
		//j for문을 빠져나오면 가로 별 개수가 몇개인지 star1변수에 들어가게 됨
		if (iStar1 == 5)
			++iBingo;
	}
	return iBingo;
	
}

int BingoCountingV(int *pArray) {
	int iStar1 = 0, iBingo = 0;
	for (int i = 0; i < 5;++i) {
		iStar1 = 0;
		for (int j = 0;j < 5;++j) {
			if (pArray[j * 5 + i] == INT_MAX)
				++iStar1;
		}
		//j for문을 빠져나오면 가로 별 개수가 몇개인지 star1변수에 들어가게 됨
		if (iStar1 == 5)
			++iBingo;
	}
	return iBingo;
}
int BingoCountingLTD(int *pArray) {
	//왼쪽 상단 -> 오른쪽 하단 대각선 체크
	int iStar1 = 0, iBingo = 0;
	for (int i = 0;i < 25;i += 6) {
		if (pArray[i] == INT_MAX)
			++iStar1;
	}
	if (iStar1 == 5)
		++iBingo;
	return iBingo;
}
int BingoCountingRTD(int *pArray) {
	//오른쪽 상단 -> 왼쪽 하단 대각선 체크
	int iStar1 = 0, iBingo = 0;
	for (int i = 4;i <= 20;i += 4) {
		if (pArray[i] == INT_MAX)
			++iStar1;
	}
	if (iStar1 == 5)
		++iBingo;
	return iBingo;
}
