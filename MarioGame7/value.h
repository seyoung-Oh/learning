
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

// Block Count
#define BLOCK_X 50
#define BLOCK_Y 10

//Render Block Count
#define RENDER_BLOCK_X 20
#define RENDER_BLOCK_Y 5

static int InputInt()
{
	int iInput;
	cin >> iInput;
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(1024, '\n');
		return INT_MAX;

	}
	return iInput;

}