#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetLogLevel(OF_LOG_VERBOSE);
    ofBackground(120);

    ofDisableArbTex(); // we need GL_TEXTURE_2D for our models coords.
    ofEnableDepthTest();
    ofEnableAlphaBlending();
    ofEnablePointSprites();

    ofEnableBlendMode(OF_BLENDMODE_ALPHA);

    float _scale1 = 1.0;
    float _scale2 = 1.0;
    float _scale3 = 1.0;
    float _scale4 = 1.0;
    float _scale5 = 1.0;
    float _scale6 = 1.0;
    
    model1.setScale(_scale1, _scale1, _scale1);
    model2.setScale(_scale2, _scale2, _scale2);
    model3.setScale(_scale3, _scale3, _scale3);
    model4.setScale(_scale4, _scale4, _scale4);
    model5.setScale(_scale5, _scale5, _scale5);
    model6.setScale(_scale6, _scale6, _scale6);
    
    model1.loadModel("mesh01_b/mesh01.obj");
    model1.setPosition(0, 0, 0);
    model1.setScaleNomalization(true);

    model2.loadModel("mesh02_b/mesh02.obj");
    model2.setPosition(0, 0, 0);
    model2.setScaleNomalization(true);

    model3.loadModel("mesh03_b/mesh03.obj");
    model3.setPosition(0, 0, 0);
    model3.setScaleNomalization(true);

    model4.loadModel("mesh04_b/mesh04.obj");
    model4.setPosition(0, 0, 0);
    model4.setScaleNomalization(true);

    model5.loadModel("mesh05_b/mesh05.obj");
    model5.setPosition(0, 0, 0);
    model5.setScaleNomalization(true);

    model6.loadModel("mesh/sculpt.obj");
    model6.setPosition(0, 0, 0);
    model6.setScaleNomalization(true);

    
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
    
    ofEnableDepthTest();
	glEnable(GL_POINT_SMOOTH); // use circular points instead of square points
	glPointSize(1); // make the points bigger

	wall3D = false;
	pointTest = false;
	normal3D = false;

}

//--------------------------------------------------------------
void ofApp::update(){

//    model.update();
    
//    mesh = model.getCurrentAnimatedMesh(0);
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
//    glShadeModel(GL_SMOOTH); //some model / light stuff
//    light.enable();
//    ofEnableSeparateSpecularLight();


    cam.begin();

    if (normal3D) {
        normal3DDraw();
    }
    
    if (wall3D) {
        wall3DDraw();
    }

    if (pointTest) {
        pointTestDraw();
    }
    
    cam.end();
    
    
//   if(ofGetGLProgrammableRenderer()){
//		glPushAttrib(GL_ALL_ATTRIB_BITS);
//		glPushClientAttrib(GL_CLIENT_ALL_ATTRIB_BITS);
//    }
//    glEnable(GL_NORMALIZE);
//
//    ofPushMatrix();
//    
//    ofxAssimpMeshHelper & meshHelper = model.getMeshHelper(0);
//    
//    ofMultMatrix(model.getModelMatrix());
//    ofMultMatrix(meshHelper.matrix);
//    
//    ofMaterial & material = meshHelper.material;
//    if(meshHelper.hasTexture()){
//        meshHelper.getTextureRef().bind();
//    }
//    material.begin();
////    mesh.drawWireframe();
//    material.end();
//    if(meshHelper.hasTexture()){
//        meshHelper.getTextureRef().unbind();
//    }
//    ofPopMatrix();
//
//    if(ofGetGLProgrammableRenderer()){
//    	glPopAttrib();
//    }
//        
//    ofDisableDepthTest();
////    light.disable();
//    ofDisableLighting();
//    ofDisableSeparateSpecularLight();
    
    
    ofDrawBitmapString("f : Fullscreen", 10, 15);
    ofDrawBitmapString("n : Normal Draw", 10, 29);
    ofDrawBitmapString("w : all Draw", 10, 43);
    ofDrawBitmapString("p : point Draw", 10, 57);
    
    
}

void ofApp::pointTestDraw(){
    
    ofPushMatrix();
    ofPushStyle();
    
    ofPoint _posAll = ofPoint(0, -ofGetHeight()*0.5, 0);
    ofTranslate(_posAll);
    ofRotateZ(180);

    float _scale = 40;
    ofScale( _scale, _scale, _scale );
    mesh1.drawVertices();
    
    ofPopStyle();
    ofPopMatrix();

}


void ofApp::normal3DDraw(){
    
    ofPushMatrix();
    ofPushStyle();

    ofPoint _posAll = ofPoint(0, -ofGetHeight()*0.5, 0);
    ofTranslate(_posAll);
    
    ofPushMatrix();
    ofPoint _pos1 = ofPoint(-600, 0, 0);
    ofTranslate(_pos1);
    model1.drawFaces();
    ofPopMatrix();
    
    ofPushMatrix();
    ofPoint _pos2 = ofPoint(-200, 0, 0);
    ofTranslate(_pos2);
    model2.drawFaces();
    ofPopMatrix();
    
    ofPushMatrix();
    ofPoint _pos3 = ofPoint(200, 0, 0);
    ofTranslate(_pos3);
    model3.drawFaces();
    ofPopMatrix();
    
    //    ofPushMatrix();
    //    ofPoint _pos4 = ofPoint(0, 500, 0);
    //    ofTranslate(_pos4);
    //    model4.drawFaces();
    //    ofPopMatrix();
    
    ofPushMatrix();
    ofPoint _pos5 = ofPoint(600, 0, 0);
    ofTranslate(_pos5);
    model5.drawFaces();
    //    model5.drawVertices();
    ofPopMatrix();

    
    ofPushMatrix();
    ofPoint _pos6 = ofPoint(600, 0, 0);
    ofTranslate(_pos6);
    model6.drawFaces();
        model6.drawVertices();
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

        ofPushMatrix();
        ofPoint _pos2 = ofPoint(-200, i*_spacing-_centerOffset, 0);
        ofTranslate(_pos2);
        model2.drawFaces();
        ofPopMatrix();
        
        ofPushMatrix();
        ofPoint _pos3 = ofPoint(200, i*_spacing-_centerOffset, 0);
        ofTranslate(_pos3);
        model3.drawFaces();
        ofPopMatrix();
        
        ofPushMatrix();
        ofPoint _pos5 = ofPoint(600, i*_spacing-_centerOffset, 0);
        ofTranslate(_pos5);
        model5.drawFaces();
        ofPopMatrix();
        
//        ofPushMatrix();
//        ofPoint _pos6 = ofPoint(600, i*_spacing-_centerOffset, 0);
//        ofTranslate(_pos6);
//        model6.drawFaces();

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

