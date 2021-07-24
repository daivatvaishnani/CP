#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull  n,mod;
long double r;
ull ri;
ull ans;
ull POW[65],REP[2500];
bool flag[75000];

ull power2(ull x, ull y, ull p) {
    ull res = 1; 
    x = x % p; 
    while (y > 0) {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;  
    }
    return res;
}

ull power(int index) {
	if(index<64) {
		return POW[index]%mod;
	}
	ull rep = index/63;
	ull ans = REP[rep];
	ull rem = index%63; 
	ans = ((ans%mod) * (POW[rem]%mod))%mod;
	return ans;
}

ull computeAns(ull a) {
	int ret;
	if(a==1) {
		ret = (2%mod)%mod;
		return ret;
	}
	ret = power(a);
	return ret;
}

int main() {
	freopen("in","r",stdin); freopen("out","w",stdout);
	std::ios_base::sync_with_stdio(false);
	cin>>n>>mod;
	POW[0] = 1;
	for(int i=1; i<65; ++i) {
		POW[i] = POW[i-1] << 1;
	}
	REP[0] = 1;
	for(int i=1; i<2500; ++i) {
		REP[i] = ((REP[i-1]%mod) * (POW[63]%mod))%mod;
	}
	ull i=2;
	ans = 0;
	std::vector<ull> v;
	while(i<=n/2) {
		r = n / (i + 0.0);
		ri = r;
		if(r == ri) {
			bool ok = 1;
			if(!v.empty()) {
				for(int i=0; i<v.size(); ++i) {
					if(v[i]%ri==0) {
						ok = 0;
						break;
					}
				}
			}
			if(v.empty() || ok == 1) {
				ull temp = computeAns(ri);
				ans += temp;
				v.push_back(ri);
			}
		}
		++i;
	}
	if(ans==0)
		ans = computeAns(1);
	ull ans2 = (computeAns(n) - ans%mod)%mod;
	cout<<ans2<<"\n"; 
	// cerr<<(mod + computeAns(n) - ans%mod)%mod<<"\n";
	return 0;
}
