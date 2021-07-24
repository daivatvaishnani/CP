#include <stdio.h>
#include <string.h>

int main() {
	char name[10];
	int dd,mm,yy,salary;
	FILE* fin = fopen("in","r");
	FILE* fout = fopen("out","w");
	while(1) {
		char c;
		int i=0;
		c = fgetc(fin);
		while(c!=',') {
			name[i]=c;
			++i;
			c = fgetc(fin);
		}
		name[i]='\0';
		fscanf(fin,"%d/%d/%d,%d",&dd,&mm,&yy,&salary);
		c = fgetc(fin);
		if(salary>100) fprintf(fout,"NAME : %s\nDOB : %d/%d/%d\nSALARY : %d\n\n",name,dd,mm,yy,salary);
		if(c==EOF) break;
	}
}