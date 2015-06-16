#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    XML.loadFile("map.osm.xml");
    

    mesh.setMode(OF_PRIMITIVE_POINTS);
    mesh.enableColors();

    glPointSize(2);
    
    int numTags = XML.getNumTags("osm:node");
    
    if (numTags>0) {
        XML.pushTag("osm", numTags-1);
        
        float _fMinlat, _fMinlon, _fLat, _fLon;
        
        int numBoundTags = XML.getNumTags("node");

        if (numBoundTags>0) {
            float _minlat = XML.getAttribute("bounds", "minlat", 0.0);
            _fMinlat = _minlat;
            float _minlon = XML.getAttribute("bounds", "minlon", 0.0);
            _fMinlon = _minlon;
        }
    
        int numNodeTags = XML.getNumTags("node");
        
        if (numNodeTags>0) {

            for (int i=0; i<numNodeTags; i++){

                float _lat = XML.getAttribute("node", "lat", 0.0, i);
                _fLat = _lat;
                
                float _lon = XML.getAttribute("node", "lon", 0.0, i);
                _fLon = _lon;

                ofVec3f _mV = ofVec3f( _fLon - _fMinlon, _fLat - _fMinlat, 0) * ofVec3f( 1, 1, 1);
                
                mesh.addVertex( _mV * 10000 );
                mesh.addColor(ofFloatColor(1.0, 0.0, 0.0));
                
            }
            
        
        }
    }
    
    
    for (int i=0; i<lat.size(); i++) {
    }

    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    cam.begin();
    mesh.draw();
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
