#include <iostream>
#include <time.h>
using namespace std;

enum SRP {
	SRP_S = 1,
	SRP_R,
	SRP_P,
	SRP_end
};
int main() {

	int iNumber = 1;
	//system("cls"); 화면을 깨끗이 지워주는 dos 명령어 cmd창에서 띄우기 때문에 cls사용 가능

	//난수 테이블 생성
	srand((unsigned int)time(0));
	int iPlayer, iAI;

	while (true)
	{
		cout << "1.가위" << endl;
		cout << "2.바위" << endl;
		cout << "3.보" << endl;
		cout << "4.종료" << endl;
		cout << "메뉴를 선택하세요 : ";
		cin >> iPlayer;

		if (iPlayer < SRP_S || iPlayer > SRP_end)
		{
			cout << "잘못된 값을 입력하였습니다. " << endl;
			//일시정지
			system("pause");
			continue;//반복문의 시작점으로 이동
		}

		else if (iPlayer == SRP_end)
			break;

		iAI = rand() % 3 + SRP_S;

		switch (iAI)
		{
		case SRP_S:
			cout << "AI : 가위" << endl;
			break;
		case SRP_R:
			cout << "AI : 바위" << endl;
			break;
		case SRP_P:
			cout << "AI : 보" << endl;
			break;
		}

		int iWin = iPlayer - iAI;
		/*
		if (iWin == 1 || iWin == -2)
		cout << "Player의 승리" << endl;
		else if (iWin == 0)
		cout << "비김 " << endl;
		else
		cout << "AI의 승리" << endl;*/

		switch (iWin) {
		case 1:
		case -2:
			cout << "Player의 승리" << endl;
			break;
		case 0:
			cout << "비김 " << endl;
			break;
		default:
			cout << "AI의 승리" << endl;
			break;
		}
		system("pause");
	}
	return 0;

}
