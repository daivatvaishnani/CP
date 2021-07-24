#include <iostream>
#include <string>

using namespace std;

int maxcontcnt(string s, char c) {
	int max=0,count=0;
	for(int i=0; i<s.size(); i++) {
		if(s[i]==c) {count++; max = (max > count ? max : count);}
		else {count=0;}
	}
	return max;
}

int main() {
	string s;
	cin >> s;
	cout << maxcontcnt(s,'c') << endl;
	return 0;
}