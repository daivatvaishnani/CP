#include <bits/stdc++.h>

using namespace std;

void process(string line) {
	line = "-" + line;
	int a = 0, b = 0, ta = 0, tb = 0;
	for(int i = 1; i <= 10; ++i) {
		if(i & 1) {
			if(line[i] == '1') {
				++a;
			}
			++ta;
		}
		else {
			if(line[i] == '1') {
				++b;
			}
			++tb;
		}
		if(a > 5 - tb + b) {
			cout << "TEAM-A" << " " << i << "\n";
			return;
		}
		if(b > 5 - ta + a) {
			cout << "TEAM-B" << " " << i << "\n";
			return;
		}
	}
	for(int i = 11; i <= 19; i = i + 2) {
		if(line[i] == '1' && line[i + 1] == '0') {
			cout << "TEAM-A" << " " << i + 1 << "\n";
			return;
		}
		if(line[i] == '0' && line[i + 1] == '1') {
			cout << "TEAM-B" << " " << i + 1 << "\n";
			return;
		}
	}
	cout << "TIE\n";
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	// freopen("in","r",stdin);
	// freopen("out", "w", stdout);
	string line;
	while(cin >> line) {
		process(line);
	}
	return 0;
}