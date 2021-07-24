#include <bits/stdc++.h>

using namespace std;

vector<int> divs;

void getdivs(int n) {
	divs.clear();
    for (int i = 1; i <= sqrt(n) + 1; ++i) {
        if (n % i == 0) {
            if (n / i == i) {
                divs.push_back(i);
            }
            else {
            	divs.push_back(i);
            	divs.push_back(n / i);
            }
        }
    }
}

bool beautiful(int no) {
	for(int i = 0; i < 20; ++i) {
		int n = (pow(2, i) - 1) * (pow(2, i - 1));
		if(n == no) {
			return 1;
		} 
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	// freopen("in","r",stdin);
	// freopen("out", "w", stdout);
	int n;
	cin >> n;
	getdivs(n);
	int maxn = -1;
	for(int i = 0; i < divs.size(); ++i) {
		int no = divs[i];
		if(beautiful(no)) {
			maxn = max(maxn, no);
		}
	}
	cout << maxn << "\n";
	return 0;
}