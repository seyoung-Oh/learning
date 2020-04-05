#include <iostream>
#include <time.h>
using namespace std;

int main(void)
{
	/*
	*
	**
	***
	****
	*****
	*/
	for (int i = 0; i < 5; ++i) {
		for (int j = 0;j < i + 1;++j) {
			cout << "*";
		}
		cout << endl;
	}
	cout << endl;
	/*
	*****
	****
	***
	**
	*
	*/
	for (int i = 0; i < 5; ++i) {
		for (int j = 0;j < 5-i;++j) {
			cout << "*";
		}
		cout << endl;
	}
	/*
	   *
	  ***
	 *****
	*******
	 */

	for (int i = 0;i < 5;++i) {
		for (int j = 0;j < 4 - i;++j)
			cout << " ";
		for (int j = 0;j < 2 * i - 1 ;++j)
			cout << "*";
		cout << endl;
	}

	/*
	2단 3단 4단
	5단 6단 7단
	8단 9단 10단
	*/
	for (int i = 2; i < 11; i += 3) {
		for (int j = 1;j < 10;++j) {
			cout << i << " * " << j << " = " << i * j << "\t";
			cout << i+1 << " * " << j << " = " << (i+1) * j << "\t";
			cout << i+2 << " * " << j << " = " << (i+2) * j <<  endl;
		} 
		
		cout << endl;
	}
	/*
	   *
	  ***
	 *****
	*******
	 *****
	  ***
	   *
	 */
	int iCount = 0;
	int iLine = 7;
	for (int i = 0;i < 7;++i) {
		iCount = i;
		if (i > iLine / 2)
		{
			iCount = iLine - 1 - i;
		}
		for (int j = 0;j < 3 - iCount;++j) {
			cout << " ";
		}
		for (int j = 0;j <iCount * 2 + 1;++j) {
			cout << "*";
		}
		cout << endl;
	}
	
	return 0;

}
