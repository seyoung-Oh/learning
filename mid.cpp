#include <iostream>
using namespace std;

int main()
{
	int A[3];
	int temp;
	cin >> A[0] >> A[1] >> A[2];

	for (int j = 0; j < 2; ++j)
	{
		for (int i = 0; i < 2; ++i)
		{
			if (A[i] >= A[i + 1])
			{
				temp = A[i];
				A[i] = A[i + 1];
				A[i + 1] = temp;
			}
		}
	}

	cout << A[1] << endl;
	
	return 0;
}