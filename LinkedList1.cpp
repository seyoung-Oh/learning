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
}STUDENT, *pSTUDENT;
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
			break;
		case MM_DELETE:
			break;
		case MM_SEARCH:
			break;
		case MM_OUTPUT:
			break;
		}

	}

	return 0;
}