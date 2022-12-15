#include<iostream>
#include<graphics.h>
#include<math.h>

using namespace std;

class BRESEN_CIRCLE{

	public:
	int x, y, xi, yi, R, di, Limit, d1, d2;

	void bres_circ(int, int, int);
	void mh();
	void mv();
	void md();
};

void BRESEN_CIRCLE::bres_circ(int x, int y, int R){

	
	xi = 0;
	yi = R;
	di = 2*(1-R);
	Limit = 0;
	
	while(yi >= Limit){
		putpixel(x+xi, y+yi, 4);
		putpixel(x+xi, y-yi, 4);
		putpixel(x-xi, y-yi, 4);
		putpixel(x-xi, y+yi, 4);
		
		if (di < 0){
			d1 = 2*di + 2*yi - 1;
			if (d1 <= 0){
				mh();
			}
			else {
				md();
			}
		}
		else if (di > 0){
			d2 = 2*di - 2*xi -1;
			if (d2 <= 0){
				md();
					
			}
			else {
				mv();			
			}
		}
		else if (di == 0){
			md();
		}
		delay(7);
	}
}


void BRESEN_CIRCLE::mh(){
	
	xi += 1;
	di = di + 2*xi + 1;
}


void BRESEN_CIRCLE::md(){
	
	xi += 1;
	yi = yi - 1;
	di = di + 2*xi - 2*yi + 2;
}


void BRESEN_CIRCLE::mv(){
	
	yi = yi - 1;
	di = di - 2*yi + 1;
}


void dda_line(int x1, int y1, int x2, int y2, int color){
	float i, x, y, length, dx, dy;
	
	if (abs(x2-x1) >= abs(y2-y1)){
		length = abs(x2-x1);
	}
	else {
		length = abs(y2 -y1);
	}
	
	dx = (x2 - x1) / length;
	dy = (y2 -y1) / length;
	
	x = x1 + 0.5;
	y = y1 + 0.5;
	
	i = 1;
	while (i <= length){
		putpixel(x, y, color);
		x += dx;
		y += dy;
		i += 1;
		delay(4);	
	}
}

void figure_a(){
	BRESEN_CIRCLE c1;

	c1.bres_circ(250, 250, 150);
	
	dda_line(250, 100, 120.09619, 325, 4);
	dda_line(250, 100, 379.90381, 325, 4);
	dda_line(120.09619, 325, 379.90381, 325, 4);
	
	c1.bres_circ(250, 250, 75);
	
}
	

void figure_b(){
	BRESEN_CIRCLE c2;
	
	dda_line(200, 150, 600, 150, 5);
	dda_line(200, 150, 200, 450, 5);
	dda_line(200, 450, 600, 450, 5);
	dda_line(600, 150, 600, 450, 5);
	
	dda_line(400, 150, 200, 300, 5);
	dda_line(400, 150, 600, 300, 5);
	dda_line(200, 300, 400, 450, 5);
	dda_line(400, 450, 600, 300, 5);
	
	c2.bres_circ(400, 300, 120);
	
}

int main(){
	
	int gd = DETECT, gm, ch;
		
	
	
	while (ch != 3){
		cout<<"\n\nFor Figure(a) press--1\tFor Figure(b) press--2\tTo terminate program press--3\nEnter choice: ";
		cin>>ch;
		if (ch == 1){
			
			initgraph(&gd, &gm, NULL);
			figure_a();
			delay(1100);
			closegraph();
					
		}
		else if (ch == 2){
			
			initgraph(&gd, &gm, NULL);
			figure_b();
			delay(1100);
			closegraph();
		}
		
		else if (ch == 3){
			cout<<"\n\nThankyou!"<<endl;
		}
		
		else {
			cout<<"\n\nEnter a valid choice!"<<endl;
		}
		
	}
	closegraph();
		
return 0; 

}
