#pragma once

#include "value.h"


class CObjectManager
{
private:
	// map�� �⺻������ key, value�� �����Ǿ� �ִ�.
	// ù��° template Ÿ���� key, �ι�° template Ÿ���� value �̴�.
	// �׷��� Ÿ���� 2���� �������ְ� key �� �̿��ؼ� Ž���� �ϰ� �ȴ�
	// ���� ���� value�� ������ Ÿ���� ���� �����ϴ� ���̴�.
	unordered_map<string, class CObj*> m_mapObj;

public:
	bool Init();

	DECLARE_SINGLE(CObjectManager)
};

