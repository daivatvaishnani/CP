#include <bits/stdc++.h>
using namespace std;
const int N = 307;
int n,k,size,val;
set<int> relative;
unordered_set<int> a[N];
class cmp {
public:
	bool operator()(unordered_set<int> s1, unordered_set<int> s2) {
		return (s1.size() > s2.size());
	}
};
bool isRelative(int i, int k) {
	for(unordered_set<int>::iterator j=a[i].begin(); j!=a[i].end(); ++j) {
		if(a[1].find(*j)!=a[1].end())
			--k;
		if(k==0)
			return true;
	}
	return false;
}
int main() {
	std::ios_base::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=1; i<=n; ++i) {
		cin>>size;
		while(size--) {
			cin>>val;
			a[i].insert(val);
		}
	}
	int repeat=500;
	while(repeat--) {
		for(int i=2; i<=n; ++i) {
			if(isRelative(i,k)) {
				relative.insert(i);
				for(unordered_set<int>::iterator j=a[i].begin(); j!=a[i].end(); ++j) {
					if(a[1].find(*j)==a[1].end())
						a[1].insert(*j);
				}
			}
		}
	}
	cout<<relative.size()+1<<"\n";
}
