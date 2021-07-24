#include <bits/stdc++.h>

using namespace std;

#define npos std::string::npos

typedef struct {
	string name;
	int nn;
	unordered_set<string> nos;
} Entry;

vector<Entry> en;
unordered_map<string, int> m;

string match(string p, string c) {
	if(p.size() < c.size()) {
		swap(p, c);
	}
	int pi = p.size() - 1, ci = c.size() - 1;
	while(ci >= 0 && c[ci] == p[pi]) {
		--ci, --pi;
	}
	if(ci == -1) {
		return c;
	}
	else return "nil";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	// freopen("in","r",stdin);
	// freopen("out", "w", stdout);
	int n;
	cin >> n;
	while(n--) {
		string ename;
		int enn;
		cin >> ename >> enn;		
		if(m.find(ename) == m.end()) {
			Entry e;
			e.name = ename;
			e.nos.clear();
			while(enn--) {
				string num;
				cin >> num;
				if(e.nos.find(num) == e.nos.end()) {
					string er = "nil";
					for(string s : e.nos) {
						er = match(s, num);
						if(er != "nil") {
							break;
						}
					}
					e.nos.insert(num);
					if(er != "nil") {
						e.nos.erase(er);
					}		
				}
			}
			e.nn = e.nos.size();
			en.push_back(e);
			int eei = en.size() - 1;
			m.insert({ename, eei});
		}
		else {
			int ei = m[ename];
			while(enn--) {
				string num;
				cin >> num;
				if(en[ei].nos.find(num) == en[ei].nos.end()) {
					string er = "nil";
					for(string s : en[ei].nos) {
						er = match(s, num);
						if(er != "nil") {
							break;
						}
					}
					en[ei].nos.insert(num);
					if(er != "nil") {
						en[ei].nos.erase(er);
					}		
				}
			}
			en[ei].nn = en[ei].nos.size();
		}
	}
	cout << en.size() << "\n";
	for(Entry e : en) {
		cout << e.name << " " << e.nn << " ";
		for(string num : e.nos) {
			cout << num << " ";
		}
		cout << "\n";
	}
	return 0;
}