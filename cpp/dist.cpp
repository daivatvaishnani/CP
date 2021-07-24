#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	long long int n,cordi,dist,count=0,mindist=LLONG_MAX;
	cin >> n;
	std::vector<long long int> v;
	for(long long int i=0;i<n;i++) {
		cin >> cordi;
		v.push_back(cordi);
	}
	sort(v.begin(), v.end());
	for(long long int i=0;i<=n-2;i++) {
		dist = v[i+1]-v[i];
		if(dist < mindist) {mindist = dist; count=1;}
		else if(dist == mindist) {count++;}
	}
	cout << mindist << " " << count << endl;
	return 0;
}