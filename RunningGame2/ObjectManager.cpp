#include "ObjectManager.h"
#include "Player.h"
#include "Bullet.h"

CObjectManager* CObjectManager::m_pInst = NULL;

CObjectManager::CObjectManager():
	m_pPlayer(NULL)
{
}


CObjectManager::~CObjectManager()
{
	SAFE_DELETE(m_pPlayer);

	for (int i = 0; i < m_iCurBulletCount;++i)
	{
		SAFE_DELETE(m_pBullet[i]);
	}
}

bool CObjectManager::Init()
{
	m_pPlayer = new CPlayer;

	m_pPlayer->Init();

	//1�� ���ڿ� ���� ������ �޸� �ּҸ��־��ش�
	//3�� ���ڴ� ���� ������ �޸� ũ�⸦ �־��ش�.
	//�̷��� ���ָ� 1���� �־��� �ּҺ��� 3���� �־��� �޸� ũ�⸸ŭ 2�� ���ڿ� �������� �޸𸮸� �ʱ�ȭ����
	memset(m_pBullet, 0, sizeof(CBullet*) * BULLET_COUNT_MAX);
	m_iCurBulletCount = 0;

	return true;
}

bool CObjectManager::CreateBullet()
{
	//�Ѿ� ������ ������ �Ѿ��� �̹� �ִ�ġ��� ���̻� �������� �ʴ´�.
	if (m_iCurBulletCount == BULLET_COUNT_MAX)
		return false;

	//�Ѿ��� �����Ѵ�.
	CBullet* pBullet = new CBullet;

	//�Ѿ��� �ʱ�ȭ�Ѵ�. �Ѿ� �ʱ�ȭ ���н� ������ �Ѿ��� ����� false ��ȯ
	if (!pBullet->Init())
	{
		SAFE_DELETE(pBullet);
	}

	m_pBullet[m_iCurBulletCount] = pBullet;
	++m_iCurBulletCount;

	return true;
}
