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
	//Ai���̵��� �����Ѵ�.
	while (true) {
		system("cls");
		cout << " 1, Easy " << endl;
		cout << " 2, Hard " << endl;
		cout << "AI��带 �����ϼ��� : ";
		cin >> iAIMode;

		if (iAIMode >= AM_EASY || iAIMode <= AM_HARD)
			break;
	}
	/*
	AI�������� ���� AI���� ����� *�� �ٲ��� ���� ���� ����� ���� �� ��� �� �ϳ��� �����ϰ� �Ѵ�
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

		bool bAcc = true;//�ߺ��Է� üũ ����
		for (int i = 0;i < 25;++i) {
			if (iInput == iNumber[i]) {
				bAcc = false;

				iNumber[i] = INT_MAX;//*�� �����ϱ� ���� Ư���� ��
				break;
			}
		}
		if (bAcc)
			continue;
		//�ߺ��� �ƴ϶�� ai�� ���ڵ� ã�Ƽ� *�� �ٲ��ֱ�
		for (int i = 0;i < 25;++i) {
			if (iInput == iAiNumber[i]) {
				iAiNumber[i] = INT_MAX;//*�� �����ϱ� ���� Ư���� ��
				break;
			}
		}
		//���� �� ���� üũ�ϴ� �� �Ź� ���ڸ� �Է��� ������ ó������ ���� ī��Ʈ
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
		case AM_HARD: //���� ���� �� ������ �ϼ� ���ɼ��� ���� ���� ���� ã�´�
			int iLine = 0 ;
			int iStarCount = 0;
			int iSaveCount = 0;
			for (int i = 0;i < 5;++i) {
				for (int j = 0;j < 5;++j) {
					if (iAiNumber[i * 5 + j] == INT_MAX)
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
					if (iAiNumber[i * 5 + j] == INT_MAX)
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
				if (iAiNumber[i] == INT_MAX)
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
				if (iAiNumber[i] == INT_MAX)
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
					if (iAiNumber[iLine * 5 + i] != INT_MAX)
					{
						iInput = iAiNumber[iLine * 5 + i];
						break;
					}
				}
			}
			else if (iLine <= LN_V5) 
			{//�������� ��� iLine 5~9
				for (int i = 0; i < 5;i++) {
					if (iAiNumber[i * 5 +(iLine - 5)] != INT_MAX)
					{
						iInput = iAiNumber[i * 5 + (iLine - 5)];
						break;
					}
				}
			}

			else if (iLine == LN_LT)
			{
				for (int i = 0;i < 25;i += 6) {
					if (iAiNumber[i] != INT_MAX) {
						iInput = iAiNumber[i];
						break;
					}
				}
			}

			else if (iLine == LN_RT)
			{
				for (int i = 0;i < 20;i += 4) {
					if (iAiNumber[i] != INT_MAX) {
						iInput = iAiNumber[i];
						break;
					}
				}
			}
			break;
		}

		for (int i = 0;i < 25;++i) {
			if (iInput == iNumber[i]) {
				iNumber[i] = INT_MAX;//*�� �����ϱ� ���� Ư���� ��
				break;
			}
		}

		for (int i = 0;i < 25;++i) {
			if (iInput == iAiNumber[i]) {
				iAiNumber[i] = INT_MAX;//*�� �����ϱ� ���� Ư���� ��
				break;
			}
		}
		iBingo = 0;
		iAiBingo = 0;

		//���� ���� �� ���� ���ϱ�
		int iStar1 = 0, iStar2 = 0; //star1�� ���� ,star2�� ���� �� ����
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
			//j for���� ���������� ���� �� ������ ����� star1������ ���� ��
			if (iStar1 == 5)
				++iBingo;

			if (iStar2 == 5)
				++iBingo;

			if (iAIStar1 == 5)
				++iAiBingo;

			if (iAIStar2 == 5)
				++iAiBingo;
		}
		//���� ��� -> ������ �ϴ� �밢�� üũ
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
		//������ ��� -> ���� �ϴ� �밢�� üũ
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