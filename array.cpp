#include <iostream>

using namespace std;

int main(void)
{
	/*
	do while 
	do()while{���ǽ�}
	while�� ó�� ���Ժ��� ���ǽ��� üũ ������ do while�� ���ǹ� üũ�ϱ� ���� ������ �ѹ� �����
	*/
	
	int iNumber = 0;

	do
	{
		cout << iNumber << endl;
	} while (iNumber > 0);

	//int iArray[10] = { 1,2,3,4,5,6,7,8,9,10 }; �迭 �������� ������ �ѹ��� �������� �� �ִ� ��� ���ӵ� �޸� ���� ���� �Ҵ��
	//int  iArray[10] = { 1,2,3,4,5 }; 5�����ʹ� 0���� �ʱ�ȭ
	int iArray[10] = {}; //��� �迭�� 0���� �ʱ�ȭ 
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
