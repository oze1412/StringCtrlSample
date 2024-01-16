#include "pch.h"
#include "MyStringEx.h"

int main()
{
	CMyString b("World"), c;

	c = "Hello" + b;
	cout << c << endl;

	return 0;
}
