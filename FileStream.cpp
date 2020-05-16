#include <iostream>

using namespace std;

//pp는 main 함수 안에 있는 int* 타입의 p변수의 주소를 가지게 된다
void Test(int** pp) 
{
	*pp = new int;
}

int main()
{
	//int* p = NULL;

	//p = new int; 이거랑 Test함수 호출하는것과 같은 효과

	//Test(&p);
	
	FILE* pFile = NULL;
	
	//1번 인자 : 파일의 이중포인터이다.
	//2번 인자 : 파일 경로이다. 파일이 생성되는 기준 경로는 현재 프로젝트가 있는 폴더기준. exe파일 실행시 해당 exe 파일이 있는 경로를 기준으로 생성
	//3번 인자 : 파일 모드이다. 모드는 크게 2가지로 구분된다. 읽기, 쓰기, 접근이 있고 파일 형태, txt, binary 두가지 존재
	//r : 읽기 w : 쓰기 a : 접근			t : 텍스트 파일 b : 바이너리 파일
	/*
	fopen_s(&pFile, "hot.txt", "wt");

	if (pFile != NULL)
	{
		//fwrite, fread, fputs, fgets
		const char* pText = "abcd";

		fwrite(pText, 1, 4, pFile);

		fclose(pFile);
		cout << "파일 만들기 성공" << endl;
	}
	*/
	fopen_s(&pFile, "hot.txt", "rt");
	if (pFile)
	{
		char strText[5] = {};
		fread(strText, 1, 4, pFile);
		cout << strText << endl;

		fclose(pFile);
		cout << "파일 읽기 성공" << endl;

	}

	return 0;
}