#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+7;
unordered_map<int, int> h;
unordered_map<int, int> vis;
vector<int> x;
#define height first
#define dist second
class cmp {
public:
	bool operator() (pair<int,int> p1, pair<int,int> p2) {
		return (p1.height > p2.height);
	}
};
pair<int,int> newPair; 
set<pair<int,int>, cmp> s;
int t, n, xi, hi; 
int main() {
	ios_base::sync_with_stdio(false);
	freopen("in","r",stdin); freopen("out","w",stdout);
	cin >> t;
	while(t--) {
		cin >> n; 
		while(n--) {
			cin >> xi >> hi;
			x.push_back(xi);
			h.insert(make_pair(xi,hi));
			vis.insert(make_pair(xi,0));
		}
		for(int i=0; i<x.size(); ++i) {
			s.insert(make_pair(x[i],h[x[i]]));
		}
		for(auto i=s.begin(); i!=s.end(); ++i) {
			cout<<(*i).height<<" "<<(*i).dist<<"\n";
		}

		cout<<s.upper_bound()
		// for(auto i=x.end()-1; i!=x.begin()+1; --i) {
		// 	if(s.empty()) {
		// 		vis[*i] = -1;
		// 		newPair.height = h[*i];
		// 		newPair.dist = *i;
		// 		s.insert(newPair);
		// 		continue;
		// 	}


		// }
	}
}