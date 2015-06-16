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
    
    
    ofxFloatSlider randomRange;
    
    void imageFormatButtonClick(bool &_b);

    ofxLabel fullscreen;
    
    ofxPanel gui;
    ofxLabel num_Point;
    ofxToggle pointView;
    ofxToggle lineView;
    ofxToggle modelView;
    ofxToggle sphereView;
    ofxToggle pointMoving;
    ofxToggle seqPlayOnOff;
    ofxButton modelSelect;
    ofxFloatSlider attack;
    ofxFloatSlider decay;
    ofxFloatSlider sustain;
    ofxFloatSlider release;
    ofxFloatSlider gain;
    ofxToggle wavePlaneView;

    ofxToggle imageFormat;
    
    
    void guiDrawing();
    
    int modelIndex;
    
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
    

    void seqPlay();
    int playNoteIndex;
    float minX, maxX, minY, maxY, minZ, maxZ;
    
    ofFbo fbo;
    ofTexture texScreen;
    ofRectangle captureRect;
    void captureFunction();
    ofImage captureImage;
    ofMatrix4x4 setMatrix;
    
    int capture43W, capture43H, capture51W, capture51H;
    int capture43Left, capture43Top, capture51Left, capture51Top;

    int captureW, captureH;
    
};

#endif
