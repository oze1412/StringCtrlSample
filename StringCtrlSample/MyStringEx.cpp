#include "pch.h"
#include "MyStringEx.h"

CMyStringEx::CMyStringEx()
{
}

CMyStringEx::~CMyStringEx()
{
}

int CMyStringEx::Find(const char* pszParam)
{
	if (pszParam == NULL || GetString() == NULL)
		return -1;

	const char* Finder = strstr(GetString(), pszParam);
	
	if (Finder != NULL)
		return Finder - GetString();

	return -1;
}


void CMyStringEx::OnSetString(char* pszData, int nLength)
{
	if (strcmp(pszData, "개들의아들") == 0)
		strcpy_s(pszData, sizeof(char) * (nLength + 1), "*착한아들*");
}
