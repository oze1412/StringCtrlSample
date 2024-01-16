#pragma once
class CMyString
{
	// ���ڿ� ������ ���� ���� �Ҵ��� �޸𸮸� ����Ű�� ������
	char* m_pszData;
	
	// ����� ���ڿ��� ����
	int m_nLength;

public:

	// ������
	CMyString();
	explicit CMyString(const char* pszData);
	~CMyString();

	CMyString(const CMyString& rhs);
	CMyString(CMyString&& rhs);

	// ������
	operator char*(void) const; 
	CMyString& operator=(const CMyString& rhs);
	CMyString operator+(const CMyString& rhs);
	CMyString& operator+=(const CMyString& rhs);
	char operator[](int nIndex) const;
	char& operator[](int nIndex);
	int operator==(const CMyString& rhs);
	int operator!=(const CMyString& rhs);
	// ��Ÿ �Լ�
	int SetString(const char* pszParam);
	const char* GetString() const;
	int GetLength() const;
	int Append(const char* pszParam);

	void Release();

	// ���� �Լ�
	virtual void OnSetString(char* pszData, int nLength);

	// friend �Լ�
	friend CMyString operator+(const char* pszParam, const CMyString& strParam);
};

