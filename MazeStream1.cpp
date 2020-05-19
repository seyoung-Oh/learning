#include <iostream>
#include <conio.h>
#include <time.h>
/*
0 : 벽
1 : 길
2 : 시작점
3 : 도착점
4 : 폭탄
5 : 파워아이템
6 : 벽밀기 아이템
7 : 투명 아이템
8 : 웜홀
*/
using namespace std;

struct _tagPoint
{
	int x;
	int y;
};
typedef _tagPoint POINT;
typedef _tagPoint* PPOINT;
typedef struct _tagPlayer
{
	_tagPoint tPos;
	bool bWallPush;
	bool bPushOnOff;
	bool bTransparency;
	int iBombPower;
}PLAYER, *PPLAYER;

void SetMaze(char Maze[21][21], PPLAYER pPlayer, PPOINT pStartPos, PPOINT pEndPos)
{
	//MazeList.txt 파일을 읽어와서 미로 목록을 만든다.
	FILE* pFile = NULL;

	fopen_s(&pFile, "MazeList.txt", "rt");

	char** pMazeList = NULL;

	if (pFile)
	{
		char cCount;

		fread(&cCount, 1, 1, pFile);

		int iMazeCount = atoi(&cCount);

		fread(&cCount, 1, 1, pFile);

		//char* 배열을 미로 개수만큼 할당한다.
		pMazeList = new char*[iMazeCount];

		for (int i = 0;i < iMazeCount;++i)
		{
			int iNameCount = 0;

			//현재 미로의 파일 이름을 저장할 배열을 256개로 할당해둔다. 미리 넉넉하게
			pMazeList[i] = new char[256];

			while (true)
			{
				fread(&cCount, 1, 1, pFile);
				if (cCount != '\n')
				{
					pMazeList[i][iNameCount] = cCount;
					++iNameCount;
				}
				else
					break;
			}
			//파일 이름을 모두 읽었다면 문자열의 마지막에 0을 넣어서 이 문자열의 끝을 알려준다.
			pMazeList[i][iNameCount] = 0;
			cout << pMazeList[i] << endl;
		}

		fclose(pFile);
		
		//읽을 파일 목록이 만들어졌으므로 각 파일 중 하나를 선택해서 미로를 읽어와서 설정한다.
		for (int i = 0; i < iMazeCount;++i) {
			cout << i + 1 << ". " << pMazeList[i] << endl;
		}

		cout << "미로를 선택하세요 : ";
		int iSelect;
		cin >> iSelect;

		fopen_s(&pFile, pMazeList[iSelect - 1], "rt");
		if (pFile)
		{
			//미로의 세로 줄 수만큼 반복하면 각 줄 별로 읽어온다.

			for (int i = 0;i < 20;++i)
			{
				fread(Maze[i], 1, 20, pFile);

				//현재 줄의 미로를 검사하여 시작점 혹은 도착점이 있는지를 판단한다.
				for (int j = 0;j < 20;++j)
				{
					if (Maze[i][j] == '2')
					{
						pStartPos->x = j;
						pStartPos->y = i;

						pPlayer->tPos = *pStartPos;
					}
					else if (Maze[i][j] == '3')
					{
						pEndPos->x = j;
						pEndPos->y = i;
					}
				}

				//개행문자 읽어오기
				fread(&cCount, 1, 1, pFile);
			}
			fclose(pFile);
		}
	}


}
void Output(char Maze[21][21], PPLAYER pPlayer) {
	for (int i = 0;i < 20;++i) {
		for (int j = 0;j < 20;++j) {

			if (Maze[i][j] == '4')
				cout << "♨";
			else if (pPlayer->tPos.x == j && pPlayer->tPos.y == i)
				cout << "☆";

			else if (Maze[i][j] == '0')
				cout << "■";

			else if (Maze[i][j] == '1')
				cout << "  ";

			else if (Maze[i][j] == '2')
				cout << "★";

			else if (Maze[i][j] == '3')
				cout << "◎";

			else if (Maze[i][j] == '5')
				cout << "㈜";

			else if (Maze[i][j] == '6')
				cout << "※";

			else if (Maze[i][j] == '7')
				cout << "▷";
		}
		cout << endl;
	}
	cout << "폭탄 파워 : " << pPlayer->iBombPower << endl;
	cout << "벽통과: ";
	if (pPlayer->bTransparency)
		cout << "ON\t";
	else
		cout << "OFF\t";
	cout << "벽밀기 : ";
	if (pPlayer->bWallPush)
	{
		cout << "가능 / ";
		if (pPlayer->bPushOnOff)
			cout << "ON" << endl;

		else
			cout << "OFF" << endl;
	}
	else
		cout << "불가능 / OFF" << endl;
}


