
#include "Core.h"

/*
170727 ���� : ���� 50 x 10 ���� �����.
Stage Ŭ���� Init�Լ����� �� ���� �����
Stage Ŭ������ Render�Լ��� ���� �̸��� ����ϴ� �ڵ带 �ۼ��϶�.
�� �Ŀ� Map ������ Ŭ������ Run�Լ����� �ش� ���������� ����϶�.
(Render �Լ� ȣ���϶�� �ǹ�)
*/

int main()
{
	// ������ �ʱ�ȭ�Ѵ�.
	if (!CCore::GetInst()->Init())
	{
		cout << "���� �ʱ�ȭ ����!!" << endl;
		CCore::DestroyInst();

		return 0;
	}

	// �ʱ�ȭ�� �����ߴٸ� ������ ������Ų��.
	CCore::GetInst()->Run();

	// ������ ������ CCore ��ü�� �޸𸮿��� ������Ų��.
	CCore::DestroyInst();

	return 0;
}
