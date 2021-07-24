#include <iostream>

using namespace std;

void flagup(int index, int* flags) {
	flags[index] = 1;
}

int main()
{
	int n=10;
	int flags[n+1]={0};
	flags[2]=0;
	for(int i=2; i<=n; i+=1) {
		if(flags[i]==0) {
			for(int j=i*2; j<=n; j+=i) {
				flagup(j,flags);
			}
		}
	}
	for(int i=2; i<=n; i++){
		if(flags[i]==0) {cout << i << " ";}
	}
	return 0;
}