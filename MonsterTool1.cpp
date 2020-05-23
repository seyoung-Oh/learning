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
		return INT_MAX;//int max return시 입력 잘못됨
	}
	return iInput;
}
void AddMonster(_tagMonster* pMonsterArr)
{
	system("cls");
	int iMap = 0;
	while (true)
	{
		cout << "1.쉬움" << endl;
		cout << "2.보통" << endl;
		cout << "3.어려움" << endl;
		cout << "4.취소" << endl;
		cout << "추가할 난이도를 선택하세요 : ";
		iMap = Inputint();

		if (iMap == 4)
			return;
		else if (iMap < 1 || iMap > 4)
			continue;

		--iMap;//1부터 시작이기 때문에 1을 감소시켜야 사냥터 인덱스가 된다.
		break;
	}
	system("cls");
	cin.clear();
	cin.ignore(1024, '\n');

	cout << "이름 : ";
	cin.getline(pMonsterArr[iMap].strName, NAME_SIZE - 1);//마지막에 null 넣을 공간 뺌

	cout << "최소 공격력 :";
	pMonsterArr[iMap].iAttackMin = Inputint();
	cout << "최대 공격력 :";
	pMonsterArr[iMap].iAttackMAX = Inputint();
	cout << "최소 방어력 :";
	pMonsterArr[iMap].iArmorMin = Inputint();
	cout << "최대 방어력 :";
	pMonsterArr[iMap].iArmorMax = Inputint();
	cout << "체력 :";
	pMonsterArr[iMap].iHP = Inputint();
	pMonsterArr[iMap].iHPMax = pMonsterArr[iMap].iHP;
	cout << "마나 :";
	pMonsterArr[iMap].iMP = Inputint();
	pMonsterArr[iMap].iMPMax = pMonsterArr[iMap].iMP;


	cout << "레벨 :";
	pMonsterArr[iMap].iLevel = Inputint();

	cout << "획득경험치 :";
	pMonsterArr[iMap].iExp = Inputint();

	cout << "획득 최소 골드 :";
	pMonsterArr[iMap].iGoldMin = Inputint();

	cout << "획득 최대 골드 :";
	pMonsterArr[iMap].iGoldMax = Inputint();

	cout << "몬스터 추가 완료" << endl;

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
	cout << "이름 : " << pMonster->strName << "\t레벨 : " << pMonster->iLevel << endl;
	cout << "공격력 : " << pMonster->iAttackMin << " - " << pMonster->iAttackMAX << "\t방어력 : " << pMonster->iArmorMin << " - " << pMonster->iArmorMax << endl;
	cout << "체력 : " << pMonster->iHP << " / " << pMonster->iHPMax << "\t마나 : " << pMonster->iMP << " / " << pMonster->iMPMax << endl;
	cout << "획득경험치 : " << pMonster->iExp << "\t획득골드 : " << pMonster->iGoldMin << " - " << pMonster->iGoldMax << endl << endl;
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
		cout << "1. 몬스터 추가" << endl;
		cout << "2. 읽어오기" << endl;
		cout << "3. 저장" << endl;
		cout << "4. 몬스터 출력" << endl;
		cout << "5. 종료" << endl;
		cout << "메뉴를 선택하세요 : ";
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