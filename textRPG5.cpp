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
enum EQUIP {
	EQ_WEAPON,
	EQ_ARMOR,
	EQ_MAX
};
#define NAME_SIZE 32
#define ITEM_DESC_LENGTH 512
#define INVENTORY_MAX 20
#define STORE_WEAPON_MAX 3
#define STORE_ARMOR_MAX 3
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

enum JOB {
	JOB_NONE,
	JOB_KNIGHT,
	JOB_ARCHER,
	JOB_WIZARD,
	JOB_END
};

enum BATTLE {
	BATTLE_NONE,
	BATTLE_ATTACK,
	BATTLE_BACK
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
int main() {
	srand((unsigned int)time(0));
	_tagPlayer tPlayer = {};
	cout << "이름 : ";
	cin.getline(tPlayer.strName, NAME_SIZE - 1);//마지막에 null 넣을 공간 뺌

	int iJob = JOB_NONE;

	while (iJob == JOB_NONE) {
		system("cls");
		cout << "1. 기사" << endl;
		cout << "2. 궁수" << endl;
		cout << "3. 마법사" << endl;
		cout << "직업을 선택하세요 : " << endl;
		cin >> iJob;

		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}

		else if (iJob <= JOB_NONE || iJob >= JOB_END)
			iJob = JOB_NONE;
	}

	tPlayer.iLevel = 1;
	tPlayer.iExp = 0;
	tPlayer.eJob = (JOB)iJob;
	tPlayer.tInventory.iGold = 10000;

	switch (tPlayer.eJob) {
	case JOB_KNIGHT:
		strcpy_s(tPlayer.strJobName, "기사");
		tPlayer.iAttackMin = 5;
		tPlayer.iAttackMAX = 10;
		tPlayer.iArmorMin = 15;
		tPlayer.iArmorMax = 20;
		tPlayer.iHPMax = 500;
		tPlayer.iHP = 500;
		tPlayer.iMP = 500;
		tPlayer.iMPMax = 100;
		break;
	case JOB_ARCHER:
		strcpy_s(tPlayer.strJobName, "궁수");
		tPlayer.iAttackMin = 10;
		tPlayer.iAttackMAX = 15;
		tPlayer.iArmorMin = 10;
		tPlayer.iArmorMax = 20;
		tPlayer.iHPMax = 400;
		tPlayer.iHP = 400;
		tPlayer.iMP = 200;
		tPlayer.iMPMax = 200;
		break;
	case JOB_WIZARD:
		strcpy_s(tPlayer.strJobName, "마법사");
		tPlayer.iAttackMin = 15;
		tPlayer.iAttackMAX = 20;
		tPlayer.iArmorMin = 5;
		tPlayer.iArmorMax = 10;
		tPlayer.iHPMax = 300;
		tPlayer.iHP = 300;
		tPlayer.iMP = 300;
		tPlayer.iMPMax = 300;
		break;
	}

	_tagMonster tMonsterArr[MT_BACK - 1] = {};

	strcpy_s(tMonsterArr[0].strName, "고블린");
	tMonsterArr[0].iAttackMin = 20;
	tMonsterArr[0].iAttackMAX = 30;
	tMonsterArr[0].iArmorMin = 2;
	tMonsterArr[0].iArmorMax = 3;
	tMonsterArr[0].iHP = 100;
	tMonsterArr[0].iHPMax = 100;
	tMonsterArr[0].iMP = 10;
	tMonsterArr[0].iMPMax = 10;
	tMonsterArr[0].iLevel = 1;
	tMonsterArr[0].iExp = 1000;
	tMonsterArr[0].iGoldMin = 500;
	tMonsterArr[0].iGoldMax = 1500;

