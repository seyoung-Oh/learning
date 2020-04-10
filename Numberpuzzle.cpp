#include <iostream>
#include <time.h>
//console input output헤더 파일. 콘솔창에서 입출력 하는 기능들을 제공해주는 헤더파일
#include<conio.h>

using namespace std;

int main()
{
	srand((unsigned int)time(0));

	int iNumber[25] = {};

	for (int i = 0;i < 24;++i) 
	{
		iNumber[i] = i + 1;
	}
	//가장 마지막 칸은 공백으로 비워둔다. 공백을 의미하는 값으로 특수한 값을 사용할건데 INT_MAX라는 값을 사용할 것이다. 
	//INT_MAX는 이미 정의되어 있는 값으로 int를 표현할 수 있는 최대값이다.

	iNumber[24] = INT_MAX;

	//마지막 공백을 제외하고 1~24까지의 숫자만 섞어준다. 즉 인덱스는 0~23까지만 섞어준다
	int iStaridx = 24;
	int iTemp, idx1, idx2;

	for (int i = 0;i < 100;++i) {
		idx1 = rand() % 24;
		idx2 = rand() % 24;

		iTemp = iNumber[idx1];
		iNumber[idx1] = iNumber[idx2];
		iNumber[idx2] = iTemp;
	}

	while (true) {
		system("cls");//화면 지우기
		//i for문이 세로를 의미
		for (int i = 0; i < 5;++i)
		{
			//j for문이 가로를 의미
			for (int j = 0;j < 5;++j) {
				if (iNumber[i * 5 + j] == INT_MAX)
					cout << "*\t";
				else
					cout << iNumber[i * 5 + j] << "\t"; //줄번호 * 가로개수 + 칸번호
			}
			cout << endl;
		}
		bool bWin = true;

		for (int i = 0; i < 24; ++i) {
			if (iNumber[i] != i + 1) {
				bWin = false;
				break;
			}
		}
		if (bWin == true) {
			cout << "숫자를 모두 맞췄습니다." << endl;
			break;
		}
		cout << "w : 위 s : 아래 a : 왼쪽 d : 오른쪽 q : 종료 ";
		char cinput = _getch();//문자 1개를 입력받는 함수. enter안쳐도 문자를 누르는 순간 바로 그 문자 반환하고 종료된다.
		if (cinput == 'q' || cinput == 'Q')
			break;
		switch (cinput) {
		case 'w':
		case 'W':
			if (iStaridx >= 5) {
				iNumber[iStaridx] = iNumber[iStaridx - 5];
				iNumber[iStaridx - 5] = INT_MAX;
				iStaridx -= 5;
			}
			break;
		case 's':
		case 'S':
			if (iStaridx <= 19) {
				iNumber[iStaridx] = iNumber[iStaridx + 5];
				iNumber[iStaridx + 5] = INT_MAX;
				iStaridx += 5;
			}
			break;
		case 'a':
		case 'A':
			if (iStaridx % 5 != 0) {
				iNumber[iStaridx] = iNumber[iStaridx - 1];
				iNumber[iStaridx - 1] = INT_MAX;
				--iStaridx;
			}
			break;
		case 'd':
		case 'D':
			if (iStaridx % 5 != 4) {
				iNumber[iStaridx] = iNumber[iStaridx + 1];
				iNumber[iStaridx + 1] = INT_MAX;
				++iStaridx;
			}
			break;
		}
	}

	cout << endl << "게임을 종료합니다. " << endl;
	return 0;
}