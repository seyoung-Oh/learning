#include <iostream>
#include <functional>
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
float TestFunc(float a)
{
	cout << a << endl;
	return a;
}
void Output()
{
	cout << "Output Function" << endl;
}

class CHanzo
{
public :
	CHanzo()
	{
		m_iTest = 10;
	}
	~CHanzo()
	{

	}
public :
	int m_iTest;

public:
	void Output()
	{
		cout << "Hanzo" << endl;
		//this->는 생략 가능하다.
		cout << "Test : " << this->m_iTest << endl;
	}
};
int main()
{
	int(*pFunc)(int, int) = Sum;

	cout << pFunc(10, 20) << endl;

	pFunc = OutSum;

	OutSum(10, 20);

	//pFunc = Output;

	void(*pFunc1)() = Output;

	pFunc1();

	CHanzo hanzo1, hanzo2;

	//this 포인터 : 클래스 안에서 this를 사용할 경우 해당 객체의 메모리 주소가 된다. 자기 자신의 포인터이다.
	//멤버 함수를 호출할 때 this 포인터
	hanzo1.m_iTest = 100;
	hanzo2.m_iTest = 200;

	hanzo1.Output();
	hanzo2.Output();

	//멤버함수 포인터 선언시 포인터 변수 이름 앞에 클래스명 ::을 붙여준다.
	void(CHanzo::*pFunc2)() = &CHanzo::Output;

	//(*pFunc2)();

	//hanzo1.(*pFunc2)();
	(hanzo1.*pFunc2)();
	/*
	function 기능은 c++ 11부터 지원가능 함수포인터를 전역, 멤버를 가리지 않고 쉽게 주소를 저장해서 호출해줄 수 있도록 만들어 주는 기능이다
	function<반환타입(인자타입)> 변수명; 의 형태로 선언한다.
	*/
	function<void()> func;
	function<void()> func1;
	//bind이용해서 함수를 묶어준다.
	func = bind(Output);
	func1 = bind(&CHanzo::Output, &hanzo2);

	cout << "============== Functional ===============" << endl;

	func();
	func1();

	function<int(int, int)> func3;
	function<float(float)> func4;

	//함수에 인자가 있을 경우 placeholders를 이용해서 인자의 순서를 정의할 수 있다. 아래처럼 2,1로 넣으면 순서가 바뀜
	func3 = bind(OutSum, placeholders::_2, placeholders::_1);

	func3(10, 20);

	func4 = bind(TestFunc, placeholders::_1);
	func4(3.14f);

	return 0;
}