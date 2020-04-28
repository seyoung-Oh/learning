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

//�Լ��� ����� ���� �κ����� ���� �� �ִ�. 
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

		//�ټ��� 5 �̻��� ��� ������ �����Ѵ�. 
		if (iBingo >= 5) {
			cout << "Player �¸�" << endl;
			break;
		}
		else if (iAiBingo >= 5) {
			cout << "Ai �¸�" << endl;
			break;
		}
		cout << "���ڸ� �Է��ϼ���(0 : ����) : ";
		int iInput;
		cin >> iInput;

		if (iInput == 0)
			break;

		else if (iInput > 25 || iInput < 0)
			continue;

		bool bAcc = ChangeNumber(iNumber, iInput);//�ߺ��Է� üũ ����

		if (bAcc)
			continue;

		//�ߺ��� �ƴ϶�� ai�� ���ڵ� ã�Ƽ� *�� �ٲ��ֱ�
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
		cout << "AI��带 �����ϼ��� : ";
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
			pArray[i] = INT_MAX;//*�� �����ϱ� ���� Ư���� ��
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
	case AM_HARD: //���� ���� �� ������ �ϼ� ���ɼ��� ���� ���� ���� ã�´�
		int iLine = 0;
		int iStarCount = 0;
		int iSaveCount = 0;
		for (int i = 0;i < 5;++i) {
			for (int j = 0;j < 5;++j) {
				if (pArray[i * 5 + j] == INT_MAX)
					++iStarCount;
			}
			//���� 5�� �̸��̿��� ���� �� �ƴϰ� ������ ���� ���� ������ �� ���� Ŀ�� 
			//���� ���� ���� �����̹Ƿ� ������ ��ü���ְ� ����� �� ���� ��ü�Ѵ�.
			if (iStarCount < 5 && iSaveCount < iStarCount)
			{//���� ���� �� ���� ���� ���� �ڸ��� üũ
				iLine = i;
				iSaveCount = iStarCount;
			}

		}
		//���� ������ ���� ���� ���� ������ �̹� ���� 
		// �� ���� ���ζ��ε��� ���Ͽ� ���� ���� ���� ������ ���Ѵ�.
		for (int i = 0;i < 5;++i) {
			iStarCount = 0;
			for (int j = 0;j < 5;++j) {
				if (pArray[i * 5 + j] == INT_MAX)
					++iStarCount;
			}
			if (iStarCount < 5 && iSaveCount < iStarCount)
			{//���� ������ 5 ~ 9
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
		//������ -> ���� �밢�� üũ
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
		//��� ���� ���� �� iLine�� ���ɼ��� ���� ���� �� ��ȣ�� �����.
		if (iLine <= LN_H5)
		{
			//�������� ��� iLine�� 0~4������ ��
			for (int i = 0; i < 5;i++) {
				if (pArray[iLine * 5 + i] != INT_MAX)
				{
					return pArray[iLine * 5 + i];
				}
			}
		}
		else if (iLine <= LN_V5)
		{//�������� ��� iLine 5~9
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
		//j for���� ���������� ���� �� ������ ����� star1������ ���� ��
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
		//j for���� ���������� ���� �� ������ ����� star1������ ���� ��
		if (iStar1 == 5)
			++iBingo;
	}
	return iBingo;
}
int BingoCountingLTD(int *pArray) {
	//���� ��� -> ������ �ϴ� �밢�� üũ
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
	//������ ��� -> ���� �ϴ� �밢�� üũ
	int iStar1 = 0, iBingo = 0;
	for (int i = 4;i <= 20;i += 4) {
		if (pArray[i] == INT_MAX)
			++iStar1;
	}
	if (iStar1 == 5)
		++iBingo;
	return iBingo;
}
