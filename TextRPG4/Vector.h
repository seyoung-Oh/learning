#pragma once

template <typename T>
class CVectorNode
{
private:
	CVectorNode()
	{

	}
	~CVectorNode()
	{

	}

private :
	template <typename T>
	friend class CVector;

private:
	T m_Data;
	int m_iIndex;
};

template <typename T>
class CVector
{
public:
	CVector()
	{
		m_iSize = 0;
		m_iCapasity = 2;

		m_pArray = new NODE[m_iCapasity + 2];
	}

	CVector(int iSize)
	{
		m_pArray = new NODE[iSize + 2];
		m_iCapasity = iSize;
		m_iSize = 0;
	}
	~CVector()
	{
		delete[] m_pArray;
	}

private:
	typedef CVectorNode<T> NODE;
	typedef CVectorNode<T>* PNODE;

private:
	PNODE m_pArray;
	unsigned int m_iSize;
	unsigned int m_iCapasity;

public:
	void push_back(const T& data)
	{
		if (full())
			resize(m_iSize * 2);

		m_pArray[m_iSize + 1].m_Data = data;
		//0���� ���, 1�� �ε������� ��� �߰�
		//ó�� �߰��� ���� 0������ �ε����� �ֵ��� �Ѵ�.
		m_pArray[m_iSize + 1].m_iIndex = m_iSize;
		++m_iSize;
	}

	void resize(int iSize)
	{
		//+2�� ���ִ� ������ begin�� end�� ���Խ��� �����ϱ� ���ؼ��̴�
		PNODE pArray = new NODE[iSize + 2];

		//������ 2�踸ŭ ������ ���� �Ҵ��ϰ� ������ �ִ�
		//����� �����͸� ���� �Ҵ��� ������ �������ش�.
		//1�� �ε������� �����̶� +1 ����
		memcpy(pArray + 1, m_pArray + 1, sizeof(NODE) * m_iSize);

		//���� ��带 �����Ѵ�
		delete[]  m_pArray;

		m_pArray = pArray;

		m_iCapasity = iSize;
	}

	void clear()
	{
		delete[] m_pArray;
		m_iSize = 0;
		m_iCapasity = 2;
		m_pArray = new NODE[m_iCapasity + 2];
	}

	bool full()
	{
		return m_iSize == m_iCapasity;
	}

	bool empty()
	{
		return m_iSize == 0;
	}

	unsigned int size() const
	{
		return m_iSize;
	}

	unsigned int capasity() const
	{
		return m_iCapasity;
	}

	T operator [](int idx)
	{
		return m_pArray[idx + 1].m_Data;
	}

	void reserve(int iSize)
	{
		delete[] m_pArray;
		m_pArray = new NODE[iSize + 2];

		m_iCapasity = iSize;
		m_iSize = 0;
	}
};

