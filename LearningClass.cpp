#include <iostream>

using namespace std;

/*
객체 : 모든 사물을 의미함. 각 변수들도 객체 취급, 객체지향 프로그래밍을 지원하기 위해 제공되는 수단은 class
class 클래스명 {};형태로 선언 , 코드블럭 안에 멤버변수 넣어줌 함수도 멤버로 만들 수 있음
클래스의 네가지 속성
캡슐화 : 클래스 안에 속하는 여러 변수 혹은 함수를 하나의 클래스로 묶어주는 기능을 말한다.
은닉화 : 클래스 안에 속하는 변수 혹은 함수를 내가 원하는 부분만 외부에 공개하고 외부에 공개하지 않을 수 있다.
	- public :클래스 내부와 외부에서 모두 접근 가능한 방법
	- protected : 클래스 외부에서는 접근이 불가능하고 자기 자신 내부나 자식 클래스 내부에서는 접근이 가능한 키워드이다. 
	- private : 자기자신 내부에서만 접근이 가능하고 외부나 자식 내부에서는 접근이 불가능한 방법이다.
상속성 : 클래스는 클래스와 클래스간에 부모, 자식 관계를 형성 할 수 있다. 자식 클래스는 부모 클래스의 멤버를 물려받아 자신의 것처럼 사용할 수 있다. private멤버는 접근 불가
다형성 : 부모 자식 관계로 상속관계가 형성되어 있는 클래스간에 서로 형변환이 가능한 성질을 말한다.
*/
class CTracer
{
	//클래스 멤버변수를 선언할 때 m_붙여주면 편함
	char m_strName[32];

public:
	int m_iAttack;
	int m_iHP;

private:
	int m_iFlash;

private:
	int m_iBack;
public:
	void Output()
	{
		cout << "Tracer Output" << endl;
	}
};
int main()
{
	CTracer tr1;
	//main안에는 클래스 외부이기 때문에 public만 접근 가능
	tr1.Output();
	return 0;
}