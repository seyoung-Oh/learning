#include <iostream>
using namespace std;

int main()
{
	int year;
	int leapyear = 0;
	cin >> year;

	if (year % 4 == 0 && year % 100 != 0)
		leapyear = 1;

	else if(year % 400 ==0)
		leapyear = 1;


	cout << leapyear << endl;
}