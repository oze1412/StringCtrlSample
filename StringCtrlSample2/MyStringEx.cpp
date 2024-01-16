#include "pch.h"
#include "MyStringEx.h"

CMyStringEx::CMyStringEx()
{
}

CMyStringEx::~CMyStringEx()
{
}

CMyStringEx::CMyStringEx(const char* pszParam) :
	CMyString(pszParam)
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

int CMyStringEx::SetString(const char* pszParam)
{
	if (!strcmp(pszParam, "¸Û¸ÛÀÌ¾Æµé"))
		return CMyString::SetString("ÂøÇÑ »ç¶÷");
	else
		return CMyString::SetString(pszParam);
}