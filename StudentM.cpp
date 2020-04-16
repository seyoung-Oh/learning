#include <iostream>

using namespace std;

#define NAME_SIZE 32
#define STUDENT_MAX 10
#define ADDRESS_SIZE 128
#define PHONE_SIZE 14

struct _tagStudent
{
	char strName[NAME_SIZE];
	char strAddress[ADDRESS_SIZE];
	char strPhone[PHONE_SIZE];
	int iNumber;
	int iKor;
	int iEng;
	int iMath;
	int iTotal;
	float fAvg;
};

enum MENU
{
	MENU_NONE,
	MENU_INSERT,
	MENU_DELETE,
	MENU_SEARCH,
	MENU_OUTPUT,
	MENU_EXIT
};

int main() 
{
	_tagStudent tStudentArr[STUDENT_MAX] = {};

	char strName[NAME_SIZE] = {};
	//배열에 추가된 개수를 저장한 변수를 만들어줌
	int iStudentCount = 0;
	int iStdNumber = 1;

	while (true)
	{
		system("cls");

		cout << "1. 학생 등록" << endl;
		cout << "2. 학생 삭제" << endl;
		cout << "3. 학생 탐색" << endl;
		cout << "4. 학생 출력" << endl;
		cout << "5. 종료" << endl;

		int iMenu;
		cin >> iMenu;//int 대신 char입력할 경우 에러 발생한다, 그래서 예외처리 해줘야함

		if (cin.fail())//입력에러 발생시 true 반환
		{
			cin.clear();//에러버퍼 비워주기
			cin.ignore(1024, '\n');//입력버퍼에 \n남아있으므로 \n검색해서 지워주기, 앞에는 검색하고자 하는 버퍼 크기 지정, 뒤에는 찾고자 하는 문자 넣어줌
			continue;
		}
		if (iMenu == MENU_EXIT)
			break;

		switch (iMenu)
		{
		case MENU_INSERT://학생정보 추가, 학번, 이름, 핸드폰 번호, 주소, 점수들은 입력 받고 학점 총점 평균은 연산 통해 계산
			system("cls");
			cout << "===================학생추가=======================" << endl;
			//등록된 학생이 등록할 수 있는 최대치일 경우 더이상 등록 안되게 막기
			if (iStudentCount == STUDENT_MAX)
				break;
			cout << "이름 : ";
			cin >> tStudentArr[iStudentCount].strName;
			cin.ignore(1024, '\n');//ignore이용해서 enter지워주기

			cout << "주소 : ";
			cin.getline(tStudentArr[iStudentCount].strAddress,ADDRESS_SIZE);//스페이스바도 입력 받고 엔터로만 문장 마치려면 cin.getline
			cout << tStudentArr[iStudentCount].strAddress << endl;

			cout << "핸드폰 번호 : " << endl;
			cin.getline(tStudentArr[iStudentCount].strPhone, PHONE_SIZE);

			cout << "국어 : ";
			cin >> tStudentArr[iStudentCount].iKor;

			cout << "영어 : ";
			cin >> tStudentArr[iStudentCount].iEng;

			cout << "수학 : ";
			cin >> tStudentArr[iStudentCount].iMath;

			tStudentArr[iStudentCount].iTotal = tStudentArr[iStudentCount].iKor + tStudentArr[iStudentCount].iEng + tStudentArr[iStudentCount].iMath;

			tStudentArr[iStudentCount].fAvg = tStudentArr[iStudentCount].iTotal / 3;

			tStudentArr[iStudentCount].iNumber = iStdNumber;
			++iStdNumber;
			++iStudentCount;

			cout << "학생 추가 완료" << endl;
			break;
		case MENU_DELETE:
			system("cls");
			cout << "===================학생삭제=======================" << endl;

			cin.ignore(1024, '\n');
			cout << "탐색할 이름을 입력하세요 : ";
			cin.getline(strName, NAME_SIZE);

			for (int i = 0;i < iStudentCount;++i) {
				if (strcmp(tStudentArr[i].strName, strName) == 0)
				{
					for (int j = i;j < iStudentCount - 1;++j)
					{
						tStudentArr[i] = tStudentArr[i + 1];
					}
					--iStudentCount;
					cout << "학생을 삭제하였습니다" << endl;
					break;
				}
			}


			break;
		case MENU_SEARCH:
			system("cls");
			cout << "===================학생탐색=======================" << endl;

			cin.ignore(1024, '\n');
			cout << "탐색할 이름을 입력하세요 : ";
			cin.getline(strName, NAME_SIZE);
			
			for (int i = 0;i < iStudentCount;++i) {
				if (strcmp(tStudentArr[i].strName, strName) == 0)
				{
					cout << "이름 : " << tStudentArr[i].strName << endl;
					cout << "전화번호 : " << tStudentArr[i].strPhone << endl;
					cout << "주소 : " << tStudentArr[i].strAddress << endl;
					cout << "학번 : " << tStudentArr[i].iNumber << endl;
					cout << "국어 : " << tStudentArr[i].iKor << endl;
					cout << "영어 : " << tStudentArr[i].iEng << endl;
					cout << "수학 : " << tStudentArr[i].iMath << endl;
					cout << "총점 : " << tStudentArr[i].iTotal << endl;
					cout << "평균 : " << tStudentArr[i].fAvg << endl << endl;
					break;
				}
			}

			break;
		case MENU_OUTPUT:
			system("cls");
			cout << "===================학생출력=======================" << endl;

			for (int i = 0;i < iStudentCount;++i) {
				cout << "이름 : " << tStudentArr[i].strName << endl;
				cout << "전화번호 : " << tStudentArr[i].strPhone << endl;
				cout << "주소 : " << tStudentArr[i].strAddress << endl;
				cout << "학번 : " << tStudentArr[i].iNumber << endl;
				cout << "국어 : " << tStudentArr[i].iKor << endl;
				cout << "영어 : " << tStudentArr[i].iEng << endl;
				cout << "수학 : " << tStudentArr[i].iMath << endl;
				cout << "총점 : " << tStudentArr[i].iTotal << endl;
				cout << "평균 : " << tStudentArr[i].fAvg << endl << endl;
			}
			break;
		default:
			cout << "메뉴를 잘못 입력하셨습니다." << endl;
			break;
		}

		system("pause");
	}

	return 0;
}