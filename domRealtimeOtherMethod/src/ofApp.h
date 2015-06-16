#pragma once

#include "ofMain.h"

#include "ofxOpenCv.h"
#include "oscillator.h"


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
    
    //video and opencv
    int camW;
    int camH;
    ofVideoGrabber grabber;
    ofxCvColorImage	colorImg;
    ofxCvGrayscaleImage grayImage;
    unsigned char* grayImagePixels;
    std::vector<int> grayscaleVerticalLine;
    
    //audio
    void audioRequested(float * output, int bufferSize, int nChannels);
    ofSoundStream stream;
    std::vector<oscillator> oscillators;

    
};
