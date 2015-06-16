#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetFrameRate(60);
//    ofEnableDepthTest();
    ofEnableAlphaBlending();
    
    columns.resize(24);

    ofDisableArbTex();


    
    widthColumn = 10;
    heightColumn = 10;

    float _xPosColunm[6] = { 394, 507, 694, 811, 997, 1116};
    float _yPosColunm[4] = { 107, 221, 407, 521};
    
    for (int j=0; j<6; j++) {
        for (int i=0; i<4; i++) {
            int _index = i + j * 4;
            ofRectangle _r = ofRectangle( _xPosColunm[j]-widthColumn*0.5, _yPosColunm[i]-heightColumn*1.5, widthColumn, heightColumn );
            columns[_index] = _r;
        }
    }
    
    imgDomPlan.load("domPlan.jpg");
    

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    cam.begin();
    



    ofPushMatrix();
    
    ofTranslate(-imgDomPlan.getWidth()*0.5, -imgDomPlan.getHeight()*0.5);
    
    
    ofPushStyle();
    ofSetColor(255, 80);
    imgDomPlan.draw(0, 0);
    ofPopStyle();
    
    ofPushStyle();
    ofNoFill();
    for (int j=0; j<6; j++) {
        for (int i=0; i<4; i++) {
            int _index = i + j * 4;
            ofSetColor(255, 0, 0, 180);
            ofDrawRectangle(columns[_index]);
            
            ofDrawLine(columns[_index].getMaxX(), columns[_index].getMaxY(), 0, columns[_index].getMaxX(), columns[_index].getMaxY(), 100);
            ofDrawLine(columns[_index].getMinX(), columns[_index].getMinY(), 0, columns[_index].getMinX(), columns[_index].getMinY(), 100);
            ofDrawLine(columns[_index].getMinX(), columns[_index].getMaxY(), 0, columns[_index].getMinX(), columns[_index].getMaxY(), 100);
            ofDrawLine(columns[_index].getMaxX(), columns[_index].getMinY(), 0, columns[_index].getMaxX(), columns[_index].getMinY(), 100);

            ofDrawRectangle(columns[_index].getMinX(), columns[_index].getMinY(), 100,  widthColumn, heightColumn );

            
            
        }
    }
    
    for (int j=0; j<5; j++) {
        for (int i=0; i<3; i++) {
            int _index = i + j * 4;
            
            float _height = 300;
            ofDrawBezier(columns[_index].getMaxX(), columns[_index].getMaxY(), 100,
                         columns[_index].getMaxX(), columns[_index].getMaxY(), _height,
                         columns[_index+5].getMaxX(), columns[_index+5].getMaxY(), _height,
                         columns[_index+5].getMaxX(), columns[_index+5].getMaxY(), 100);
            ofDrawBezier(columns[_index+1].getMaxX(), columns[_index+1].getMaxY(), 100,
                         columns[_index+1].getMaxX(), columns[_index+1].getMaxY(), _height,
                         columns[_index+4].getMaxX(), columns[_index+4].getMaxY(), _height,
                         columns[_index+4].getMaxX(), columns[_index+4].getMaxY(), 100);
            
        }
    }

    ofPopStyle();

    
    ofPopMatrix();
    
    cam.end();
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
    
    cout << x << " : " << y << endl;

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
