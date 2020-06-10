#include "FileStream.h"



CFileStream::CFileStream():
	m_pFile(NULL),
	m_iFileSize(0),
	m_bOpen(false)
{
}


CFileStream::~CFileStream()
{
	Close();
}

bool CFileStream::Open(char * pFileName, char * pMode)
{
	//파일을 이미 열어서 사용하고 있다면 다시 열지 못하게 한다,
	if (m_bOpen)
		return false;

	fopen_s(&m_pFile, pFileName, pMode);

	if (!m_pFile)
		return false;

	//파일 커서를 가장 뒤로 이동시킨다, fseek함수는 파일 커서를 원하는 위치로 이동시킬 수 있는 함수이다,
	/*
	세번째 인자는 3종류가 존재한다.
	SEEK_SET : 파일의 제일 처음을 의미한다.
	SEEK_CUR : 현재 가리키고 있는 파일 커서의 위치를 의미한다.
	SEEK_END : 파일의 가장 마지막을 의미한다.
	두번째 인자인 offset에 들어가는 바이트 수만큼 세번째 인자에서 지정한 위치로 이동하게 된다,
	*/
	fseek(m_pFile, 0, SEEK_END);
	//ftell : 파일 커서의 위치를 얻어오는 함수이다. 파일 커서를 가장 마지막으로 이동시켰기 때문에 ftell을 이용해서 파일 커서의 위치를 얻어오면 곧 파일 크기가 된다.
	m_iFileSize = ftell(m_pFile);

	//파일 크기를 구한 후에 가장 앞으로 다시 이동
	fseek(m_pFile, 0, SEEK_SET);

	m_bOpen = true;

	return true;
}

bool CFileStream::Close()
{
	if (!m_bOpen)
		return false;

	m_bOpen = false;

	fclose(m_pFile);
	m_pFile = NULL;
	m_iFileSize = 0;

	return true;
}

void CFileStream::Read(void * pData, int iSize)
{
	//파일이 열려있지 않은 상태라면 읽고 쓰기를 할 수 없다.
	if (!m_bOpen)
		return;

	fread(pData, iSize, 1, m_pFile);
}

void CFileStream::ReadLine(void * pData, int& iSize)
{
	if (!m_bOpen)
		return;

	char cData;
	char* pChangeData = (char*)pData;
	iSize = 0;

	while (feof(m_pFile) == 0)//end of file 파일 커서가 파일의 끝에 도달했는지를 체크 파일의 끝에 도달하지 않았을 경우 0 리턴하고 끝일경우 0이 아닌 수 리턴
	{
		fread(&cData, 1, 1, m_pFile);

		if (cData == '\n')
			break;

		pChangeData[iSize] = cData;
		++iSize;
	}
}

void CFileStream::Write(void * pData, int iSize)
{
	if (!m_bOpen)
		return;

	fwrite(pData, iSize, 1, m_pFile);
}

void CFileStream::WriteLine(void * pData, int iSize)
{
	if (!m_bOpen)
		return;

	char* pBuffer = (char*)pData;

	*(pBuffer + iSize) = '\n';

	fwrite(pData, iSize, 1, m_pFile);
}
