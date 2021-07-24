#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 6;
int n,len,val,maxval,ssize,maxsize,start,filled,reach;
string s;
int cnt[N], maxlens[N];
vector<string> data[N];
int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	cin >> n;
	while(n--) {
		cin >> s;
		cin >> len;
		ssize = s.size();
		maxval = 0;
		while(len--) {
			cin >> val;
			data[val].push_back(s);
			if(data[val].empty())
				maxlens[val] = cnt[val];
			else maxlens[val] = max((int)data[val][maxlens[val]].size(), ssize) == ssize ? cnt[val] : maxlens[val];
			maxval = max(maxval, val);
			++cnt[val];
		}
		maxsize = max(maxsize, ssize+maxval-1);
	}
	string ans = string(maxsize+1,'a');
	start = 1; filled = 0;
	while(filled < maxsize) {
		if(!data[start].empty()) {
			reach = start + (int)data[start][maxlens[start]].size() - 1;
			if(reach > filled) {
				for(int i = max(start, filled+1); i <= reach; ++i) ans[i] = data[start][maxlens[start]][i-start];
				filled = reach;
			}			
		}
		++start;
	}
	for(int i=1; i<=maxsize; ++i)	cout<<ans[i];
}
