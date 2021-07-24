#include <bits/stdc++.h>

using namespace std;

const int maxnm = 1005; 

int arr[maxnm][maxnm], arrv[maxnm][maxnm];
bool poss[maxnm][maxnm];

bool valid(int x, int y, int n, int m) {
	if(x <= n && x >= 1 && y <= m && y >= 1) return true;
	else return false;
}

int main() {
	// freopen("in", "r", stdin);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while(t--) {
		int n, m;
		memset(arr, 0, sizeof(arr));
		memset(arrv, 0, sizeof(arrv));
		memset(poss, 0, sizeof(poss));
		cin >> n >> m;
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				cin >> arr[i][j];
			}
		}
		for(int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				if(arr[i][j] > 0) ++arr[i][j];
			}
		}
		int cnt = 100;
		while(cnt--) {	
			for(int i = 1; i <= n; ++i) {
				for (int j = 1; j <= m; ++j) {
					arrv[i][j] = arr[i][j];
					if(arr[i][j] != -1) {
						if(valid(i, j + 1, n, m)) {
							arrv[i][j] = max(arrv[i][j], arrv[i][j + 1] - 1);
						}
						if(valid(i + 1, j, n, m)) {
							arrv[i][j] = max(arrv[i][j], arrv[i + 1][j] - 1);
						}
						if(valid(i, j - 1, n, m)) {
							arrv[i][j] = max(arrv[i][j], arrv[i][j - 1] - 1);
						}
						if(valid(i - 1, j, n, m)) {
							arrv[i][j] = max(arrv[i][j], arrv[i - 1][j] - 1);
						}
					}
				}
			}
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				if(arrv[i][j] == -1) cout << "B";
				else if(arrv[i][j] > 0) cout << "Y";
				else cout << "N";
			}
			cout << "\n";
		}
	}
	return 0;
}