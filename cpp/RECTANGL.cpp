#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		int arr[] = {a,b,c,d};
		sort(arr, arr+4);
		if(arr[0]==arr[1] && arr[2]==arr[3]) cout << "YES\n";
		else cout << "NO\n";
	}
} 