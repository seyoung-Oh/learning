#include <iostream>
#include "Queue.h"

using namespace std;

int main()
{

	//int iNum = 100;
	//int iArray[iNum] = {};

	CQueue<int> queue;

	for (int i = 0;i < 100;++i)
	{
		queue.push(i + 1);
	}

	while (!queue.empty())
	{
		cout << queue.pop() << endl;
	}

	CCircleQueue<int, 10> queue1;
	CCircleQueue<int> queue2;
	CCircleQueue<int, 300> queue3;

	for (int i = 0;i < 10;++i)
	{
		queue1.push(i + 1);
	}
	cout << "3개 pop" << endl;

	for (int i = 0; i < 3; ++i)
	{
		cout << queue1.pop() << endl;
	}

	cout << "4개 push" <<endl;
	for (int i = 0; i < 4; ++i)
	{
		queue1.push(i + 1);
	}

	cout << "전부 pop" << endl;
	while (!queue1.empty())
	{
		cout << queue1.pop() << endl;
	}
	return 0;
}