#include <iostream>
#include<graphics.h>
using namespace std;

//Translation
void translate(){
	int gd = DETECT, gm, x1f, y1f, x2f, y2f, x1, x2, y1, y2, w, z;
		
	cout<<"Enter the initial co-ordinates of rectangle: ";
	cin>>x1>>y1>>x2>>y2;
	cout<<"Enter the translation on X-Axis: ";
	cin>>w;
	cout<<"Enter the translation on Y-Axis: ";
	cin>>z;
	x1f = x1 + w;
	x2f = x2 + w;
	y1f = y1 + z;
	y2f = y2 + z;
	
	while(x1!=x1f || y1!=y1f || x2!=x2f || y2!=y2f){
		initgraph(&gd, &gm, NULL);
		rectangle(x1, y1, x2, y2);
		delay(100);
		cleardevice();
		x1 += 3;
		x2 += 3;
		y1 += 3;
		y2 += 3;
	}
	float maxx,maxy;
	
	maxx=getmaxx();
	
	maxy=getmaxy();
	
	maxx=maxx/2;
	maxy=maxy/2;
	setcolor(GREEN);
	line(0,maxy,maxx*2,maxy);
	line(maxx,0,maxx,maxy*2);
	setcolor(WHITE);
	closegraph();
}


int main(){
	int gd = DETECT, gm;
	
	translate();
	closegraph();
	return 0;
}
