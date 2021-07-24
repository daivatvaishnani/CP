#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 1;

vector<int> id;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("in","r",stdin);
	freopen("out", "w", stdout);
	int t;
	cin >> t;
	while(t--) {
		string a, temp;
		cin >> a;
		int sza = a.size();
		if( (a[sza - 1] & 1) && (a[sza - 2] & 1) ) {
			cout << "-1\n";
			continue;
		}
		bool one = 0;
		if(a[sza - 1] & 1) {
			a = a.substr(0, sza - 1);
			--sza;
			one = 1;
		}
		int sum = 0;
		for(int i = 0; i < sza; ++i) {
			sum += a[i] - '0';
		}
		if(one) {
			if(sum % 3 == 0) {
				cout << a << "\n";
				continue;
			}
			else {
				cout << "-1\n";
				continue;
			}
		}
		else {
			int rem = -1, val = 0;
			id.clear();
			for(int i = 0; i < sza; ++i) {
				if((sum - (a[i] - '0')) % 3 == 0) {
					id.push_back(i);
				}
			}
			if(id.size() == 0) {
				cout << "-1\n";
				continue;
			}
		}
		// cout << sum << "\n";
		cout << a << "\n";
	}	
	return 0;
}


/*
1911532
*/