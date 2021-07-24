#include <iostream>
#include <graphics.h>

using namespace std;

int main() {
	int gd = DETECT, gm;
	// initwindow(800,600,"title");
	initgraph (&gd, &gm, NULL);

	for(int j=0; j<100; j+=30){for(int i=0; i<600; i+=40){bar(10+i,10+j,40+i,30+j);}}
	
	

	// rectangle(640,10,60,30);
	// rectangle(50,10,80,30);

	// for(int i=0; i<100 ;i++) {
	// 	setbkcolor(5);
	// 	cleardevice();
	// 	circle (100+i, getmaxy()/2, 100);
	// 	circle (120+i, getmaxy()/2, 120);
	// 	circle (140+i, getmaxy()/2, 140); 
	// 	outtextxy (getmaxx()/2-40+i, getmaxy()/2, "virtualloops");
	// }
	

	delay(10000);
	return 0; 
}