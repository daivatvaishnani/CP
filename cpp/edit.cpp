#include <iostream>
#include <cstdio>

using namespace std;

int maxarray(int array[], int size) {
	int max = 0;
	for(int i=0; i<size; i++) {max = (array[i] > max ? array[i] : max); }
	return max;
}

int main() {
	int cases,n,m,y,goldmax=0;
	cin >> cases;
	while(cases>0) {
		cin >> n >>m;
		int matrix[n][m];
		int goldarray[n]={0};
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				cin >> matrix[i][j];
			}
		}
		for(y=0; y<n; y++) {
			int tmpy=y,tmpx=0,gold=matrix[tmpy][tmpx];
			while(tmpx+1<m) {
				if(tmpy+1 >= n){
					if(matrix[tmpy][tmpx+1] >= matrix[tmpy-1][tmpx+1]) {
						gold += matrix[tmpy][tmpx+1];
						tmpx++;
					}
					else {
						gold += matrix[tmpy-1][tmpx+1];
						tmpx++;
						tmpy--;
					}
				}
				else if (tmpy-1 <0){
					if(matrix[tmpy][tmpx+1] >= matrix[tmpy+1][tmpx+1]) {
						gold += matrix[tmpy][tmpx+1];
						tmpx++;
					}
					else {
						gold += matrix[tmpy+1][tmpx+1];
						tmpx++;
						tmpy++;
					}
				}
				else if(matrix[tmpy][tmpx+1] >= matrix[tmpy+1][tmpx+1]) {
					if(matrix[tmpy][tmpx+1] >= matrix[tmpy-1][tmpx+1]) {
						gold += matrix[tmpy][tmpx+1];
						tmpx++;
					}
					else {
						gold += matrix[tmpy-1][tmpx+1];
						tmpx++;
						tmpy--;
					}
				}
				else {
					if(matrix[tmpy+1][tmpx+1] >= matrix[tmpy-1][tmpx+1]) {
						gold += matrix[tmpy+1][tmpx+1];
						tmpx++;
						tmpy++;
					}
					else {
						gold += matrix[tmpy-1][tmpx+1];
						tmpx++;
						tmpy--;
					}
				}
			}
			goldarray[y] = gold;
		}
		cout << maxarray(goldarray,n) << endl;
		cases--;
	}
	return 0;
}