	strcpy_s(tMonsterArr[1].strName, "트롤");
	tMonsterArr[1].iAttackMin = 80;
	tMonsterArr[1].iAttackMAX = 130;
	tMonsterArr[1].iArmorMin = 60;
	tMonsterArr[1].iArmorMax = 90;
	tMonsterArr[1].iHP = 2000;
	tMonsterArr[1].iHPMax = 2000;
	tMonsterArr[1].iMP = 100;
	tMonsterArr[1].iMPMax = 100;
	tMonsterArr[1].iLevel = 5;
	tMonsterArr[1].iExp = 7000;
	tMonsterArr[1].iGoldMin = 6000;
	tMonsterArr[1].iGoldMax = 8000;

	strcpy_s(tMonsterArr[2].strName, "드래곤");
	tMonsterArr[2].iAttackMin = 250;
	tMonsterArr[2].iAttackMAX = 500;
	tMonsterArr[2].iArmorMin = 200;
	tMonsterArr[2].iArmorMax = 400;
	tMonsterArr[2].iHP = 30000;
	tMonsterArr[2].iHPMax = 30000;
	tMonsterArr[2].iMP = 20000;
	tMonsterArr[2].iMPMax = 20000;
	tMonsterArr[2].iLevel = 10;
	tMonsterArr[2].iExp = 30000;
	tMonsterArr[2].iGoldMin = 20000;
	tMonsterArr[2].iGoldMax = 50000;

	//상점에서 판매할 아이템 목록을 생성
	_tagITem tStoreWeapon[STORE_WEAPON_MAX] = {};

	strcpy_s(tStoreWeapon[0].strName, "목검");
	strcpy_s(tStoreWeapon[0].strTypeName, "무기");
	tStoreWeapon[0].eType = IT_WEAPON;
	tStoreWeapon[0].iMin = 5;
	tStoreWeapon[0].iMax = 10;
	tStoreWeapon[0].iPrice = 1000;
	tStoreWeapon[0].iSell = 500;
	strcpy_s(tStoreWeapon[0].strDesc, "나무로 만든 칼");

	strcpy_s(tStoreWeapon[1].strName, "장궁");
	strcpy_s(tStoreWeapon[1].strTypeName, "무기");
	tStoreWeapon[1].eType = IT_WEAPON;
	tStoreWeapon[1].iMin = 20;
	tStoreWeapon[1].iMax = 40;
	tStoreWeapon[1].iPrice = 7000;
	tStoreWeapon[1].iSell = 3500;
	strcpy_s(tStoreWeapon[1].strDesc, "짱짱한 활");

	strcpy_s(tStoreWeapon[2].strName, "지팡이");
	strcpy_s(tStoreWeapon[2].strTypeName, "무기");
	tStoreWeapon[2].eType = IT_WEAPON;
	tStoreWeapon[2].iMin = 90;
	tStoreWeapon[2].iMax = 150;
	tStoreWeapon[2].iPrice = 30000;
	tStoreWeapon[2].iSell = 15000;
	strcpy_s(tStoreWeapon[2].strDesc, "나무로 만든 지팡이");

	_tagITem tStoreArmor[STORE_ARMOR_MAX] = {};

	strcpy_s(tStoreArmor[0].strName, "천갑옷");
	strcpy_s(tStoreArmor[0].strTypeName, "방어구");
	tStoreArmor[0].eType = IT_ARMOR;
	tStoreArmor[0].iMin = 2;
	tStoreArmor[0].iMax = 5;
	tStoreArmor[0].iPrice = 1000;
	tStoreArmor[0].iSell = 500;
	strcpy_s(tStoreArmor[0].strDesc, "천으로 만든 허접한 갑옷");

	strcpy_s(tStoreArmor[1].strName, "가죽갑옷");
	strcpy_s(tStoreArmor[1].strTypeName, "방어구");
	tStoreArmor[1].eType = IT_ARMOR;
	tStoreArmor[1].iMin = 10;
	tStoreArmor[1].iMax = 20;
	tStoreArmor[1].iPrice = 7000;
	tStoreArmor[1].iSell = 3500;
	strcpy_s(tStoreArmor[1].strDesc, "가죽으로 만든 질긴 갑옷");

