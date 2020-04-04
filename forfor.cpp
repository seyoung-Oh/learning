#include <iostream>
#include <time.h>
using namespace std;

int main(void)
{
	for (int i = 0;i < 10;++i)
	{
		cout << i << endl;
	}

	// 구구단 2단 출력하기

	for (int i = 1; i <= 9;++i)
	{
		cout << "2 * "<< i << " = " << 2*i << endl;
	}

	// 1 ~ 100 사이의 숫자중 짝수만 출력하는 for문을 작성하기

	for (int i = 2; i <= 100; i += 2)//증감연산자, 식 들어갈 수 있음
	{
		cout << i << endl;
	}

	//3과 7의 공배수만 출력해보기

	for (int i = 1;i <= 100;++i)
	{
		if (i % 3 == 0 && i % 7 == 0) 
		{
			cout << i << endl;
		}
	}

	// 중첩 for문 
	for (int i = 0; i < 10; ++i) {
		for (int j = 0;j < 10;++j) {
			cout << " i = " << i << " j = " << j << endl;
		}
	}

	// 2~9단 출력하는 중첩 for문
	for (int i = 2; i < 10; ++i) {
		for (int j = 1;j < 10;++j) {
			cout << i << " * " << j << " = " << i*j << endl;
		}
	}
	//별찍기
	for (int i = 0; i < 5; i++) {
		for (int j = 0;j <= i ;j++) {
			cout << "*";
		}
		cout << "\n";
	}
	cout << "\n";

	for (int i = 0; i < 5; i++) {
		for (int j = 0;j < 5-i;j++) {
			cout << "*";
		}
		cout << "\n";
	}

	return 0;

}
