#pragma once

#include "value.h"

// Ŭ���� ���漱�� : �̰����� ���漱���� Ŭ������ �ִ� ��� �ν��ϰ� �����.
// ���漱�� �� �κп����� ������ �ϴ� ���̱� ������ ���漱���� Ŭ������ ��ü
// �� �����ϴ��� ����� ����� ����� �� ����.
// �ܼ��� ������ ������ ������ �������� �ַ� ����ϰ� ���漱���� ���������
// �� ������� ����� #include �ϴ� ��Ȳ�� �����ְ� cpp���� ���� �����
// �� include�� ���־ ������� ���� include�ϴ� ��Ȳ�� ������ �� �ִ�.
class CStage;
class CMapManager
{
private:
	CMapManager();
	~CMapManager();

private:
	static CMapManager*	m_pInst;

public:
	static CMapManager* GetInst();
	static void DestroyInst();

private:
	CStage * m_pStage[STAGE_MAX_COUNT];

public:
	bool Init();
};


