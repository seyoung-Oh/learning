#include <iostream>
#include <time.h>
using namespace std;
enum GAME_MODE
{
	GM_NONE,
	GM_NEW,
	GM_LOAD,
	GM_END
};
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
enum STORE_MENU {
	SM_NONE,
	SM_WEAPON,
	SM_ARMOR,
	SM_BACK
};
#define NAME_SIZE 32
#define ITEM_DESC_LENGTH 512
#define INVENTORY_MAX 20
#define STORE_WEAPON_MAX 3
#define STORE_ARMOR_MAX 3
#define LEVEL_MAX 10

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
struct  _tagLevelUpStatus
{
	int iAttackMin;
	int iAttackMax;
	int iArmorMin;
	int iArmorMax;
	int iHPMin;
	int iHPMax;
	int iMPMin;
	int iMPMax;
};
const int g_iLevelUpExp[LEVEL_MAX] = { 4000, 10000, 20000, 35000, 50000, 70000, 100000, 150000, 200000, 400000 };
_tagLevelUpStatus g_tLvUpTable[JOB_END - 1] = {};
int Inputint() {
	int iInput;
	cin >> iInput;

	if (cin.fail()) {
		cin.clear();
		cin.ignore(1024, '\n');
		return INT_MAX;//int max return시 입력 잘못됨
	}
	return iInput;
}
int OutputMainMenu() {//메인 메뉴를 화면에 보여주고 입력받은 메뉴를 반환 입력 오류시 MM_NONE반환
	system("cls");

	cout << "*************************************로비*************************************" << endl;
	cout << "1.맵" << endl;
	cout << "2.상점" << endl;
	cout << "3.가방" << endl;
	cout << "4.종료" << endl;
	cout << "메뉴를 선택하세요 : ";

	int iMenu = Inputint();

	if (iMenu == INT_MAX || iMenu <= MM_NONE || iMenu > MM_EXIT)
		return MM_NONE;

	return iMenu;
}
void OutputBattleTag(int iMenu) {
	system("cls");
	switch (iMenu) {
	case MT_EASY:
		cout << "*************************************쉬움*************************************" << endl;
		break;
	case MT_NORMAL:
		cout << "*************************************보통*************************************" << endl;
		break;
	case MT_HARD:
		cout << "*************************************어려움*************************************" << endl;
		break;
	}
}
void OutputPlayer(_tagPlayer* pPlayer) {

	cout << "=======================Player=======================" << endl;
	cout << "이름 : " << pPlayer->strName << "\t직업 : " << pPlayer->strJobName << endl;
	cout << "레벨 : " << pPlayer->iLevel << "\t경험치 : " << pPlayer->iExp << " / " << g_iLevelUpExp[pPlayer->iLevel - 1] << endl;
	if (pPlayer->bEquip[EQ_WEAPON] == true)
		cout << "공격력 : " << pPlayer->iAttackMin << " + " << pPlayer->tEquip[EQ_WEAPON].iMin << " - " << pPlayer->iAttackMAX << " + " << pPlayer->tEquip[EQ_WEAPON].iMax;
	else
		cout << "공격력 : " << pPlayer->iAttackMin << " - " << pPlayer->iAttackMAX;

	if (pPlayer->bEquip[EQ_ARMOR] == true)
		cout << "\t방여력 : " << pPlayer->iArmorMin << " + " << pPlayer->tEquip[EQ_ARMOR].iMin << " - " << pPlayer->iArmorMax << " + " << pPlayer->tEquip[EQ_ARMOR].iMax << endl;
	else
		cout << "\t방여력 : " << pPlayer->iArmorMin << " - " << pPlayer->iArmorMax << endl;
	
	cout << "체력 : " << pPlayer->iHP << " / " << pPlayer->iHPMax << "\t마나 : " << pPlayer->iMP << " / " << pPlayer->iMPMax << endl;
	cout << "보유 골드 : " << pPlayer->tInventory.iGold << " Gold" << endl;
}
void OutputMonster(_tagMonster* pMonster) {
	cout << "=======================Moster=======================" << endl;
	cout << "이름 : " << pMonster->strName << "\t레벨 : " << pMonster->iLevel << endl;
	cout << "공격력 : " << pMonster->iAttackMin << " - " << pMonster->iAttackMAX << "\t방어력 : " << pMonster->iArmorMin << " - " << pMonster->iArmorMax << endl;
	cout << "체력 : " << pMonster->iHP << " / " << pMonster->iHPMax << "\t마나 : " << pMonster->iMP << " / " << pMonster->iMPMax << endl;
	cout << "획득경험치 : " << pMonster->iExp << "\t획득골드 : " << pMonster->iGoldMin << " - " << pMonster->iGoldMax << endl << endl;
}
int OutputBattleMenu() {
	cout << "1. 공격" << endl;
	cout << "2. 도망가기" << endl;

	cout << "메뉴를 선택하세요 : ";
	int iMenu = Inputint();

	if (iMenu == INT_MAX || iMenu <= BATTLE_NONE || iMenu > BATTLE_BACK)
		return BATTLE_NONE;
	return iMenu;
}
void Battle(_tagPlayer* pPlayer, _tagMonster* pMonster) {
	int iAttackMin = pPlayer->iAttackMin;
	int iAttackMax = pPlayer->iAttackMAX;

	//무기를 장착하고 있을 경우 무기와 Min Max를 더해준다.
	if (pPlayer->bEquip[EQ_WEAPON])
	{
		iAttackMin += pPlayer->tEquip[EQ_WEAPON].iMin;
		iAttackMax += pPlayer->tEquip[EQ_WEAPON].iMax;
	}


	int iAttack = rand() % (iAttackMax - iAttackMin + 1) + iAttackMin;
	int iArmor = rand() % (pMonster->iArmorMax - pMonster->iArmorMin + 1) + pMonster->iArmorMin;

	int iDamage = iAttack - iArmor;
	//삼항연산자 : 조건식 ? true일때 값 : false일떄 값:
	iDamage = iDamage < 1 ? 1 : iDamage; //if(iDamage < 1) iDamage = 1;과 같음

	pMonster->iHP -= iDamage;
	cout << pPlayer->strName << " 가 " << pMonster->strName << " 에게 " << iDamage << " 피해를 입혔습니다." << endl;
	//몬스터가 죽었을 경우 처리
	if (pMonster->iHP <= 0)
	{
		cout << pMonster->strName << "몬스터가 사망 " << endl;
		pPlayer->iExp += pMonster->iExp;
		int iGold = (rand() % (pMonster->iGoldMax - pMonster->iGoldMin + 1) + pMonster->iGoldMin);
		pPlayer->tInventory.iGold += iGold;

		cout << pMonster->iExp << "경험치를 획득하였습니다. " << endl;
		cout << iGold << " Gold를 획득하였습니다. " << endl;

		pMonster->iHP = pMonster->iHPMax;
		pMonster->iMP = pMonster->iMPMax;

		//레벨업을 했는지 체크
		if (pPlayer->iExp >= g_iLevelUpExp[pPlayer->iLevel - 1]) {
			//플레이어 경험치를 레벨업에 필요한 경험치만큼 차감한다,
			pPlayer->iExp -= g_iLevelUpExp[pPlayer->iLevel - 1];

			++pPlayer->iLevel;

			cout << pPlayer->iLevel << "레벨업 하였습니다." << endl;

			//능력치를 상승시킨다
			//직업인덱스를 구한다

			int iJobIndex = pPlayer->eJob - 1;
			int iAttackUp = rand() % (g_tLvUpTable[iJobIndex].iAttackMax - g_tLvUpTable[iJobIndex].iAttackMin + 1) + g_tLvUpTable[iJobIndex].iAttackMin;
			int iArmorUp = rand() % (g_tLvUpTable[iJobIndex].iArmorMax - g_tLvUpTable[iJobIndex].iArmorMin + 1) + g_tLvUpTable[iJobIndex].iArmorMin;
			int iHPUp = rand() % (g_tLvUpTable[iJobIndex].iHPMax - g_tLvUpTable[iJobIndex].iHPMin + 1) + g_tLvUpTable[iJobIndex].iHPMin;
			int iMPUp = rand() % (g_tLvUpTable[iJobIndex].iMPMax - g_tLvUpTable[iJobIndex].iMPMin + 1) + g_tLvUpTable[iJobIndex].iMPMin;

			pPlayer->iAttackMin += g_tLvUpTable[iJobIndex].iAttackMin;
			pPlayer->iAttackMAX += g_tLvUpTable[iJobIndex].iAttackMax;
		
			pPlayer->iArmorMin += g_tLvUpTable[iJobIndex].iAttackMin;
			pPlayer->iArmorMax += g_tLvUpTable[iJobIndex].iAttackMax;
			
			pPlayer->iHPMax += iHPUp;
			pPlayer->iMPMax += iMPUp;
		
			pPlayer->iHP = pPlayer->iHPMax;
			pPlayer->iMP = pPlayer->iMPMax;
		}
		return;
	}
	iAttack = rand() % (pMonster->iAttackMAX - pMonster->iAttackMin + 1) + pMonster->iAttackMin;

	int iArmorMin = pPlayer->iArmorMin;
	int iArmorMax = pPlayer->iArmorMax;

	if (pPlayer->bEquip[EQ_ARMOR])
	{
		iArmorMin += pPlayer->tEquip[EQ_ARMOR].iMin;
		iArmorMax += pPlayer->tEquip[EQ_ARMOR].iMax;
	}

	iArmor = rand() % (iArmorMax - iArmorMin + 1) + iArmorMin;

	iDamage = iAttack - iArmor;
	//삼항연산자 : 조건식 ? true일때 값 : false일떄 값:
	iDamage = iDamage < 1 ? 1 : iDamage;

	//플레이어의 HP감소
	pPlayer->iHP -= iDamage;

	cout << pMonster->strName << " 가 " << pPlayer->strName << " 에게 " << iDamage << " 피해를 입혔습니다." << endl;

	//플레이어가 죽었을 경우
	if (pPlayer->iHP <= 0)
	{
		cout << pPlayer->strName << "플레이어가 사망 " << endl;

		int iExp = pPlayer->iExp *0.1f;
		int iGold = pPlayer->tInventory.iGold * 0.1f;

		pPlayer->iExp -= iExp;
		pPlayer->tInventory.iGold -= iGold;

		cout << iExp << " 경험치를 잃었습니다." << endl;
		cout << iGold << " Gold를 잃었습니다." << endl;

		//플레이어의 HP MP회복
		pPlayer->iHP = pPlayer->iHPMax;
		pPlayer->iMP = pPlayer->iMPMax;
	}
}
void RunBattle(_tagPlayer* pPlayer, _tagMonster* pMonsterArr, int iMenu) {
	_tagMonster tMonster = pMonsterArr[iMenu - 1];
	while (true)
	{
		system("cls");
		OutputBattleTag(iMenu);

		//플레이어 출력
		OutputPlayer(pPlayer);
		//몬스터 출력
		OutputMonster(&tMonster);

		switch (OutputBattleMenu()) {
		case BATTLE_ATTACK:
			Battle(pPlayer, &tMonster);
			system("pause");
			break;
		case BATTLE_BACK:
			return;
		}
	}
}
int OutputMapMenu() {
	system("cls");
	cout << "*************************************맵*************************************" << endl;
	cout << "1. 쉬움" << endl;
	cout << "2. 보통" << endl;
	cout << "3. 어려움" << endl;
	cout << "4. 뒤로가기" << endl;
	cout << "맵을 선택하세요 : ";
	int iMenu = Inputint();
	if (iMenu == INT_MAX || iMenu <= MT_NONE || iMenu > MT_BACK)
		return MT_NONE;

	return iMenu;
}
void RunMap(_tagPlayer* pPlayer, _tagMonster* pMonsterArr) {//맵에 관련된 동작 처리
	bool bLoop = true;
	while (bLoop) {
		int iMenu = OutputMapMenu();

		if (MT_BACK == iMenu)
			return;

		//전투 시작
		RunBattle(pPlayer, pMonsterArr, iMenu);

	}
}

