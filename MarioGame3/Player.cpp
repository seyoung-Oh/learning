#include "Player.h"



CPlayer::CPlayer()
{
}


CPlayer::~CPlayer()
{
}

bool CPlayer::Init()
{
	m_iX = 4;
	m_iY = 8;
	return true;
}

void CPlayer::Update()
{
	//Ű �Է��� �޴´�.
	//getAsyncState �Լ��� win32 API���� �����Ǵ� Ű �Է� �Լ��̴�.
	// wŰ�� ������ �� �ٷ� �����ϱ� ���ؼ� 0x8000�� &������ �Ͽ� 
	//������ �� true�� ������ �ȴ�.
	
	if (GetAsyncKeyState('A') & 0x8000)
	{
		--m_iX;
		if (m_iX < 0)
			m_iX = 0;
	}
	if (GetAsyncKeyState('D') & 0x8000)
	{
		++m_iX;
		if (m_iX >= 50)
			m_iX = 49;
	}
	if (GetAsyncKeyState(VK_SPACE) & 0X8000)
	{

	}
}
