#include <bits/stdc++.h>
using namespace std;
const int N = 1e5;
int n,ti,xi;
std::vector<pair<int,int> > v;
#define t first
#define x second
class cmp {
public:
	bool operator() (pair<int,int> p1, pair<int,int> p2) {
		if(p1.x == p2.x)
			return (p1.t < p2.t); 
		return (p1.x > p2.x);
	}
};
int main () {
	std::ios_base::sync_with_stdio(false);
	cin >> n;
	int t[n], x[n];
	for(int i=0; i<n; ++i) {
		cin >> ti >> xi;
		v.push_back(make_pair(ti,xi));
	}
	sort(v.begin(),v.end(), cmp());
	int whatihave=0, whatineed=0, whatillget=0, ans=0;
	for(int i=0; i<n; ++i) {
	    whatineed = v[i].t;
	    whatillget = v[i].x;
	    if(whatihave < whatineed) {
	        ans += whatineed - whatihave;
	        whatihave = whatillget;
	    }
	    else {
	        whatihave = whatihave - whatineed + whatillget;
	    }
	}
    cout << ans << "\n";
}
