#pragma once
template <typename T>
class CListNode
{
	//�����ڿ� �Ҹ��ڸ� private�ϰ� �Ǹ� �ܺο��� ��ü ����, ���� �Ұ�
	//�����ڴ� ��ü�� ������ �� �ڵ����� ȣ���� �Ǵ� �Լ��ε� private���� �Ǹ� ��ü�� �����ϸ鼭
	//ȣ��� ������ �Ұ����ϴ�
private:
	CListNode() :
		m_pNext(NULL),
		m_pPrev(NULL)
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
	template <typename T>
	friend class CListIterator;
	template <typename T>
	friend class CListReverseIterator;

private:
	T m_Data;
	CListNode<T>* m_pNext;
	CListNode<T>* m_pPrev;
};

//�ݺ��� Ŭ���� : ����Ʈ�� ��带 �ݺ��ؼ� ��ȸ�� �� �ִ� ����� �����ϴ� Ŭ����
template <typename T>
class CListIterator
{
public:
	CListIterator()
	{

	}
	~CListIterator()
	{

	}
private:
	template<typename T>
	friend class CLinkedList;

private:
	typedef CListNode<T> NODE;
	typedef CListNode<T>* PNODE;

private:
	PNODE m_pNode;

public:
	bool operator ==(const CListIterator<T>& iter)
	{
		return m_pNode == iter.m_pNode;
	}
	bool operator !=(const CListIterator<T>& iter)
	{
		return m_pNode != iter.m_pNode;
	}

	void operator ++()
	{
		m_pNode = m_pNode->m_pNext;
	}

	void operator--()
	{
		m_pNode = m_pNode->m_pPrev;
	}

	T operator *()
	{
		return m_pNode->m_Data;
	}

};

template <typename T>
class CListReverseIterator
{
public:
	CListReverseIterator()
	{

	}
	~CListReverseIterator()
	{

	}
private:
	template <typename T>
	friend class CLinkedList;

private:
	typedef CListNode<T> NODE;
	typedef CListNode<T>* PNODE;

private:
	PNODE m_pNode;

public:
	bool operator ==(const CListReverseIterator<T>& iter)
	{
		return m_pNode == iter.m_pNode;
	}

	bool operator !=(const CListReverseIterator<T>& iter)
	{
		return m_pNode != iter.m_pNode;
	}

	void operator ++()
	{
		m_pNode = m_pNode->m_pPrev;
	}

	void operator --()
	{
		m_pNode = m_pNode->m_pNext;
	}

	T operator *() //������ ���鶧�� ���� ���� ����� �ָ� ��
	{
		return m_pNode->m_Data;
	}
};

template <typename T>
class CLinkedList
{
public:
	CLinkedList()
	{
		m_pBegin = new NODE;
		m_pEnd = new NODE;

		m_pBegin->m_pNext = m_pEnd;
		m_pEnd->m_pPrev = m_pBegin;

		m_iSize = 0;
	}

	~CLinkedList()
	{
		clear();
		delete m_pBegin;
		delete m_pEnd;
		m_iSize = 0;
	}

private:
	typedef CListNode<T> NODE;
	typedef CListNode<T>* PNODE;

public:
	typedef CListIterator<T> iterator;
	typedef CListReverseIterator<T> reverse_iterator;

private:
	PNODE m_pBegin;
	PNODE m_pEnd;
	unsigned int m_iSize;

public:
	//���۷����� �����ϴ� ����� ���� ���� ����
	//������ const���̸� �����ϴ� ����� �� ���� �Ұ�
	void push_back(const T& data)
	{
		PNODE pNode = new NODE;
		pNode->m_Data = data;

		//end�� ���� ��尡 ���� ������ ����̴�
		PNODE pPrev = m_pEnd->m_pPrev;

		//�������ش�
		pPrev->m_pNext = pNode;
		pNode->m_pPrev = pPrev;

		pNode->m_pNext = m_pEnd;
		m_pEnd->m_pPrev = pNode;

		++m_iSize;
	}

	void push_front(const T& data)
	{
		PNODE pNode = new NODE;
		pNode->m_Data = data;

		//begin�� ���� ���� ���� ù��° ����̴�
		PNODE pFirst = m_pBegin->m_pNext;

		pFirst->m_pPrev = pNode;
		pNode->m_pNext = pFirst;

		pNode->m_pPrev = m_pBegin;
		m_pBegin->m_pNext = pNode;

		++m_iSize;
	}

	//��� �Լ� �ڿ� const�ٿ��ָ� �� �Լ� ������ ��� ���� ���� ������ �� ����.
	unsigned int size() const
	{
		return m_iSize;
	}

	bool empty() const
	{
		return m_iSize == 0;
	}
	void clear()
	{
		//ù��° ��带 ���´�.
		PNODE pNode = m_pBegin->m_pNext;

		//pNode�� end�� �Ǹ� �ݺ��� �����Ѵ� �̷��� �ؼ� begin, end������ ��� ��� ����
		while (pNode != m_pEnd)
		{
			PNODE pNext = pNode->m_pNext;
			delete pNode;
			pNode = pNext;
		}

		m_pBegin->m_pNext = m_pEnd;
		m_pEnd->m_pPrev = m_pBegin;
		m_iSize = 0;
	}

	iterator begin()
	{
		iterator iter;
		iter.m_pNode = m_pBegin->m_pNext;
		return iter;
	}

	iterator end()
	{
		iterator iter;
		iter.m_pNode = m_pEnd;
		return iter;
	}

	reverse_iterator rbegin()
	{
		reverse_iterator iter;
		iter.m_pNode = m_pEnd->m_pPrev;
		return iter;
	}

	reverse_iterator rend()
	{
		reverse_iterator iter;
		iter.m_pNode = m_pBegin;
		return iter;
	}
};
