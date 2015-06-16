#include "ofApp.h"

bool my_compare( ofVec3f a, ofVec3f b){
    return a.x < b.x;
}


//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetFrameRate(60);
    ofSetLogLevel(OF_LOG_VERBOSE);
    ofBackground(10);
    
    ofDisableArbTex(); // we need GL_TEXTURE_2D for our models coords.
    //    ofEnableDepthTest();
    ofEnableAlphaBlending();
    
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    
    float _scale1 = 1.0;
    model1.setScale(_scale1, _scale1, _scale1);
    model1.loadModel("mesh01_b/mesh01.obj");
    model1.setPosition(0, 0, 0);
    model1.setScaleNomalization(true);
    
    cam.setAutoDistance(false);
    cam.setPosition(0, 0, 800);
    
    mesh1.setMode(OF_PRIMITIVE_POINTS);
    mesh1 = model1.getMesh(0);
    for (int i=0; i<mesh1.getNumVertices(); i++) {
        //        mesh1.addColor(ofFloatColor(0,0,0,1));
        //        mesh1.setNormal(i, ofVec3f(10,10,10));
    }
    mesh1.enableColors();
    mesh1.enableIndices();
    
    lineMesh.setMode(OF_PRIMITIVE_LINES);
    
        glEnable(GL_POINT_SMOOTH); // use circular points instead of square points
        glPointSize(1); // make the points bigger
    
    //    ofPoint _posAll = ofPoint(0, -ofGetHeight()*0.5, 0);
    //    ofTranslate(_posAll);
    //    ofRotateZ(180);
    //
    //    float _scale = 40;
    //    ofScale( _scale, _scale, _scale );
    
    numPoint = mesh1.getNumVertices();
    point3D.resize(numPoint);
    
    for (int i=0; i<numPoint; i++) {
        mesh1.setVertex(i, mesh1.getVertex(i)*40);
        point3D[i] = mesh1.getVertex(i);
        
        int _randomRange = 3000000;
        offsets.push_back(ofVec3f(ofRandom(0,_randomRange), ofRandom(0,_randomRange), ofRandom(0,_randomRange)));
    }
    
    float _length = 100;
    ofVec3f _zLength = ofVec3f(0,0,_length);
    
    for (int i=0; i<numPoint; i++) {
        ofVec3f _startPoint = point3D[i] +_zLength;
        ofVec3f _endPoint = point3D[i] -_zLength;
        
        lineMesh.addVertex(_startPoint);
        lineMesh.addVertex(_endPoint);
        
        vboLine.setMesh(lineMesh, GL_STATIC_DRAW);
        
    }
    
    //    std::sort(point3D.begin(), point3D.end(), my_compare);
    
    changePoint = 0;
    sphere.setRadius(5);
    
    gui.setup();
    gui.add(pointView.setup("Point View", true));
    gui.add(lineView.setup("Line View", false));
    gui.add(modelView.setup("Model View", false));
    gui.add(sphereView.setup("Sphere View", false));
    gui.add(pointMoving.setup("Moving Points", false));
    gui.add(randomRange.setup("Random Range", 10.0, 0.1, 30.0));
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    changePoint = changePoint + 1;
    if (changePoint>numPoint) changePoint = 0;
    
    
    if (pointMoving) {
        for (int i=0; i<numPoint; i++) {
            ofVec3f vert = mesh1.getVertex(i);
            
            float time = ofGetElapsedTimef();
            float timeScale = 5.0;
            float displacementScale = randomRange;
            ofVec3f timeOffsets = offsets[i];
            
            vert.x += (ofSignedNoise(time*timeScale+timeOffsets.x)) * displacementScale;
            vert.y += (ofSignedNoise(time*timeScale+timeOffsets.y)) * displacementScale;
            vert.z += (ofSignedNoise(time*timeScale+timeOffsets.z)) * displacementScale;
            mesh1.setVertex(i, vert);
            
            point3D[i] = mesh1.getVertex(i);
        }
    } else {
        mesh1 = model1.getMesh(0);
        for (int i=0; i<numPoint; i++) {
            mesh1.setVertex(i, mesh1.getVertex(i)*40);
            point3D[i] = mesh1.getVertex(i);
            
            int _randomRange = 3000000;
            offsets.push_back(ofVec3f(ofRandom(0,_randomRange), ofRandom(0,_randomRange), ofRandom(0,_randomRange)));
        }
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofEnableDepthTest();
    ofEnablePointSprites();
    
    cam.begin();
    
    ofPushMatrix();
    ofPushStyle();
    
    ofPoint _posAll = ofPoint(0, -ofGetHeight()*0.5, 0);
    ofTranslate(_posAll);
    ofRotateX(-40);
    ofRotateZ(180);
    
    if (pointView) {
        pointTestDraw();
    }
    
    if (sphereView) {
        sphere.setPosition(point3D[changePoint]);
        sphere.draw();
        ofVec3f _o = ofVec3f(0,0,-1000);
        ofLine(_o, point3D[changePoint]);
    }
    
    ofPushStyle();
    ofSetColor(255, 30);
    
    if (lineView) {
        vboLine.draw(GL_LINES, 0, lineMesh.getNumVertices());
    }
    
    ofPopStyle();
    ofPopMatrix();
    
    
    ofPushStyle();
    ofSetColor(255, 255);
    if (modelView) {
        normal3DDraw();
    }
    ofPopStyle();
    ofPopMatrix();
    
    
    
    cam.end();
    
    ofDrawBitmapString(ofToString(ofGetFrameRate(),1), 10, ofGetHeight()-10);
    
    guiDrawing();
    
}

