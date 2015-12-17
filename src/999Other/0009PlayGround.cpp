#include <iostream>
#include <vector>
using namespace std;

void display(int mat[5][5]);
int main(){
	int mat[5][5] = {
		{ 1, 0, 1, 6, 8 }
		, { 7, 2, 0, 7, 8 }
		, { 2, 3, 6, 0, 1 }
		, { 4, 3, 9, 1, 7 }
		, { 0, 8, 5, 4, 1 }
	};

	display(mat);
	return 0;
}

void display(int mat[5][5]){
	for (size_t i = 0; i < 5; ++i)
	{
		for (size_t j = 0; j < 5; ++j){
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}
}