
#include "Core.h"


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
