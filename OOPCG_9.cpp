#include <iostream>
#include<graphics.h>
using namespace std;


const int INSIDE = 0; // 0000
const int LEFT = 1; // 0001
const int RIGHT = 2; // 0010
const int BOTTOM = 4; // 0100
const int TOP = 8; // 1000

//Rectangle Corner Points
const int x_max = 400;
const int y_max = 300;
const int x_min = 100;
const int y_min = 100;


int computeCode(double x, double y)
{
	
	int code = INSIDE;

	if (x < x_min) 
		code |= LEFT;
	else if (x > x_max) 
		code |= RIGHT;
	if (y < y_min) 
		code |= BOTTOM;
	else if (y > y_max) 
		code |= TOP;

	return code;
}

void cohenSutherlandClip(double x1, double y1, double x2, double y2){

	int gd = DETECT, gm;
	
	// Compute region codes for P1, P2
	int code1 = computeCode(x1, y1);
	int code2 = computeCode(x2, y2);


	// Initialize line as outside the rectangular window
	bool accept = false;

	while (true) {
		if ((code1 == 0) && (code2 == 0)) {
			// If both endpoints lie within rectangle
			accept = true;
			break;
		}
		else if (code1 & code2) {
			// If both endpoints are outside rectangle,
			break;
		}
		else{
			int code_out;
			double x, y;

			
			if (code1 != 0)
				code_out = code1;
			else
				code_out = code2;

			
			
			if (code_out & TOP) {
				
				x = x1 + (x2 - x1) * (y_max - y1) / (y2 - y1);
				y = y_max;
			}
			else if (code_out & BOTTOM) {
				
				x = x1 + (x2 - x1) * (y_min - y1) / (y2 - y1);
				y = y_min;
			}
			else if (code_out & RIGHT) {
				
				y = y1 + (y2 - y1) * (x_max - x1) / (x2 - x1);
				x = x_max;
			}
			else if (code_out & LEFT) {
				
				y = y1 + (y2 - y1) * (x_min - x1) / (x2 - x1);
				x = x_min;
			}

			
			if (code_out == code1) {
				x1 = x;
				y1 = y;
				code1 = computeCode(x1, y1);
			}
			else {
				x2 = x;
				y2 = y;
				code2 = computeCode(x2, y2);
			}
		}
	}
	if(accept){
		cout << "Line accepted from " << x1 << ", "<< y1 << " to " << x2 << ", " << y2 << endl;
		initgraph(&gd, &gm, NULL);
		rectangle(x_min, y_min, x_max, y_max);
		line(x1, y1, x2, y2);
		delay(1000);
		closegraph();
		
	}
	
	else{
		cout <<"\n\nLine lies completely outside the boundary!!\n\n" << endl;
	}
}


int main()
{
	int gd = DETECT, gm, x_1, y_1, x_2, y_2;

	cout<<"Enter end-points of line: ";
	cin>> x_1 >> y_1 >> x_2 >> y_2;
	initgraph(&gd, &gm, NULL);
	rectangle(x_min, y_min, x_max, y_max);
	line(x_1, y_1, x_2, y_2);
	delay(1000);
	closegraph();
	cohenSutherlandClip(x_1, y_1, x_2, y_2);

	return 0;
}
