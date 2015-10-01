#include <iostream>
using namespace std;

void reverseString(char* str);

void passValidNonSpaceCharString();
void passValidSpacedCharString();
void passValidNonSpacedNumericString();
void passValidSpacedNumericString();
void passNullString();
void passEmptyString();
int main()
{
	passValidNonSpaceCharString();
	passValidSpacedCharString();
	passValidNonSpacedNumericString();
	passValidSpacedNumericString();
	passNullString();
	passEmptyString();
	return 0;
}

// Reverses a null terminated string
void reverseString(char* str)
{
	// check if string is null/empty/
	if (str == NULL)
	{
		cout << "string can't be null";
		return;
	}

	if (strlen(str) == 0)
	{
		cout << "Cant be an empty string";
	}

	// check if string has length > 1
	if (strlen(str) == 1)
	{
		cout << str;
		return;
	}

	// Implement
	char* end = str;
	while (*end)
	{
		++end;
	}
	// now *end is at '\0'
	--end;
	cout << "i am at last char = " << *end << endl;

	char temp;
	// start swapping first(*str) with last (*end) till they meet at middle
	try	{
		while (str < end)
		{
			
			temp = *str;
			cout << "temp = " << temp << endl;
			*str++ = *end;
			cout << "*str = " << *str << endl;
			*end++ = temp;
			cout << "*end = " << *end << endl;
		}

		cout << "reversed string is =" << str << endl;
	}
	catch (bad_exception &a)
	{
		cout << a.what();
	}
}

void passValidNonSpaceCharString()
{
	char* str = "abcde\0";
	reverseString(str);
}
void passValidSpacedCharString()
{
	char* str = "abcde fg hi\0";
	reverseString(str);
}
void passValidNonSpacedNumericString()
{
	char* str = "1234\0";
	reverseString(str);
}
void passValidSpacedNumericString()
{
	char* str = "12 34 56\0";
	reverseString(str);
}
void passNullString()
{
	char* str = NULL;
	reverseString(str);
}
void passEmptyString()
{
	char* str = "";
	reverseString(str);
}