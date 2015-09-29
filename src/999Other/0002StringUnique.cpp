#include <iostream>
using namespace std;

bool isUnique(char*);

/*
Test cases
*/
void passUniqueString();
void passNotUniqueString();
void passSignedUniqueInt();
void passNull();
void passUniqueStringWithSpaces();
void passNotUniqueStringWithSpaces();
int main()
{
	passUniqueString();
	passNotUniqueString();
	passSignedUniqueInt();
	passNull();
	passUniqueStringWithSpaces();
	passNotUniqueStringWithSpaces();
	return 0;
}

/*
O(n), uses extra space and maps each character to an index (asci value of the char) in it
*/
bool isUnique(char* str){
	if (str == NULL)
		return false;

	bool dirty[200] = { false };
	int i = 0;
	while (str[i++] != '\0')
	{
		char current = str[i];
		if (dirty[current])
		{
			return false;
		}

		dirty[current] = true;
	}

	return true;
}

/*
Test cases
*/
void passUniqueString()
{
	cout << (isUnique("abcd") == true ? "Unique" : "not unique") << endl;
}
void passNotUniqueString()
{
	cout << (isUnique("abcdcccc") == true ? "Unique" : "not unique") << endl;
}
void passSignedUniqueInt()
{
	cout << (isUnique("-123") == true ? "Unique" : "not unique") << endl;
}
void passNull()
{
	cout << (isUnique(NULL) == true ? "Unique" : "not unique") << endl;
}

void passUniqueStringWithSpaces()
{
	cout << (isUnique("ABC def") == true ? "Unique" : "not unique") << endl;
}
void passNotUniqueStringWithSpaces()
{
	cout << (isUnique("ABC abc cde") == true ? "Unique" : "not unique") << endl;
}
