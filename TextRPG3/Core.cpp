#include "Core.h"
#include "StageManager.h"

DEFINITION_SINGLE(CCore)

enum MAIN_MENU
{
	MM_NONE,
	MM_STAGE,
	MM_STORE,
	MM_INVENTORY,
	MM_STATUS,
	MM_EXIT
};

CCore::CCore()
{
}


CCore::~CCore()
{
	DESTROY_SINGLE(CStageManager);
}

bool CCore::Init()
{
	//Stage�� �ʱ�ȭ�Ѵ�
	if (!GET_SINGLE(CStageManager)->Init())
		return false;

	return true;
}

void CCore::Run()
{

	while (true)
	{
		switch (OutputMenu())
		{
		case MM_STAGE:
			GET_SINGLE(CStageManager)->Run();
			break;
		case MM_STORE:
			break;
		case MM_INVENTORY:
			break;
		case MM_STATUS:
			break;
		case MM_EXIT:
			return;
		}
	}
}

int CCore::OutputMenu()
{

	system("cls");
	cout << "1. ��" << endl;
	cout << "2. ����" << endl;
	cout << "3. �κ��丮" << endl;
	cout << "4. ĳ��������" << endl;
	cout << "5. ����" << endl;
	cout << "�޴��� �����ϼ��� : ";
	int iMenu = Input<int>();

	if (iMenu <= MM_NONE || iMenu > MM_EXIT)
		return MM_NONE;

	return iMenu;
}
