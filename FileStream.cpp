#include <iostream>

using namespace std;

//pp�� main �Լ� �ȿ� �ִ� int* Ÿ���� p������ �ּҸ� ������ �ȴ�
void Test(int** pp) 
{
	*pp = new int;
}

int main()
{
	//int* p = NULL;

	//p = new int; �̰Ŷ� Test�Լ� ȣ���ϴ°Ͱ� ���� ȿ��

	//Test(&p);
	
	FILE* pFile = NULL;
	
	//1�� ���� : ������ �����������̴�.
	//2�� ���� : ���� ����̴�. ������ �����Ǵ� ���� ��δ� ���� ������Ʈ�� �ִ� ��������. exe���� ����� �ش� exe ������ �ִ� ��θ� �������� ����
	//3�� ���� : ���� ����̴�. ���� ũ�� 2������ ���еȴ�. �б�, ����, ������ �ְ� ���� ����, txt, binary �ΰ��� ����
	//r : �б� w : ���� a : ����			t : �ؽ�Ʈ ���� b : ���̳ʸ� ����
	/*
	fopen_s(&pFile, "hot.txt", "wt");

	if (pFile != NULL)
	{
		//fwrite, fread, fputs, fgets
		const char* pText = "abcd";

		fwrite(pText, 1, 4, pFile);

		fclose(pFile);
		cout << "���� ����� ����" << endl;
	}
	*/
	fopen_s(&pFile, "hot.txt", "rt");
	if (pFile)
	{
		char strText[5] = {};
		fread(strText, 1, 4, pFile);
		cout << strText << endl;

		fclose(pFile);
		cout << "���� �б� ����" << endl;

	}

	return 0;
}