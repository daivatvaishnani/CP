#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define F first
#define S second
#define pb push_back
#define fo(i, n) for(int i = 1; i <= n; ++i)

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N = 200200;
int sz;
const int mod = 1e9 + 7;

inline void add(int &x, int y)
{                          
	x += y;
	if(x >= mod) x -= mod;
}
ll n, k;

struct matrix
{
	int a[16][16];
	matrix()
	{
		clear();
	}
	void clear()
	{
		for(int i = 0; i < 16; ++i)
			for(int j = 0; j < 16; ++j)
				a[i][j] = 0;
	}
	matrix operator * (const matrix b)
	{
		matrix c; c.clear();
		for(int k = 0; k < sz; ++k)
			for(int i = 0; i < sz; ++i)
				for(int j = 0; j < sz; ++j)
					(c.a[i][j] += (a[i][k] *1ll* b.a[k][j] % mod)) %= mod;
		return c;
	}
} trans, one, start, base;

inline matrix bin(matrix a, ll step)
{
	if(step == 0)
		return one;
	if(step == 1)
		return a;
	if(step % 2 == 0)
	{
		a = bin(a, step / 2);
		return a * a;
	}
	return a * bin(a, step - 1);
}


int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for(int i = 0; i < 16; ++i)
		one.a[i][i] = 1;
	base.a[0][0] = 1;
	ll a, b, c;
	fo(i, n)
	{
		cin >> a >> b >> c;
		sz = c + 1;
		trans.clear();
		for(int i = 0; i < sz; ++i)
		{
			trans.a[i][i] = 1;
			if(i - 1 >= 0) trans.a[i - 1][i] = 1;
			if(i + 1 < sz) trans.a[i + 1][i] = 1;
		}
		b = min(b, k);
		matrix x = bin(trans, b - a);
		base = base * x;	
	}
	cout << base.a[0][0];
	return 0;
}