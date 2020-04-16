#include <iostream>

using namespace std;

#define NAME_SIZE 32
#define STUDENT_MAX 10
#define ADDRESS_SIZE 128
#define PHONE_SIZE 14

struct _tagStudent
{
	char strName[NAME_SIZE];
	char strAddress[ADDRESS_SIZE];
	char strPhone[PHONE_SIZE];
	int iNumber;
	int iKor;
	int iEng;
	int iMath;
	int iTotal;
	float fAvg;
};

enum MENU
{
	MENU_NONE,
	MENU_INSERT,
	MENU_DELETE,
	MENU_SEARCH,
	MENU_OUTPUT,
	MENU_EXIT
};

int main() 
{
	_tagStudent tStudentArr[STUDENT_MAX] = {};

	char strName[NAME_SIZE] = {};
	//�迭�� �߰��� ������ ������ ������ �������
	int iStudentCount = 0;
	int iStdNumber = 1;

	while (true)
	{
		system("cls");

		cout << "1. �л� ���" << endl;
		cout << "2. �л� ����" << endl;
		cout << "3. �л� Ž��" << endl;
		cout << "4. �л� ���" << endl;
		cout << "5. ����" << endl;

		int iMenu;
		cin >> iMenu;//int ��� char�Է��� ��� ���� �߻��Ѵ�, �׷��� ����ó�� �������

		if (cin.fail())//�Է¿��� �߻��� true ��ȯ
		{
			cin.clear();//�������� ����ֱ�
			cin.ignore(1024, '\n');//�Է¹��ۿ� \n���������Ƿ� \n�˻��ؼ� �����ֱ�, �տ��� �˻��ϰ��� �ϴ� ���� ũ�� ����, �ڿ��� ã���� �ϴ� ���� �־���
			continue;
		}
		if (iMenu == MENU_EXIT)
			break;

		switch (iMenu)
		{
		case MENU_INSERT://�л����� �߰�, �й�, �̸�, �ڵ��� ��ȣ, �ּ�, �������� �Է� �ް� ���� ���� ����� ���� ���� ���
			system("cls");
			cout << "===================�л��߰�=======================" << endl;
			//��ϵ� �л��� ����� �� �ִ� �ִ�ġ�� ��� ���̻� ��� �ȵǰ� ����
			if (iStudentCount == STUDENT_MAX)
				break;
			cout << "�̸� : ";
			cin >> tStudentArr[iStudentCount].strName;
			cin.ignore(1024, '\n');//ignore�̿��ؼ� enter�����ֱ�

			cout << "�ּ� : ";
			cin.getline(tStudentArr[iStudentCount].strAddress,ADDRESS_SIZE);//�����̽��ٵ� �Է� �ް� ���ͷθ� ���� ��ġ���� cin.getline
			cout << tStudentArr[iStudentCount].strAddress << endl;

			cout << "�ڵ��� ��ȣ : " << endl;
			cin.getline(tStudentArr[iStudentCount].strPhone, PHONE_SIZE);

			cout << "���� : ";
			cin >> tStudentArr[iStudentCount].iKor;

			cout << "���� : ";
			cin >> tStudentArr[iStudentCount].iEng;

			cout << "���� : ";
			cin >> tStudentArr[iStudentCount].iMath;

			tStudentArr[iStudentCount].iTotal = tStudentArr[iStudentCount].iKor + tStudentArr[iStudentCount].iEng + tStudentArr[iStudentCount].iMath;

			tStudentArr[iStudentCount].fAvg = tStudentArr[iStudentCount].iTotal / 3;

			tStudentArr[iStudentCount].iNumber = iStdNumber;
			++iStdNumber;
			++iStudentCount;

			cout << "�л� �߰� �Ϸ�" << endl;
			break;
		case MENU_DELETE:
			system("cls");
			cout << "===================�л�����=======================" << endl;

			cin.ignore(1024, '\n');
			cout << "Ž���� �̸��� �Է��ϼ��� : ";
			cin.getline(strName, NAME_SIZE);

			for (int i = 0;i < iStudentCount;++i) {
				if (strcmp(tStudentArr[i].strName, strName) == 0)
				{
					for (int j = i;j < iStudentCount - 1;++j)
					{
						tStudentArr[i] = tStudentArr[i + 1];
					}
					--iStudentCount;
					cout << "�л��� �����Ͽ����ϴ�" << endl;
					break;
				}
			}


			break;
		case MENU_SEARCH:
			system("cls");
			cout << "===================�л�Ž��=======================" << endl;

			cin.ignore(1024, '\n');
			cout << "Ž���� �̸��� �Է��ϼ��� : ";
			cin.getline(strName, NAME_SIZE);
			
			for (int i = 0;i < iStudentCount;++i) {
				if (strcmp(tStudentArr[i].strName, strName) == 0)
				{
					cout << "�̸� : " << tStudentArr[i].strName << endl;
					cout << "��ȭ��ȣ : " << tStudentArr[i].strPhone << endl;
					cout << "�ּ� : " << tStudentArr[i].strAddress << endl;
					cout << "�й� : " << tStudentArr[i].iNumber << endl;
					cout << "���� : " << tStudentArr[i].iKor << endl;
					cout << "���� : " << tStudentArr[i].iEng << endl;
					cout << "���� : " << tStudentArr[i].iMath << endl;
					cout << "���� : " << tStudentArr[i].iTotal << endl;
					cout << "��� : " << tStudentArr[i].fAvg << endl << endl;
					break;
				}
			}

			break;
		case MENU_OUTPUT:
			system("cls");
			cout << "===================�л����=======================" << endl;

			for (int i = 0;i < iStudentCount;++i) {
				cout << "�̸� : " << tStudentArr[i].strName << endl;
				cout << "��ȭ��ȣ : " << tStudentArr[i].strPhone << endl;
				cout << "�ּ� : " << tStudentArr[i].strAddress << endl;
				cout << "�й� : " << tStudentArr[i].iNumber << endl;
				cout << "���� : " << tStudentArr[i].iKor << endl;
				cout << "���� : " << tStudentArr[i].iEng << endl;
				cout << "���� : " << tStudentArr[i].iMath << endl;
				cout << "���� : " << tStudentArr[i].iTotal << endl;
				cout << "��� : " << tStudentArr[i].fAvg << endl << endl;
			}
			break;
		default:
			cout << "�޴��� �߸� �Է��ϼ̽��ϴ�." << endl;
			break;
		}

		system("pause");
	}

	return 0;
}