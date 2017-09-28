#include <iostream>
using namespace std;
bool validPositiveValue(); // ex:2
bool invalidNegativeValue(); // ex: -2
bool outOfRangeValue(); // ex: 2001
bool notAnIntegerValue(); // ex: abcd
void pass(char* message);
void fail(char* message);
void makeStairCase(int height);
void makeStairCase(char* height);
int main()
{

	if (validPositiveValue())
		pass("validPositiveValue");
	else
		fail("validPositiveValue");

	if (invalidNegativeValue())
		pass("invalidNegativeValue");
	else
		fail("invalidNegativeValue");

	if (outOfRangeValue())
		pass("outOfRangeValue");
	else
		fail("outOfRangeValue");

	if (notAnIntegerValue())
		pass("notAnIntegerValue");
	else
		fail("notAnIntegerValue");
	return 0;
}

bool validPositiveValue()
{
	try	
	{
		makeStairCase(10);
		return true;
	}
	catch (exception &ex)
	{
		cout << ex.what() << endl;
		return false;
	}
}
bool invalidNegativeValue()
{
	try
	{
		makeStairCase(-10);
		return false;
	}
	catch (exception &ex)
	{
		cout << ex.what() << endl;
		return true;
	}
}
bool outOfRangeValue()
{
	try
	{
		makeStairCase(2001);
		return false;
	}
	catch (exception &ex)
	{
		cout << ex.what() << endl;
		return true;
	}
}
bool notAnIntegerValue()
{
	try
	{
		makeStairCase("abc");
		return false;
	}
	catch (exception &ex)
	{
		cout << ex.what() << endl;
		return true;
	}
}
void pass(char* message)
{
	cout << message << " Passed" << endl;
}
void fail(char* message)
{
	cout << message << " Failed" << endl;
}

void makeStairCase(int height)
{
	if (height < 1 || height > 2000)
		throw runtime_error("out of range");

	// print height-row space + row x '#'
	for (int row = 1; row <= height; row++)
	{
		for (int spaceRepeater = height - row; spaceRepeater > 0; spaceRepeater--)
			cout << " ";

		for (int repeater = 0; repeater < row; repeater++)
			cout << "#";

		cout << endl;
	}
}

void makeStairCase(char* height)
{
	throw runtime_error("invalid height, only integers between 1 & 2000 inclusive are allowed");
}