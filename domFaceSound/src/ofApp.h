#pragma once

#include "ofMain.h"
#include "SpectrumDrawer.h"
#include "PlayerHead.h"
#include "ofxGui.h"
#include "ofxAssimpModelLoader.h"

#define BUFFER_SIZE 8192
#define SAMPLE_RATE 44100
#define INITIAL_BUFFER_SIZE 512
#define BIT 512

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
    
    void openFile(string URL="");
    
    float line;
    
    int	maxHertz;
    
    double sineBuffer[514];
    
    float remainder;
    float wave;
    
    float outp[INITIAL_BUFFER_SIZE];
    float amp[BIT];
    int hertzScale[BIT];
    float phases[BIT];
    
    
    SpectrumDrawer* spectrum;
    PlayerHead* playerHead;
    
    void guiSetting();
    ofxPanel gui;
    ofxFloatSlider speed;
    ofxButton openf;
    ofxButton openm;
    ofxToggle invert;
    ofxToggle square;
    ofxFloatSlider maxHz;
    ofxFloatSlider minHz;
    ofxFloatSlider lineSize;
    ofxToggle reset;
    ofxToggle imageFormat;
    ofxButton modelSelect;
    ofxButton returnZero;
    ofxToggle pointView;
    ofxToggle imageProcessView;
    
    ofxToggle errorMath;
    ofxIntSlider errorLength;
    ofxFloatSlider fadeLength;
    
    ofxFloatSlider maxZDepth;
    ofxFloatSlider minZDepth;
    ofxToggle zDepthShape;
    
    ofxIntSlider brightness;
    ofxIntSlider volume;
    ofxLabel frameRate;
    
    bool bGuiView;


    //3D Model
    ofxAssimpModelLoader model1;
    ofMesh mesh;
    ofLight	light;
    ofEasyCam cam;
    
    void pointDraw();
    int numPoint;

    int modelIndex;
    ofFbo fbo;
    ofTexture texScreen;
    ofRectangle captureRect;
    void captureFunction();
    ofImage captureImage;
    ofTexture texProcessScreen;
    ofImage captureProcessImage;
    ofRectangle captureProcessRect;
    
    bool imageProcessCapture;
    
    ofMatrix4x4 setMatrix;
    
    void imageFormatButtonClick(bool &_b);

    int captureH, captureW;
    
    bool bImageCapture;
    void loadCapture(ofImage _img);

    void edgeDraw();
    
    void imageCapture();
    
    int interfaceBackgroundH, interfaceBackgroundW;
    int interfaceBackgroundTop, interfaceBackgroundLeft;
    void interfaceView();
    ofEasyCam camInterface;
    
    
    void zDepthShapeDraw();
    
    ofImage faceImg;
    
    ofSoundStream soundStream;
    
};
