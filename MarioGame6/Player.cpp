#include "Player.h"
#include "MapManager.h"
#include "Stage.h"

CPlayer::CPlayer()
{
}


CPlayer::~CPlayer()
{
}

bool CPlayer::Init()
{
	m_tPos.x = 0;
	m_tPos.y = 8;
	m_bJump = false;
	m_iJumpDir = JD_STOP;
	m_iJumpState = 0;
	m_iScore = 0;

	return true;
}

void CPlayer::Update()
{
	CStage* pStage = CMapManager::GetInst()->GetStage();
	//Ű �Է��� �޴´�.
	//getAsyncState �Լ��� win32 API���� �����Ǵ� Ű �Է� �Լ��̴�.
	// wŰ�� ������ �� �ٷ� �����ϱ� ���ؼ� 0x8000�� &������ �Ͽ� 
	//������ �� true�� ������ �ȴ�.
	
	if (GetAsyncKeyState('A') & 0x8000)
	{
		if (pStage->GetBlock(m_tPos.x - 1, m_tPos.y) != SBT_WALL)
		{
			--m_tPos.x;
			if (m_tPos.x < 0)
				m_tPos.x = 0;
		}
	}
	if (GetAsyncKeyState('D') & 0x8000)
	{
		if (pStage->GetBlock(m_tPos.x + 1, m_tPos.y) != SBT_WALL)
		{
			++m_tPos.x;
			if (m_tPos.x >= 50)
				m_tPos.x = 49;
		}
	}
	if (GetAsyncKeyState(VK_SPACE) & 0X8000 && !m_bJump)
	{
		m_bJump = true;
		m_iJumpDir = JD_UP;
		m_iJumpState = 0;
	}
	if (m_bJump)
	{

		CStage* pStage = CMapManager::GetInst()->GetStage();
		switch (m_iJumpDir)
		{
		case JD_UP:
			++m_iJumpState;

			if (m_iJumpState > JUMP_BLOCK_MAX)
			{
				m_iJumpState = JUMP_BLOCK_MAX;
				m_iJumpDir = JD_DOWN;
			}

			else if (pStage->GetBlock(m_tPos.x,m_tPos.y-1) == SBT_WALL)
			{
				--m_iJumpState;
				m_iJumpDir = JD_DOWN;
			}
			else
			{
				--m_tPos.y;
			}
				break;
		case JD_DOWN:
			if (m_tPos.y >= BLOCK_Y)
			{
				cout << "�÷��̾� ���" << endl;
				system("pause");
				m_tPos.y = BLOCK_Y - 1;
			}
			else if (pStage->GetBlock(m_tPos.x, m_tPos.y + 1) == SBT_WALL)
			{
				m_iJumpDir = JD_STOP;
				m_bJump = false;
			}
			else
				++m_tPos.y;
			break;
		}
	}
	if (pStage->GetBlock(m_tPos.x, m_tPos.y + 1) != SBT_WALL && !m_bJump)
	{
		++m_tPos.y;
	}

	if (pStage->GetBlock(m_tPos.x, m_tPos.y) == SBT_COIN)
	{
		pStage->ChangeBlock(m_tPos.x, m_tPos.y, SBT_ROAD);
		m_iScore += 1000;
	}

	if (m_tPos.y >= BLOCK_Y)
	{
		cout << "�÷��̾� ���" << endl;
		m_tPos = pStage->GetStart();
		m_iScore = 0;
		pStage->ResetStage();
		system("pause");
	}
}
