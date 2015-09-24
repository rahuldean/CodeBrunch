#include <iostream>
using namespace std;
bool validPositiveValue(); // ex:2
bool invalidNegativeValue(); // ex: -2
bool outOfRangeValue(); // ex: 2001
bool notAnIntegerValue(); // ex: abcd
void pass(char* message);
void fail(char* message);
void makeStairCase(int height);
int main()
{
	makeStairCase(10);

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
	return false;
}
bool invalidNegativeValue()
{
	return false;
}
bool outOfRangeValue()
{
	return false;
}
bool notAnIntegerValue()
{
	return false;
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