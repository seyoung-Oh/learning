#include "ObjectManager.h"
#include "Player.h"
#include "Monster.h"


DEFINITION_SINGLE(CObjectManager)

CObjectManager::CObjectManager()
{
}


CObjectManager::~CObjectManager()
{
}

bool CObjectManager::Init()
{
	return false;
}

CObj * CObjectManager::CreateObject(const string& strKey, OBJECT_TYPE eType)
{
	CObj* pObj = NULL;
	switch (eType)
	{
	case OT_PLAYER:
		pObj = new CPlayer;
		break;
	case OT_MONSTER:
		pObj = new CMonster;
		break;
	}

	if (!pObj->Init())
	{
		SAFE_DELETE(pObj);
		return NULL;
	}
	return nullptr;
}
