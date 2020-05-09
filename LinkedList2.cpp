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
링크드리스트 : 자료구조의 한 종류, 자료구조란 데이터를 관리하는 방법을 말한다.
링크드리스트는 데이터 목록을 연결시켜서 접근할 수 있는 구조를 제공한다.
링크드리스트는 데이터를 저장하기 위한 노드라는 것이 존재한다,
각 노드는 다음 노드의 메모리 주소를 저장한다.
리스트는 선형구조라 배열처럼 특정요소에ㅔ 바로 접근 불가능. 무조건 앞에서부터 차례대로 타고 들어가야한다.
노드를 새로 추가할때는 노드를 생성하고 마지막 노드에 연결만 해주면 되기 때문에 개수의 제한이 없다.
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
	pList->pBegin = NULL;//포인터는 가급적으로 초기화시 0으로 하는것이 좋음, 0이 아닌 모든 수는 true로 취급되기 때문.
	pList->pEnd = NULL;
	pList->iSize = 0;
}
int OutputMenu() {
	system("cls");
	cout << "1. 학생 추가" << endl;
	cout << "2. 학생 삭제" << endl;
	cout << "3. 학생 탐색" << endl;
	cout << "4. 학생 출력" << endl;
	cout << "5. 종료" << endl;
	cout << "메뉴를 선택하세요 : ";
	int iInput = InputInt();

	if (iInput< MM_NONE || iInput > MM_EXIT) {
		return MM_NONE;
	}
	return iInput;
}

void Insert(PLIST pList)
{
	system("cls");
	cout << "=============================학생 추가=============================" << endl;
	STUDENT tStudent = {};
	cout << "이름 : ";
	InputString(tStudent.strName, NAME_SIZE);

	cout << "학번 : ";
	tStudent.iNumber = InputInt();
	cout << "국어 : ";
	tStudent.iKor = InputInt();
	cout << "영어 : ";
	tStudent.iEng = InputInt();
	cout << "수학 : ";
	tStudent.iMath = InputInt();

	tStudent.iTotal = tStudent.iKor + tStudent.iEng + tStudent.iMath;
	tStudent.fAvg = tStudent.iTotal / 3.f;

	//추가할 리스트 노드를 생성한다.
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
void OutputStudent(const PSTUDENT pStudent)//const포인터이기 때문에 가리키는 대상의 값을 변경할 수 없다.
{
	cout << "이름 : " << pStudent->strName << "\t학번 : " << pStudent->iNumber << endl;
	cout << "국어 : " << pStudent->iKor << "\t영어 : " << pStudent->iEng << endl;
	cout << "수학 : " << pStudent->iMath << endl;
	cout << "총합 : " << pStudent->iTotal << "\t평균 : " << pStudent->fAvg << endl << endl;
}
void Output(PLIST pList)
{
	system("cls");
	cout << "=============================학생 출력=============================" << endl;
	PNODE pNode = pList->pBegin;
	while (pNode != NULL)
	{
		OutputStudent(&pNode->tStudent);
		pNode = pNode->pNext;
	}
	cout << "학생 수 : " << pList->iSize << endl;
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