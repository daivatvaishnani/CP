#include <bits/stdc++.h>
using namespace std;
int t,n,tx,th;
std::vector< pair<int,int> > v;
std::vector< pair<int,int> > rec;
#define x first
#define h second
class cmp {
public:
	bool operator() (pair<int,int> p1, pair<int,int> p2) {
		return (p1.h < p2.h);
	}
};
int main() {
	freopen("in","r",stdin); freopen("out","w",stdout);
	std::ios_base::sync_with_stdio(false);
	cin>>t;
	while(t--) {
		v.clear();
		rec.clear();
		cin>>n;
		while(n--) {
			cin>>tx>>th;
			rec.push_back(make_pair(tx,0));
			v.push_back(make_pair(tx,th));
		}
		// // for(int i=v.size()-2; i>=0; --i) {
		// // 	// cout<<v[i].x<<" "<<v[i].h<<"\n";
		// // 	// cout<<rec[i].x<<" "<<rec[i].h<<"\n";
		// // 	int recch = rec[i+1].h + ((v[i].h > v[i+1].h) ? 1 : 0);
		// // 	rec[i].h = recch; 
		// // }
		// for(int i=0; i<v.size(); ++i) {
		// 	cout<<v[i].x<<" "<<v[i].h<<"\n";
		// 	// cout<<rec[i].x<<" "<<rec[i].h<<"\n";
		// }
		// for(int i=0; i<v.size(); ++i) {
		// 	// cout<<v[i].x<<" "<<v[i].h<<"\n";
		// 	cout<<rec[i].x<<" "<<rec[i].h<<"\n";
			// }
		for(int i=v.size()-2; i>=0; ++i) {
			if(v[i].h < v[i+1].h)
				rec[i].h = -1;
			else if(i<v.size()-2) {
				if((v[i+1] < v[i+2]) && )
			}
		}
	}
}
