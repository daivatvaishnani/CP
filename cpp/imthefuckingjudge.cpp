#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("in","w",stdout);
	string s,A,B,C,D,E,F;
	for(int a=1; a<=9; ++a) {
		for(int b=1; a<=9; ++b) {
			for(int c=1; c<=9; ++c) {
				for(int d=1; d<=9; ++d) {
					for(int e=1; e<=9; ++e) {
						for(int f=1; f<=9; ++f) {
							A = to_string(a), B=to_string(b), C=to_string(c), D=to_string(d), E=to_string(e), F=to_string(f);
							s = A+B+C+D+E+F;
							cout << s << "\n";
						}
					}
				}
			}
		}
	}
}