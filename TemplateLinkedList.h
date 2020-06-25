#pragma once
template <typename T>
class CListNode
{
	//생성자와 소멸자를 private하게 되면 외부에서 객체 생성, 해제 불가
	//생성자는 객체를 생상할 때 자동으로 호출이 되는 함수인데 private으로 되면 객체를 생성하면서
	//호출시 접근이 불가능하다
private:
	CListNode()
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
