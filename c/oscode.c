#include <stdio.h>
#include <string.h>

void exec1(char *c) {
	FILE* fp = fopen(c,"r");
	char a = fgetc(fp);
	while(a!=EOF) {
		fputc(a,stdout);
		a = fgetc(fp);
	}
	fclose(fp);
	printf("\n");
}

void exec2(char *c) {
	FILE* fp = fopen(c,"w");
	char a;
	getchar();
	a = fgetc(stdin);
	while(a!=EOF) {
		fputc(a,fp);
		a = fgetc(stdin);
	}
	fclose(fp);
}

int main() {
	char cmd[5];	
	char filename[10];
	scanf("%s",cmd);
	if(!strcmp(cmd,"cat")) {
		scanf("%s",filename);
		if(!strcmp(filename,">")) {
			scanf("%s",filename);
			exec2(filename);
			return 0;
		}
		else exec1(filename);
	}
	else printf("Invalid Command!\n");
	return 0;
}