#include <bits/stdc++.h>

using namespace std;

const int N = 16;

long long mat[N][N];

bool present[30000];

long long getsum(int row1, int col1, int row2, int col2) {
        long long num = mat[row2][col2];
        long long left=0, upper=0, leftupper=0;
        
        if(col1 > 0 && row1 > 0) leftupper = mat[row1-1][col1-1];
        if(col1 > 0) left = mat[row2][col1-1];
        if(row1 > 0) upper = mat[row1-1][col2];
        
        return num - left - upper + leftupper;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	// freopen("in","r",stdin	);
	int n;
	long long subsum;
	cin >> n;
	for(int i = 0; i < 30000; ++i)
		present[i] = 0;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			cin >> mat[i][j];
		}
	}
	for(int i = 1; i < n; i++)
		mat[i][0] += mat[i-1][0];
    for(int j = 1; j < n; j++)
    	mat[0][j] += mat[0][j-1];
    for(int i = 1; i < n; i++) {
     	for(int j = 1; j < n; j++) {
    		mat[i][j] += (mat[i-1][j] + mat[i][j-1] - mat[i-1][j-1]);
    	} 
    }
    int ans = 0;
    for(int i = 0; i < n; ++i) {
    	for(int j = 0; j < n; ++j) {
    		for(int k = i; k < n; ++k) {
    			for(int l = j; l < n; ++l) {
    				subsum = getsum(i, j, k, l);
    				// cout << i << " " << j << " " << k << " " << l << " " << subsum << "\n"; 
    				if(present[subsum] == 0) {
    					++ans;
    					present[subsum] = 1;
    				} 
    			}	
    		}	
    	}
    }
    cout << ans << "\n";
	return 0;
}