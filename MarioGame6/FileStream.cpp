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
	//������ �̹� ��� ����ϰ� �ִٸ� �ٽ� ���� ���ϰ� �Ѵ�,
	if (m_bOpen)
		return false;

	fopen_s(&m_pFile, pFileName, pMode);

	if (!m_pFile)
		return false;

	//���� Ŀ���� ���� �ڷ� �̵���Ų��, fseek�Լ��� ���� Ŀ���� ���ϴ� ��ġ�� �̵���ų �� �ִ� �Լ��̴�,
	/*
	����° ���ڴ� 3������ �����Ѵ�.
	SEEK_SET : ������ ���� ó���� �ǹ��Ѵ�.
	SEEK_CUR : ���� ����Ű�� �ִ� ���� Ŀ���� ��ġ�� �ǹ��Ѵ�.
	SEEK_END : ������ ���� �������� �ǹ��Ѵ�.
	�ι�° ������ offset�� ���� ����Ʈ ����ŭ ����° ���ڿ��� ������ ��ġ�� �̵��ϰ� �ȴ�,
	*/
	fseek(m_pFile, 0, SEEK_END);
	//ftell : ���� Ŀ���� ��ġ�� ������ �Լ��̴�. ���� Ŀ���� ���� ���������� �̵����ױ� ������ ftell�� �̿��ؼ� ���� Ŀ���� ��ġ�� ������ �� ���� ũ�Ⱑ �ȴ�.
	m_iFileSize = ftell(m_pFile);

	//���� ũ�⸦ ���� �Ŀ� ���� ������ �ٽ� �̵�
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
	//������ �������� ���� ���¶�� �а� ���⸦ �� �� ����.
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

	while (feof(m_pFile) == 0)//end of file ���� Ŀ���� ������ ���� �����ߴ����� üũ ������ ���� �������� �ʾ��� ��� 0 �����ϰ� ���ϰ�� 0�� �ƴ� �� ����
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

	char* pBuffer = new char[iSize + 1];

	*(pBuffer + iSize) = '\n';
	//pBuffer[iSize] = '\n';

	fwrite(pBuffer, iSize+1, 1, m_pFile);

	delete[] pBuffer;
}
