#include "List.h"
void OutputStudent(const PSTUDENT pStudent)//const포인터이기 때문에 가리키는 대상의 값을 변경할 수 없다.
{
	cout << "이름 : " << pStudent->strName << "\t학번 : " << pStudent->iNumber << endl;
	cout << "국어 : " << pStudent->iKor << "\t영어 : " << pStudent->iEng << endl;
	cout << "수학 : " << pStudent->iMath << endl;
	cout << "총합 : " << pStudent->iTotal << "\t평균 : " << pStudent->fAvg << endl << endl;
}
void InitList(PLIST pList)
{
	pList->iSize = 0;
	pList->pBegin = new NODE;
	pList->pEnd = new NODE;

	pList->pBegin->pNext = pList->pEnd;
	pList->pEnd->pPrev = pList->pBegin;

	pList->pEnd->pNext = NULL;
	pList->pBegin->pPrev = NULL;
}

void DestroyList(PLIST pList)
{
	PNODE pNode = pList->pBegin;
	while (pNode != NULL)
	{
		PNODE pNext = pNode->pNext;
		delete pNode;
		pNode = pNext;
	}
	pList->iSize = 0;
	pList->pBegin = NULL;
	pList->pEnd = NULL;
}

void Push_Back(PLIST pList)
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

	PNODE pNode = new NODE;

	pNode->tStudent = tStudent;

	PNODE pPrev = pList->pEnd->pPrev;//새로 추가되는 노드는 End노드의 이전 노드와 End노드 사이에 추가되어야 한다.

	//pEnd 노드 이전 노드의 다음으로 추가할 노드를 지정한다.
	pPrev->pNext = pNode;
	pNode->pPrev = pPrev;

	pNode->pNext = pList->pEnd;
	pList->pEnd->pPrev = pNode;

	++pList->iSize;
}

void Push_Front(PLIST pList)
{
}
void Output(PLIST pList)
{
	system("cls");
	cout << "=============================학생 출력=============================" << endl;
	cout << "1 . 정방향 출력 " << endl;
	cout << "2 . 역방향 출력 " << endl;
	cout << "메뉴를 선택하세요 : ";
	int iMenu = InputInt();
}