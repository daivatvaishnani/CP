#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("in","r",stdin);
	freopen("out", "w", stdout);
	int t;
	cin >> t;
	while(t--) {
		int n, a, cnt, na, nb, no, ne;
		cin >> n >> a;
		nb = n / 2;
		na = n - nb; 
		string s(n, 'a');
		if(a > 2) {
			cnt = 0;
			for(int i = 0; i < n; ++i) {
				s[i] += cnt;
				cnt = (cnt + 1) % a;
			}
			cout << "1 " << s << "\n";
		}
		else if(a == 2) {
			if(n <= 10) {
				no = na / 3;
				if(na % 3  == 0) {
					--no;
				}
				string a(na - no, 'a'), b(nb - no, 'b'), aa(no, 'a'), bb(no, 'b');
				s = a + bb + aa + b;
				cout << max(3 * no, na - no) << " " << s << "\n";
			}
			else {
				cout << "4 ";
				no = n / 6;
				ne = n % 6;
				string a = "aababb";
				for(int i = 0; i < no; ++i) {
					cout << a;
				}
				if(ne > 0) {
					cout << a.substr(0, ne);
				}
				cout << "\n";
			}
		}
		else {
			cout << n << " " << s << "\n";
		}
	}
	return 0;
}