#include <iostream>

using namespace std;
#define NAME_SIZE 32
#define ITEM_DESC_LENGTH 512

#define STORE_WEAPON_MAX 3
#define STORE_ARMOR_MAX 3
enum ITEM_TYPE {
	IT_NONE,
	IT_WEAPON,
	IT_ARMOR,
	IT_BACK
};
struct _tagITem
{
	char strName[NAME_SIZE];
	char strTypeName[NAME_SIZE];
	ITEM_TYPE eType;
	int iMin;
	int iMax;
	int iPrice;
	int iSell;
	char strDesc[ITEM_DESC_LENGTH];

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

enum STORE_MENU {
	SM_NONE,
	SM_WEAPON,
	SM_ARMOR,
	SM_BACK
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
void AddItem(_tagITem* pWeaponStore, _tagITem* pArmorStore)
{
	system("cls");
	int iStore = 0;
	while (true)
	{
		cout << "1.�������" << endl;
		cout << "2.������" << endl;
		cout << "3.���" << endl;
		cout << "�߰��� ������ �����ϼ��� : ";
		iStore = Inputint();

		if (iStore == 3)
			return;
		else if (iStore < 1 || iStore > 3)
			continue;

		break;
	}
	system("cls");
	int iItemLevel = 0;
	while (true)
	{
		cout << "1.�ʱ�" << endl;
		cout << "2.�߱�" << endl;
		cout << "3.���" << endl;
		cout << "4.���" << endl;
		cout << "�߰��� ������ ���̵��� �����ϼ��� : ";
		iItemLevel = Inputint();

		if (iItemLevel == 4)
			return;
		else if (iItemLevel < 1 || iItemLevel > 4)
			continue;

		--iItemLevel;//1���� �����̱� ������ 1�� ���ҽ��Ѿ� ����� �ε����� �ȴ�.
		break;
	}
	cin.clear();
	cin.ignore(1024, '\n');
	
	_tagITem* pItem = NULL;

	//���ڷ� ����������� ����� ������ �迭�� �� �������� ����� ������ �迭�� ���� �־��־���, �������� �߰��� ������ �߰��� ���� ����, ������ ���̵� ����
	if (iStore == SM_WEAPON)
	{
		pItem = &pWeaponStore[iItemLevel];
		pItem->eType = IT_WEAPON;
		strcpy_s(pItem->strTypeName, "����");
	}
	else
	{
		pItem = &pArmorStore[iItemLevel];
		pItem->eType = IT_ARMOR;
		strcpy_s(pItem->strTypeName, "��");
	}

	cout << "�̸� : ";
	cin.getline(pItem->strName, NAME_SIZE - 1);//�������� null ���� ���� ��

	cout << "������ ���� : ";
	cin.getline(pItem->strDesc, ITEM_DESC_LENGTH - 1);
	cout << "�ּ� �ɷ�ġ :";
	pItem->iMin = Inputint();
	cout << "�ִ� �ɷ�ġ :";
	pItem->iMax = Inputint();
	cout << "Price : ";
	pItem->iPrice = Inputint();
	cout << "Sell : ";
	pItem->iSell = Inputint();

	cout << "������ �߰� �Ϸ�" << endl;

	system("pause");

}
bool SaveStore(_tagITem* pWeapon, _tagITem* pArmor)
{
	FILE* pFile;
	fopen_s(&pFile, "Store.str", "wb");

	if (pFile)
	{
		fwrite(pWeapon, sizeof(_tagITem), STORE_WEAPON_MAX, pFile);
		fwrite(pArmor, sizeof(_tagITem), STORE_ARMOR_MAX, pFile);

		fclose(pFile);
		return true;

	}
	return false;

}
bool LoadStore(_tagITem* pWeapon, _tagITem* pArmor)
{
	FILE* pFile;
	fopen_s(&pFile, "Store.str", "rb");

	if (pFile)
	{
		fread(pWeapon, sizeof(_tagITem), STORE_WEAPON_MAX, pFile);
		fread(pArmor, sizeof(_tagITem), STORE_ARMOR_MAX, pFile);
		fclose(pFile);
		return true;

	}
	return false;

}

void Output(_tagITem* pWeapon, _tagITem* pArmor)
{
	system("cls");
	cout << "=======================Store=======================" << endl;
	for (int i = 0;i < STORE_WEAPON_MAX;++i)
	{
		cout << i + 1 << ". �̸� : " << pWeapon[i].strName << "\t���� : " << pWeapon[i].strTypeName << endl;
		cout << "���ݷ� : " << pWeapon[i].iMin << " - " << pWeapon[i].iMax << endl;
		cout << "�ǸŰ��� : " << pWeapon[i].iPrice << "\t���Ű��� : " << pWeapon[i].iSell << endl;
		cout << "���� : " << pWeapon[i].strDesc << endl << endl;

	}
	for (int i = 0;i < STORE_ARMOR_MAX;++i)
	{
		cout << i + 1 << ". �̸� : " << pArmor[i].strName << "\t���� : " << pArmor[i].strTypeName << endl;
		cout << "���ݷ� : " << pArmor[i].iMin << " - " << pArmor[i].iMax << endl;
		cout << "�ǸŰ��� : " << pArmor[i].iPrice << "\t���Ű��� : " << pArmor[i].iSell << endl;
		cout << "���� : " << pArmor[i].strDesc << endl << endl;

	}
	system("pause");
}
int main()
{
	_tagITem tWeapon[STORE_WEAPON_MAX] = {};
	_tagITem tArmor[STORE_ARMOR_MAX] = {};

	while (true)
	{
		system("cls");
		cout << "1. ������ �߰�" << endl;
		cout << "2. �о����" << endl;
		cout << "3. ����" << endl;
		cout << "4. ������ ���" << endl;
		cout << "5. ����" << endl;
		cout << "�޴��� �����ϼ��� : ";
		int iMenu = Inputint();

		if (iMenu == MM_EXIT)
			break;
		switch (iMenu)
		{
		case MM_ADD:
			AddItem(tWeapon,tArmor);
			break;
		case MM_LOAD:
			LoadStore(tWeapon, tArmor);
			break;
		case MM_SAVE:
			SaveStore(tWeapon, tArmor);
			break;
		case MM_OUTPUT:
			Output(tWeapon, tArmor);
			break;
		}

	}
	SaveStore(tWeapon, tArmor);
	return 0;
}