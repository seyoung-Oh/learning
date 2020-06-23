#include <iostream>

using namespace std;

/*
상속 : 클래스는 서로간에 부모, 자식관계를 형성 할 수 있다,
자식 클래스는 부모클래스의 멤버들을 사용할 수 있다.

부모클래스에서 public이나 protected는 사용가능
private 멤버는 자식에서도 사용이 불가능하다.

상속의 형태 : public, private상속이 있음

다형성 : 상속관계에 있는 클래스간에 서로 형변환이 가능한 성질을 말한다.

가상함수 : 오버라이딩, 함수 재정의 기능
멤버함수 앞에 virtual 키워드를 붙이면 가상함수가 된다.
virtual void Output()함수가 있다면 자식함수에서 가상함수를 재정의 할 수 있음
재정의는 함수 이름과 인자가 완전히 똑같아야함

가상함수를 가지고 있는 클래스는 내부적으로 가상함수 테이블이라는 것을 생성한다
가상함수 테이블은 가상함수들의 메모리 주소를 저장하는 테이블이다.

가상함수 호출시 가상함수 테이블을 참조해서 메모리 주소를 확인한다.
가상함수 테이블에 CChild output주소가 들어가 있다면 그 주소의 함수를
호출해주는 개념이다.

소멸자도 가상함수로 만들 수 있다.
부모의 소멸자는 가상함수로 만들어주기
*/
class CParent
{
public:
	CParent()
	{
		cout << "CParent 생성자" << endl;
	}
	virtual ~CParent()
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
	virtual void Output()
	{
		cout << "Parent Output Function" << endl;
	}

	//순수 가상함수 : 가상함수 뒤에 =0을 붙여주면 해당 가상함수는 
	//순수 가상함수가 됨. 구현부분이 존재하지 않음.
	//순수 가상함수를 가지고 있는 클래스를 추상 클래스라고 함
	// 추상클래스는 인스턴스(객체)생성이 불가능함
	//순수 가상함수는 자식에서 반드시 재정의해야함
	virtual void OutputPure() = 0;
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
	virtual ~CChild()
	{
		cout << "CChild 소멸자" << endl;
	}

protected:
	int m_iD;

public:
	void ChildOutput()
	{
		cout << " Child Output Function " << endl;
	}
	virtual void Output()
	{
		CParent::Output();
	  	cout << "Child Output Function" << endl;
	}
	virtual void OutputPure()
	{
	}
};
class CChild1 : public CParent
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
public:
	virtual void OutputPure()
	{

	}
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
	CParent* pParent = new CChild;
	CChild1 child1;

	//CParent클래스는 추상클래스이므로 객체 생성 불가능
	//CParent parent;
	//CParent* pParent1 = new CChild1;
	//CParent* pParent2 = new CChildChild;
	//CParent* pParentArr[2] = {};

	//pParentArr[0] = new CChild;
	//pParentArr[1] = new CChildChild;
	// 아래 두 클래스는 모두 CParent 클래스를 상속받고 있다.
	//그러므로 pParent를 두 타입 모두 다운캐스팅 가능하다.
	//그런데 pParent는 CChild로 할당한 객체이다.
	// 이 객체를 CChild1 타입으로 다운캐스팅 하여 넣어주게 되면 
	// 이 객체를 사용할 때 문제가 발생할 수 있다, 왜냐면 애초에 생성한 객체가 아닌 다른타입으로 변환됐기 때문이다.
	CChild* pChild = (CChild*)pParent;
	CChild1* pChild1 = (CChild1*)pParent;
	
	//CChild class에 있는 Childoutput함수에 접근할 수 없다, 왜냐하면 pParent는 포인터 타입이라 자식멤버 접근 불가
	//자식멤버 접근하려면 형변환 해줘야 함
	//((CChild*)pParent)->ChildOutput();
	//pParent->CParent::Output();
	pParent->Output();

	//현재 delete를 하게 되면 CChild소멸자->CParent소멸자가 호출되어야 하는데
	//지금은 CParent 소멸자만 호출된다.
	//근본적으로 CParent 는 CParent포인터 타입이다
	//그래서 Cchild소멸자 호출 X
	delete pParent;
	//delete pParent2;

	for (int i = 0;i < 2;++i)
	{
		//delete pParentArr[i];
	}

	return 0;

}