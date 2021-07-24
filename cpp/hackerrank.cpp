#include <bits/stdc++.h>

using namespace std;

int arr[2][1000];
string name[1000];	

int main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen("in", "r", stdin);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> name[i] >> arr[0][i] >> arr[1][i];
	}
	int maxsi = 0;
	for(int i = 1; i < n; ++i) {
		if(arr[1][maxsi] - arr[0][maxsi] < arr[1][i] - arr[0][i]) {
			maxsi = i;
		}
	}
	cout << name[maxsi] << " " << arr[1][maxsi] - arr[0][maxsi] << "\n";
	return 0;
}