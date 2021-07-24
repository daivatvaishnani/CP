#include <bits/stdc++.h>
using namespace std;
const int N = 3e6+6;
int maxstring[N];
vector<string> s;
int n, occ, tsize, sid, maxsize, maxval, val, filled, start, reach;
string t;
int main() {
	cin >> n;
	sid = -1;
	maxval = 0;
	for(int i=0; i<N; ++i)	maxstring[i] = -1;
	while(n--) {
		cin >> t;
		tsize = t.size();
		s.push_back(t);
		++sid;
		cin >> occ;
		maxval = 0;
		while(occ--) {
			cin >> val;
			if(maxstring[val] != -1)	maxstring[val] = max((int)s[maxstring[val]].size(), tsize) == tsize ? sid : maxstring[val];  
			else maxstring[val] = sid;
			maxval = max(maxval, val);
		}
		maxsize = max(maxsize, tsize+maxval-1);
	}
	string ans = string(maxsize+1, 'a');
	start = 1, filled = 0;
	while(filled < maxsize) {
		if(maxstring[start] != -1) {
			reach = start+(int)s[maxstring[start]].size()-1;
			if(reach > filled) {
				for(int i = max(start, filled+1); i <= reach; ++i)	ans[i] = s[maxstring[start]][i-start];
				filled = reach;
			}
		}
		++start;
	}
	for(int i = 1; i <= maxsize; ++i)	cout<<ans[i];
	return 0;	
}