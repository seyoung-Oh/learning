#include <iostream>

using namespace std;

int main(void)
{
	/*
	do while 
	do()while{조건식}
	while은 처음 집입부터 조건식을 체크 하지만 do while은 조건문 체크하기 전에 무조건 한번 실행됨
	*/
	
	int iNumber = 0;

	do
	{
		cout << iNumber << endl;
	} while (iNumber > 0);

	//int iArray[10] = { 1,2,3,4,5,6,7,8,9,10 }; 배열 여러개의 변수를 한번에 생성해줄 수 있는 기능 연속된 메모리 블럭에 공간 할당됨
	//int  iArray[10] = { 1,2,3,4,5 }; 5번부터는 0으로 초기화
	int iArray[10] = {}; //모든 배열이 0으로 초기화 
	iArray[1] = 1234;

	for (int i = 0; i < 10; ++i)
	{
		cout << iArray[i] << endl;
	}

	int iArray2[10][10] = { {1,2,3},{4,5,6} };
	for (int i = 0; i < 10;++i) {
		for (int j = 0;j < 10;++j) {
			cout << iArray2[i][j] << "\t";
		}
		cout << endl;
	}



	return 0;

}
