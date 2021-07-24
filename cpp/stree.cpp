#include <bits/stdc++.h>
using namespace std;
const int maxi = 1e9 + 7;
typedef long long ll; 
typedef long double lf; 
typedef unsigned long long ull; 

ull segSize (int inputSize) {
	lf out = log(inputSize) / log(2);
	int o = out;
	return (o==out ? (2*inputSize - 1): (2*pow(2,o+1) - 1));
}

void constructSegTree (int input[], int segTree[], int low, int high, int pos) {
	if(high==low) {
		segTree[pos] = input[low];
		return;
	}
	int mid = (low + high) / 2;
	constructSegTree (input, segTree, low, mid, 2*pos + 1);
	constructSegTree (input, segTree, mid + 1, high, 2*pos + 2);
	segTree[pos] = min (segTree[2*pos +1], segTree[2*pos + 2]);
}

int main() {
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	int input[] = {-1, 2, 4, 0};
	int inputSize = 5;
	int size = segSize (inputSize); 
	int segTree[size];
	memset(segTree, 100, size);
	constructSegTree (input, segTree, 0, size - 1 , 0);
	for(int i=0; i<size; ++i) {cout<<segTree[i]<<" ";}cout<<"\n";
}