bool AddItem(char cItemType, PPLAYER pPlayer)
{
	if (cItemType == '5')
	{
		if (pPlayer->iBombPower<5)
			++pPlayer->iBombPower;
		return true;
	}
	else if (cItemType == '6')
	{
		pPlayer->bPushOnOff = true;
		pPlayer->bWallPush = true;
		return true;
	}
	else if (cItemType == '7')
	{
		pPlayer->bTransparency = true;
		return true;
	}
	return false;
}
void MoveUp(char Maze[21][21], PPLAYER pPlayer)
{

	if (pPlayer->tPos.y - 1 >= 0) {
		//벽인지 체크
		if (Maze[pPlayer->tPos.y - 1][pPlayer->tPos.x] != '0' && Maze[pPlayer->tPos.y - 1][pPlayer->tPos.x] != '4')
		{
			--pPlayer->tPos.y;
		}
		//벽밀기가 가능하고 바로 위칸이 벽일 경우
		else if (pPlayer->bWallPush && Maze[pPlayer->tPos.y - 1][pPlayer->tPos.x] == '0') {
			//벽밀기가 ON 상태일 경우
			if (pPlayer->bPushOnOff)
			{
				//위의 위칸이 0보다 크거나 같을 경우는 인덱스가 있다는 의미
				if (pPlayer->tPos.y - 2 >= 0) {
					//위의 위칸이 길이어야 밀기가 가능. 그러므로 길인지 체크
					if (Maze[pPlayer->tPos.y - 2][pPlayer->tPos.x] == '0')
					{
						if (pPlayer->bTransparency)
							--pPlayer->tPos.y;
					}
					//길일경우 벽을 밀어낸다
					else if (Maze[pPlayer->tPos.y - 2][pPlayer->tPos.x] == '1')
					{
						//위의 위칸을 벽으로 하고
						Maze[pPlayer->tPos.y - 2][pPlayer->tPos.x] = '0';
						//위칸은 벽이었는데 길로 만들어준다
						Maze[pPlayer->tPos.y - 1][pPlayer->tPos.x] = '1';
						//플레이어를 이동시킨다.
						--pPlayer->tPos.y;
					}
				}
				else if (pPlayer->bTransparency)
					--pPlayer->tPos.y;
			}
			//벽 밀기 off 상태일 경우
			else if (pPlayer->bTransparency)
				--pPlayer->tPos.y;
		}
		else if (pPlayer->bTransparency)
			--pPlayer->tPos.y;

		if (AddItem(Maze[pPlayer->tPos.y][pPlayer->tPos.x], pPlayer))
			Maze[pPlayer->tPos.y][pPlayer->tPos.x] = '1';

	}



}

