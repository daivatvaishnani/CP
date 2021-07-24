#include <bits/stdc++.h>

using namespace std;

int arr[100005];
bool match[100005];

int main() {
	freopen("in", "r", stdin);
	int T;
	scanf("%d", &T);
	while(T--) {
		memset(arr, 0, sizeof(arr));
		int N, val;
		scanf("%d", &N);
		for(int i = 1; i <= N; ++i) {
			scanf("%d", &arr[i]);
		}
		/*for 1*/
		memset(match, true, sizeof(match));
		int ans1 = 0;
		bool p1 = 0;
		for(int i = 1; i <= N; ++i) {
			if(i & 1) {
				if(i + 1 <= N && arr[i + 1] >= arr[i]) match[i] = 0;
				else if(i - 1 >= 1 && arr[i - 1] >= arr[i]) match[i] = 0;
			}
			else {
				if(i + 1 <= N && arr[i + 1] <= arr[i]) match[i] = 0;
				else if(i - 1 >= 1 && arr[i - 1] <= arr[i]) match[i] = 0;
			}	
		}
		/*for 2*/
		memset(match, true, sizeof(match));
		int ans2 = 0;
		bool p2 = 0;
		for(int i = 1; i <= N; ++i) {
			if(i & 1) {
				if(i + 1 <= N && arr[i + 1] <= arr[i]) match[i] = 0;
				else if(i - 1 >= 1 && arr[i - 1] <= arr[i]) match[i] = 0;
			}
			else {
				if(i + 1 <= N && arr[i + 1] >= arr[i]) match[i] = 0;
				else if(i - 1 >= 1 && arr[i - 1] >= arr[i]) match[i] = 0;
			}
		}
	}
	return 0;
}