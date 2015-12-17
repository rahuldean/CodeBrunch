#include <iostream>
using namespace std;

char* IndexToColumnResolver(int index);

int main(){
	cout << IndexToColumnResolver(702) <<endl;
	return 0;
}

char* IndexToColumnResolver(int index){

	// mapping Z -> 0 as remainder of 0 indicates a Z
	const char* alphabet = "ZABCDEFGHIJKLMNOPQRSTUVWXY";

	char* buff = new char(25); // to hold the resolved column name
	int len = 0; // to track buff string length

	while(index > 0){

		// Use remainder to map to the alphabet
		int rem = index % 26;

		*++buff = alphabet[rem];
		len++;

		// slicing the index one by one towards left
		index = (rem == 0) ? (index / 26) - 1 : (index / 26);
	}

	// set the terminal
	*++buff = '\0';

	// restore the initial state of buff
	while(len--)
		--buff;

	// reverse the buff contents as we sliced from right to left
	char *p = buff, *s = buff + strlen(buff) - 1;
	    while (p < s) {
	        char tmp = *p;
	        *p++ = *s;
	        *s-- = tmp;
	    }
	return buff;
}