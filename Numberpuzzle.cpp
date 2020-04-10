#include <iostream>
#include <time.h>
//console input output��� ����. �ܼ�â���� ����� �ϴ� ��ɵ��� �������ִ� �������
#include<conio.h>

using namespace std;

int main()
{
	srand((unsigned int)time(0));

	int iNumber[25] = {};

	for (int i = 0;i < 24;++i) 
	{
		iNumber[i] = i + 1;
	}
	//���� ������ ĭ�� �������� ����д�. ������ �ǹ��ϴ� ������ Ư���� ���� ����Ұǵ� INT_MAX��� ���� ����� ���̴�. 
	//INT_MAX�� �̹� ���ǵǾ� �ִ� ������ int�� ǥ���� �� �ִ� �ִ밪�̴�.

	iNumber[24] = INT_MAX;

	//������ ������ �����ϰ� 1~24������ ���ڸ� �����ش�. �� �ε����� 0~23������ �����ش�
	int iStaridx = 24;
	int iTemp, idx1, idx2;

	for (int i = 0;i < 100;++i) {
		idx1 = rand() % 24;
		idx2 = rand() % 24;

		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;
	}

	while (true) {
		system("cls");//ȭ�� �����
		//i for���� ���θ� �ǹ�
		for (int i = 0; i < 5;++i)
		{
			//j for���� ���θ� �ǹ�
			for (int j = 0;j < 5;++j) {
				if (iNumber[i * 5 + j] == INT_MAX)
					cout << "*\t";
				else
					cout << iNumber[i * 5 + j] << "\t"; //�ٹ�ȣ * ���ΰ��� + ĭ��ȣ
			}
			cout << endl;
		}
		bool bWin = true;

		for (int i = 0; i < 24; ++i) {
			if (iNumber[i] != i + 1) {
				bWin = false;
				break;
			}
		}
		if (bWin == true) {
			cout << "���ڸ� ��� ������ϴ�." << endl;
			break;
		}
		cout << "w : �� s : �Ʒ� a : ���� d : ������ q : ���� ";
		char cinput = _getch();//���� 1���� �Է¹޴� �Լ�. enter���ĵ� ���ڸ� ������ ���� �ٷ� �� ���� ��ȯ�ϰ� ����ȴ�.
		if (cinput == 'q' || cinput == 'Q')
			break;
		switch (cinput) {
		case 'w':
		case 'W':
			if (iStaridx >= 5) {
				iNumber[iStaridx] = iNumber[iStaridx - 5];
				iNumber[iStaridx - 5] = INT_MAX;
				iStaridx -= 5;
			}
			break;
		case 's':
		case 'S':
			if (iStaridx <= 19) {
				iNumber[iStaridx] = iNumber[iStaridx + 5];
				iNumber[iStaridx + 5] = INT_MAX;
				iStaridx += 5;
			}
			break;
		case 'a':
		case 'A':
			if (iStaridx % 5 != 0) {
				iNumber[iStaridx] = iNumber[iStaridx - 1];
				iNumber[iStaridx - 1] = INT_MAX;
				--iStaridx;
			}
			break;
		case 'd':
		case 'D':
			if (iStaridx % 5 != 4) {
				iNumber[iStaridx] = iNumber[iStaridx + 1];
				iNumber[iStaridx + 1] = INT_MAX;
				++iStaridx;
			}
			break;
		}
	}

	cout << endl << "������ �����մϴ�. " << endl;
	return 0;
}