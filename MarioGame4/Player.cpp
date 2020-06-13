#include "Player.h"



CPlayer::CPlayer()
{
}


CPlayer::~CPlayer()
{
}

bool CPlayer::Init()
{
	m_iX = 0;
	m_iY = 8;
	m_bJump = false;
	m_iJumpDir = JD_STOP;
	m_iJumpState = 0;
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
	if (GetAsyncKeyState(VK_SPACE) & 0X8000 && !m_bJump)
	{
		m_bJump = true;
		m_iJumpDir = JD_UP;
		m_iJumpState = 0;
	}
	if (m_bJump)
	{
		switch (m_iJumpDir)
		{
		case JD_UP:
			++m_iJumpState;
			if (m_iJumpState > JUMP_BLOCK_MAX)
			{
				m_iJumpState = JUMP_BLOCK_MAX;
				m_iJumpDir = JD_DOWN;
			}
			else
			{
				--m_iY;
			}
				break;
		case JD_DOWN:
			--m_iJumpState;
			
			if(m_)
			break;
		}
	}
}
