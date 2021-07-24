#include <bits/stdc++.h>

using namespace std;

typedef pair<long double, long double> Pt;
#define x first
#define y second

long double dist(Pt p1, Pt p2) {
	return sqrt(pow(p1.x-p2.x,2) + pow(p1.y-p2.y,2));
}

int main() {
	ios::sync_with_stdio(false);
	// freopen("in","r",stdin);
	Pt p1,p2,p3;
	cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
	if(dist(p1,p2)==dist(p2,p3) && dist(p1,p3)!=dist(p1,p2)+dist(p2,p3)) cout << "Yes\n";
	else cout << "No\n";
}