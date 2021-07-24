#include <bits/stdc++.h>

using namespace std;

unordered_set<char> S, ss;
vector<char> er;

void msg() {
	cout << "S :-\n";
	for(char ch : S) {
		cout << ch << " ";
	}
	cout << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("in","r",stdin);
	freopen("out", "w", stdout);
	int n;
	char c;
	string s;
	cin >> n;
	bool done = 0;
	int cnt = 0;
	// msg();
	for(int i = 0; i < n; ++i) {
		cin >> c >> s;
		ss.clear();
		for(char ch : s) {
			ss.insert(ch);
		}
		if(done && c == '?') ++cnt;
		if(S.size() == 1) {
			done = 1;
			continue;
		}
		if(c == '!') {
			if(S.empty()) {
				for(char ch : s) {
					S.insert(ch);
				}
			}
			else {
				for(char ch : S) {
					if(ss.find(ch) == ss.end()) {
						er.push_back(ch);
					}
				}
				for(char ch : er) {
					S.erase(ch);
				}
				er.clear();
			}
		}
		else if(c == '.') {
			for(char ch : s) {
				er.push_back(ch);
			}
		}
		else if(c == '?') {
			er.push_back(s[0]);
		}
		// msg();
	}
	cout << cnt << "\n";
	return 0;
}