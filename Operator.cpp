#include <iostream>
#include <functional>
using namespace std;

/*
�Լ������� : �Լ��� �޸� �ּҸ� �����ϱ� ���� ������ ������ ������ �� �ִ�.
�����Լ��� ��� �Լ����� �� �Լ��� �޸� �ּ��̴�.
�Լ������� ���� ��� : ��ȯŸ�� (*������ ������)(����Ÿ��); �� ���·� ����
*/

int Sum(int a, int b)
{
	return a + b;
}
int OutSum(int a, int b)
{
	cout << a - b << endl;
	return a - b;
}
float TestFunc(float a)
{
	cout << a << endl;
	return a;
}
void Output()
{
	cout << "Output Function" << endl;
}

class CHanzo
{
public :
	CHanzo()
	{
		m_iTest = 10;
	}
	~CHanzo()
	{

	}
public :
	int m_iTest;

public:
	void Output()
	{
		cout << "Hanzo" << endl;
		//this->�� ���� �����ϴ�.
		cout << "Test : " << this->m_iTest << endl;
	}
};

typedef struct _tagPoint
{
	int x;
	int y;

	_tagPoint() :
		x(0),
		y(0)
	{

	}
	_tagPoint(int _x, int _y) :
		x(_x),
		y(_y)
	{

	}
	_tagPoint(const _tagPoint* pt)
	{
		// ���� ���縦 �Ѵ�, �̷��� ���� ��� this �� �ڱ� �ڽ��� �������̰�
		//*�� �ٿ��� �ڱ� �ڽ��� �������Ͽ� ��� �����͸� �����ϰ� �Ѵ�.
		*this = pt;
	}

	void operator << (const _tagPoint& pt)
	{
		x = pt.x;
		y = pt.y;
	}
	_tagPoint operator +(const _tagPoint &pt)
	{
		_tagPoint result;
		result.x = x + pt.x;
		result.y = y + pt.y;
		return result;
	}

	void operator >> (_tagPoint& pt)
	{
		pt.x = x;
		pt.y = y;
	}

	_tagPoint operator +(int a)
	{
		_tagPoint pt;
		pt.x = x + a;
		pt.y = y + a;
		return pt;
	}

	void operator +=(int a)
	{
		x += a;
		y += a;
	}
	void operator ++()
	{
		x++;
		y++;
	}
	void operator --()
	{
		x--;
		y--;
	}
}POINT, *PPOINT;
int main()
{
	int(*pFunc)(int, int) = Sum;

	cout << pFunc(10, 20) << endl;

	pFunc = OutSum;

	OutSum(10, 20);

	//pFunc = Output;

	void(*pFunc1)() = Output;

	pFunc1();

	CHanzo hanzo1, hanzo2;

	//this ������ : Ŭ���� �ȿ��� this�� ����� ��� �ش� ��ü�� �޸� �ּҰ� �ȴ�. �ڱ� �ڽ��� �������̴�.
	//��� �Լ��� ȣ���� �� this ������
	hanzo1.m_iTest = 100;
	hanzo2.m_iTest = 200;

	hanzo1.Output();
	hanzo2.Output();

	//����Լ� ������ ����� ������ ���� �̸� �տ� Ŭ������ ::�� �ٿ��ش�.
	void(CHanzo::*pFunc2)() = &CHanzo::Output;

	//(*pFunc2)();

	//hanzo1.(*pFunc2)();
	(hanzo1.*pFunc2)();
	/*
	function ����� c++ 11���� �������� �Լ������͸� ����, ����� ������ �ʰ� ���� �ּҸ� �����ؼ� ȣ������ �� �ֵ��� ����� �ִ� ����̴�
	function<��ȯŸ��(����Ÿ��)> ������; �� ���·� �����Ѵ�.
	*/
	function<void()> func;
	function<void()> func1;
	//bind�̿��ؼ� �Լ��� �����ش�.
	func = bind(Output);
	func1 = bind(&CHanzo::Output, &hanzo2);

	cout << "============== Functional ===============" << endl;

	func();
	func1();

	function<int(int, int)> func3;
	function<float(float)> func4;

	//�Լ��� ���ڰ� ���� ��� placeholders�� �̿��ؼ� ������ ������ ������ �� �ִ�. �Ʒ�ó�� 2,1�� ������ ������ �ٲ�
	func3 = bind(OutSum, placeholders::_2, placeholders::_1);

	func3(10, 20);

	func4 = bind(TestFunc, placeholders::_1);
	func4(3.14f);

	cout << " =================== Point ==================== " << endl;

	POINT pt1(10, 20), pt2(30, 40), pt3;

	//POINT ����ü�� +�����ڰ� operartor�� ������ �Ǿ��ִ�. �׷��� +������ �����ϰ� �ǰ� pt1�� +������ �Լ���ȣ�����ִ� ���� pt2�� ���ڷ� �Ѱ��ش�.
	pt3 = pt1 + pt2;

	pt3 << pt1;

	pt2 >> pt3;

	pt3 = pt1 + 1000;

	pt3 += 2000;

	++pt3;

	--pt3;

	cout << "x : " << pt3.x << "\ty : " << pt3.y << endl;

	return 0;
}