#include "pch.h"
#include "MyString.h"
#include <string>

// 생성자
CMyString::CMyString()
	: m_pszData(NULL)
	, m_nLength(0)
{

}

CMyString::CMyString(const char* pszParam)
	: m_pszData(NULL)
	, m_nLength(0)
{
	SetString(pszParam);
}

CMyString::~CMyString()
{
	Release();
}


CMyString::CMyString(const CMyString& rhs)
	: m_pszData(NULL)
	, m_nLength(0)
{
	this->SetString(rhs.GetString());
}

CMyString::CMyString(CMyString&& rhs)
	: m_pszData(NULL)
	, m_nLength(0)
{
	cout << "CMyString 이동 생성자 호출" << endl;

	// 얕은 복사 수행해도 상관 X, 원본은 곧 소멸하기 때문
	m_pszData = rhs.m_pszData;
	m_nLength = rhs.m_nLength;

	// 원본 임시 객체 멤버 초기화, 절대로 해제 X
	rhs.m_pszData = NULL;
	rhs.m_nLength = 0;
}

// 연산자
CMyString::operator char*(void) const
{
	return m_pszData;
}

CMyString& CMyString::operator=(const CMyString& rhs)
{
	if(this != &rhs)
		SetString(rhs.GetString());

	return *this;
}

CMyString CMyString::operator+(const CMyString& rhs)
{
	CMyString temp(m_pszData);

	temp.Append(rhs.GetString());

	return temp;
}

CMyString& CMyString::operator+=(const CMyString& rhs)
{
	Append(rhs.GetString());

	return *this;
}

char CMyString::operator[](int nIndex) const
{
	return m_pszData[nIndex];
}

char& CMyString::operator[](int nIndex)
{
	return m_pszData[nIndex];
}

int CMyString::operator==(const CMyString& rhs)
{
	if (m_pszData != NULL && rhs.m_pszData != NULL)
		if (strcmp(m_pszData, rhs.m_pszData) == 0)
			return 1;

	return 0;
}

int CMyString::operator!=(const CMyString& rhs)
{
	if (m_pszData != NULL && rhs.m_pszData != NULL)
		if (strcmp(m_pszData, rhs.m_pszData) == 0)
			return 0;

	return 1;
}



// 기타 함수
int CMyString::SetString(const char* pszParam)
{
	Release();

	if (pszParam == NULL)	return 0;

	int nLength = strlen(pszParam);
	if (nLength == 0)		return 0;

	m_pszData = new char[nLength + 1];
	if (m_pszData == NULL)	return 1;

	strcpy_s(m_pszData, nLength + 1, pszParam);
	m_nLength = nLength;

	OnSetString(m_pszData, m_nLength);

	return m_nLength;
}

const char* CMyString::GetString() const
{
	return m_pszData;
}

int CMyString::GetLength() const
{
	return m_nLength;
}

int CMyString::Append(const char* pszParam)
{
	if (pszParam == NULL)
		return 0;

	int nLenParam = strlen(pszParam);

	if (nLenParam == 0)
		return 0;

	if (m_pszData == NULL)
	{
		SetString(pszParam);

		return m_nLength;
	}

	int nLenCur = m_nLength;

	char* pszResult = new char[nLenCur + nLenParam + 1];

	strcpy_s(pszResult, sizeof(char) * (nLenCur + 1), m_pszData);
	strcpy_s(pszResult + (sizeof(char) * nLenCur), sizeof(char) * (nLenParam + 1), pszParam);

	Release();

	m_pszData = pszResult;
	m_nLength = nLenCur + nLenParam;

	return m_nLength;
}

void CMyString::Release()
{
	if (m_pszData != NULL)
		delete[] m_pszData;

	m_pszData = NULL;
	m_nLength = 0;
}


void CMyString::OnSetString(char* pszData, int nLength)
{
}

// friend 함수
CMyString operator+(const char* pszParam, const CMyString& strParam)
{
	CMyString strResult(pszParam);
	strResult.Append(strParam.m_pszData);

	return strResult;
}