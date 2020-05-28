#include <iostream>

using namespace std;

/*
함수포인터 : 함수의 메모리 주소를 저장하기 위한 포인터 변수를 선언할 수 있다.
전역함수의 경우 함수명이 곧 함수의 메모리 주소이다.
함수포인터 선언 방법 : 반환타입 (*포인터 변수명)(인자타입); 의 형태로 선언
*/

int Sum(int a, int b)
{
	return a + b;
}
int OutSum(int a, int b)
{
	cout << a - b << endl;
	return a - b;
}
void Output()
{
	cout << "Output Function" << endl;
}
int main()
{
	int(*pFunc)(int, int) = Sum;

	cout << pFunc(10, 20) << endl;

	pFunc = OutSum;

	OutSum(10, 20);

	//pFunc = Output;

	void(*pFunc1)() = Output;

	pFunc1();

	return 0;
}