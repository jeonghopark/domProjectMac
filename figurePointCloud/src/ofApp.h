#ifndef _TEST_APP
#define _TEST_APP

#include "ofMain.h"
#include "ofxAssimpModelLoader.h"
//#include "ofVboMesh.h"
#include "ofxGui.h"

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
    
    
};

#endif
