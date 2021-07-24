#include <bits/stdc++.h>
using namespace std;

char a[10][10];

bool check(int i, int j, int x, int y) {
	if(i>5 && j>5) return false;
	if((i>5 && x==1 && y==0) || (j>5 && y==1 && x==0) || (x==1 && y==1 && (i>5 || j>5))) return false;
	int num = 0, flag = 1;	  
	for(int k=i, l=j; k<10 && l<10 && k<i+5 && l<j+5 && k>=0 && l>=0; k+=x, l+=y) {
		if(a[k][l] == 'X') {
			++num;
		}
		if(a[k][l] == 'O')
			flag = 0;
	}
	if(num == 4 && flag == 1) {
		return true;
	}
	else
		return false;
}

int main() {
	for(int i=0; i<10; ++i) {
		for(int j=0; j<10; ++j) {
			cin >> a[i][j];
		}
	}
	for(int i=0; i<10; ++i) {
		for(int j=0; j<10; ++j) {
			if(check(i,j,1,0) || check(i,j,0,1) || check(i,j,1,1) || check(i,j,-1,1)) {
				cout << "YES\n";
				return 0;
			}
		}
	}
	cout << "NO\n";
	return 0;
}