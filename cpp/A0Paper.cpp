#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class A0Paper {
	public:
		string canBuild(vector<ll> A) {
			ll n = A.size();
			vector<ll> can(n, -1);
			ll ans = go(0, can, A);
			if(ans > 0) {
				return "Possible";
			}
			return "Impossible";
		}
	private:
		ll go(ll dim, vector<ll> &can, vector<ll> &arr) {
			if(dim < arr.size() && can[dim] > 0) {
				return can[dim];
			}
			ll ans = 0;
			if(dim < arr.size()) {
				ans = arr[dim] + go(dim + 1, can, arr) / 2; 
			}
			can[dim] = ans;
			return ans;
		}
};


ll main() {
	freopen("in", "r", stdin), freopen("out", "w", stdout);
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	vector<ll> stock = {0,0,0,0,15};
	A0Paper A0PaperFactory;
	cout << A0PaperFactory.canBuild(stock);
	return 0;
}