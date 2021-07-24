#include <bits/stdc++.h>

using namespace std;

string ms = "312831303130313130313031";
string msl = "312931303130313130313031";

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	// freopen("in","r",stdin);
	// freopen("out", "w", stdout);
	int n;
	cin >> n;
	string msi = "", s;
	for(int i = 0; i < n; ++i) {
		cin >> s;
		msi += s;
	}
	string mscan = "";
	for(int year = 2000; year <= 2030; ++year) {
		if(year % 4 == 0 && year % 100 != 0) mscan += msl;
		else if(year % 400 == 0) mscan += msl;
		else mscan += ms;
	}
	if(mscan.find(msi) != std::string::npos) {
		cout << "Yes\n";
	}
	else cout << "No\n";
	return 0;
}