#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+55;

int n;
int val;
pair<int,int> a[N];
int score[N],data[N];

class cmp {
public:
	bool operator() (pair<int,int> p1, pair<int,int> p2) {
		return (p1.second > p2.second);
	}
};

int main() {
	
	freopen("in","r",stdin); freopen("out","w",stdout);

	scanf("%d",&n);
	for(int i=1; i<=n; ++i) {
		scanf("%d",&val);
		a[i] = make_pair(i,val);
		data[i] = val;

	}
	
	sort(a+1, a+n+1, cmp());

	for(int i=1; i<=n; ++i) {
		printf("%d %d\n",a[i].first, a[i].second);
	}

	for(int i=1; i<=n; ++i) {
		score[i] = data[i] + a[1].first ;
		if(score[n - a[i].first + 1] < a[i].second + n)
			score[n - a[i].first + 1] = a[i].second + n;
	}

	for(int i=1; i<=n; ++i) {
		printf("%d\n",score[i]);
	}

	return 0;
}