void MoveDown(char Maze[21][21], PPLAYER pPlayer)
{
	if (pPlayer->tPos.y + 1 < 20) {
		//벽인지 체크
		if (Maze[pPlayer->tPos.y + 1][pPlayer->tPos.x] != '0' && Maze[pPlayer->tPos.y + 1][pPlayer->tPos.x] != '4')
		{
			++pPlayer->tPos.y;
		}
		else if (pPlayer->bWallPush && Maze[pPlayer->tPos.y + 1][pPlayer->tPos.x] == '0') {
			//벽밀기가 ON 상태일 경우
			if (pPlayer->bPushOnOff)
			{
				//위의 위칸이 0보다 크거나 같을 경우는 인덱스가 있다는 의미
				if (pPlayer->tPos.y + 2 < 20) {
					//위의 위칸이 길이어야 밀기가 가능. 그러므로 길인지 체크
					if (Maze[pPlayer->tPos.y + 2][pPlayer->tPos.x] == '0')
					{
						if (pPlayer->bTransparency)
							++pPlayer->tPos.y;
					}
					//길일경우 벽을 밀어낸다
					else if (Maze[pPlayer->tPos.y + 2][pPlayer->tPos.x] == '1')
					{
						//위의 위칸을 벽으로 하고
						Maze[pPlayer->tPos.y + 2][pPlayer->tPos.x] = '0';
						//위칸은 벽이었는데 길로 만들어준다
						Maze[pPlayer->tPos.y + 1][pPlayer->tPos.x] = '1';
						//플레이어를 이동시킨다.
						++pPlayer->tPos.y;
					}
				}
				else if (pPlayer->bTransparency)
					++pPlayer->tPos.y;
			}
			//벽 밀기 off 상태일 경우
			else if (pPlayer->bTransparency)
				++pPlayer->tPos.y;
		}
		else if (pPlayer->bTransparency)
			++pPlayer->tPos.y;

		if (AddItem(Maze[pPlayer->tPos.y][pPlayer->tPos.x], pPlayer))
			Maze[pPlayer->tPos.y][pPlayer->tPos.x] = '1';
	}
}

void MoveRight(char Maze[21][21], PPLAYER pPlayer)
{
	if (pPlayer->tPos.x + 1 < 20) {
		//벽인지 체크
		if (Maze[pPlayer->tPos.y][pPlayer->tPos.x + 1] != '0'  && Maze[pPlayer->tPos.y][pPlayer->tPos.x + 1] != '4')
		{
			++pPlayer->tPos.x;
		}
		else if (pPlayer->bWallPush && Maze[pPlayer->tPos.y][pPlayer->tPos.x + 1] == '0') {
			//벽밀기가 ON 상태일 경우
			if (pPlayer->bPushOnOff)
			{
				//위의 위칸이 0보다 크거나 같을 경우는 인덱스가 있다는 의미
				if (pPlayer->tPos.x + 2 < 20) {
					//위의 위칸이 길이어야 밀기가 가능. 그러므로 길인지 체크
					if (Maze[pPlayer->tPos.y][pPlayer->tPos.x + 2] == '0')
					{
						if (pPlayer->bTransparency)
							++pPlayer->tPos.x;
					}
					//길일경우 벽을 밀어낸다
					else if (Maze[pPlayer->tPos.y][pPlayer->tPos.x + 2] == '1')
					{
						//위의 위칸을 벽으로 하고
						Maze[pPlayer->tPos.y][pPlayer->tPos.x + 2] = '0';
						//위칸은 벽이었는데 길로 만들어준다
						Maze[pPlayer->tPos.y][pPlayer->tPos.x + 1] = '1';
						//플레이어를 이동시킨다.
						++pPlayer->tPos.x;
					}
				}
				else if (pPlayer->bTransparency)
					++pPlayer->tPos.x;
			}
			//벽 밀기 off 상태일 경우
			else if (pPlayer->bTransparency)
				++pPlayer->tPos.x;
		}
		else if (pPlayer->bTransparency)
			++pPlayer->tPos.x;

		if (AddItem(Maze[pPlayer->tPos.y][pPlayer->tPos.x], pPlayer))
			Maze[pPlayer->tPos.y][pPlayer->tPos.x] = '1';
	}

}

