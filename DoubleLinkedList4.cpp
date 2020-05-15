#include "List2.h"

enum MAIN_MENU {
	MM_NONE,
	MM_INSERT,
	MM_DELETE,
	MM_SEARCH,
	MM_OUTPUT,
	MM_SORT,
	MM_EXIT
};

int OutputMenu() {
	system("cls");
	cout << "1. 학생 추가" << endl;
	cout << "2. 학생 삭제" << endl;
	cout << "3. 학생 탐색" << endl;
	cout << "4. 학생 출력" << endl;
	cout << "5. 학생 정렬" << endl;
	cout << "6. 종료" << endl;
	cout << "메뉴를 선택하세요 : ";
	int iInput = InputInt();

	if (iInput< MM_NONE || iInput > MM_EXIT) {
		return MM_NONE;
	}
	return iInput;
}
int main() {
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
			Push_Back(&tList);
			break;
		case MM_DELETE:
			Delete(&tList);
			break;
		case MM_SEARCH:
			Search(&tList);
			break;
		case MM_OUTPUT:
			Output(&tList);
			break;
		case MM_SORT:
			Sort(&tList);
			break;
		}

	}
	DestroyList(&tList);

	return 0;
}