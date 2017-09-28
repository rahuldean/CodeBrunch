#include <iostream>
using namespace std;
void MergeSort(long* collection, long collectionSize);
void Merge(long* left, long leftSize, long* right, long rightSize, long* collection, long collectionSize);

void Display(long* collection, long collectionSize){
	for (long i = 0; i < collectionSize; i++)
		cout << collection[i] << " ";
	cout << endl;
}

int main()
{
	long tc;
	cin >> tc;
	for (long i = 0; i < tc; i++){
		long collectionSize;
		cin >> collectionSize;

		long* collection = new long[collectionSize];
		for (long i = 0; i < collectionSize; i++){
			cin >> collection[i];
		}

		MergeSort(collection, collectionSize);
		Display(collection, collectionSize);

		delete[] collection;
	}
	return 0;
}

void MergeSort(long* collection, long collectionSize){
	if (collectionSize < 2)
		return;

	long mid = collectionSize / 2;

	// create left[]
	long* left = new long[mid];

	// create right[]
	long* right = new long[collectionSize - mid];

	// populate left
	for (long i = 0; i < mid; i++)
		left[i] = collection[i];

	// populate right
	for (long i = mid; i < collectionSize; i++)
		right[i - mid] = collection[i];

	MergeSort(left, mid);
	MergeSort(right, collectionSize - mid);

	// Do merge

	Merge(left, mid, right, collectionSize - mid, collection, collectionSize);

	delete[] left;
	delete[] right;
}

void Merge(long* left, long leftSize, long* right, long rightSize, long* collection, long collectionSize){

	long leftIterator = 0, rightIterator = 0, collectionIterator = 0;

	while (leftIterator < leftSize
		&& rightIterator < rightSize){
		if (left[leftIterator] <= right[rightIterator])
			collection[collectionIterator++] = right[rightIterator++];
		else
			collection[collectionIterator++] = left[leftIterator++];
	}

	while (leftIterator < leftSize)
		collection[collectionIterator++] = left[leftIterator++];

	while (rightIterator < rightSize)
		collection[collectionIterator++] = right[rightIterator++];

}
