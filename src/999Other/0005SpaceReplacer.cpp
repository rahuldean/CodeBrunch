#include <iostream>
using namespace std;

char* replaceSpaces(char* text);
int countSpaces(char* text);

void passValidString();
void passNULL();
void passEmpty();

int main()
{
	passValidString();
	passNULL();
	passEmpty();

	return 0;
}

char* replaceSpaces(char* text)
{
	if (text == NULL)
		return "";

	if (strlen(text) == 0)
		return "";

	int spaces = countSpaces(text);
	size_t requiredSize = strlen(text) + 2 * spaces;
	//cout << "Required new size = " << requiredSize << endl;
	char* replacedText = new char[requiredSize];
	
	for (size_t i = 0; i < strlen(text); i++)
	{
		// copy till you encounter a space;
		if (text[i] != ' ')
		{
			*replacedText++ = text[i];
		}
		else
		{
			*replacedText++ = '%';
			*replacedText++ = '2';
			*replacedText++ = '0';			
		}
	}
	// since replacedText is now at the end, rollback to first position
	for (size_t i = requiredSize;i > 0; i--)
	{
		*(--replacedText);
	}
	//delete[]replacedText;
	//cout << strlen(finalString) << endl;
	return replacedText;
}

int countSpaces(char* text)
{
	if (text == NULL)
		return 0;

	int count = 0;
	while (*text)
	{
		if (*text == ' ')
			count++;

		*text++;
	}

	return count;
}

void passValidString()
{
	char* output = replaceSpaces("abcd efg 123 4567    90a");
	if (strcmp(output , "abcd%20efg%20123%204567%20%20%20%2090") == 0)
		cout << "[PASS] passValidString()" << endl;
	else
	{
		cout << "[FAIL] passValidString()" << endl;
		cout << "Expected output :" << endl;
		cout << "abcd%20efg%20123%204567%20%20%20%2090" << endl;
		cout << "Found output : " << endl;
		cout << output << endl;
	}

}
void passNULL()
{
	string output = replaceSpaces(NULL);
	if (output == "")
		cout << "[PASS] passNULL()" << endl;
	else
		cout << "[FAIL] passNULL()" << endl;
}
void passEmpty()
{
	string output = replaceSpaces("");
	if (output == "")
		cout << "[PASS] passEmpty()" << endl;
	else
		cout << "[FAIL] passEmpty()" << endl;
}
