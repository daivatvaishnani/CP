/**
* Problem Link: 
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll maximize(vector<ll> arr) {
	ll n = arr.size();
	ll ans = LLONG_MIN;
	assert(n >= 5);
	for(ll i = 0; i < n-4; ++i) {
		for(ll j = i+1; j < n-3; ++j) {
			for(ll k = j+1; k < n-2; ++k) {
				for(ll l = k+1; l < n-1; ++l) {
					for(ll t = l+1; t < n; ++t) {
						ans = max(ans, arr[i] * arr[j] * arr[k] * arr[l] * arr[t]);
					}
				}
			}			
		}
	}
	return ans;
}

void test_case() {
	ll n;
	cin >> n;
	vector<ll> arr(n);
	for(ll i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	vector<ll> pos, neg;
	for(ll i = 0; i < n; ++i) {
		if(arr[i] >= 0) {
			pos.push_back(arr[i]);
		} else {
			neg.push_back(arr[i]);
		}
	}
	reverse(pos.begin(), pos.end());
	vector<ll> maxarr;
	ll ps = pos.size();
	ll ns = neg.size();
	for(ll i = 0; i < min(5LL, ps); ++i) {
		maxarr.push_back(pos[i]);
	}
	for(ll i = 0; i < min(5LL, ns); ++i) {
		maxarr.push_back(neg[i]);
	}
	long long ans = maximize(maxarr);
	cout << ans << "\n";
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin >> t;
    while(t--) {
        test_case();
    }
    return 0;
}