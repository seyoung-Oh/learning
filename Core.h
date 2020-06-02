#pragma once

#include "value.h"

// ������Ͽ��� Ŭ������ ����κ��� ���´�.
class CCore
{
private:
	CCore();
	~CCore();

private:
	static CCore*	m_pInst;

public:
	static CCore* GetInst();
	static void DestroyInst();

public:
	// �� �Լ��� ��ü ������ �ʱ�ȭ�ϴ� ������ �Ѵ�.
	bool Init();

	// �� �Լ��� ������ ���۽�Ű�� ������ �Ѵ�.
	void Run();
};

