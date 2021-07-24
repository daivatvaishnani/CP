#include <bits/stdc++.h>

using namespace std;

int get(long long int a, long long int b){
    int ret = 1;
    if (a == b)
        return 1;
    else if ((b - a) >= 5) 
        return 0;
 
    else {
        for (long long int i = a + 1; i <= b; i++)
            ret = (ret * (i % 10)) % 10;
        return ret % 10;
    }
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	// freopen("in","r",stdin);
	// freopen("out", "w", stdout);
	long long a, b;
	cin >> a >> b;
	cout << get(a, b) << "\n";	
	return 0;
}