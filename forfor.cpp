#include <iostream>
#include <time.h>
using namespace std;

int main(void)
{
	for (int i = 0;i < 10;++i)
	{
		cout << i << endl;
	}

	// ������ 2�� ����ϱ�

	for (int i = 1; i <= 9;++i)
	{
		cout << "2 * "<< i << " = " << 2*i << endl;
	}

	// 1 ~ 100 ������ ������ ¦���� ����ϴ� for���� �ۼ��ϱ�

	for (int i = 2; i <= 100; i += 2)//����������, �� �� �� ����
	{
		cout << i << endl;
	}

	//3�� 7�� ������� ����غ���

	for (int i = 1;i <= 100;++i)
	{
		if (i % 3 == 0 && i % 7 == 0) 
		{
			cout << i << endl;
		}
	}

	// ��ø for�� 
	for (int i = 0; i < 10; ++i) {
		for (int j = 0;j < 10;++j) {
			cout << " i = " << i << " j = " << j << endl;
		}
	}

	// 2~9�� ����ϴ� ��ø for��
	for (int i = 2; i < 10; ++i) {
		for (int j = 1;j < 10;++j) {
			cout << i << " * " << j << " = " << i*j << endl;
		}
	}
	//�����
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
