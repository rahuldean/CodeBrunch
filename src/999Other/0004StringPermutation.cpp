#include <iostream>
using namespace std;
/*
 * Given two strings, find if one is the permutation of the other 
 */

/*
 * arg: mainString: The primary string 
 * arg: permString: The string to be checked if it is a permutation of the mainString
 * ret: true if permString is the permutation of mainString else false.
 */
bool isPermutant(char* mainString, char* permString);
const int ENC_LENGTH = 256; // Character encoding length;
int main()
{
	cout << isPermutant("abad\0", "abac\0");
	return 0;
}

bool isPermutant(char* mainString, char* permString)
{
	//int* charCounter = new int[ENC_LENGTH];
	int charCounter[256] = { 0 };
	// strings can't be null
	if (mainString == NULL || permString == NULL)
	{
		cout << ((mainString == NULL) ? "mainString can't be NULL" : "")
			<< ((permString == NULL) ? "permString can't be NULL" : "")
			<< endl;
		return false;
	}

	// strings can't be empty
	if (strlen(mainString) == 0 || strlen(permString) == 0)
	{
		cout << ((strlen(mainString) == 0) ? "mainString can't be empty " : "")
			<< ((strlen(permString) == 0) ? "permString can't be empty " : "")
			<< endl;
		return false;
	}

	// if lengths are not same then can't be a permutant
	if (strlen(mainString) != strlen(permString))
	{
		cout << "mainString & permString are not of same length" << endl;
		return false;
	}

	// count the char instances of mainString
	char* temp_mainString = mainString;

	while (*temp_mainString)
	{
		try {
			charCounter[*temp_mainString]++;
			cout << *temp_mainString << "  " << charCounter[*temp_mainString] << endl;
			*temp_mainString++;
		}
		catch (runtime_error &e)
		{
			cout << e.what();
		}
			
	}

	// check each character of permString
	while (*permString)
	{
		if (--charCounter[*permString++] < 0)
		{
			return false;
		}
	}

	delete[]charCounter;
	return true;
}