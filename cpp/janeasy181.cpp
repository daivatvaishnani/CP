#include <bits/stdc++.h>

using namespace std;

unordered_set<string> ss;
vector<int> v;

int main() {
	freopen("in", "r",stdin);
	freopen("out", "w",stdout);
	int n,val;
	scanf("%d",&n);
	for(int i=0; i<n; ++i) {
		scanf("%d",&val);
		v.push_back(val);
	}
	int ans = 0;
	for(int i=0; i<n; ++i) {
		for(int j=0; i+j<n; ++j) {
			s += to_string(v[j]);
		}
		sort(s.begin(), s.end());
		if(ss.find(s) == ss.end()) ss.insert(s);
	}
	for(string s : ss) printf("%s\n",s.c_str());
	printf("%d",(int)ss.size());
}