void MoveLeft(char Maze[21][21], PPLAYER pPlayer)
{
	if (pPlayer->tPos.x + 1 >= 0) {
		//벽인지 체크
		if (Maze[pPlayer->tPos.y][pPlayer->tPos.x - 1] != '0'  && Maze[pPlayer->tPos.y][pPlayer->tPos.x - 1] != '4')
		{
			--pPlayer->tPos.x;
		}
		//벽밀기가 가능하고 바로 위칸이 벽일 경우
		else if (pPlayer->bWallPush && Maze[pPlayer->tPos.y][pPlayer->tPos.x - 1] == '0') {
			//벽밀기가 ON 상태일 경우
			if (pPlayer->bPushOnOff)
			{
				//위의 위칸이 0보다 크거나 같을 경우는 인덱스가 있다는 의미
				if (pPlayer->tPos.x - 2 >= 0) {
					//위의 위칸이 길이어야 밀기가 가능. 그러므로 길인지 체크
					if (Maze[pPlayer->tPos.y][pPlayer->tPos.x - 2] == '0')
					{
						if (pPlayer->bTransparency)
							--pPlayer->tPos.x;
					}
					//길일경우 벽을 밀어낸다
					else if (Maze[pPlayer->tPos.y][pPlayer->tPos.x - 2] == '1')
					{
						//위의 위칸을 벽으로 하고
						Maze[pPlayer->tPos.y][pPlayer->tPos.x - 2] = '0';
						//위칸은 벽이었는데 길로 만들어준다
						Maze[pPlayer->tPos.y][pPlayer->tPos.x - 1] = '1';
						//플레이어를 이동시킨다.
						--pPlayer->tPos.x;
					}
				}
				else if (pPlayer->bTransparency)
					--pPlayer->tPos.x;
			}
			//벽 밀기 off 상태일 경우
			else if (pPlayer->bTransparency)
				--pPlayer->tPos.x;
		}
		else if (pPlayer->bTransparency)
			--pPlayer->tPos.x;

		if (AddItem(Maze[pPlayer->tPos.y][pPlayer->tPos.x], pPlayer))
			Maze[pPlayer->tPos.y][pPlayer->tPos.x] = '1';
	}
}
void MovePlayer(char Maze[21][21], PPLAYER pPlayer, char cinput)
{
	switch (cinput) {
	case 'w':
	case 'W':
		MoveUp(Maze, pPlayer);
		break;
	case 's':
	case 'S':
		MoveDown(Maze, pPlayer);
		break;
	case 'a':
	case 'A':
		MoveLeft(Maze, pPlayer);
		break;
	case 'd':
	case 'D':
		MoveRight(Maze, pPlayer);
		break;

	}
}
// 포인터 변수를 const로 생성하면 가리키는 대상의 값을 변경할 수 있다.
void CreateBomb(char Maze[21][21], const PPLAYER pPlayer, PPOINT pBombArr, int* pBombCount)
{
	if (*pBombCount == 5)
		return;
	else if (Maze[pPlayer->tPos.y][pPlayer->tPos.x] == '0')
		return;

	if (*pBombCount == 5)
		return;
	for (int i = 0;i < *pBombCount; ++i)
	{
		if (pPlayer->tPos.x == pBombArr[i].x && pPlayer->tPos.y == pBombArr[i].y)
			return;
	}

	pBombArr[*pBombCount] = pPlayer->tPos;
	++(*pBombCount);

	Maze[pPlayer->tPos.y][pPlayer->tPos.x] = '4';
}

