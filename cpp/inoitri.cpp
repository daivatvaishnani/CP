#include <bits/stdc++.h>
using namespace std;
#define id first.first
#define a first.second
#define b second.first
#define c second.second
#define mp make_pair
#define pb push_back
#define out(a,b,c,d) cout<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<"\n" 
typedef pair< pair<int, int> , pair<int, int > > person;
const int MAX = 2e5+55;
int n,ta,tb,tc;
vector<person> v;
class cmp {
public:
	bool operator()(person p1, person p2) {
		return (p1.b + p1.c > p2.b + p2.c);
	}
};

int main() {
	freopen("in","r",stdin); freopen("out","w",stdout);
	std::ios_base::sync_with_stdio(false);
	cin>>n;
	for(int i=1; i<=n; ++i) {
		cin>>ta>>tb>>tc;
		v.pb(mp(mp(i,ta),mp(tb,tc)));
	}
	sort(v.begin(), v.end(),cmp());
	int tep=0,time=0;
	for(int i=0; i<v.size(); ++i) {
		time = max(time, tep + v[i].a + v[i].b + v[i].c);
		tep += v[i].a;
	}
	cout<<time<<endl;
}