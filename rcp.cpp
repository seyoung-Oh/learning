#include <iostream>
#include <time.h>
using namespace std;

enum SRP {
	SRP_S = 1,
	SRP_R,
	SRP_P,
	SRP_end
};
int main() {

	int iNumber = 1;
	//system("cls"); ȭ���� ������ �����ִ� dos ��ɾ� cmdâ���� ���� ������ cls��� ����

	//���� ���̺� ����
	srand((unsigned int)time(0));
	int iPlayer, iAI;

	while (true)
	{
		cout << "1.����" << endl;
		cout << "2.����" << endl;
		cout << "3.��" << endl;
		cout << "4.����" << endl;
		cout << "�޴��� �����ϼ��� : ";
		cin >> iPlayer;

		if (iPlayer < SRP_S || iPlayer > SRP_end)
		{
			cout << "�߸��� ���� �Է��Ͽ����ϴ�. " << endl;
			//�Ͻ�����
			system("pause");
			continue;//�ݺ����� ���������� �̵�
		}

		else if (iPlayer == SRP_end)
			break;

		iAI = rand() % 3 + SRP_S;

		switch (iAI)
		{
		case SRP_S:
			cout << "AI : ����" << endl;
			break;
		case SRP_R:
			cout << "AI : ����" << endl;
			break;
		case SRP_P:
			cout << "AI : ��" << endl;
			break;
		}

		int iWin = iPlayer - iAI;
		/*
		if (iWin == 1 || iWin == -2)
		cout << "Player�� �¸�" << endl;
		else if (iWin == 0)
		cout << "��� " << endl;
		else
		cout << "AI�� �¸�" << endl;*/

		switch (iWin) {
		case 1:
		case -2:
			cout << "Player�� �¸�" << endl;
			break;
		case 0:
			cout << "��� " << endl;
			break;
		default:
			cout << "AI�� �¸�" << endl;
			break;
		}
		system("pause");
	}
	return 0;

}
