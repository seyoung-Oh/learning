
#pragma once

#include <iostream>
// Windows.h ������� �������� ����� ����� �� �ִ� ���� �Լ�����
// �������ְ� �ִ�. �츮�� ���⿡�� Ű�Է� ����� Ȱ���� ���̴�.
#include <Windows.h>

using namespace std;

// ��ũ�δ� #define�� �̿��ؼ� ����� ������ִ� ���̴�. �� ��ũ�θ� ����ϰ�
// �Ǹ� ����� �κп� �����ϴܰ迡�� ���� �ڵ带 �������ִ� �����̴�.
// ��ũ���� ���� : �극��ũ �����͸� �ɰ� ���� üũ�� �� ����.
#define	SAFE_DELETE(p)	if(p)	{ delete p; p = NULL; }

// Stage Max Count
#define	STAGE_MAX_COUNT	3
