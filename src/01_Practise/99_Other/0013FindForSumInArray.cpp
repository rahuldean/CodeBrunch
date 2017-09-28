// http://www.geeksforgeeks.org/write-a-c-program-that-given-a-set-a-of-n-numbers-and-another-number-x-determines-whether-or-not-there-exist-two-elements-in-s-whose-sum-is-exactly-x/

#include <iostream>
#include <unordered_map>
using namespace std;
void GetPair(int collection[], int collectionSize, int sumToFind, int& val1, int& val2){
	std::unordered_map<int, int> hashTable;

	for(int i = 0; i < collectionSize; i++){
		std::unordered_map<int,int>::const_iterator it;
		it = hashTable.find(sumToFind - collection[i]);
		if(it != hashTable.end()){
			val1 = collection[i];
			val2 = it->first;
			return;
		} else {
			hashTable.insert(std::make_pair(collection[i], 0));
		}
	}
}

int main()
{
	cout << "Play" << endl;
	int collection[] = {5,8,2,1,-4,6};

	int val1=0, val2=0;
	GetPair(collection, 6, -3, val1, val2);
	cout << val1 << " " << val2 <<endl;

	return 0;
}
