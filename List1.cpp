#include "List1.h"
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
	int iMenu;
	while (true) {
		system("cls");
		cout << "=============================학생 출력=============================" << endl;
		cout << "1 . 정방향 출력 " << endl;
		cout << "2 . 역방향 출력 " << endl;
		cout << "메뉴를 선택하세요 : ";
		iMenu = InputInt();

		if (iMenu > OT_NONE && iMenu <= OT_INVERSE)
			break;
	}
	PNODE pNode = NULL;
	switch (iMenu)
	{
	case OT_OUTPUT:
		pNode = pList->pBegin->pNext;//추가되는 노드들은 begin과 end사이에 배치됨 그러므로 begin의 다음 노드를 얻어옴
		while (pNode != pList->pEnd)
		{
			OutputStudent(&pNode->tStudent);
			pNode = pNode->pNext;
		}
		break;
	case OT_INVERSE:
		pNode = pList->pEnd->pPrev;
		while (pNode != pList->pBegin)
		{
			OutputStudent(&pNode->tStudent);
			pNode = pNode->pPrev;
		}
		break;
	}
	cout << "학생수 : " << pList->iSize << endl;
	system("pause");
}
void Search(PLIST pList)
{
	system("cls");
	cout << "=============================학생 탐색=============================" << endl;
	cout << "탐색할 이름을 입력하세요 : ";
	char strName[NAME_SIZE] = {};
	InputString(strName, NAME_SIZE);

	PNODE pNode = pList->pBegin->pNext;
	while (pNode != pList->pEnd)
	{
		if (strcmp(pNode->tStudent.strName, strName) == 0)
		{
			OutputStudent(&pNode->tStudent);
			system("pause");
			return;
		}
		pNode = pNode->pNext;
	}

	cout << "학생을 찾을 수 없습니다." << endl;
	system("pause");
}
void Delete(PLIST pList)
{
	system("cls");
	cout << "=============================학생 삭제=============================" << endl;
	cout << "삭제할 이름을 입력하세요 : ";
	char strName[NAME_SIZE] = {};
	InputString(strName, NAME_SIZE);

	PNODE pNode = pList->pBegin->pNext;
	while (pNode != pList->pEnd)
	{
		if (strcmp(pNode->tStudent.strName, strName) == 0)
		{
			pNode->pPrev->pNext = pNode->pNext; 
			pNode->pNext->pPrev = pNode->pPrev;
			delete pNode;
			--pList->iSize;
			cout << strName << "학생을 삭제하였습니다. " << endl;
			system("pause");
			return;
		}
		pNode = pNode->pNext;
	}

	cout << "삭제할 학생을 찾을 수 없습니다." << endl;
	system("pause");
}