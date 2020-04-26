#include <iostream>

using namespace std;

/*
함수 : 기능을 만들어준다. 일종의 사용할 수 있는 부품을 만들어준다.
특정 상황에 동작하는 코드 집합을 만들어 내는 것
형태 : 반환타입 함수명(인자) {}
반환타입 : 함수가 기능을 수행하고 결과를 반환해야 할 경우 지정
*/

int g_iNum = 123;

int Sum(int a, int b) {
	return a + b;
}

void OutputText() {
	cout << "OutputTextFuction!" << endl;
}

void OutputNumber(int iNumber) 
{
	cout << "Number : " << iNumber << endl;
}
void ChangeNumber(int iNumber) 
{
	iNumber = 9999;
	g_iNum = 456;
}
/*
오버로딩 : 같은 이름의 함수지만 기능이 다르던가 인자가 다른 함수를 말한다.
오버로딩의 조건 : 함수 이름은 무조건 같고 인자의 개수 혹은 타입이 달라야 오버로딩 성립, 반환 타입은 오버로딩에 영향을 주지 않는다.
*/
void ChangeNumber(int* pNumber) {
	*pNumber = 2939;
}
//함수의  디폴트 인자 : 인자는 기본적으로 값을 넘겨받게 설정 그런데 인자에 기본값을 대입해두면 인자를 넘겨주지 않을 경우 기본 설정한 값이 되고
//인자를 넘겨받을 경우 넘겨받은 값으로 인자를 설정하는 기능
void Output(int iNum1, int iNum2 = 10)//디폴트 인자는 가장 오른쪽부터 지정
{
	cout << iNum1 << endl;
	cout << iNum2 << endl;
}

int main() 
{
	cout << Sum(10, 20) << endl;
	cout << Sum(103, 304) << endl;

	OutputText();
	OutputNumber(1234);
	int iNumber = 0;

	ChangeNumber(iNumber);
	ChangeNumber(&iNumber);

	cout << iNumber << endl;
	cout << g_iNum << endl;
	{
		int iNum1 = 1234;
	}

	Output(20);
	//cout << iNum1 << endl; Num1은 코드블럭 안에서만 존재하는 변수 밖에서는 사용 불가
	return 0;
}