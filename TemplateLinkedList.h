#pragma once
template <typename T>
class CListNode
{
	//�����ڿ� �Ҹ��ڸ� private�ϰ� �Ǹ� �ܺο��� ��ü ����, ���� �Ұ�
	//�����ڴ� ��ü�� ������ �� �ڵ����� ȣ���� �Ǵ� �Լ��ε� private���� �Ǹ� ��ü�� �����ϸ鼭
	//ȣ��� ������ �Ұ����ϴ�
private:
	CListNode()
	{

	}
	~CListNode()
	{

	}
private:
	//friend : ģ���� �������, ������ ���� Ŭ�������� private, protected ���� ����
	//�Ϲ� Ŭ������ friend ���θ� ������ �Ǵµ� ���ø��� �Ʒ�ó�� �����������
	template <typename T>
	friend class CLinkedList;

private:
	T m_Data;
	CListNode<T>* m_pNext;
	CListNode<T>* m_pPrev;
};

template <typename T>
class CLinkedList
{
public:
	CLinkedList()
	{
	}

	~CLinkedList()
	{
	}

private:
	typedef CListNode<T> NODE;
	typedef CListNode<T>* PNODE;
};
