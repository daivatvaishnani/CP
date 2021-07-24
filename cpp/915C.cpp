#include <bits/stdc++.h>

using namespace std;

int main() {
	// freopen("in", "r", stdin);
	string a, b;
	cin >> a >> b;
	string sa = a;
	sort(sa.rbegin(), sa.rend());
	if(sa.size() == b.size()) {
		for(int i = 0; i < sa.size() - 1; ++i) {
			if(i >=1 && sa[i - 1] < b[i - 1]) break;
			if(sa[i] > b[i]) {
				bool found = 0;
				for(int j = i + 1; j < sa.size(); ++j) {
					if(sa[j] <= b[i]) {
						swap(sa[j], sa[i]);
						found = 1;
						break;
					}
				}
				if(!found) {
					swap(sa[i], sa[i - 1]);
					sort(sa.rbegin(), sa.rend() - i - 1);
					break;
				}
				else sort(sa.rbegin(), sa.rend() - i - 1);
			}
		}
		cout << sa;
	}
	else {
		cout << sa;
	}
	return 0;
}