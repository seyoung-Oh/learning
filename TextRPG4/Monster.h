#pragma once
#include "Character.h"
class CMonster :
	public CCharacter
{
public:
	CMonster();
	~CMonster();

private:
	friend class CObjectManager;

public:
	virtual bool Init();
};

