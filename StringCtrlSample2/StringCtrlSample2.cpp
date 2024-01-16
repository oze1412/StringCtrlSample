#include "pch.h"
#include "MyStringEx.h"

int main()
{
	CMyStringEx strLeft("Hello"), strRight("World");
	cout << strLeft + strRight << endl;

	return 0;
}