	strcpy_s(tStoreArmor[2].strName, "플레이트아머");
	strcpy_s(tStoreArmor[2].strTypeName, "방어구");
	tStoreArmor[2].eType = IT_ARMOR;
	tStoreArmor[2].iMin = 70;
	tStoreArmor[2].iMax = 90;
	tStoreArmor[2].iPrice = 30000;
	tStoreArmor[2].iSell = 15000;
	strcpy_s(tStoreArmor[2].strDesc, "강철로 만든 판금 갑옷");

	//아이템 정보들을 설정해줌


	while (true) {
		system("cls");

		cout << "*************************************로비*************************************"<<endl;
		cout << "1.맵" << endl;
		cout << "2.상점" << endl;
		cout << "3.가방" << endl;
		cout << "4.종료" << endl;
		cout << "메뉴를 선택하세요 : " ;
		
		int iMenu = 0;

		cin >> iMenu;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}

		if (iMenu == MM_EXIT)
			break;


		switch (iMenu) {
		case MM_MAP:
			while (true)
			{
				system("cls");
				cout << "*************************************맵*************************************" << endl;
				cout << "1. 쉬움" << endl;
				cout << "2. 보통" << endl;
				cout << "3. 어려움" << endl;
				cout << "4. 뒤로가기" << endl;
				cout << "맵을 선택하세요 : ";
				cin >> iMenu;
				if (cin.fail()) {
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}

				if (iMenu == MT_BACK)
					break;
				//선택한 메뉴에서 1을 빼주면 인덱스로 사용

				_tagMonster tMonster = tMonsterArr[iMenu - 1];

				while (true) {
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
					//플레이어 정보를 출력한다.
					cout << "=======================Player=======================" << endl;
					cout << "이름 : " << tPlayer.strName << "\t직업 : " << tPlayer.strJobName << endl;
					cout << "레벨 : " << tPlayer.iLevel << "\t경험치 : " << tPlayer.iExp << endl;
					if (tPlayer.bEquip[EQ_WEAPON] == true)
						cout << "공격력 : " << tPlayer.iAttackMin << " + " << tPlayer.tEquip[EQ_WEAPON].iMin << " - " << tPlayer.iAttackMAX << " + " << tPlayer.tEquip[EQ_WEAPON].iMax;
					else
						cout << "공격력 : " << tPlayer.iAttackMin << " - " << tPlayer.iAttackMAX;

					//방어구 장착시 방어력 추가
					if (tPlayer.bEquip[EQ_ARMOR] == true)
						cout << "\t방여력 : " << tPlayer.iArmorMin << " + " << tPlayer.tEquip[EQ_ARMOR].iMin << " - " << tPlayer.iArmorMax << " + " << tPlayer.tEquip[EQ_ARMOR].iMax << endl;
					else
						cout << "\t방여력 : " << tPlayer.iArmorMin << " - " << tPlayer.iArmorMax << endl;
					//cout << "공격력 : " << tPlayer.iAttackMin << " - " << tPlayer.iAttackMAX << "\t방어력 : " << tPlayer.iArmorMin << " - " << tPlayer.iArmorMax  << endl;
					cout << "체력 : " << tPlayer.iHP << " / " << tPlayer.iHPMax << "\t마나 : " << tPlayer.iMP << " / " << tPlayer.iMPMax << endl;
					cout << "보유 골드 : " << tPlayer.tInventory.iGold << " Gold" << endl;

					//몬스터 정보 출력
					cout << "=======================Moster=======================" << endl;
					cout << "이름 : " << tMonster.strName << " 레벨 : " << tMonster.iLevel << endl;
					cout << "공격력 : " << tMonster.iAttackMin << " - " << tMonster.iAttackMAX << "\t방어력 : " << tMonster.iArmorMin << " - " << tMonster.iArmorMax << endl;
					cout << "체력 : " << tMonster.iHP << " / " << tMonster.iHPMax << "\t마나 : " << tMonster.iMP << " / " << tMonster.iMPMax << endl;
					cout << "획득경험치 : " << tMonster.iExp << "\t획득골드 : " << tMonster.iGoldMin << " - " << tMonster.iGoldMax << endl << endl;

					cout << "1. 공격" << endl;
					cout << "2. 도망가기" << endl;

					cout << "메뉴를 선택하세요 : ";
					cin >> iMenu;

					if (cin.fail()) {
						cin.clear();
						cin.ignore(1024, '\n');
						continue;
					}

					else if (iMenu == BATTLE_BACK)
						break;

					switch (iMenu) {
					case BATTLE_ATTACK:
					{
						//예를 들어 min5 max 15라고 가정할 경우 15-5+1을하면 11이 됨
						//11로 나눈 나머지는 0~10이되고 min값인 5를 더하면 5~15값이 나오게 됨
						int iAttackMin = tPlayer.iAttackMin;
						int iAttackMax = tPlayer.iAttackMAX;

						//무기를 장착하고 있을 경우 무기와 Min Max를 더해준다.
						if (tPlayer.bEquip[EQ_WEAPON])
						{
							iAttackMin += tPlayer.tEquip[EQ_WEAPON].iMin;
							iAttackMax += tPlayer.tEquip[EQ_WEAPON].iMax;
						}


						int iAttack = rand() % (iAttackMax - iAttackMin + 1) + iAttackMin;
						int iArmor = rand() % (tMonster.iArmorMax - tMonster.iArmorMin + 1) + tMonster.iArmorMin;

						int iDamage = iAttack - iArmor;
						//삼항연산자 : 조건식 ? true일때 값 : false일떄 값:
						iDamage = iDamage < 1 ? 1 : iDamage; //if(iDamage < 1) iDamage = 1;과 같음

						//몬스터 hp감소
						tMonster.iHP -= iDamage;
						cout << tPlayer.strName << " 가 " << tMonster.strName << " 에게 " << iDamage << " 피해를 입혔습니다." << endl;
						//몬스터가 죽었을 경우 처리
						if (tMonster.iHP <= 0)
						{
							cout << tMonster.strName << "몬스터가 사망 " << endl;
							tPlayer.iExp += tMonster.iExp;
							int iGold = (rand() % (tMonster.iGoldMax - tMonster.iGoldMin + 1) + tMonster.iGoldMin);
							tPlayer.tInventory.iGold += iGold;

							cout << tMonster.iExp << "경험치를 획득하였습니다. " << endl;
							cout << iGold << " Gold를 획득하였습니다. " << endl;

							tMonster.iHP = tMonster.iHPMax;
							tMonster.iMP = tMonster.iMPMax;
							system("pause");
							break;
						}
						//몬스터가 살아있다면 플레이어를 공격한다;
						iAttack = rand() % (tMonster.iAttackMAX - tMonster.iAttackMin + 1) + tMonster.iAttackMin;

						int iArmorMin = tPlayer.iArmorMin;
						int iArmorMax = tPlayer.iArmorMax;

						if (tPlayer.bEquip[EQ_ARMOR])
						{
							iArmorMin += tPlayer.tEquip[EQ_ARMOR].iMin;
							iArmorMax += tPlayer.tEquip[EQ_ARMOR].iMax;
						}

						iArmor = rand() % (iArmorMax - iArmorMin + 1) + iArmorMin;

						iDamage = iAttack - iArmor;
						//삼항연산자 : 조건식 ? true일때 값 : false일떄 값:
						iDamage = iDamage < 1 ? 1 : iDamage;

						//플레이어의 HP감소
						tPlayer.iHP -= iDamage;

						cout << tMonster.strName << " 가 " << tPlayer.strName << " 에게 " << iDamage << " 피해를 입혔습니다." << endl;

						//플레이어가 죽었을 경우
						if (tPlayer.iHP <= 0)
						{
							cout << tPlayer.strName << "플레이어가 사망 " << endl;

							int iExp = tPlayer.iExp *0.1f;
							int iGold = tPlayer.tInventory.iGold * 0.1f;

							tPlayer.iExp -= iExp;
							tPlayer.tInventory.iGold -= iGold;

							cout << iExp << " 경험치를 잃었습니다." << endl;
							cout << iGold << " Gold를 잃었습니다." << endl;

							//플레이어의 HP MP회복
							tPlayer.iHP = tPlayer.iHPMax;
							tPlayer.iMP = tPlayer.iMPMax;
						}
						system("pause");
					}
						break;

					}
				}

			}
			break;
		case MM_STORE:
			while (true) {
				system("cls");
				cout << "*************************************상점*************************************" << endl;
				cout << "1. 무기상점 " << endl;
				cout << "2. 방어구상점" << endl;
				cout << "3. 뒤로가기" << endl;
				cout << "상점을 선택하세요" << endl;

				cin >> iMenu;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}
				else if (iMenu == SM_BACK)
					break;

				switch (iMenu) {
				case SM_WEAPON:
					while (true) {
						system("cls");

						cout << "*************************************무기상점*************************************" << endl;
						//판매 목록을 보여준다.
						for (int i = 0;i < STORE_WEAPON_MAX;++i) {
							cout << i + 1 << ". 이름 : " << tStoreWeapon[i].strName << "\t종류 : " << tStoreWeapon[i].strTypeName << endl;
							cout << "공격력 : " << tStoreWeapon[i].iMin << " - " << tStoreWeapon[i].iMax << endl;
							cout << "판매가격 : " << tStoreWeapon[i].iPrice << "\t구매가격 : " << tStoreWeapon[i].iSell << endl;
							cout << "설명 : " << tStoreWeapon[i].strDesc << endl << endl;

						}
						cout << STORE_WEAPON_MAX + 1 << ". 뒤로가기" << endl;
						cout << "보유금액 : " << tPlayer.tInventory.iGold << " Gold" << endl;
						cout << "남은공간 : " << INVENTORY_MAX - tPlayer.tInventory.iItemCount << endl;
						cout << "구입할 아이템을 선택하세요 : ";
						cin >> iMenu;
						if (cin.fail())
						{
							cin.clear();
							cin.ignore(1024, '\n');
							continue;
						}
						else if (iMenu == STORE_WEAPON_MAX + 1)
							break;

						else if (iMenu <1 || iMenu>STORE_WEAPON_MAX + 1) {
							cout << "잘못 선택하였습니다." << endl;
							system("pause");
							continue;
						}

						//상점 판매목록 배열의 인덱스 구해주기
						int iWeaponIndex = iMenu - 1;

						// 인벤토리 꽉 찼는지 검사
						if (tPlayer.tInventory.iItemCount == INVENTORY_MAX) {
							cout << "가방이 꽉 찼습니다. " << endl;
							system("pause");
							continue;
						}

						else if (tPlayer.tInventory.iGold < tStoreWeapon[iWeaponIndex].iPrice)
						{
							cout << "보유금액이 부족합니다. " << endl;
							system("pause");
							continue;
						}
						//처음에는 iitemcount에 하나도 추가되어 있지 않기 때문에 0으로 초기화됨
						tPlayer.tInventory.tItem[tPlayer.tInventory.iItemCount] = tStoreWeapon[iWeaponIndex];

						++tPlayer.tInventory.iItemCount;

						//골드를 차감한다.
						tPlayer.tInventory.iGold -= tStoreWeapon[iWeaponIndex].iPrice;

						cout << tStoreWeapon[iWeaponIndex].strName << "아이템을 구매하였습니다." << endl;
						system("pause");
					}
					break;
				case SM_ARMOR:

					while (true) {
						system("cls");

						cout << "*************************************방어구상점*************************************" << endl;
						//판매 목록을 보여준다.
						for (int i = 0;i < STORE_ARMOR_MAX;++i) {
							cout << i + 1 << ". 이름 : " << tStoreArmor[i].strName << "\t종류 : " << tStoreArmor[i].strTypeName << endl;
							cout << "공격력 : " << tStoreArmor[i].iMin << " - " << tStoreArmor[i].iMax << endl;
							cout << "판매가격 : " << tStoreArmor[i].iPrice << "\t구매가격 : " << tStoreArmor[i].iSell << endl;
							cout << "설명 : " << tStoreArmor[i].strDesc << endl << endl;

						}
						cout << STORE_ARMOR_MAX + 1 << ". 뒤로가기" << endl;
						cout << "보유금액 : " << tPlayer.tInventory.iGold << " Gold" << endl;
						cout << "남은공간 : " << INVENTORY_MAX - tPlayer.tInventory.iItemCount << endl;
						cout << "구입할 아이템을 선택하세요 : ";
						cin >> iMenu;
						if (cin.fail())
						{
							cin.clear();
							cin.ignore(1024, '\n');
							continue;
						}
						else if (iMenu == STORE_ARMOR_MAX + 1)
							break;

						else if (iMenu <1 || iMenu>STORE_ARMOR_MAX + 1) {
							cout << "잘못 선택하였습니다." << endl;
							system("pause");
							continue;
						}

						//상점 판매목록 배열의 인덱스 구해주기
						int iArmorIndex = iMenu - 1;

						// 인벤토리 꽉 찼는지 검사
						if (tPlayer.tInventory.iItemCount == INVENTORY_MAX) {
							cout << "가방이 꽉 찼습니다. " << endl;
							system("pause");
							continue;
						}

						else if (tPlayer.tInventory.iGold < tStoreArmor[iArmorIndex].iPrice)
						{
							cout << "보유금액이 부족합니다. " << endl;
							system("pause");
							continue;
						}
						//처음에는 iitemcount에 하나도 추가되어 있지 않기 때문에 0으로 초기화됨
						tPlayer.tInventory.tItem[tPlayer.tInventory.iItemCount] = tStoreArmor[iArmorIndex];

						++tPlayer.tInventory.iItemCount;

						//골드를 차감한다.
						tPlayer.tInventory.iGold -= tStoreArmor[iArmorIndex].iPrice;

						cout << tStoreArmor[iArmorIndex].strName << "아이템을 구매하였습니다." << endl;
						system("pause");
					}
					break;
				}
			}
			break;

