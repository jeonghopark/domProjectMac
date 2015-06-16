#pragma once

#include "ofMain.h"

#define BUFFER_SIZE 8192
#define SAMPLE_RATE 44100
#define INITIAL_BUFFER_SIZE 512
#define BIT 24

class ofApp : public ofBaseApp{
    
public:
    
    void setup();
    void update();
    void draw();
    void close();
    
    void keyPressed  (int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    
    void dragEvent(ofDragInfo info);
    
    void audioRequested (float * input, int bufferSize, int nChannels);
    void audioReceived (float * input, int bufferSize, int nChannels);
    
    float line;
    
    int	maxHertz;
    int	minHertz;
    
    double sineBufferNormalRight[514];
    double sineBufferNormalLeft[514];
    double sineBufferLine[514];
    
    float remainderNormalRight;
    float remainderNormalLeft;
    float remainderLine;
    float waveNormalRight;
    float waveNormalLeft;
    float waveLine;
    float ampNormalRight[BIT];
    float ampNormalLeft[BIT];
    float ampLine[BIT];
    int hertzScaleNormalRight[BIT];
    int hertzScaleNormalLeft[BIT];
    int hertzScaleLine[BIT];
    float phasesNormalRight[BIT];
    float phasesNormalLeft[BIT];
    float phasesLine[BIT];
    
    bool bPlaying;
    
    float getPixelNormalRight(int x, int y);
    float getampNormalRight(float x, float y);
    float getFreqNormalRight(float y);
    float getPixelNormalLeft(int x, int y);
    float getampNormalLeft(float x, float y);
    float getFreqNormalLeft(float y);
    float getPixelLine(int x, int y);
    float getAmpLine(float x, float y);
    float getFreqLine(float y);
    
    
    void pointDraw();
    int numPoint;
    
    ofImage domPanorama;
    ofPixels domPanoramaPixel;
    ofImage domPanoramaFromPixel;
    
    
    float movXRight;
    float movXLeft;
    float directionX;
    float threshold;
    
    float widthForLandscape;
    float heightForLandscape;
    
    void audioSpecturmRight();
    void audioSpecturmLeft();
    
    void onePixelDrawRight();
    ofPixels onePixelRight;
    ofImage imgonePixelDrawRight;
    vector<ofColor> onePixelLineRight;
    
    void onePixelDrawLeft();
    ofPixels onePixelLeft;
    ofImage imgonePixelDrawLeft;
    vector<ofColor> onePixelLineLeft;
    
    float widthOnePixel;
    float heightOnePixel;
    
    void onePixelSortDrawRight();
    ofPixels onePixelSort;
    ofImage imgonePixelSortDrawRight;
    
    ofImage panorama360_line;
    ofPixels panorama360_linePixel;
    ofImage panorama360_lineFromPixel;
    ofImage panorama360_line_black;
    ofPixels panorama360_line_blackPixel;
    
    void panoramaLineDraw();
    
    void connectionLineDraw();
    float linePosieion;
    
    void lineonePixelDrawRight();
    ofPixels lineOnePixelRight;
    ofImage imgLineOnePixelRight;
    
    float speed;
    
};


