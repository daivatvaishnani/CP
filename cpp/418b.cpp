#include <bits/stdc++.h>
using namespace std;
#define fio freopen("in","r",stdin);freopen("out","w",stdout)
#define fastio ios_base::sync_with_stdio(false)
const int N=1e5;
int a[N],b[N];
bool used[N];
int n;
bool search(set<int> s,int val) {
	return (s.find(val)!=s.end() ? true: false);
}
int main() {
	// fio;
	fastio;
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	for(int i=1; i<=n; i++) {
		cin>>b[i];
	}
	int diff=0;
	for(int i=1; i<=n; i++) {
		diff+= a[i]!=b[i] ? 1 : 0;
	}
	if(diff==1) {
		for(int i=1; i<=n; i++) {
			used[a[i]]=true;
			used[b[i]]=true;
		}
		int idx=0;
		for(int i=1; i<=n; i++) {
			if(!used[i]) {
				idx=i;
				break;
			}
		}
		for(int i=1; i<=n; i++) {
			if(a[i]!=b[i]) {
				cout<<idx<<" ";
				continue;
			}
			cout<<a[i]<<" ";
		}
		cout<<"\n";
	}
	else {
		std::set<int> notused;
		for(int i=1; i<=n; i++) {
			if(a[i]!=b[i]) {continue;}
			used[a[i]]=true;
		}
		for(int i=1; i<=n; i++) {
			if(a[i]!=b[i]) {
				if(used[a[i]]) {
					used[b[i]]=true;
					continue;
				}
				if(used[b[i]]) {
					used[a[i]]=true;
					continue;
				}
			}
		}
		for(int i=1; i<=n; i++) {
			if(!used[i])
				notused.insert(i); 
		}
		// for(std::set<int>::iterator i = notused.begin(); i != notused.end(); ++i) {cout<<(*i)<<" ";}cout<<"\n";
		for(int i=1; i<=n; i++) {
			if(a[i]!=b[i]) {
				if(search(notused, a[i])) {
					cout<<a[i]<<" ";
					notused.erase(a[i]);
					continue;
				}
				if(search(notused, b[i])) {
					cout<<b[i]<<" ";
					notused.erase(b[i]);
					continue;
				}
			}
			cout<<a[i]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}