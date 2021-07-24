#include "bits/stdc++.h"
using namespace std;
int t , n;
#define fio freopen("in","r",stdin);freopen("out","w",stdout)
#define fastio ios_base::sync_with_stdio(false)
int main(){
	fastio;
    fio;
    cin >> t;
	while(t--){
		cin >> n;
		for(int i = 500 - n + 1 ; i < 500 ; ++i){
			cout << i << " ";
		}
		cout << "500\n";
	}
}