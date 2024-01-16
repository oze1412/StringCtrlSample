#pragma once
#include "MyString.h"
class CMyStringEx :
    public CMyString
{
public :
    using CMyString::CMyString;

    CMyStringEx();
    ~CMyStringEx();
    CMyStringEx(const char* pszParam);
    int Find(const char* pszParam);
    int SetString(const char* pszParam);

    virtual void OnSetString(char* pszData, int nLength);
};

