#pragma once

template <typename T>
class CStackNode
{
private:
	CStackNode():
		m_pNext(NULL)
	{

	}
	~CStackNode()
	{

	}
private:
	template <typename T>
	friend class CStack;

private:
	T m_Data;
	CStackNode<T>* m_pNext;
};

template <typename T>

class CStack
{
public:
	CStack()
	{
		m_pBegin = new NODE;
		m_pEnd = new NODE;

		m_pBegin->m_pNext = m_pEnd;

		m_iSize = 0;
	}
	~CStack()
	{

	}

private:
	typedef CStackNode<T> NODE;
	typedef CStackNode<T>* PNODE;

private:
	PNODE m_pBegin;
	PNODE m_pEnd;
	unsigned int m_iSize;


};