int SelectJob() {
	int iJob = JOB_NONE;
	while (iJob == JOB_NONE) 
	{
		system("cls");
		cout << "1. 기사" << endl;
		cout << "2. 궁수" << endl;
		cout << "3. 마법사" << endl;
		cout << "직업을 선택하세요 : " << endl;
		iJob = Inputint();

		if (iJob <= JOB_NONE || iJob >= JOB_END)
			iJob = JOB_NONE;
	}
	return iJob;
}

void SetPlayer(_tagPlayer* pPlayer) 
{
	system("cls");
	cin.clear();
	cin.ignore(1024, '\n');

	cout << "이름 : ";
	cin.getline(pPlayer->strName, NAME_SIZE - 1);//마지막에 null 넣을 공간 뺌

	pPlayer->eJob = (JOB)SelectJob();
	pPlayer->iLevel = 1;
	pPlayer->iExp = 0;
	pPlayer->tInventory.iGold = 10000;

	switch (pPlayer->eJob) {
	case JOB_KNIGHT:
		strcpy_s(pPlayer->strJobName, "기사");
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
		strcpy_s(pPlayer->strJobName, "궁수");
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
		strcpy_s(pPlayer->strJobName, "마법사");
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
bool LoadPlayer(_tagPlayer* pPlayer)
{
	FILE* pFile = NULL;
	fopen_s(&pFile, "Player.ply", "rb");

	if (pFile)
	{
		fread(pPlayer->strName, 1, NAME_SIZE, pFile);
		fread(&pPlayer->eJob, sizeof(JOB), 1, pFile);
		fread(pPlayer->strJobName, 1, NAME_SIZE, pFile);

		fread(&pPlayer->iAttackMin, 4, 1, pFile);
		fread(&pPlayer->iAttackMAX, 4, 1, pFile);

		fread(&pPlayer->iArmorMin, 4, 1, pFile);
		fread(&pPlayer->iArmorMax, 4, 1, pFile);

		fread(&pPlayer->iHP, 4, 1, pFile);
		fread(&pPlayer->iHPMax, 4, 1, pFile);

		fread(&pPlayer->iMP, sizeof(int), 1, pFile);
		fread(&pPlayer->iMPMax, 4, 1, pFile);

		fread(&pPlayer->iExp, 4, 1, pFile);
		fread(&pPlayer->iLevel, 4, 1, pFile);

		fread(&pPlayer->bEquip[EQ_WEAPON], 1, 1, pFile);

		if (pPlayer->bEquip[EQ_WEAPON])
			fread(&pPlayer->tEquip[EQ_WEAPON], sizeof(_tagITem), 1, pFile);

		fread(&pPlayer->bEquip[EQ_ARMOR], 1, 1, pFile);

		if (pPlayer->bEquip[EQ_ARMOR])
			fread(&pPlayer->tEquip[EQ_ARMOR], sizeof(_tagITem), 1, pFile);

		fread(&pPlayer->tInventory.iGold, 4, 1, pFile);//골드 읽어오기
		fread(&pPlayer->tInventory.iItemCount, 4, 1, pFile);//인벤토리 아이템 수 읽어오기

		//읽어온 아이템 수만큼 인벤토리에 아이템 정보를 읽어온다
		fread(pPlayer->tInventory.tItem, sizeof(_tagITem), pPlayer->tInventory.iItemCount, pFile);

		fclose(pFile);
		return true;
	}
	return false;

}
//bool을 이용해서 파일이 제대로 만들어졌는지 판단한다.
bool SavePlayer(_tagPlayer* pPlayer)
{
	FILE* pFile = NULL;
	fopen_s(&pFile, "Player.ply", "wb");
	if (pFile)
	{
		fwrite(pPlayer->strName, 1, NAME_SIZE, pFile);
		fwrite(&pPlayer->eJob, sizeof(JOB), 1, pFile);
		fwrite(pPlayer->strJobName, 1, NAME_SIZE, pFile);
		
		fwrite(&pPlayer->iAttackMin, 4, 1, pFile);
		fwrite(&pPlayer->iAttackMAX, 4, 1, pFile);
		
		fwrite(&pPlayer->iArmorMin, 4, 1, pFile);
		fwrite(&pPlayer->iArmorMax, 4, 1, pFile);
	
		fwrite(&pPlayer->iHP, 4, 1, pFile);
		fwrite(&pPlayer->iHPMax, 4, 1, pFile);
		
		fwrite(&pPlayer->iMP, sizeof(int), 1, pFile);
		fwrite(&pPlayer->iMPMax, 4, 1, pFile);
	
		fwrite(&pPlayer->iExp, 4, 1, pFile);
		fwrite(&pPlayer->iLevel, 4, 1, pFile);
	
		fwrite(&pPlayer->bEquip[EQ_WEAPON], 1, 1, pFile);

		if (pPlayer->bEquip[EQ_WEAPON])
			fwrite(&pPlayer->tEquip[EQ_WEAPON], sizeof(_tagITem), 1, pFile);

		fwrite(&pPlayer->bEquip[EQ_ARMOR], 1, 1, pFile);

		if (pPlayer->bEquip[EQ_ARMOR])
			fwrite(&pPlayer->tEquip[EQ_ARMOR], sizeof(_tagITem), 1, pFile);

		fwrite(&pPlayer->tInventory.iGold, 4, 1, pFile);//골드 저장하기
		fwrite(&pPlayer->tInventory.iItemCount, 4, 1, pFile);//인벤토리 아이템 수 저장하기

		// 아이템 수만큼 인벤토리에 아이템 정보를 저장하기
		fwrite(pPlayer->tInventory.tItem, sizeof(_tagITem), pPlayer->tInventory.iItemCount, pFile);
		fclose(pFile);
		return true;
	}
	return false;
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
	pMonsterArr[0] = CreateMonster("고블린", 20, 30, 2, 3, 100, 100, 10, 10, 1, 1000, 500, 1500);
	pMonsterArr[1] = CreateMonster("트롤", 80, 130, 60, 90, 2000, 2000, 100, 100, 5, 7000, 6000, 8000);
	pMonsterArr[2] = CreateMonster("드래곤", 250, 500, 200, 400, 30000, 30000, 20000, 20000, 10, 30000, 20000, 50000);
}
_tagLevelUpStatus CreateLvUpStaus(int iAttackMin, int iAttackMax, int iArmorMin, int iArmorMax, int iHPMin, int iHPMax, int iMPMin, int iMPMax)
{
	_tagLevelUpStatus	tStatus = {};

	tStatus.iAttackMin = iAttackMin;
	tStatus.iAttackMax = iAttackMax;
	tStatus.iArmorMin = iArmorMin;
	tStatus.iArmorMax = iArmorMax;
	tStatus.iHPMin = iHPMin;
	tStatus.iHPMax = iHPMax;
	tStatus.iMPMin = iMPMin;
	tStatus.iMPMax = iMPMax;

	return tStatus;
}
int OutputStoreMenu() {
	system("cls");
	cout << "*************************************상점*************************************" << endl;
	cout << "1. 무기상점 " << endl;
	cout << "2. 방어구상점" << endl;
	cout << "3. 뒤로가기" << endl;
	cout << "상점을 선택하세요" << endl;

	int iMenu = Inputint();
	if (iMenu <SM_NONE || iMenu > SM_BACK)
		return SM_NONE;
	return iMenu;

}
int OutputStoreItemList(_tagInventory* pInventory, _tagITem* pStore, int iItemCount) {
	for (int i = 0;i < iItemCount;++i) {
		cout << i + 1 << ". 이름 : " << pStore[i].strName << "\t종류 : " << pStore[i].strTypeName << endl;
		cout << "공격력 : " << pStore[i].iMin << " - " << pStore[i].iMax << endl;
		cout << "판매가격 : " << pStore[i].iPrice << "\t구매가격 : " << pStore[i].iSell << endl;
		cout << "설명 : " << pStore[i].strDesc << endl << endl;

	}
	cout << iItemCount + 1 << ". 뒤로가기" << endl;
	cout << "보유금액 : " << pInventory->iGold << " Gold" << endl;
	cout << "남은공간 : " << INVENTORY_MAX - pInventory->iItemCount << endl;
	cout << "구입할 아이템을 선택하세요 : ";

	int iMenu = Inputint();

	if (iMenu <1 || iMenu > iItemCount + 1)
		return INT_MAX;

	return iMenu;
}
void BuyItem(_tagInventory* pInventory, _tagITem* pStore, int iItemCount, int tStoreType) 
{
	while (true)
	{
		system("cls");
		switch (tStoreType) {
		case SM_WEAPON:
			cout << "*************************************무기상점*************************************" << endl;
			break;
		case SM_ARMOR:
			cout << "*************************************방어구상점*************************************" << endl;
			break;
		}
		int iInput = OutputStoreItemList(pInventory, pStore, iItemCount);

		if (iInput == INT_MAX) {
			cout << "잘못 입력하셨습니다. " << endl;
			system("pause");
			continue;
		}
		else if (iInput == iItemCount + 1)
			break;

		int iIndex = iInput - 1;

		// 인벤토리 꽉 찼는지 검사
		if (pInventory->iItemCount == INVENTORY_MAX) {
			cout << "가방이 꽉 찼습니다. " << endl;
			system("pause");
			continue;
		}

		else if (pInventory->iGold < pStore[iIndex].iPrice)
		{
			cout << "보유금액이 부족합니다. " << endl;
			system("pause");
			continue;
		}
		//처음에는 iitemcount에 하나도 추가되어 있지 않기 때문에 0으로 초기화됨
		pInventory->tItem[pInventory->iItemCount] = pStore[iIndex];

		++pInventory->iItemCount;

		//골드를 차감한다.
		pInventory->iGold -= pStore[iIndex].iPrice;

		cout << pStore[iIndex].strName << "아이템을 구매하였습니다." << endl;
		system("pause");
	}
}
void RunStore(_tagInventory* pInventory, _tagITem* pWeapon, _tagITem* pArmor)
{
	while (true)
	{
		switch (OutputStoreMenu()) {
		case SM_WEAPON:
			BuyItem(pInventory, pWeapon, STORE_WEAPON_MAX, SM_WEAPON);
			break;
		case SM_ARMOR:
			BuyItem(pInventory, pArmor, STORE_ARMOR_MAX, SM_ARMOR);
			break;
		case SM_BACK:
			return;
		}
	}
}
_tagITem CreateItem(const char* pName, ITEM_TYPE eType, int iMin, int iMax, int iPrice, int iSell, const char* pDesc) 
{
	_tagITem tItem = {};
	strcpy_s(tItem.strName, pName);
	strcpy_s(tItem.strDesc, pDesc);
	tItem.eType = eType;
	switch (eType)
	{
	case IT_WEAPON:
		strcpy_s(tItem.strTypeName, "무기");
		break;
	case IT_ARMOR:
		strcpy_s(tItem.strTypeName, "방어구");
		break;
	}
	tItem.iMin = iMin;
	tItem.iMax = iMax;
	tItem.iPrice = iPrice;
	tItem.iSell = iSell;

	return tItem;
}
int OutputInventory(_tagPlayer* pPlayer) {
	system("cls");
	cout << "*************************************가방*************************************" << endl;
	OutputPlayer(pPlayer);

	for (int i = 0; i < pPlayer->tInventory.iItemCount; ++i) {
		cout << i + 1 << ". 이름 : " << pPlayer->tInventory.tItem[i].strName << "\t종류 : " << pPlayer->tInventory.tItem[i].strTypeName << endl;
		cout << "공격력 : " << pPlayer->tInventory.tItem[i].iMin << " - " << pPlayer->tInventory.tItem[i].iMax << endl;
		cout << "판매가격 : " << pPlayer->tInventory.tItem[i].iPrice << "\t구매가격 : " << pPlayer->tInventory.tItem[i].iSell << endl;
		cout << "설명 : " << pPlayer->tInventory.tItem[i].strDesc << endl << endl;
	}

	cout << pPlayer->tInventory.iItemCount + 1 << ". 뒤로가기" << endl;
	cout << "창착할 아이템을 선택하세요 : ";

	int iMenu = Inputint();

	if (iMenu <1 || iMenu > pPlayer->tInventory.iItemCount + 1)
		return INT_MAX;

	return iMenu;
}

EQUIP ComputeEquipType(ITEM_TYPE eType)
{
	EQUIP eq;
	switch (eType) {
	case IT_WEAPON:
		eq = EQ_WEAPON;
		break;
	case IT_ARMOR:
		eq = EQ_ARMOR;
		break;
	}

	return eq;
}

void RunInventory(_tagPlayer* pPlayer) {
	while (true) {
		int iInput = OutputInventory(pPlayer);
		if (iInput == INT_MAX)
			continue;
		else if (iInput == pPlayer->tInventory.iItemCount + 1)
			break;

		int idx = iInput - 1;//아이템 인덱스 구하기

		EQUIP eq = ComputeEquipType(pPlayer->tInventory.tItem[idx].eType);
		
		//아이템이 장착되어 있을 경우 장착되어있는 아이템과 장착할 아이템을 교체해주어야 한다 swap알고리즘 활용
		if (pPlayer->bEquip[eq] == true) {
			_tagITem tSwap = pPlayer->tEquip[eq];
			pPlayer->tEquip[eq] = pPlayer->tInventory.tItem[idx];
			pPlayer->tInventory.tItem[idx] = tSwap;
		}

		//장착되어있지 않을 경우 인벤토리 아이템을 장착장으로 옮기고 인벤토리는 1칸 비워지게 됨
		else {
			pPlayer->tEquip[eq] = pPlayer->tInventory.tItem[idx];

			for (int i = idx;i < pPlayer->tInventory.iItemCount - 1;++i) {
				pPlayer->tInventory.tItem[i] = pPlayer->tInventory.tItem[i + 1];
			}
			--pPlayer->tInventory.iItemCount;

			//장착을 했기 때문에 true로 만들어줌

			pPlayer->bEquip[eq] = true;

		}
		cout << pPlayer->tEquip[eq].strName << "아이템을 장착했습니다." << endl;
		system("pause");
	}
}
int main() {

	srand((unsigned int)time(0));

	_tagPlayer tPlayer = {};
	
	int iGameMode = 0;
	while (iGameMode<=GM_NONE||iGameMode>GM_END)
	{
		system("cls");
		cout << "1.새로하기" << endl;
		cout << "2.이어하기" << endl;
		cout << "3.종료" << endl;
		cout << "게임 모드를 선택하세요 : ";
		iGameMode = Inputint();
	}

	if (iGameMode == GM_END)
		return 0;

	switch (iGameMode)
	{
	case GM_NEW:
		SetPlayer(&tPlayer);
		break;
	case GM_LOAD:
		if (!LoadPlayer(&tPlayer))
		{
			cout << "플레이어 파일 오류! " << endl;

		}
		break;
	}

	_tagMonster tMonsterArr[MT_BACK - 1] = {};

	SetMonster(tMonsterArr);
	g_tLvUpTable[JOB_KNIGHT - 1] = CreateLvUpStaus(4, 10, 8, 16, 50, 100, 10, 20);

	g_tLvUpTable[JOB_ARCHER - 1] = CreateLvUpStaus(10, 15, 5, 10, 30, 60, 30, 50);

	g_tLvUpTable[JOB_WIZARD - 1] = CreateLvUpStaus(15, 20, 3, 7, 20, 40, 50, 100);

	_tagITem tStoreWeapon[STORE_WEAPON_MAX] = {};
	_tagITem tStoreArmor[STORE_ARMOR_MAX] = {};

	tStoreWeapon[0] = CreateItem("목검", IT_WEAPON, 5, 10, 1000, 500, "나무로 만든 칼");
	tStoreWeapon[1] = CreateItem("장궁", IT_WEAPON, 20, 40, 7000, 3500, "짱짱한 활");
	tStoreWeapon[2] = CreateItem("지팡이", IT_WEAPON, 90, 150, 30000, 15000, "나무로 만든 지팡이");

	tStoreArmor[0] = CreateItem("천갑옷", IT_ARMOR, 2, 5, 1000, 500, "천으로 만든 허접한 갑옷");
	tStoreArmor[1] = CreateItem("가죽갑옷", IT_ARMOR, 10, 20, 7000, 3500, "가죽으로 만든 질긴 갑옷");
	tStoreArmor[2] = CreateItem("풀플레이트 아머", IT_ARMOR, 70, 90, 30000, 15000, "강철로 만든 판금 갑옷");

	bool bLoop = true;
	while (bLoop) {
		switch (OutputMainMenu())
		{
		case MM_MAP:
			RunMap(&tPlayer, tMonsterArr);
			break;
		case MM_STORE:
			RunStore(&tPlayer.tInventory, tStoreWeapon, tStoreArmor);
			break;
		case MM_INVENTORY:
			RunInventory(&tPlayer);
			break;
		case MM_EXIT:
			bLoop = false;
			break;
		}
	}
	SavePlayer(&tPlayer);
	return 0;
}