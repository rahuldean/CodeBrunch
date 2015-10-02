#include <iostream>
using namespace std;

class StringCompresser
{
private:
	char* string_to_compress;
public:
	StringCompresser(char* string_to_compress);
	~StringCompresser();
	char* Compress();
	int GetLength();
};

StringCompresser::StringCompresser(char* string_to_compress)
{
	this->string_to_compress = string_to_compress;
}

StringCompresser::~StringCompresser()
{

}

char* StringCompresser::Compress()
{
	return "";
}

int StringCompresser::GetLength()
{
	return strlen(this->string_to_compress);
}
int main()
{
	StringCompresser sc = StringCompresser("asdasdas");
	cout << sc.GetLength();
	return 0;
}