		case MM_INVENTORY:
			while (true) {

				system("cls");
				cout << "*************************************가방*************************************" << endl;
				cout << "=======================Player=======================" << endl;
				cout << "이름 : " << tPlayer.strName << "\t직업 : " << tPlayer.strJobName << endl;
				cout << "레벨 : " << tPlayer.iLevel << "\t경험치 : " << tPlayer.iExp << endl;
				//무기를 장착하고 있을 경우 공격력에 무기 공격력을 추가하여 출력한다.
				if (tPlayer.bEquip[EQ_WEAPON] == true)
					cout << "공격력 : " << tPlayer.iAttackMin << " + " << tPlayer.tEquip[EQ_WEAPON].iMin << " - " << tPlayer.iAttackMAX << " + " << tPlayer.tEquip[EQ_WEAPON].iMax;
				else
					cout << "공격력 : " << tPlayer.iAttackMin << " - " << tPlayer.iAttackMAX;

				//방어구 장착시 방어력 추가
				if (tPlayer.bEquip[EQ_ARMOR] == true)
					cout << "\t방여력 : " << tPlayer.iArmorMin << " + " << tPlayer.tEquip[EQ_ARMOR].iMin << " - " << tPlayer.iArmorMax << " + " << tPlayer.tEquip[EQ_ARMOR].iMax << endl;
				else
					cout << "\t방여력 : " << tPlayer.iArmorMin << " - " << tPlayer.iArmorMax << endl;

				cout << "체력 : " << tPlayer.iHP << " / " << tPlayer.iHPMax << "\t마나 : " << tPlayer.iMP << " / " << tPlayer.iMPMax << endl;

				if (tPlayer.bEquip[EQ_WEAPON] == true)
					cout << "장착무기 : " << tPlayer.tEquip[EQ_WEAPON].strName;
				else
					cout << "장착무기 : 없음";

				if (tPlayer.bEquip[EQ_ARMOR] == true)
					cout << "\t장착방어구 : " << tPlayer.tEquip[EQ_ARMOR].strName << endl;
				else
					cout << "\t장착방어구 : 없음" << endl;


				cout << "보유 골드 : " << tPlayer.tInventory.iGold << " Gold" << endl;

				for (int i = 0; i < tPlayer.tInventory.iItemCount; ++i) {
					cout << i + 1 << ". 이름 : " << tPlayer.tInventory.tItem[i].strName << "\t종류 : " << tPlayer.tInventory.tItem[i].strTypeName << endl;
					cout << "공격력 : " << tPlayer.tInventory.tItem[i].iMin << " - " << tPlayer.tInventory.tItem[i].iMax << endl;
					cout << "판매가격 : " << tPlayer.tInventory.tItem[i].iPrice << "\t구매가격 : " << tPlayer.tInventory.tItem[i].iSell << endl;
					cout << "설명 : " << tPlayer.tInventory.tItem[i].strDesc << endl << endl;
				}

				cout << tPlayer.tInventory.iItemCount + 1 << ". 뒤로가기" << endl;
				cout << "창착할 아이템을 선택하세요 : ";
				cin >> iMenu;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}
				else if (iMenu == tPlayer.tInventory.iItemCount + 1)
					break;

