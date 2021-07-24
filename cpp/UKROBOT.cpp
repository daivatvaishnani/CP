/**
* Problem Link: https://www.codechef.com/LTIME88A/problems/UKROBOT
*/
#include <bits/stdc++.h>

using namespace std;

const int maxlen = 1e4;

vector<pair<int,int> > done;

void print(int x, int y) {
	// cout << x << " " << y << "\n";
	done.push_back({x, y});
}

void solve(int r, int c) {
	// swap(r, c);
	int x = 1, y = 0;
    int len = 0;
    string ans = "R";
    print(0, 0);
    print(x, y);
    while(len <= maxlen) {
    	while(y < x) {
    		y++;
    		len++;
    		ans += 'U';
    		print(x, y);
    		if(x >= r && y >= c) {
    			break;
    		}
    	}
    	while(x > 0) {
    		x--;
    		len++;
    		ans += 'L';
    		print(x, y);
    		if(x >= r && y >= c) {
    			break;
    		}
    	}
    	y++;
    	len++;
    	ans += 'U';
    	print(x, y);
    	if(x >= r && y >= c) {
    		break;
    	}
    	while(x < y) {
    		x++;
    		len++;
    		ans += 'R';
    		print(x, y);
    		if(x >= r && y >= c) {
	    		break;
	    	}
    	}
    	while(y > 0) {
    		y--;
    		len++;
    		ans += 'D';
    		print(x, y);
    		if(x >= r && y >= c) {
	    		break;
	    	}
    	}
    	x++;
    	len++;
    	ans += 'R';
    	print(x, y);
    	if(x >= r && y >= c) {
    		break;
    	}	
    }
    // sort(done.begin(), done.end());
    for(auto i : done) {
    	cout << i.first << " " << i.second << "\n";
    }
    cout << ans << "\n";
}

void solve_task(int r, int c) {
	int x = 1, y = 0;
	string ans = "U";
	while(y < c) {
		y++;
		ans += 'R';
	}
	cout << ans << "\n";
}

void test_case() {
    int r, c;
    cin >> r >> c;
    // solve(r, c);
    solve_task(r, c);
}

int main() {
    freopen("in", "r", stdin), freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1;
    while(t--) {
        test_case();
    }
    return 0;
}