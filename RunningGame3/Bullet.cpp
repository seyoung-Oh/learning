#include "Bullet.h"



CBullet::CBullet()
{
}


CBullet::~CBullet()
{
}

bool CBullet::Init()
{
	return true;
}

void CBullet::Update()
{
	//�Ź� �Ѿ��� ���������� ��ĭ �̵���Ų��.
	m_tPos.x++;
}
