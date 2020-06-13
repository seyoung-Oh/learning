#pragma once
#include "value.h"
enum JUMP_DIR
{
	JD_STOP,
	JD_UP,
	JD_DOWN
};

#define JUMP_BLOCK_MAX 2
class CPlayer
{
public:
	CPlayer();
	~CPlayer();

private:
	int m_iX;
	int m_iY;
	int m_bJump;
	int m_iJumpDir;
	int m_iJumpState;

public:
	void SetPos(int x, int y)
	{
		m_iX = x;
		m_iY = y;
	}
public:
	int GetX()
	{
		return m_iX;
	}
	int GetY()
	{
		return m_iY;
	}
public:
	bool Init();
	void Update();
};