void ofApp::pointTestDraw(){
    
    ofPushMatrix();
    ofPushStyle();
    
    
    mesh1.drawVertices();
    
    ofPopStyle();
    ofPopMatrix();
    
}


void ofApp::normal3DDraw(){
    
    ofPushMatrix();
    ofPushStyle();
    
    ofPoint _posAll = ofPoint(0, -ofGetHeight()*0.5, 0);
    ofTranslate(_posAll);
    float _s = 2.2;
    ofScale(_s,_s,_s);
    ofRotateX(-45);
    
    ofPushMatrix();
    ofPoint _pos1 = ofPoint(0, 0, 0);
    ofTranslate(_pos1);
    model1.drawFaces();
    ofPopMatrix();
    
    
    ofPopStyle();
    ofPopMatrix();
    
}



void ofApp::wall3DDraw(){
    
    ofPushMatrix();
    ofPushStyle();
    
    //    ofPoint _posAll = ofPoint(0, -ofGetHeight()*0.5, 0);
    //    ofTranslate(_posAll);
    
    int _modeNum = 5;
    float _spacing = 400;
    float _centerOffset = _spacing * (_modeNum-1) * 0.5;
    
    for (int i=0; i<_modeNum; i++) {
        ofPushMatrix();
        ofPoint _pos1 = ofPoint(-600, i*_spacing-_centerOffset, 0);
        ofTranslate(_pos1);
        model1.drawFaces();
        ofPopMatrix();
    }
    
    ofPopStyle();
    ofPopMatrix();
    
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if (key=='f') {
        fullScreen = !fullScreen;
        ofSetFullscreen(fullScreen);
    }
    
    if (key=='w') {
        wall3D = !wall3D;
    }
    
    if (key=='p') {
        pointTest = !pointTest;
    }
    
    if (key=='n') {
        normal3D = !normal3D;
    }
    
}


//--------------------------------------------------------------
void ofApp::guiDrawing(){
    
    ofPushMatrix();
    ofPushStyle();
    
    ofDisableDepthTest();
    ofDisablePointSprites();
    
    gui.draw();
    
    ofPopStyle();
    ofPopMatrix();
    
}




//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}

