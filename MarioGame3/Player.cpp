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
	//키 입력을 받는다.
	//getAsyncState 함수는 win32 API에서 제공되는 키 입력 함수이다.
	// w키를 눌렸을 때 바로 반응하기 위해서 0x8000과 &연산을 하여 
	//눌렀을 때 true가 나오게 된다.
	
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
