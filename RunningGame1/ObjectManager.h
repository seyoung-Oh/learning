#pragma once
#include "value.h"

class CObjectManager
{
public:
	CObjectManager();
	~CObjectManager();

private:
	static CObjectManager* m_pInst;

public:
	static CObjectManager* GetInst()
	{
		if (!m_pInst)
			m_pInst = new CObjectManager;
		return m_pInst;
	}

	static void DestroyInst()
	{
		SAFE_DELETE(m_pInst);
	}
private:
	//���� ���� �ϴ� ���� �ƴ� �ش� Ÿ���� ����ϰ��� �� �� ���漱���� ���� �� �ִ�.
	class CPlayer* m_pPlayer;
public:
	class CPlayer* GetPlayer()
	{
		return m_pPlayer;
	}
public:
	bool Init();
};

