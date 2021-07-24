#include <bits/stdc++.h>

using namespace std;

const int N = 1e6;

unordered_map <string, long long> P, Q;
vector<int> Pf, Qf;

// long long arr[10*N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("in","r",stdin);
	string s, t, str;
	cin >> s >> t;
	int szs = s.size();
	int szt = t.size();
	P.clear(), Q.clear();
	for(int i = 0; i < szs; ++i) {
		for(int j=0; i+j < szs; ++j) {
			str = s.substr(i, j+1);
			if(P.find(str) == P.end()) {
				P.insert(make_pair(str, 1));
			}
			else {
				++P[str];
			}
		}
	}
	for(int i = 0; i < szt; ++i) {
		for(int j=0; i+j < szt; ++j) {
			str = t.substr(i, j);
			if(Q.find(str) == Q.end()) {
				Q.insert(make_pair(str, 1));
			}
			else {
				++Q[str];
			}
		}
	}
	
	for(auto i = P.begin(); i != P.end(); ++i) {
		Pf.push_back((*i).second);
	}

	for(auto i = Q.begin(); i != Q.end(); ++i) {
		Pf.push_back((*i).second);
	}

	sort(Pf.begin(), Pf.end());
	// sort(Qf.begin(), Qf.end());

	// cout << Pf[0] << " " << Qf[0] << "\n";
	long long ans = Pf[0];

	for(int i=1; i<Pf.size(); ++i) ans ^= Pf[i];

	cout << ans << "\n"; 
		
	return 0;
}