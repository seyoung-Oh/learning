#include <iostream>

using namespace std;

int main() {

	/*
	������ : ����Ű��. �Ϲ� ������ �Ϲ����� ���� �����ϰ� ������ ������ ������ �޸� �ּҸ� �����ϰ� �ȴ�. ��� ���� Ÿ���� ������ Ÿ���� ������ �� �ִ�.
	�����ʹ� �޸� �ּҸ� ��Ƴ��� �����̱� ������ x86���� ������ ���� ������ 4byte, x64�϶��� 8byte�� ���´�.
	����Ÿ�� *������;
	*/
	int iNumber = 100;
	int *pNum = &iNumber;//���� ����� *�� �ٿ��ָ� �ش� Ÿ���� ������ ������ ����ȴ�. pNum�� iNumber�� �޸� �ּҸ� ���� �ȴ�.

	cout << sizeof(int*) << endl;
	cout << sizeof(char*) << endl;
	cout << sizeof(double*) << endl;

	//pNum�� �̿��ؼ� iNumber�� ���� �����ϱ�
	//�������� �̿��ؼ� ���� �����ų� ���� ���� ������ ���� �տ� *�� ���̸� �������� ��
	cout << *pNum << endl;
	*pNum = 1234;
	/*
	�����Ϳ� �迭�� ���� : �迭���� �����ʹ�.
	�迭�� ��ü�� �迭�� ������ �ּҸ� �ǹ��Ѵ�.
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

	// vhdlsxj dustks +,-,++,--�� ���� �ܼ��� �޸� �ּ� ���� 1�����ϴ� ���� �ƴ϶� ����Ű�� �ش������� Ÿ���� ���� Ÿ�� ũ�⸸ŭ ������ int�� 4��ŭ ����

	cout << pArray << endl;
	cout << pArray + 2 << endl;
	cout << *pArray << endl;
	cout << *(pArray + 2) << endl;
	cout << *pArray + 100 << endl;

	return 0;
}