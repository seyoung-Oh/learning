#include "Stage.h"
#include "FileStream.h"

enum STAGE_BLOCK_TYPE
{
	SBT_WALL = '0',
	SBT_ROAD = '1',
	SBT_START = '2',
	SBT_END = '3',
	SBT_COIN= '4'
};
CStage::CStage()
{
}

CStage::~CStage()
{
}

bool CStage::Init()
{
	return true;
}

bool CStage::Init(char * pFileName)
{
	CFileStream file;

	if (!file.Open(pFileName, "rt"))
		return false;

	for (int i = 0;i < 10;++i)
	{
		int iSize = 0;
		file.ReadLine(m_cStage[i], iSize);
	}

	return true;
}

void CStage::Render()
{
	/*���� ��ũ�� ó���� �ؾ��Ѵ�. �׷��� ������ ���� �÷��̾
	�̵��� ��ġ�κ��� ���� ������־�� �Ѵ�. ��� ũ��� ���� 4ĭ ���� 10ĭ���� ���ش�.
	������ �÷��̾ ó���� �ִ� �����ϰ� ó�� 4 X 10 ����� ���ش�.
	0 : �� 1 : �� 2 : ������ 3 : ������ 4 : ����
	*/
	for (int i = 6;i < 10;++i)
	{
		for (int j = 0;j < 10; ++j)
		{
			if (m_cStage[i][j] == SBT_WALL)
				cout << "��";

			else if (m_cStage[i][j] == SBT_ROAD)
				cout << "  ";

			else if (m_cStage[i][j] == SBT_START)
				cout << "��";

			else if (m_cStage[i][j] == SBT_END)
				cout << "��";

			else if (m_cStage[i][j] == SBT_COIN)
				cout << "��";

		}
		cout << endl;
	}
}
