#include <iostream>
using namespace std;

void SpiralPrint(int matrix[4][4]);

int main(){
	int arr[4][4] = {
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12},
		{13,14,15,16}
	};

	SpiralPrint(arr);
	return 0;
}

void SpiralPrint(int matrix[4][4]){
	int  l =0, r = 3;
	int t= 0, b = 3;
	int dir = 0; // 0 - top 1 - right, 2 - bottom, 3 - left

	while( l <= r && t <= b){
		// print top
		if(dir == 0){
			for(int i = l; i <=r; i++){
				cout << matrix[t][i] << " ";
			}
			t++;
		}


		// print right
		if(dir == 1){
			for(int i = t; i <=b; i++){
				cout << matrix[i][r] << " ";
			}
			r--;
		}

		// print bottom
		if(dir == 2){
			for(int i = r; i >= l; i--){
				cout << matrix[b][i] << " ";
			}
			b--;
		}

		// print left
		if(dir == 3){
			for(int i = b; i >= t; i--){
				cout << matrix[i][l] << " ";
			}
			l++;
		}

		dir = (dir + 1) % 4;
	}
}
