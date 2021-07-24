#include <bits/stdc++.h>

using namespace std;

int ways[105];
int dice[2][51];

int calc(int sum) {
	int ans = 0;
	for(int i = 1; i < 51; ++i) {
		if(sum - i > 0 && sum - i < 51 && dice[0][i] != 0 && dice[1][sum - i] != 0) {
			ans += dice[0][i] * dice[1][sum - i]; 
		}
		// NO NEED NOTE:
		// if(i != sum - i && dice[1][i] != 0 && dice[0][sum - i] != 0) {
		// 	ans += dice[1][i] * dice[0][sum - i];
		// }
	}
	return ans;
}

int main() {
	freopen("in", "r", stdin);
	int val;
	memset(ways, 0, sizeof(ways));
	memset(dice, 0, sizeof(dice));
	for(int i = 0; i < 6; ++i) {
		scanf("%d", &val);
		++dice[0][val];
	}
	for(int i = 0; i < 6; ++i) {
		scanf("%d", &val);
		++dice[1][val];
	}
	for(int sum = 1; sum < 101; sum++) {
		ways[sum] = calc(sum);
	}
	int maxwayssum = 0; 
	for(int i = 1; i < 101; ++i) {
		if(ways[maxwayssum] < ways[i]) {
			maxwayssum = i;
		}
	}
	printf("%d", maxwayssum);
	return 0;
}