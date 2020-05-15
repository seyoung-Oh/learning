#include <iostream>

using namespace std;

enum MAIN_MENU {
	MM_NONE,
	MM_INSERT,
	MM_DELETE,
	MM_SEARCH,
	MM_OUTPUT,
	MM_EXIT
};

#define NAME_SIZE 32

typedef struct _tagStudent
{
	char strName[NAME_SIZE];
	int iNumber;
	int iKor;
	int iEng;
	int iMath;
	int iTotal;
	int fAvg;
}STUDENT, *PSTUDENT;
/*
��ũ�帮��Ʈ : �ڷᱸ���� �� ����, �ڷᱸ���� �����͸� �����ϴ� ����� ���Ѵ�.
��ũ�帮��Ʈ�� ������ ����� ������Ѽ� ������ �� �ִ� ������ �����Ѵ�.
��ũ�帮��Ʈ�� �����͸� �����ϱ� ���� ����� ���� �����Ѵ�,
�� ���� ���� ����� �޸� �ּҸ� �����Ѵ�.
����Ʈ�� ���������� �迭ó�� Ư����ҿ��� �ٷ� ���� �Ұ���. ������ �տ������� ���ʴ�� Ÿ�� �����Ѵ�.
��带 ���� �߰��Ҷ��� ��带 �����ϰ� ������ ��忡 ���Ḹ ���ָ� �Ǳ� ������ ������ ������ ����.
*/
typedef struct _tagNode
{
	STUDENT tStudent;
	_tagNode* pNext;
}NODE, *PNODE;
typedef struct _tagList
{
	PNODE pBegin;
	PNODE pEnd;
	int iSize;
}LIST, *PLIST;
int InputInt() {
	int iInput;
	cin >> iInput;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(1024, '\n');

		return INT_MAX;
	}
	return iInput;
}

void InputString(char* pString, int iSize) 
{
	cin.clear();
	cin.ignore(1024, '\n');
	cin.getline(pString, iSize - 1);
}
void InitList(PLIST pList)
{
	pList->pBegin = NULL;//�����ʹ� ���������� �ʱ�ȭ�� 0���� �ϴ°��� ����, 0�� �ƴ� ��� ���� true�� ��޵Ǳ� ����.
	pList->pEnd = NULL;
	pList->iSize = 0;
}
int OutputMenu() {
	system("cls");
	cout << "1. �л� �߰�" << endl;
	cout << "2. �л� ����" << endl;
	cout << "3. �л� Ž��" << endl;
	cout << "4. �л� ���" << endl;
	cout << "5. ����" << endl;
	cout << "�޴��� �����ϼ��� : ";
	int iInput = InputInt();

	if (iInput< MM_NONE || iInput > MM_EXIT) {
		return MM_NONE;
	}
	return iInput;
}

void Insert(PLIST pList)
{
	system("cls");
	cout << "=============================�л� �߰�=============================" << endl;
	STUDENT tStudent = {};
	cout << "�̸� : ";
	InputString(tStudent.strName, NAME_SIZE);

	cout << "�й� : ";
	tStudent.iNumber = InputInt();
	cout << "���� : ";
	tStudent.iKor = InputInt();
	cout << "���� : ";
	tStudent.iEng = InputInt();
	cout << "���� : ";
	tStudent.iMath = InputInt();

	tStudent.iTotal = tStudent.iKor + tStudent.iEng + tStudent.iMath;
	tStudent.fAvg = tStudent.iTotal / 3.f;

	//�߰��� ����Ʈ ��带 �����Ѵ�.
	PNODE pNode = new NODE;

	pNode->pNext = NULL;
	pNode->tStudent = tStudent;

	if (pList->pBegin == NULL)
		pList->pBegin = pNode;
	else
		pList->pEnd->pNext = pNode;

	pList->pEnd = pNode;

	++pList->iSize;
}

void ClearList(PLIST pList) {
	PNODE pNode = pList->pBegin;
	while (pNode != NULL)
	{
		PNODE pNext = pNode->pNext;
		delete pNode;
		pNode = pNext;
	}
	pList->pBegin = NULL;
	pList->pBegin = NULL;
	pList->iSize = 0;
}
void OutputStudent(const PSTUDENT pStudent)//const�������̱� ������ ����Ű�� ����� ���� ������ �� ����.
{
	cout << "�̸� : " << pStudent->strName << "\t�й� : " << pStudent->iNumber << endl;
	cout << "���� : " << pStudent->iKor << "\t���� : " << pStudent->iEng << endl;
	cout << "���� : " << pStudent->iMath << endl;
	cout << "���� : " << pStudent->iTotal << "\t��� : " << pStudent->fAvg << endl << endl;
}
void Output(PLIST pList)
{
	system("cls");
	cout << "=============================�л� ���=============================" << endl;
	PNODE pNode = pList->pBegin;
	while (pNode != NULL)
	{
		OutputStudent(&pNode->tStudent);
		pNode = pNode->pNext;
	}
	cout << "�л� �� : " << pList->iSize << endl;
	system("pause");
}
int main()
{
	LIST tList;
	InitList(&tList);

	while (true)
	{
		int iMenu = OutputMenu();
		if (iMenu == MM_EXIT)
			break;
		switch (iMenu)
		{
		case MM_INSERT:
			Insert(&tList);
			break;
		case MM_DELETE:
			break;
		case MM_SEARCH:
			break;
		case MM_OUTPUT:
			Output(&tList);
			break;
		}

	}
	ClearList(&tList);
	return 0;
}