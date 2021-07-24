#include <bits/stdc++.h>
using namespace std;
#define index first
#define pos second
const int N = 555;
char a[4][N], b[4][N];
unordered_map<char, int> m, modd, meven;
vector<int> single;
int t, n;
void reset() {
	for(int i=0; i<4; ++i) {
		for(int j=0; j<N; ++j) {
			a[i][j] = 'A';
			b[i][j] = 'A';
		}
	}
	m.clear();
	modd.clear();
	meven.clear();
}
void input(int n) {
	for(int i=1; i<=2; ++i) {
		for(int j=1; j<=n; ++j) {
			cin >> a[i][j];
			if(m.find(a[i][j]) == m.end()) {
				m.insert(make_pair(a[i][j], 1));
			}
			else 
				m[a[i][j]] = m[a[i][j]] + 1;
		}
	}
	for(auto i=m.begin(); i!=m.end(); ++i) {
		if((*i).second & 1) {
			modd.insert(*i);
			continue;
		}
		else
			meven.insert(*i);
	}
}
void printg(int n) {
	// for(int i=1; i<=2; ++i) {
	// 	for(int j=1; j<=n; ++j) {
	// 		cout << a[i][j] << " ";
	// 	}
	// 	cout << "\n";
	// }
	// cout << "\n";
	for(int i=1; i<=2; ++i) {
		for(int j=1; j<=n; ++j) {
			cout << b[i][j];
		}
		cout << "\n";
	}
	// cout << "\n";
	// for(auto i = m.begin(); i != m.end(); ++i) {
	// 	cout << (*i).first << " " << (*i).second << "\n";
	// }
	// cout << "\n";
	// for(auto i = modd.begin(); i != modd.end(); ++i) {
	// 	cout << (*i).first << " " << (*i).second << "\n";
	// }
	// cout << "\n";
	// for(auto i = meven.begin(); i != meven.end(); ++i) {
	// 	cout << (*i).first << " " << (*i).second << "\n";
	// }
	// cout << "\n";
}
pair<int,int> fillb(char c1, int index, int pos, int num) {
	while(num--) {
		b[pos][index] = c1;
		if(pos == 1 && b[2][index] == 'A')
			pos = 2;
		else if(pos == 2 && b[1][index] == 'A')
			pos = 1;
		else
			++index;
	}
	return make_pair(index,pos);
} 
void rearrange(int n) {
	pair<int,int> p1;
	p1.index = 1;
	p1.pos = 1;
	while(!meven.empty()) {
		p1 = fillb((*meven.begin()).first, p1.index, p1.pos, (*meven.begin()).second);
		meven.erase(meven.begin());
	}
	while(!modd.empty()) {
		p1 = fillb((*modd.begin()).first, p1.index, p1.pos, (*modd.begin()).second);
		modd.erase(modd.begin());
	}
}
int main() {
	freopen("in","r",stdin);
	std::ios_base::sync_with_stdio(false);
	cin >> t;
	while(t--) {
		reset();
		cin >> n;
		input(n);
		rearrange(n);
		printg(n);
	}
}