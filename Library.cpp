#include <iostream>

using namespace std;
#define NAME_SIZE 64
#define BOOK_MAX 100
struct _book {
	char strBookName[NAME_SIZE];
	int iBookPrice;
	int iBookNumber;
	bool bBookRent;//BookRent true면 대출된 상태
};

enum MENU {
	MENU_NONE,
	MENU_INSERT,
	MENU_RENT,
	MENU_RETURN,
	MENU_SEARCH,
	MENU_EXIT
};
int main() {
	_book tBook;
	_book tBookArr[BOOK_MAX] = {};
	int BookCount = 0;
	int BookNumber = 1;
	while (true) {
		system("cls");
		cout << "1. 책등록" << endl;
		cout << "2. 책대출" << endl;
		cout << "3. 책반납" << endl;
		cout << "4. 책목록" << endl;
		cout << "5. 종료" << endl;
		char BookName[NAME_SIZE] = {};
		int iMenu;
		cin >> iMenu;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		if (iMenu == MENU_EXIT)
			break;
		switch (iMenu) {
		case MENU_INSERT:
			system("cls");

			cout << "==========책추가===========" << endl;
			cout << "책이름 : ";
			cin.ignore(1024, '\n');
			cin.getline(tBookArr[BookCount].strBookName, NAME_SIZE);
			cout << "대출 가격 : ";
			cin >> tBookArr[BookCount].iBookPrice;
			tBookArr[BookCount].iBookNumber = BookNumber;
			tBookArr[BookCount].bBookRent = false;
			++BookCount;
			++BookNumber;
			break;
		case MENU_RENT:
			system("cls");
			cout << "==========책대출===========" << endl;

			cout << "책이름 : ";

			cin.ignore(1024, '\n');
			cin.getline(BookName, NAME_SIZE);

			for (int i = 0;i < BookCount;++i) {
				if (strcmp(tBookArr[i].strBookName, BookName) == 0) {
					if (tBookArr[i].bBookRent == false) {
						cout << "책이 대출되었습니다." << endl;
						tBookArr[i].bBookRent = true;
						break;
					}
					else
					{
						cout << "이미 대출된 책입니다." << endl;
						break;
					}
				}
			}
			break;
		case MENU_RETURN:
			system("cls");
			cout << "==========책반납===========" << endl;

			cout << "책이름 : ";

			cin.ignore(1024, '\n');
			cin.getline(BookName, NAME_SIZE);

			for (int i = 0;i < BookCount;++i) {
				if (strcmp(tBookArr[i].strBookName, BookName) == 0) {
					if (tBookArr[i].bBookRent == false) {
						cout << "대출 기록이 없습니다." << endl;
						break;
					}
					else
					{
						cout << "반납 완료" << endl;
						tBookArr[i].bBookRent = false;
						break;
					}
				}
			}
			break;
		case MENU_SEARCH:
			system("cls");
			cout << "==========책목록===========" << endl;
			for (int i = 0;i < BookCount;++i) {
				cout << "책이름 : " << tBookArr[i].strBookName << endl;
				cout << "책가격 : " << tBookArr[i].iBookPrice << endl;
				cout << "책번호 : " << tBookArr[i].iBookNumber << endl;
				cout << "책대출여부 : ";
				if (tBookArr[i].bBookRent == true)
					cout << "대출중" << endl;
				else
					cout << "대출가능" << endl;
			}
			break;

		}

		system("pause");
	}
}