
#include <iostream>
#include "LinkedList.h"

using namespace std;

class CA
{
public:
	CA()
	{

	}
	~CA()
	{

	}
public:
	class CB
	{
	public:
		CB()
		{

		}
		~CB()
		{

		}
	};
};

int main()
{
	CA a;
	CA::CB b;

	CLinkedList<int> listInt;
	CLinkedList<float> listFloat;

	for (int i = 0; i < 100;++i)
	{
		listInt.push_back(i + 1);
	}

	cout << listInt.size() << endl;

	CLinkedList<int>::iterator iter;
	//위와 아래는 같음
	//CListIterator<int> iter;

	for (iter = listInt.begin();iter != listInt.end();++iter)
	{
		cout << *iter << endl;
	}

	cout << "======= reverse =======" << endl;
	CLinkedList<int>::reverse_iterator riter;

	for (riter = listInt.rbegin(); riter != listInt.rend(); ++riter)
	{
		cout << *riter << endl;
	}
 	return 0;
}
