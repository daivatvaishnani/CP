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
		for(int row=0;row<n;row++) {
			int rightup = (row==0 || )
		}
		cout << maxarray(goldarray,n) << endl;
		cases--;
	}
	return 0;
}
