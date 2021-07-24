#include <bits/stdc++.h>
using namespace std;
int n,ans,temp,val;
vector<int> d;
string s;
int main() {
	std::ios_base::sync_with_stdio(false);
	cin >> n;
	temp = 1;
	ans = 0;
	n = n*2;
	while(n--) {
		cin >> s;
		if(s=="add") {
			cin >> val;
			d.push_back(val);
		}
		else {
			if(d[d.size()-1] == temp || d.empty()) {
				if(!d.empty())
					d.pop_back();
			}
			else {
				++ans;
				d.clear();
			}
			++temp;
		}
	}
	cout << ans << "\n";
}