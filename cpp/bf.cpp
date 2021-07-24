#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 57;
ll n;
int a[N][N];
unordered_set<ll> s;
int main() {	
	std::ios_base::sync_with_stdio(false);
	cin >> n;
	int cA=0, cB=0;
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=n; ++j) {
			cin >> a[i][j];
			if(a[i][j] != 1)
				++cA; 
		}

	}
	for(int i=1; i<=n; ++i) {
		for(int j=1; j<=n; ++j) {
			s.clear();
			if(a[i][j] != 1) {
				for(int k=1; k<=n; ++k) {
					s.insert(a[i][j] - a[i][k]);
				}
				for(int k=1; k<=n; ++k) {
					if(s.find(a[k][j]) != s.end()) {
						++cB;
						break;						
					}
				}
			}
		}
	}
	if(cA == cB)
		cout<<"Yes\n";
	else
		cout<<"No\n";
}