void Fire(char Maze[21][21], PPLAYER pPlayer, PPOINT pBombArr, int *pBombCount)
{
	for (int i = 0; i < *pBombCount; ++i)
	{
		Maze[pBombArr[i].y][pBombArr[i].x] = '1';

		if (pPlayer->tPos.x == pBombArr[i].x && pPlayer->tPos.y == pBombArr[i].y) {
			pPlayer->tPos.x = 0;
			pPlayer->tPos.y = 0;
		}
		for (int j = 1; j <= pPlayer->iBombPower; ++j)
		{
			if (pBombArr[i].y - j >= 0)
			{
				if (Maze[pBombArr[i].y - j][pBombArr[i].x] == '0')
				{
					//아이템 드랍 확률 구하기
					if (rand() % 100 < 20) {
						int iPercent = rand() % 100;
						if (iPercent < 70)
							Maze[pBombArr[i].y - j][pBombArr[i].x] = '5';
						else if (iPercent < 80)
							Maze[pBombArr[i].y - j][pBombArr[i].x] = '6';
						else
							Maze[pBombArr[i].y - j][pBombArr[i].x] = '7';
					}
					else
						Maze[pBombArr[i].y - j][pBombArr[i].x] = '1';
				}

				if (pPlayer->tPos.x == pBombArr[i].x && pPlayer->tPos.y == pBombArr[i].y - j) {
					pPlayer->tPos.x = 0;
					pPlayer->tPos.y = 0;
				}

			}
			if (pBombArr[i].y + j < 20)
			{
				if (Maze[pBombArr[i].y + j][pBombArr[i].x] == '0')
				{
					//아이템 드랍 확률 구하기
					if (rand() % 100 < 20) {
						int iPercent = rand() % 100;
						if (iPercent < 70)
							Maze[pBombArr[i].y + j][pBombArr[i].x] = '5';
						else if (iPercent < 80)
							Maze[pBombArr[i].y + j][pBombArr[i].x] = '6';
						else
							Maze[pBombArr[i].y + j][pBombArr[i].x] = '7';
					}
					else
						Maze[pBombArr[i].y + j][pBombArr[i].x] = '1';
				}

				if (pPlayer->tPos.x == pBombArr[i].x && pPlayer->tPos.y == pBombArr[i].y + j) {
					pPlayer->tPos.x = 0;
					pPlayer->tPos.y = 0;
				}
			}
			if (pBombArr[i].x - j >= 0)
			{
				if (Maze[pBombArr[i].y][pBombArr[i].x - j] == '0')
				{
					//아이템 드랍 확률 구하기
					if (rand() % 100 < 20) {
						int iPercent = rand() % 100;
						if (iPercent < 70)
							Maze[pBombArr[i].y][pBombArr[i].x - j] = '5';
						else if (iPercent < 80)
							Maze[pBombArr[i].y][pBombArr[i].x - j] = '6';
						else
							Maze[pBombArr[i].y][pBombArr[i].x - j] = '7';
					}
					else
						Maze[pBombArr[i].y][pBombArr[i].x - j] = '1';
				}

				if (pPlayer->tPos.x == pBombArr[i].x - j && pPlayer->tPos.y == pBombArr[i].y) {
					pPlayer->tPos.x = 0;
					pPlayer->tPos.y = 0;
				}
			}
			if (pBombArr[i].x + j < 20)
			{
				if (Maze[pBombArr[i].y][pBombArr[i].x + j] == '0')
				{
					//아이템 드랍 확률 구하기
					if (rand() % 100 < 20) {
						int iPercent = rand() % 100;
						if (iPercent < 70)
							Maze[pBombArr[i].y][pBombArr[i].x + j] = '5';
						else if (iPercent < 80)
							Maze[pBombArr[i].y][pBombArr[i].x + j] = '6';
						else
							Maze[pBombArr[i].y][pBombArr[i].x + j] = '7';
					}
					else
						Maze[pBombArr[i].y][pBombArr[i].x + j] = '1';
				}

				if (pPlayer->tPos.x == pBombArr[i].x + j && pPlayer->tPos.y == pBombArr[i].y) {
					pPlayer->tPos.x = 0;
					pPlayer->tPos.y = 0;
				}
			}
		}
	}
	*pBombCount = 0;
}

int main()
{
	srand((unsigned int)time(0));

	//20 X 20 미로 만들기
	char strMaze[21][21] = {};

	PLAYER tPlayer = {};
	POINT tStartPos;
	POINT tEndPos;

	tPlayer.iBombPower = 1;

	int iBombCount = 0;

	POINT tBombPos[5];

	SetMaze(strMaze, &tPlayer, &tStartPos, &tEndPos);



	while (true) {
		system("cls");
		Output(strMaze, &tPlayer);

		if (tPlayer.tPos.x == tEndPos.x && tPlayer.tPos.y == tEndPos.y) {
			cout << "도착했습니다. " << endl;
			system("pause");
			break;
		}
		cout << "t : 폭탄설치 u : 폭탄 터트리기 i : 벽밀기 ON/OFF" << endl;
		cout << "w : 위 s : 아래 a : 왼쪽 d : 오른쪽 q : 종료 : ";
		char cinput = _getch();

		if (cinput == 'q' || cinput == 'Q')
			break;

		else if (cinput == 't' || cinput == 'T')
			CreateBomb(strMaze, &tPlayer, tBombPos, &iBombCount);

		else if (cinput == 'u' || cinput == 'U')

			Fire(strMaze, &tPlayer, tBombPos, &iBombCount);

		else if (cinput == 'i' || cinput == 'I')
		{
			if (tPlayer.bWallPush)
				tPlayer.bPushOnOff = !tPlayer.bPushOnOff;
		}

		MovePlayer(strMaze, &tPlayer, cinput);

	}
	return 0;
}