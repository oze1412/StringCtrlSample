#pragma once
class CMyString
{
	// 문자열 저장을 위해 동적 할당한 메모리를 가르키는 포인터
	char* m_pszData;
	
	// 저장된 문자열의 길이
	int m_nLength;

public:

	// 생성자
	CMyString();
	explicit CMyString(const char* pszData);
	~CMyString();

	CMyString(const CMyString& rhs);
	CMyString(CMyString&& rhs);

	// 연산자
	operator char*(void) const; 
	CMyString& operator=(const CMyString& rhs);
	CMyString operator+(const CMyString& rhs);
	CMyString& operator+=(const CMyString& rhs);
	char operator[](int nIndex) const;
	char& operator[](int nIndex);
	int operator==(const CMyString& rhs);
	int operator!=(const CMyString& rhs);
	// 기타 함수
	int SetString(const char* pszParam);
	const char* GetString() const;
	int GetLength() const;
	int Append(const char* pszParam);

	void Release();
};

