#pragma once

#include "value.h"

class CStage
{
public:
	CStage();
	~CStage();

private:
	char m_cStage[10][50];

public:
	// �� �Լ��� �׳� �ʱ�ȭ�� ������ �Լ��̴�.
	bool Init();

	// �� �Լ��� ���Ͽ��� ������ �о�ͼ� ������ ������ �Լ��̴�.
	bool Init(char* pFileName);
};

