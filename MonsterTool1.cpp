#include <iostream>
using namespace std;


#define NAME_SIZE 32
#define ITEM_DESC_LENGTH 512

enum MAP_TYPE
{
	MT_EASY,
	MT_NORMAL,
	MT_HARD,
	MT_END
};
enum MAIN_MENU
{
	MM_NONE,
	MM_ADD,
	MM_LOAD,
	MM_SAVE,
	MM_OUTPUT,
	MM_EXIT
};
struct _tagMonster {
	char strName[NAME_SIZE];
	int iAttackMin;
	int iAttackMAX;
	int iArmorMin;
	int iArmorMax;
	int iHP;
	int iHPMax;
	int iMP;
	int iMPMax;
	int iLevel;
	int iExp;
	int iGoldMin;
	int iGoldMax;
};
int Inputint() {
	int iInput;
	cin >> iInput;

	if (cin.fail()) {
		cin.clear();
		cin.ignore(1024, '\n');
		return INT_MAX;//int max return�� �Է� �߸���
	}
	return iInput;
}
void AddMonster(_tagMonster* pMonsterArr)
{
	system("cls");
	int iMap = 0;
	while (true)
	{
		cout << "1.����" << endl;
		cout << "2.����" << endl;
		cout << "3.�����" << endl;
		cout << "4.���" << endl;
		cout << "�߰��� ���̵��� �����ϼ��� : ";
		iMap = Inputint();

		if (iMap == 4)
			return;
		else if (iMap < 1 || iMap > 4)
			continue;

		--iMap;//1���� �����̱� ������ 1�� ���ҽ��Ѿ� ����� �ε����� �ȴ�.
		break;
	}
	system("cls");
	cin.clear();
	cin.ignore(1024, '\n');

	cout << "�̸� : ";
	cin.getline(pMonsterArr[iMap].strName, NAME_SIZE - 1);//�������� null ���� ���� ��

	cout << "�ּ� ���ݷ� :";
	pMonsterArr[iMap].iAttackMin = Inputint();
	cout << "�ִ� ���ݷ� :";
	pMonsterArr[iMap].iAttackMAX = Inputint();
	cout << "�ּ� ���� :";
	pMonsterArr[iMap].iArmorMin = Inputint();
	cout << "�ִ� ���� :";
	pMonsterArr[iMap].iArmorMax = Inputint();
	cout << "ü�� :";
	pMonsterArr[iMap].iHP = Inputint();
	pMonsterArr[iMap].iHPMax = pMonsterArr[iMap].iHP;
	cout << "���� :";
	pMonsterArr[iMap].iMP = Inputint();
	pMonsterArr[iMap].iMPMax = pMonsterArr[iMap].iMP;


	cout << "���� :";
	pMonsterArr[iMap].iLevel = Inputint();

	cout << "ȹ�����ġ :";
	pMonsterArr[iMap].iExp = Inputint();

	cout << "ȹ�� �ּ� ��� :";
	pMonsterArr[iMap].iGoldMin = Inputint();

	cout << "ȹ�� �ִ� ��� :";
	pMonsterArr[iMap].iGoldMax = Inputint();

	cout << "���� �߰� �Ϸ�" << endl;

	system("pause");
	
}
bool SaveMonster(_tagMonster* pMonsterArr)
{
	FILE* pFile;
	fopen_s(&pFile, "Monster.mst", "wb");

	if (pFile)
	{
		fwrite(pMonsterArr, sizeof(_tagMonster), MT_END, pFile);
		fclose(pFile);
		return true;

	}
	return false;

}
bool LoadMonster(_tagMonster* pMonsterArr)
{
	FILE* pFile;
	fopen_s(&pFile, "Monster.mst", "rb");

	if (pFile)
	{
		fread(pMonsterArr, sizeof(_tagMonster), MT_END, pFile);
		fclose(pFile);
		return true;

	}
	return false;

}
void OutputMonster(_tagMonster* pMonster) {
	cout << "=======================Moster=======================" << endl;
	cout << "�̸� : " << pMonster->strName << "\t���� : " << pMonster->iLevel << endl;
	cout << "���ݷ� : " << pMonster->iAttackMin << " - " << pMonster->iAttackMAX << "\t���� : " << pMonster->iArmorMin << " - " << pMonster->iArmorMax << endl;
	cout << "ü�� : " << pMonster->iHP << " / " << pMonster->iHPMax << "\t���� : " << pMonster->iMP << " / " << pMonster->iMPMax << endl;
	cout << "ȹ�����ġ : " << pMonster->iExp << "\tȹ���� : " << pMonster->iGoldMin << " - " << pMonster->iGoldMax << endl << endl;
}
void Output(_tagMonster* pMonsterArr)
{
	system("cls");
	for (int i = 0;i < MT_END;++i)
	{
		OutputMonster(&pMonsterArr[i]);
	}
	system("pause");
}
int main()
{
	_tagMonster tMonster[MT_END] = {};
	while (true)
	{
		system("cls");
		cout << "1. ���� �߰�" << endl;
		cout << "2. �о����" << endl;
		cout << "3. ����" << endl;
		cout << "4. ���� ���" << endl;
		cout << "5. ����" << endl;
		cout << "�޴��� �����ϼ��� : ";
		int iMenu = Inputint();

		if (iMenu == MM_EXIT)
			break;
		switch (iMenu)
		{
		case MM_ADD:
			AddMonster(tMonster);
			break;
		case MM_LOAD:
			LoadMonster(tMonster);
			break;
		case MM_SAVE:
			SaveMonster(tMonster);
			break;
		case MM_OUTPUT:
			Output(tMonster);
			break;
		}

	}
	SaveMonster(tMonster);
	return 0;
}