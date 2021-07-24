#include <bits/stdc++.h>

using namespace std;

int a[25001], b[25001], c[25001];

void multiply(int aa, int bb) {
	for(int i=0; i<25001; ++i) {
		a[i] = 0;
		b[i] = 0;
		c[i] = 0;
	}
	int na = 25000;
	int nb = 25000;
	while(aa != 0){
		a[na] = aa%10;
		aa = aa/10;
		na--;
	}
	while(bb != 0){
		b[na] = bb%10;
		bb = bb/10;
		na--;
	}
	for(int i=na; i<=25000; ++i) {
		cout<<a[i]<<" ";
	}cout<<"\n";
	for(int i=nb; i<=25000; ++i) {
		cout<<b[i]<<" ";
	}cout<<"\n";
	int carry=0;
	for(int i=25000; i>=min(na,nb)-1; --i) {
		c[i] = a[i]*b[i] + carry;
		if(c[i]/10 != 0) {
			c[i] = c[i]%10;
			carry = c[i]/10;
		}
	}
	for(int i=min(na,nb)-1; i<=25000; ++i) {
		cout<<c[i]<<" ";
	}cout<<"\n";
} 

int main() {

	return 0;
}