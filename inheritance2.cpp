#include <iostream>

using namespace std;

/*
��� : Ŭ������ ���ΰ��� �θ�, �ڽİ��踦 ���� �� �� �ִ�,
�ڽ� Ŭ������ �θ�Ŭ������ ������� ����� �� �ִ�.

�θ�Ŭ�������� public�̳� protected�� ��밡��
private ����� �ڽĿ����� ����� �Ұ����ϴ�.

����� ���� : public, private����� ����

������ : ��Ӱ��迡 �ִ� Ŭ�������� ���� ����ȯ�� ������ ������ ���Ѵ�.

*/
class CParent
{
public:
	CParent()
	{
		cout << "CParent ������" << endl;
	}
	~CParent()
	{
		cout << "CParent �Ҹ���" << endl;
	}
public:
	int m_iA;
protected:
	int m_iB;
private:
	int m_iC;
public:
	void Output()
	{
		cout << "A : " << m_iA << endl;
		cout << "B : " << m_iB << endl;
		cout << "C : " << m_iC << endl;
	}
};
class CChild : public CParent
{
public:
	CChild()
	{
		m_iB = 200;
		//m_iC�� private�̱� ������ �ڽ� Ŭ�������� ������ �Ұ���
		//m_iC = 300;
		cout << "CChild ������" << endl;
	}
	~CChild()
	{
		cout << "CChild �Ҹ���" << endl;
	}

private:
	int m_iD;
};
class CChild1 : private CParent
{
public:
	CChild1()
	{
		m_iA = 100;
		m_iB = 200;
		cout << "CChild1 ������" << endl;
	}
	~CChild1()
	{
		cout << "CChild1 �Ҹ���" << endl;
	}
protected:
	int m_iD;
};
class CChildChild : public CChild1
{
public:
	CChildChild()
	{	
		m_iD = 500;
		cout << "CChildChild ������" << endl;
	}
	~CChildChild()
	{

		cout << "CChildChild �Ҹ���" << endl;
	}

private:
	int m_iE;
};

int main()
{	/*
	��Ӱ��迡���� ������ ȣ�� ���� : �θ�->�ڽ� ������ ȣ��ȴ�.
	��Ӱ��迡���� �Ҹ��� ȣ�� ���� : �ڽ�->�θ� ������ ȣ��ȴ�.
    */
	//CParent parent;
	//CChild child;
	//CChild1 child1;
	//CChildChild childchild;

	//parent.m_iA = 100;
	//child.m_iA = 200;

	//Child1 Ŭ������ CParent �� private ����� �ϰ� �־ CParent�� public���� �����Ǿ� �ִ� ����鵵 �ܺο����� ������ �Ұ����ϴ�.
	//child1.m_iA = 300;
	//child1.Output();

	//CChild Ŭ������ CParentŬ������ ��ӹް� �ִ�.
	//new child �� �ϰ� �Ǹ� CChild ��ü �ϳ��� �������ְ� �� �޸� �ּҸ� ��ȯ�Ѵ�.
	//�׷��� �Ʒ������� CParent * Ÿ�Ժ����� �� ��ȯ�� �ּҸ� �������ְ� �ִ�.
	//�θ� ������ Ÿ�Կ� CChild ��ü�� �޸� �ּҸ� ���� �� �ִ� ������ ��Ӱ��迡 �ֱ� �����̴�.
	//�ڽ� �޸� �ּҸ� �θ� ������ Ÿ������ ����ȯ �� ���̱� �����̴�. �� �� ��ȯ�� ��ĳ�����̶�� ��
	//�ڽ�-> �θ� Ÿ�� ����ȯ : ��ĳ����
	//�θ�-> �ڽ� Ÿ�� ����ȯ : �ٿ�ĳ����
	CParent* pParent = new CChild;
	//CParent* pParent1 = new CChild1;
	//CParent* pParent2 = new CChildChild;
	CParent* pParentArr[2] = {};

	pParentArr[0] = new CChild;
	pParentArr[1] = new CChildChild;
	// �Ʒ� �� Ŭ������ ��� CParent Ŭ������ ��ӹް� �ִ�.
	//�׷��Ƿ� pParent�� �� Ÿ�� ��� �ٿ�ĳ���� �����ϴ�.
	//�׷��� pParent�� CChild�� �Ҵ��� ��ü�̴�.
	// �� ��ü�� CChild1 Ÿ������ �ٿ�ĳ���� �Ͽ� �־��ְ� �Ǹ� 
	// �� ��ü�� ����� �� ������ �߻��� �� �ִ�, �ֳĸ� ���ʿ� ������ ��ü�� �ƴ� �ٸ�Ÿ������ ��ȯ�Ʊ� �����̴�.
	CChild* pChild = (CChild*)pParent;
	CChild1* pChild1 = (CChild1*)pParent;


	delete pChild;
	//delete pParent2;
	
	return 0;

}