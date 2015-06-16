#include "PlayerHead.h"

//--------------------------------------------------------------
PlayerHead::PlayerHead(){
	cout << "hello";
	x1 = 10;
	y1 = 10;
	x2 = 10;
	y2 = 522;
	
	dragging1=false;
	dragging2=false;
}


void PlayerHead::update(){
	ofSetColor(255, 255, 255);
//	ofCircle(x1, y1, 3);
//	ofCircle(x2, y2, 3);
	ofLine(x1, y1, x2, y2);
}

void PlayerHead::mouseMoved(int x, int y) {
	//cout << "hello";
}

void PlayerHead::mousePressed(int x, int y, int button) {
	//if(e.x>x-10 and e.x<x+10){
	//	dragging = true;
	//}
	
	if(distance(x,x1,y,y1)<10){
		dragging1 = true;
	}
	if(distance(x,x2,y,y2)<10){
		dragging2 = true;
	}
}

void PlayerHead::mouseDragged(int x, int y, int button) {
	if(dragging1){
		if(x<10){
			x1 = fmax(x, 10);
		}else {
			x1 = fmin(x, ofGetWidth()-10);
		}

		if (y<10) {
			y1 = fmax(y, 10);
		}else {
			y1 = fmin(y, 522);
		}
	}
	if(dragging2){
		if(x<10){
			x2 = fmax(x, 10);
		}else {
			x2 = fmin(x, ofGetWidth()-10);
		}
		
		if (y<10) {
			y2 = fmax(y, 10);
		}else {
			y2 = fmin(y, 522);
		}
	}
}
vector< pair <float,float > > PlayerHead::getPoints(int bit){
	vector< pair <float,float > > tomb;
	for (int i = 0; i<bit; i++) {
		pair <float,float > point;
		float _X = (float)(x2-x1)/(float)bit * (float)i;
		
		float _Y = (float)(y2-y1)/(float)bit * (float)i;
		
		_X += x1;
		_Y += y1;
		point.first = _X;
		point.second = _Y;
		tomb.push_back(point);
	}
	return tomb;
}

int fmax (int a,int b){
	if(a>=b){
		return a;
	}else {
		return b;
	}
}

int fmin (int a,int b){
	if(a>=b){
		return b;
	}else {
		return a;
	}	
}

int PlayerHead::distance(int _x1, int _x2, int _y1, int _y2){
	return sqrt(pow(_x2-_x1,2.0) + pow(_y2-_y1,2.0));
}

void PlayerHead::mouseReleased(int x, int y, int button) {
	if(dragging1){
		dragging1 = false;
	}
	if(dragging2){
		dragging2 = false;
	}
}