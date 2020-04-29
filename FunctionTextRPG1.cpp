#include <iostream>
#include <time.h>
using namespace std;

enum MAIN_MENU {
	MM_NONE,
	MM_MAP,
	MM_STORE,
	MM_INVENTORY,
	MM_EXIT
};
enum MAP_TYPE
{
	MT_NONE,
	MT_EASY,
	MT_NORMAL,
	MT_HARD,
	MT_BACK
};
enum JOB {
	JOB_NONE,
	JOB_KNIGHT,
	JOB_ARCHER,
	JOB_WIZARD,
	JOB_END
};
enum EQUIP {
	EQ_WEAPON,
	EQ_ARMOR,
	EQ_MAX
};
enum BATTLE {
	BATTLE_NONE,
	BATTLE_ATTACK,
	BATTLE_BACK
};
enum ITEM_TYPE {
	IT_NONE,
	IT_WEAPON,
	IT_ARMOR,
	IT_BACK
};
#define NAME_SIZE 32
#define ITEM_DESC_LENGTH 512
#define INVENTORY_MAX 20
#define STORE_WEAPON_MAX 3
#define STORE_ARMOR_MAX 3
#define LEVEL_MAX 10
const int g_iLevelUpExp[LEVEL_MAX] = { 4000, 10000, 20000, 35000, 50000, 70000, 100000, 150000, 200000, 400000 };
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
struct _tagInventory
{
	_tagITem tItem[INVENTORY_MAX];
	int iItemCount;
	int iGold;
};
struct _tagPlayer {
	char strName[NAME_SIZE];
	char strJobName[NAME_SIZE];
	JOB eJob;
	int iAttackMin;
	int iAttackMAX;
	int iArmorMin;
	int iArmorMax;
	int iHP;
	int iHPMax;
	int iMP;
	int iMPMax;
	int iExp;
	int iLevel;
	_tagITem	tEquip[EQ_MAX];
	bool		bEquip[EQ_MAX];
	_tagInventory tInventory;
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
int OutputMainMenu() {//���� �޴��� ȭ�鿡 �����ְ� �Է¹��� �޴��� ��ȯ �Է� ������ MM_NONE��ȯ
	system("cls");

	cout << "*************************************�κ�*************************************" << endl;
	cout << "1.��" << endl;
	cout << "2.����" << endl;
	cout << "3.����" << endl;
	cout << "4.����" << endl;
	cout << "�޴��� �����ϼ��� : ";

	int iMenu = Inputint();

	if (iMenu == INT_MAX || iMenu <= MM_NONE || iMenu > MM_EXIT)
		return MM_NONE;

	return iMenu;
}
void OutputBattleTag(int iMenu) {
	system("cls");
	switch (iMenu) {
	case MT_EASY:
		cout << "*************************************����*************************************" << endl;
		break;
	case MT_NORMAL:
		cout << "*************************************����*************************************" << endl;
		break;
	case MT_HARD:
		cout << "*************************************�����*************************************" << endl;
		break;
	}
}
void OutputPlayer(_tagPlayer* pPlayer) {

	cout << "=======================Player=======================" << endl;
	cout << "�̸� : " << pPlayer->strName << "\t���� : " << pPlayer->strJobName << endl;
	cout << "���� : " << pPlayer->iLevel << "\t����ġ : " << pPlayer->iExp << " / " << g_iLevelUpExp[pPlayer->iLevel - 1] << endl;
	if (pPlayer->bEquip[EQ_WEAPON] == true)
		cout << "���ݷ� : " << pPlayer->iAttackMin << " + " << pPlayer->tEquip[EQ_WEAPON].iMin << " - " << pPlayer->iAttackMAX << " + " << pPlayer->tEquip[EQ_WEAPON].iMax;
	else
		cout << "���ݷ� : " << pPlayer->iAttackMin << " - " << pPlayer->iAttackMAX;

	if (pPlayer->bEquip[EQ_ARMOR] == true)
		cout << "\t�濩�� : " << pPlayer->iArmorMin << " + " << pPlayer->tEquip[EQ_ARMOR].iMin << " - " << pPlayer->iArmorMax << " + " << pPlayer->tEquip[EQ_ARMOR].iMax << endl;
	else
		cout << "\t�濩�� : " << pPlayer->iArmorMin << " - " << pPlayer->iArmorMax << endl;
	
	cout << "ü�� : " << pPlayer->iHP << " / " << pPlayer->iHPMax << "\t���� : " << pPlayer->iMP << " / " << pPlayer->iMPMax << endl;
	cout << "���� ��� : " << pPlayer->tInventory.iGold << " Gold" << endl;
}
void OutputMonster(_tagMonster* pMonster) {
	cout << "=======================Moster=======================" << endl;
	cout << "�̸� : " << pMonster->strName << "\t���� : " << pMonster->iLevel << endl;
	cout << "���ݷ� : " << pMonster->iAttackMin << " - " << pMonster->iAttackMAX << "\t���� : " << pMonster->iArmorMin << " - " << pMonster->iArmorMax << endl;
	cout << "ü�� : " << pMonster->iHP << " / " << pMonster->iHPMax << "\t���� : " << pMonster->iMP << " / " << pMonster->iMPMax << endl;
	cout << "ȹ�����ġ : " << pMonster->iExp << "\tȹ���� : " << pMonster->iGoldMin << " - " << pMonster->iGoldMax << endl << endl;

}
int OutputBattleMenu() {
	cout << "1. ����" << endl;
	cout << "2. ��������" << endl;

	cout << "�޴��� �����ϼ��� : ";
	int iMenu = Inputint();

	if (iMenu == INT_MAX || iMenu <= BATTLE_NONE || iMenu > BATTLE_BACK)
		return BATTLE_NONE;

	return iMenu;
}
void RunBattle(_tagPlayer* pPlayer, _tagMonster* pMonsterArr, int iMenu) {
	_tagMonster tMonster = pMonsterArr[iMenu - 1];
	while (true)
	{
		system("cls");
		OutputBattleTag(iMenu);

		//�÷��̾� ���
		OutputPlayer(pPlayer);

		//���� ���
		OutputMonster(pMonsterArr);

		switch (OutputBattleMenu()) {
		case BATTLE_ATTACK:
			break;
		case BATTLE_BACK:
			return;
		}
	}
}
int OutputMapMenu() {
	system("cls");
	cout << "*************************************��*************************************" << endl;
	cout << "1. ����" << endl;
	cout << "2. ����" << endl;
	cout << "3. �����" << endl;
	cout << "4. �ڷΰ���" << endl;
	cout << "���� �����ϼ��� : ";
	int iMenu = Inputint();
	if (iMenu == INT_MAX || iMenu <= MT_NONE || iMenu > MT_BACK)
		return MT_NONE;

	return iMenu;
}
void RunMap(_tagPlayer* pPlayer, _tagMonster* pMonsterArr) {//�ʿ� ���õ� ���� ó��
	bool bLoop = true;
	while (bLoop) {
		int iMenu = OutputMapMenu();

		if (MT_BACK == iMenu)
			return;

		//���� ����
		RunBattle(pPlayer, pMonsterArr, iMenu);

	}
}

int SelectJob() {
	int iJob = JOB_NONE;
	while (iJob == JOB_NONE) 
	{
		system("cls");
		cout << "1. ���" << endl;
		cout << "2. �ü�" << endl;
		cout << "3. ������" << endl;
		cout << "������ �����ϼ��� : " << endl;
		iJob = Inputint();

		if (iJob <= JOB_NONE || iJob >= JOB_END)
			iJob = JOB_NONE;
	}
	return iJob;
}

void SetPlayer(_tagPlayer* pPlayer) 
{
	cout << "�̸� : ";
	cin.getline(pPlayer->strName, NAME_SIZE - 1);//�������� null ���� ���� ��

	pPlayer->eJob = (JOB)SelectJob();
	pPlayer->iLevel = 1;
	pPlayer->iExp = 0;
	pPlayer->tInventory.iGold = 10000;

	switch (pPlayer->eJob) {
	case JOB_KNIGHT:
		strcpy_s(pPlayer->strJobName, "���");
		pPlayer->iAttackMin = 5;
		pPlayer->iAttackMAX = 10;
		pPlayer->iArmorMin = 15;
		pPlayer->iArmorMax = 20;
		pPlayer->iHPMax = 500;
		pPlayer->iHP = 500;
		pPlayer->iMP = 500;
		pPlayer->iMPMax = 100;
		break;
	case JOB_ARCHER:
		strcpy_s(pPlayer->strJobName, "�ü�");
		pPlayer->iAttackMin = 10;
		pPlayer->iAttackMAX = 15;
		pPlayer->iArmorMin = 10;
		pPlayer->iArmorMax = 20;
		pPlayer->iHPMax = 400;
		pPlayer->iHP = 400;
		pPlayer->iMP = 200;
		pPlayer->iMPMax = 200;
		break;
	case JOB_WIZARD:
		strcpy_s(pPlayer->strJobName, "������");
		pPlayer->iAttackMin = 15;
		pPlayer->iAttackMAX = 20;
		pPlayer->iArmorMin = 5;
		pPlayer->iArmorMax = 10;
		pPlayer->iHPMax = 300;
		pPlayer->iHP = 300;
		pPlayer->iMP = 300;
		pPlayer->iMPMax = 300;
		break;
	}
}
_tagMonster CreateMonster(const char *pName, int iAttackMin, int iAttackMax, int iArmorMin, int iArmorMax, int iHP, int iHPMax, int iMP, int iMPMax,
	int iLevel, int iExp, int iGoldMin, int iGoldMax) 
{
	_tagMonster tMonster = {};

	strcpy_s(tMonster.strName, pName);
	tMonster.iAttackMin = iAttackMin;
	tMonster.iAttackMAX = iAttackMax;
	tMonster.iArmorMin = iArmorMin;
	tMonster.iArmorMax = iArmorMax;
	tMonster.iHP = iHP;
	tMonster.iHPMax = iHPMax;
	tMonster.iMP = iMP;
	tMonster.iMPMax = iMPMax;
	tMonster.iLevel = iLevel;
	tMonster.iExp = iExp;
	tMonster.iGoldMin = iGoldMin;
	tMonster.iGoldMax = iGoldMax;

	return tMonster;
}
void SetMonster(_tagMonster *pMonsterArr) {
	pMonsterArr[0] = CreateMonster("���", 20, 30, 2, 3, 100, 100, 10, 10, 1, 1000, 500, 1500);
	pMonsterArr[1] = CreateMonster("Ʈ��", 80, 130, 60, 90, 2000, 2000, 100, 100, 5, 7000, 6000, 8000);
	pMonsterArr[2] = CreateMonster("�巡��", 250, 500, 200, 400, 30000, 30000, 20000, 20000, 10, 30000, 20000, 50000);
}

int main() {

	srand((unsigned int)time(0));

	_tagPlayer tPlayer = {};

	_tagMonster tMonsterArr[MT_BACK - 1] = {};

	SetMonster(tMonsterArr);

	SetPlayer(&tPlayer);

	bool bLoop = true;
	while (bLoop) {
		switch (OutputMainMenu())
		{
		case MM_MAP:
			RunMap(&tPlayer, tMonsterArr);
			break;
		case MM_STORE:
			break;
		case MM_INVENTORY:
			break;
		case MM_EXIT:
			bLoop = false;
			break;
		}
	}
	return 0;
}