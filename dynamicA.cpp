#include <iostream>

using namespace std;

int main()
{
	/*
	동적할당 : 메모리 생성을 원하는 시점에 할 수 있는 기능이다.
	메모리 영역중 힙영역에 공간이 할당된다. 힙의 특성상 메모리를 해제하기 전까지 계속 남아있다.
	동적할당을 하고 메모리를 해제하지 않으면 사용하지는 않지만 공간은 계속 잡혀있음
	해당 공간은 다른 곳에 사용이 불가능
	이런 현상을 메모리 릭이라고 한다.

	new 키워드 이용해서 사용한다
	c언어는 malloc()함수를 이용해서 사용

	new, malloc 모두 힙영역에 메모리 공간 할당, 해당 메모리의 주소를 반환해준다.
	*/
	int* pNumber = new int;

	*pNumber = 100;

	delete pNumber; // delete 키워드를 이용해서 동적할당한 메모리를 해제할 수 있다.

	/*
	동적 배열 할당 방법 : new type [개수];
	*/

	int* pArray = new int[100];

	pArray[1] = 300;


	delete[] pArray; // 동적 배열을 지울 때는 []사용하기

	return 0;
}