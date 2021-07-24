#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	int t;
	cin >> t;
	while(t--) {
		string s;
		int x, y;
		cin >> s >> x >> y;
		int na = 0, nb = 0, ssz = s.size();
		for(int i = 0; i < ssz; ++i) {
			na += (s[i] == 'a') ? 1 : 0;
			nb += (s[i] == 'b') ? 1 : 0;
		}
		double rda = (na + .0) / x;
		double rdb = (nb + .0) / y;
    int ra = (int) rda;
    int rb = (int) rdb;
    ra += (ra != rda) ? 1 : 0;
    rb += (rb != rdb) ? 1 : 0;
		int asz = max(ra, rb);
		string saa[asz], sab[asz];
		for(int i = 0; i < asz; ++i) {
			saa[i].clear();
			sab[i].clear();
		}
		int fi = 0;
		while(na--) {
			saa[fi] += 'a';
			fi = (fi + 1) % asz;
		}
		fi = 0;
		while(nb--) {
			sab[fi] += 'b';
			fi = (fi + 1) % asz;
		}
		for(int i = 0; i < asz; ++i) {
			if(saa[i].size() == 0) {
				saa[i] += '*';
			}
			if(sab[i].size() == 0) {
				sab[i] += '*';
			}
		}
    bool turn = (ra > rb) ? 1 : 0;
		if(turn == 1) {
			if(saa[0] == "*") {
				saa[0].clear();
			}
			if(sab[asz - 1] == "*") {
				sab[asz - 1].clear();
			}
		}
		else {
			if(sab[0] == "*") {
				sab[0].clear();
			}
			if(saa[asz - 1] == "*") {
				saa[asz - 1].clear();
			}
		}
		int tms = 2 * asz;
		int pia = 0;
		int pib = 0;
		while(tms--) {
			cout << (turn ? saa[pia++] : sab[pib++]);
			turn = !turn;
		}
        cout << "\n";
	}
	return 0;
}
