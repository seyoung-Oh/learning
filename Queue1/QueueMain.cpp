#include <iostream>
#include "Queue.h"

using namespace std;

int main()
{
	CQueue<int> queue;

	for (int i = 0;i < 100;++i)
	{
		queue.push(i + 1);
	}

	while (!queue.empty())
	{
		cout << queue.pop() << endl;
	}
	return 0;
}