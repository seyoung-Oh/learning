#include <iostream>

using namespace std;

#define NAME_SIZE  32

/*
����ü : ������ �ִ� �������� ��Ƽ� �ϳ��� ���ο� Ÿ���� ����� �ִ� ���
struct ����ü�� {}; ���·� ������
�迭�� ����ü�� ������ : ������ �����̴�, ���ӵ� �޸� ���� �Ҵ�ȴ�
*/
struct _tagStudent
{
	char strName[NAME_SIZE];
	int iNumber;
	int iKor;
	int iEng;
	int iMath;
	int iTotal;
	float fAvg;
};
int main() {
	
	_tagStudent tStudent;
	_tagStudent tStudentArr[100] = {};

	tStudent.iKor = 100;
	strcpy_s(tStudent.strName, "osy");// ���ڿ� �迭�� �־��� ���� strcpy_sȰ���ϱ�

	//tStudent.strName[0] = 'a';
	//tStudent.strName[1] = 'b';
	//tStudent.strName[2] = 0;
	cout << "�̸� ���� : " << strlen(tStudent.strName) << endl;

	strcat_s(tStudent.strName, "���ڿ����̱�");//�����ʿ� �ִ� ���ڿ��� ���ʿ� �ٿ��ش�.

	//strcmp()�� ���ڿ��� ���� ���� ��� 0��ȯ�ϰ� �ٸ� ��� 0�� �ƴ� ���� ��ȯ 

	strcpy_s(tStudent.strName, "������");
	cout << "���� �̸��� �Է��ϼ��� : ";
	char strName[NAME_SIZE] = {};

	cin >> strName;

	if (strcmp(tStudent.strName, strName) == 0) {
		cout << "�л��� ã�ҽ��ϴ� " << endl;
	}
	else {
		cout << "�л��� ��ã�ҽ��ϴ�. " << endl;
	}

	cout << "�̸� : " << tStudent.strName << endl;
	cout << "�й� : " << tStudent.iNumber << endl;
	cout << "���� : " << tStudent.iKor<< endl;
	cout << "���� : " << tStudent.iEng << endl;
	cout << "���� : " << tStudent.iMath << endl;
	cout << "��� : " << tStudent.fAvg << endl;
	return 0;

}