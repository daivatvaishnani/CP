#include <bits/stdc++.h>

using namespace std;

const int maxt = 1e5;

int g[maxt];

int main() {
	int tot, n, choice;
	bool chance = 1, cheat = 0;
	printf("Can you beat Grundy at the game of NIM!!\n");
	printf("Enter total coins : ");
	scanf("%d", &tot);
	printf("Enter max coins that can be taken in one move : ");
	scanf("%d", &n);
	for(int i=0; i<=tot; ++i) {
		g[i] = i % (n + 1);
	}
	while(tot) {
		printf("\n");
		if(chance) {
			choice = 1e5;
			while(choice > n) {
				if(cheat) {
					printf("You cheater!! You can only remove upto %d coins in a move.\n", n);
				}
				printf("Choose wisely!! : ");
				scanf("%d", &choice);
				if(choice > n) cheat = 1;
			}
			cheat = 0;
			tot -= choice;
			printf("You removed %d coins. Now the coins remaining is %d!!\n", choice, tot);
		}
		else {
			if(g[tot] == 0) {
				choice = 1 + rand() % n;
				tot -= choice;
			}
			else {
				choice = g[tot];
				tot -= choice;
			}
			printf("Grundy removed %d coins. Now the coins remaining is %d!!\n", choice, tot);			
		}
		chance ^= 1;		
	}
	if(chance == 1) {
		printf("\nYou lost!! Hahahhaa nobody can beat me I'm very smart!!\n");
	}
	else {
		printf("\nYou must be knowing Grundy Numbers!! -_-\n");
	}
	return 0;
}