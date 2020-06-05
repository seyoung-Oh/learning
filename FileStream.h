#pragma once


#include "value.h"

class CFileStream
{
public:
	CFileStream();
	~CFileStream();

private:
	FILE * m_pFile;
	int m_iFileSize;
	bool m_bOpen;


public:
	bool Open(char* pFileName, char* pMode);
	bool Close();
};

