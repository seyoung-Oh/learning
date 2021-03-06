#include <iostream>

using namespace std;

/*
상속 : 클래스는 서로간에 부모, 자식관계를 형성 할 수 있다,
자식 클래스는 부모클래스의 멤버들을 사용할 수 있다.

부모클래스에서 public이나 protected는 사용가능
private 멤버는 자식에서도 사용이 불가능하다.

상속의 형태 : public, private상속이 있음

다형성 : 상속관계에 있는 클래스간에 서로 형변환이 가능한 성질을 말한다.

*/
class CParent
{
public:
	CParent()
	{
		cout << "CParent 생성자" << endl;
	}
	~CParent()
	{
		cout << "CParent 소멸자" << endl;
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
		//m_iC는 private이기 때문에 자식 클래스에서 접근이 불가능
		//m_iC = 300;
		cout << "CChild 생성자" << endl;
	}
	~CChild()
	{
		cout << "CChild 소멸자" << endl;
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
		cout << "CChild1 생성자" << endl;
	}
	~CChild1()
	{
		cout << "CChild1 소멸자" << endl;
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
		cout << "CChildChild 생성자" << endl;
	}
	~CChildChild()
	{

		cout << "CChildChild 소멸자" << endl;
	}

private:
	int m_iE;
};

int main()
{	/*
	상속관계에서의 생성자 호출 순서 : 부모->자식 순으로 호출된다.
	상속관계에서의 소멸자 호출 순서 : 자식->부모 순으로 호출된다.
    */
	//CParent parent;
	//CChild child;
	//CChild1 child1;
	//CChildChild childchild;

	//parent.m_iA = 100;
	//child.m_iA = 200;

	//Child1 클래스는 CParent 를 private 상속을 하고 있어서 CParent에 public으로 설정되어 있는 멤버들도 외부에서는 접근이 불가능하다.
	//child1.m_iA = 300;
	//child1.Output();

	//CChild 클래스는 CParent클래스를 상속받고 있다.
	//new child 를 하게 되면 CChild 객체 하나를 생성해주고 그 메모리 주소를 반환한다.
	//그런데 아래에서는 CParent * 타입변수에 이 반환된 주소를 대입해주고 있다.
	//부모 포인터 타입에 CChild 객체의 메모리 주소를 넣을 수 있는 이유는 상속관계에 있기 때문이다.
	//자식 메모리 주소를 부모 포인터 타입으로 형변환 된 것이기 떄문이다. 이 형 변환을 업캐스팅이라고 함
	//자식-> 부모 타입 형변환 : 업캐스팅
	//부모-> 자식 타입 형변환 : 다운캐스팅
	CParent* pChild = new CChild;

	delete pChild;
	
	return 0;

}