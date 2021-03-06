#include <iostream>

using namespace std;

struct _tagStudent
{
	int iKor;
	int iEng;
	int iMath;
	int iTotal;
	float fAvg;
};

int main() {

	/*
	포인터 : 가리키다. 일반 변수는 일반적인 값을 저장하게 되지만 포인터 변수는 메모리 주소를 저장하게 된다. 모든 변수 타입은 포인터 타입을 선언할 수 있다.
	포인터는 메모리 주소를 담아놓는 변수이기 때문에 x86으로 개발할 때는 무조건 4byte, x64일때는 8byte가 나온다.
	변수타입 *변수명;
	*/
	int iNumber = 100;
	int *pNum = &iNumber;//변수 선언시 *을 붙여주면 해당 타입의 포인터 변수가 선언된다. pNum은 iNumber의 메모리 주소를 갖게 된다.

	cout << sizeof(int*) << endl;
	cout << sizeof(char*) << endl;
	cout << sizeof(double*) << endl;

	//pNum을 이용해서 iNumber의 값을 제어하기
	//역참조를 이용해서 값을 얻어오거나 변경 가능 포인터 변수 앞에 *을 붙이면 역참조가 됨
	cout << *pNum << endl;
	*pNum = 1234;
	/*
	포인터와 배열의 관계 : 배열명은 포인터다.
	배열명 자체가 배열의 시작점 주소를 의미한다.
	*/

	cout << "iNumber Value : " << iNumber << endl;
	cout << "iNumber Adress : " << &iNumber << endl;
	cout << "pNum Value : " << pNum << endl;
	cout << "pNum Adress : " << &pNum << endl;

	int iArray[10] = { 1,2,3,4,5,6,7,8,9,10 };

	cout << "Array Adress : " << iArray << endl;
	cout << "Array Adress : " << &iArray[0] << endl;

	int *pArray = iArray;

	cout << pArray[2] << endl;

	// 포인터 연산 :  +,-,++,--다 가능 단순히 메모리 주소 값이 1증가하는 것이 아니라 가리키는 해당포인터 타입의 변수 타입 크기만큼 증가됨 int는 4만큼 증가

	cout << pArray << endl;
	cout << pArray + 2 << endl;
	cout << *pArray << endl;
	cout << *(pArray + 2) << endl;
	cout << *pArray + 100 << endl;

	const char *pText = "테스트 문자열";

	cout << pText << endl;
	cout << (int*)pText << endl;

	pText = "abcd";
	cout << pText << endl;
	cout << (int*)pText << endl;

	pText = "abcdefg";
	cout << pText << endl;
	cout << (int*)pText << endl;

	char str[8] = "abcdefg";

	cout << str << endl;
	cout << (int*)str << endl;
	cout << (int*)&str[0] << endl;

	_tagStudent tStudent = {};

	tStudent.iKor = 100;

	_tagStudent *pStudent = &tStudent;

	//연산자 우선순위 때문에 .을 먼저 인식함 그래서 괄호로 묶어 주어야 함
	(*pStudent).iKor = 50;
	pStudent->iKor = 80;//윗줄과 같은 용도

	cout << tStudent.iKor << endl;

	//void : 타입이 없다. void의 포인터 타입을 활용할 수 있다. 어떤 타입의 메모리 주소든 모두 저장 가능하다. 단 역참조는 불가능, 메모리 주소만 저장 가능

	void* pVoid = &iNumber;
	
	cout << "iNumber Address : " << pVoid << endl;

	int* pConvert = (int*)pVoid;
	*pConvert = 10101010;
	cout << iNumber << endl;
	*((int*)pVoid) = 9999;

	cout << iNumber << endl;

	pVoid = &tStudent;

	cout << "tStudent address : " << pVoid << endl;

	return 0;
}