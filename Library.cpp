#include <iostream>

using namespace std;
#define NAME_SIZE 64
#define BOOK_MAX 100
struct _book {
	char strBookName[NAME_SIZE];
	int iBookPrice;
	int iBookNumber;
	bool bBookRent;//BookRent true�� ����� ����
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
		cout << "1. å���" << endl;
		cout << "2. å����" << endl;
		cout << "3. å�ݳ�" << endl;
		cout << "4. å���" << endl;
		cout << "5. ����" << endl;
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

			cout << "==========å�߰�===========" << endl;
			cout << "å�̸� : ";
			cin.ignore(1024, '\n');
			cin.getline(tBookArr[BookCount].strBookName, NAME_SIZE);
			cout << "���� ���� : ";
			cin >> tBookArr[BookCount].iBookPrice;
			tBookArr[BookCount].iBookNumber = BookNumber;
			tBookArr[BookCount].bBookRent = false;
			++BookCount;
			++BookNumber;
			break;
		case MENU_RENT:
			system("cls");
			cout << "==========å����===========" << endl;

			cout << "å�̸� : ";

			cin.ignore(1024, '\n');
			cin.getline(BookName, NAME_SIZE);

			for (int i = 0;i < BookCount;++i) {
				if (strcmp(tBookArr[i].strBookName, BookName) == 0) {
					if (tBookArr[i].bBookRent == false) {
						cout << "å�� ����Ǿ����ϴ�." << endl;
						tBookArr[i].bBookRent = true;
						break;
					}
					else
					{
						cout << "�̹� ����� å�Դϴ�." << endl;
						break;
					}
				}
			}
			break;
		case MENU_RETURN:
			system("cls");
			cout << "==========å�ݳ�===========" << endl;

			cout << "å�̸� : ";

			cin.ignore(1024, '\n');
			cin.getline(BookName, NAME_SIZE);

			for (int i = 0;i < BookCount;++i) {
				if (strcmp(tBookArr[i].strBookName, BookName) == 0) {
					if (tBookArr[i].bBookRent == false) {
						cout << "���� ����� �����ϴ�." << endl;
						break;
					}
					else
					{
						cout << "�ݳ� �Ϸ�" << endl;
						tBookArr[i].bBookRent = false;
						break;
					}
				}
			}
			break;
		case MENU_SEARCH:
			system("cls");
			cout << "==========å���===========" << endl;
			for (int i = 0;i < BookCount;++i) {
				cout << "å�̸� : " << tBookArr[i].strBookName << endl;
				cout << "å���� : " << tBookArr[i].iBookPrice << endl;
				cout << "å��ȣ : " << tBookArr[i].iBookNumber << endl;
				cout << "å���⿩�� : ";
				if (tBookArr[i].bBookRent == true)
					cout << "������" << endl;
				else
					cout << "���Ⱑ��" << endl;
			}
			break;

		}

		system("pause");
	}
}