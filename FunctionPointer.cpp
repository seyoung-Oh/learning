#include <iostream>

using namespace std;

/*
�Լ������� : �Լ��� �޸� �ּҸ� �����ϱ� ���� ������ ������ ������ �� �ִ�.
�����Լ��� ��� �Լ����� �� �Լ��� �޸� �ּ��̴�.
�Լ������� ���� ��� : ��ȯŸ�� (*������ ������)(����Ÿ��); �� ���·� ����
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