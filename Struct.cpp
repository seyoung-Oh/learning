#include <iostream>

using namespace std;

#define NAME_SIZE  32

/*
구조체 : 관련이 있는 변수들을 모아서 하나의 새로운 타입을 만들어 주는 기능
struct 구조체명 {}; 형태로 구성됨
배열과 구조체의 공통점 : 데이터 집합이다, 연속된 메모리 블럭에 할당된다
*/
struct _tagStudent
{
	char strName[NAME_SIZE];
	int iNumber;
	int iKor;
	int iEng;
	int iMath;
	int iTotal;
	float fAvg;
};
int main() {
	
	_tagStudent tStudent;
	_tagStudent tStudentArr[100] = {};

	tStudent.iKor = 100;
	strcpy_s(tStudent.strName, "osy");// 문자열 배열에 넣어줄 때는 strcpy_s활용하기

	//tStudent.strName[0] = 'a';
	//tStudent.strName[1] = 'b';
	//tStudent.strName[2] = 0;
	cout << "이름 길이 : " << strlen(tStudent.strName) << endl;

	strcat_s(tStudent.strName, "문자열붙이기");//오른쪽에 있는 문자열을 왼쪽에 붙여준다.

	//strcmp()두 문자열을 비교해 같을 경우 0반환하고 다를 경우 0이 아닌 값을 반환 

	strcpy_s(tStudent.strName, "오세영");
	cout << "비교할 이름을 입력하세요 : ";
	char strName[NAME_SIZE] = {};

	cin >> strName;

	if (strcmp(tStudent.strName, strName) == 0) {
		cout << "학생을 찾았습니다 " << endl;
	}
	else {
		cout << "학생을 못찾았습니다. " << endl;
	}

	cout << "이름 : " << tStudent.strName << endl;
	cout << "학번 : " << tStudent.iNumber << endl;
	cout << "국어 : " << tStudent.iKor<< endl;
	cout << "영어 : " << tStudent.iEng << endl;
	cout << "수학 : " << tStudent.iMath << endl;
	cout << "평균 : " << tStudent.fAvg << endl;
	return 0;

}