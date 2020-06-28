#pragma once
template <typename T>
class CListNode
{
	//생성자와 소멸자를 private하게 되면 외부에서 객체 생성, 해제 불가
	//생성자는 객체를 생상할 때 자동으로 호출이 되는 함수인데 private으로 되면 객체를 생성하면서
	//호출시 접근이 불가능하다
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
	//friend : 친구로 만들어줌, 프렌드 지정 클래스에서 private, protected 접근 가능
	//일반 클래스는 friend 라인만 적으면 되는데 템플릿은 아래처럼 지정해줘야함
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

//반복자 클래스 : 리스트의 노드를 반복해서 순회할 수 있는 기능을 제공하는 클래스
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

	T operator *() //역참조 만들때는 인자 없이 만들어 주면 됨
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
	//레퍼런스는 참조하는 대상의 값을 변경 가능
	//하지만 const붙이면 참조하는 대상의 값 변경 불가
	void push_back(const T& data)
	{
		PNODE pNode = new NODE;
		pNode->m_Data = data;

		//end의 이전 노드가 가장 마지막 노드이다
		PNODE pPrev = m_pEnd->m_pPrev;

		//연결해준다
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

		//begin의 다음 노드는 가장 첫번째 노드이다
		PNODE pFirst = m_pBegin->m_pNext;

		pFirst->m_pPrev = pNode;
		pNode->m_pNext = pFirst;

		pNode->m_pPrev = m_pBegin;
		m_pBegin->m_pNext = pNode;

		++m_iSize;
	}

	//멤버 함수 뒤에 const붙여주면 이 함수 내에서 멤버 변수 값을 변경할 수 없다.
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
		//첫번째 노드를 얻어온다.
		PNODE pNode = m_pBegin->m_pNext;

		//pNode가 end가 되면 반복을 종료한다 이렇게 해서 begin, end제외한 모든 노드 삭제
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
