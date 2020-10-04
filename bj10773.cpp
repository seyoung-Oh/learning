#include <iostream>
#include <stack>
using namespace std;

int main()
{
	int k;
	stack<int> Stack;
	int num;
	int sum = 0;
	cin >> k;

	for (int i = 0;i < k;i++)
	{
		cin >> num;
		Stack.push(num);
		if (num == 0)
		{
			Stack.pop();
			Stack.pop();
		}
	}
	while(!Stack.empty())
	{
		sum += Stack.top();
		Stack.pop();
	}

	cout << sum << endl;
}