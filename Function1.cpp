#include <iostream>

using namespace std;

/*
�Լ� : ����� ������ش�. ������ ����� �� �ִ� ��ǰ�� ������ش�.
Ư�� ��Ȳ�� �����ϴ� �ڵ� ������ ����� ���� ��
���� : ��ȯŸ�� �Լ���(����) {}
��ȯŸ�� : �Լ��� ����� �����ϰ� ����� ��ȯ�ؾ� �� ��� ����
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
�����ε� : ���� �̸��� �Լ����� ����� �ٸ����� ���ڰ� �ٸ� �Լ��� ���Ѵ�.
�����ε��� ���� : �Լ� �̸��� ������ ���� ������ ���� Ȥ�� Ÿ���� �޶�� �����ε� ����, ��ȯ Ÿ���� �����ε��� ������ ���� �ʴ´�.
*/
void ChangeNumber(int* pNumber) {
	*pNumber = 2939;
}
//�Լ���  ����Ʈ ���� : ���ڴ� �⺻������ ���� �Ѱܹް� ���� �׷��� ���ڿ� �⺻���� �����صθ� ���ڸ� �Ѱ����� ���� ��� �⺻ ������ ���� �ǰ�
//���ڸ� �Ѱܹ��� ��� �Ѱܹ��� ������ ���ڸ� �����ϴ� ���
void Output(int iNum1, int iNum2 = 10)//����Ʈ ���ڴ� ���� �����ʺ��� ����
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
	//cout << iNum1 << endl; Num1�� �ڵ�� �ȿ����� �����ϴ� ���� �ۿ����� ��� �Ұ�
	return 0;
}