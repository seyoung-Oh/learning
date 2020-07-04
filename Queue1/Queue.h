#pragma once

template<typename T>
class CQueueNode
{
private:
	CQueueNode() :
		m_pNext(NULL),
		m_pPrev(NULL)
	{

	}
	~CQueueNode()
	{

	}

private:
	template<typename T>
	friend class CQueue;

private:
	T m_Data;
	CQueueNode<T>* m_pNext;
	CQueueNode<T>* m_pPrev;
};

template<typename T>
class CQueue
{
public:
	CQueue()
	{
		m_pBegin = new NODE;
		m_pEnd = new NODE;

		m_pBegin->m_pNext = m_pEnd;
		m_pEnd->m_pPrev = m_pBegin;

		m_iSize = 0;
	}
	~CQueue()
	{

	}

private:
	typedef CQueueNode<T> NODE;
	typedef CQueueNode<T>* PNODE;

private:
	PNODE m_pBegin;
	PNODE m_pEnd;
	unsigned int m_iSize;

public:
	void push(const T& data)
	{
		PNODE pNode = new NODE;
		pNode->m_Data = data;

		PNODE pPrev = m_pEnd->m_pPrev;

		pPrev->m_pNext = pNode;
		pNode->m_pPrev = pPrev;

		pNode->m_pNext = m_pEnd;
		m_pEnd->m_pPrev = pNode;

		++m_iSize;
	}

	T pop()
	{
		if (empty())
			return 0;

		PNODE pNode = m_pBegin->m_pNext;

		T data = pNode->m_Data;

		//begin의 다음 노드를 지우니까 begin과 지울 노드의 다음 노드를 서로 연결해준다.
		m_pBegin->m_pNext = pNode->m_pNext;
		pNode->m_pNext->m_pPrev = m_pBegin;

		delete pNode;
		--m_iSize;

		return data;
	}

	bool empty()
	{
		return m_iSize == 0;
	}
};