				else if (iMenu < 1 || iMenu>tPlayer.tInventory.iItemCount + 1) {
					cout << "잘못 선택하였습니다. " << endl;
					system("pause");
					continue;
				}

				//제대로 선택했을 경우 해당 아이템의 종류에 따라 장착부위를 결정하게 한다.
			
				int idx = iMenu - 1;//아이템 인덱스 구하기

				EQUIP eq;
				switch(tPlayer.tInventory.tItem[idx].eType) {
				case IT_WEAPON:
					eq = EQ_WEAPON;
					break;
				case IT_ARMOR:
					eq = EQ_ARMOR;
					break;
				}

				//아이템이 장착되어 있을 경우 장착되어있는 아이템과 장착할 아이템을 교체해주어야 한다 swap알고리즘 활용
				if (tPlayer.bEquip[eq] == true) {
					_tagITem tSwap = tPlayer.tEquip[eq];
					tPlayer.tEquip[eq] = tPlayer.tInventory.tItem[idx];
					tPlayer.tInventory.tItem[idx] = tSwap;
				}

				//장착되어있지 않을 경우 인벤토리 아이템을 장착장으로 옮기고 인벤토리는 1칸 비워지게 됨
				else {
					tPlayer.tEquip[eq] = tPlayer.tInventory.tItem[idx];

					for (int i = idx;i < tPlayer.tInventory.iItemCount - 1;++i) {
						tPlayer.tInventory.tItem[i] = tPlayer.tInventory.tItem[i + 1];
					}
					--tPlayer.tInventory.iItemCount;

					//장착을 했기 때문에 true로 만들어줌

					tPlayer.bEquip[eq] = true;

				}
				cout << tPlayer.tEquip[eq].strName << "아이템을 장착했습니다." << endl;
				system("pause");
			}
			break;
		default:
			cout << "잘못 선택하였습니다. " << endl;
			break;
		}

	}

	return 0;
}