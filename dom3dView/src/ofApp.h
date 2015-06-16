#ifndef _TEST_APP
#define _TEST_APP

#include "ofMain.h"
#include "ofxAssimpModelLoader.h"
#include "ofVboMesh.h"

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
    ofxAssimpModelLoader model2;
    ofxAssimpModelLoader model3;
    ofxAssimpModelLoader model4;
    ofxAssimpModelLoader model5;
    ofxAssimpModelLoader model6;
    
    ofMesh mesh1;
    ofMesh mesh2;
    ofMesh mesh3;
    ofMesh mesh4;
    ofMesh mesh5;
    ofMesh mesh6;

    ofLight	light;
    
    ofEasyCam cam;
    
    bool fullScreen;
    
    
    void wall3DDraw();
    bool wall3D;
  
    void pointTestDraw();
    bool pointTest;
    
    void normal3DDraw();
    bool normal3D;
    
};

#endif
