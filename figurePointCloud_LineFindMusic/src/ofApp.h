#ifndef _TEST_APP
#define _TEST_APP

#include "ofMain.h"
#include "ofxAssimpModelLoader.h"
//#include "ofVboMesh.h"
#include "ofxGui.h"

#include "ofxStk.h"
#include "DrawSynth.h"


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
    
    ofxAssimpModelLoader model1;
    
    ofMesh mesh1;

    ofLight	light;
    
    ofEasyCam cam;
    
    bool fullScreen;
    
    
    void wall3DDraw();
    bool wall3D;
  
    void pointTestDraw();
    bool pointTest;
    
    void normal3DDraw();
    bool normal3D;
    
    vector<ofVec3f> point3D;
    vector<ofVec3f> rawPoint3D;
    int numPoint;
    
    int changePoint;
  
    ofSpherePrimitive sphere;
    
    ofMesh lineMesh;
    ofVbo vboLine;
    
    ofxToggle pointView;
    ofxToggle lineView;
    ofxToggle modelView;
    ofxToggle sphereView;
    ofxToggle pointMoving;
    
    ofxFloatSlider randomRange;
    
    ofxLabel fullscreen;
    
    ofxPanel gui;
    void guiDrawing();
    
    vector<ofVec3f> offsets;
    
    
    ofVec3f lineStart;
    ofVec3f lineEnd;
    void drawSectionPoint();
    vector<ofVec3f> sectionPoint;
    void sectionPointSetup();
    ofMesh sectionPointMesh;
    
    
    //
    void audioOut(float *output, int bufferSize, int nChannels);
    
    // callback evertime user changes adsr envelope
    void adsrChanged(float &val);
    
    // checks if any keys are being held down;
    bool noNotesDown()const;
    
    // prevents the user from drawing illegal waves
    void cutWaveToPoint(ofPoint cutPoint);
    
    // creates a 5000 size waveTable from the wave drawing
    stk::StkFrames createWaveTableFromDrawing();
    
    // takes the yValue inside the drawing region and converts it to
    // range -1 to 1, where -1 is rext bottom and 1 is rect top
    float transformYValue(float yValue)const ;
    
    ofPolyline wave;
    ofRectangle drawRegion;
    
    DrawSynth drawSynth;
    
    bool drawingBegan;
    bool keyDown;
    
    ofxFloatSlider attack;
    ofxFloatSlider decay;
    ofxFloatSlider sustain;
    ofxFloatSlider release;
    ofxFloatSlider gain;
    
    ofTrueTypeFont instructions;
    
    bool aDown;
    bool sDown;
    bool dDown;
    bool fDown;
    bool gDown;
    bool hDown;
    bool jDown;
    bool kDown;
    bool lDown;
    

};

#endif
