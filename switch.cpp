#include <iostream>



using namespace std;



enum NUM

{

	NUM_0 = 10, // 아무것도 부여하지 않을 경우 0부터 1씩 차례로 값이 부여된다.

	NUM_1,

	NUM_2 = 0x0010,

	NUM_3

};



#define NUM_4 4



int main() {



	int iNumber = 0;

	cout << "숫자를 입력하세요 : ";

	cin >> iNumber;

	switch (iNumber) {

	case NUM_1:

		cout << "입력한 숫자는 1입니다 ." << endl;

		break;

	case NUM_2:

		cout << "입력한 숫자는 2입니다 ." << endl;

		//break가 없으면 밑의 case도 강제로 실행된다.

	case NUM_3:

		cout << "입력한 숫자는 3입니다 ." << endl;

		break;

	case NUM_4:

		cout << "입력한 숫자는 4입니다 ." << endl;

		break;

	default:

		cout << "그 외의 숫자입니다." << endl;

		break;

	}

	NUM eNum = (NUM)10;

	cout << sizeof(NUM) << endl;

	cout << typeid(eNum).name() << endl;



	iNumber = 0;

	while (iNumber < 10) {

		cout << iNumber << endl;

		++iNumber;



		if (iNumber == 4)

			break;

	}





	return 0;

}