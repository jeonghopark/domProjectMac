// http://en.wikipedia.org/wiki/Note

#include "ofApp.h"

bool my_compareMinX( ofVec3f a, ofVec3f b){
    return a.x < b.x;
}

bool my_compareMinY( ofVec3f a, ofVec3f b){
    return a.y < b.y;
}

bool my_compareMinZ( ofVec3f a, ofVec3f b){
    return a.z < b.z;
}



using namespace stk;

const float NoteC = 65.41;
const float NoteD = 73.42;
const float NoteE = 82.41;
const float NoteF = 87.31;
const float NoteG = 98.0;
const float NoteA = 110.0;
const float NoteB = 123.47;
const float NoteC2 = 130.81;
const float NoteD2 = 146.83;



//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetFrameRate(60);
//    ofSetLogLevel(OF_LOG_VERBOSE);
    ofBackground(120);
    
    ofDisableArbTex(); // we need GL_TEXTURE_2D for our models coords.
    ofEnableDepthTest();
    ofEnableAlphaBlending();
    ofEnablePointSprites();
    
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    
    float _scale1 = 1.0;
    
    model1.setScale(_scale1, _scale1, _scale1);
    
    model1.loadModel("mesh01_b/mesh01.obj");
    model1.setPosition(0, 0, 0);
    model1.setScaleNomalization(true);
    
    
//    cam.setPosition(0, 0, 800);
    
    
    captureW = 2048;
    captureH = 512;
    
    mesh1.setMode(OF_PRIMITIVE_POINTS);
    mesh1 = model1.getMesh(0);
    for (int i=0; i<mesh1.getNumVertices(); i++) {
        //                mesh1.addColor(ofFloatColor(1,1,1,1));
        //        mesh1.setNormal(i, ofVec3f(10,10,10));
    }
    mesh1.enableColors();
    mesh1.enableIndices();
    
    lineMesh.setMode(OF_PRIMITIVE_LINES);
    
    sectionPointMesh.setMode(OF_PRIMITIVE_POINTS);
    sectionPointMesh.enableColors();
    sectionPointMesh.enableIndices();
    
    ofEnableDepthTest();
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
    offsets.resize(numPoint);
    rawPoint3D.resize(numPoint);
    
    for (int i=0; i<numPoint; i++) {
        mesh1.setVertex(i, mesh1.getVertex(i)*40);
        point3D[i] = mesh1.getVertex(i);
        rawPoint3D[i] = mesh1.getVertex(i);
        
        int _randomRange = 3000000;
        offsets[i] = ofVec3f(ofRandom(0,_randomRange), ofRandom(0,_randomRange), ofRandom(0,_randomRange));
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
    
    changePoint = 0;
    sphere.setRadius(10);
    
    imageFormat.addListener(this, &ofApp::imageFormatButtonClick);
    
    gui.setup();
    gui.add(num_Point.setup("Num Pixels", ""));
    gui.add(modelSelect.setup("Model Select"));
    gui.add(pointView.setup("Point View", true));
    gui.add(lineView.setup("Line View", false));
    gui.add(modelView.setup("Model View", false));
    gui.add(sphereView.setup("Sphere View", false));
    gui.add(pointMoving.setup("Moving Points", false));
    gui.add(seqPlayOnOff.setup("Seq Play", false));
    gui.add(randomRange.setup("Random Range", 10.0, 0.1, 30.0));
    gui.add(attack.setup("attack(ms)",10,10,2000));
    gui.add(decay.setup("decay(ms)",200,10,2000));
    gui.add(sustain.setup("sustain",1,0,1));
    gui.add(release.setup("release(ms)",500,10,2000));
    gui.add(gain.setup("gain",.5,0,1));
    gui.add(wavePlaneView.setup("Wave Plane", false) );
    gui.add(imageFormat.setup("Image Format Quad/Land", true) );
    
    drawSynth.setAttack(attack/1000.0);
    drawSynth.setDecay(decay/1000.0);
    drawSynth.setSustain(sustain);
    drawSynth.setRelease(release/1000.0);
    drawSynth.setGain(gain);
    
    attack.addListener(this, &ofApp::adsrChanged);
    decay.addListener(this, &ofApp::adsrChanged);
    sustain.addListener(this, &ofApp::adsrChanged);
    release.addListener(this, &ofApp::adsrChanged);
    gain.addListener(this, &ofApp::adsrChanged);
    
    ofSoundStreamSetup(2, 0);
    
    cam.setAutoDistance(false);
//    cam.setPosition(0, 0, 1500);
    ofMatrix4x4 _set = ofMatrix4x4(-0.992869, 0.00643063, -0.119035,        0,
                                   -0.0135483, -0.998161, 0.0590822,        0,
                                   -0.118436, 0.0602737, 0.991131,        0,
                                   720.824,  245.241,  2414.35,        1);
    cam.setTransformMatrix(_set);
    
    lineStart = ofVec3f(-900,0,0);
    lineEnd = ofVec3f(900,0,0);
    
    num_Point = ofToString(numPoint);
    
    playNoteIndex = 0;
    
    vector<ofVec3f> _sortVec;
    _sortVec = point3D;
    std::sort (_sortVec.begin(), _sortVec.end(), my_compareMinX);
    minX = _sortVec[0].x;
    maxX = _sortVec[numPoint].x;
    std::sort (_sortVec.begin(), _sortVec.end(), my_compareMinY);
    minY = _sortVec[0].y;
    maxY = _sortVec[numPoint].y;
    std::sort (_sortVec.begin(), _sortVec.end(), my_compareMinZ);
    minZ = _sortVec[0].z;
    maxZ = _sortVec[numPoint].z;
    
    cout << minX << endl;
    cout << maxX << endl;
    cout << minY << endl;
    cout << maxY << endl;
    cout << minZ << endl;
    cout << maxZ << endl;
    
    modelIndex = 0;
    
    float _sizeRatio = 1;
    capture43W = ofGetWidth()*_sizeRatio;
    capture43H = ofGetHeight()*_sizeRatio;
    capture43Left = ofGetWidth()*0.5 - capture43W*0.5;
    capture43Top = ofGetHeight()*0.5 - capture43H*0.5;

    capture51W = ofGetWidth()*_sizeRatio;
    capture51H = ofGetHeight()*_sizeRatio*0.2656;
    capture51Left = ofGetWidth()*0.5 - capture51W*0.5;
    capture51Top = ofGetHeight()*0.5 - capture51H*0.5;

}

//--------------------------------------------------------------
void ofApp::imageFormatButtonClick(bool &_b){
    
    captureImage.clear();
//    if (_b) {
//        fbo.allocate(capture43W, capture43H, GL_RGBA);
//        texScreen.allocate(capture43W, capture43H, GL_RGBA);
//        captureImage.allocate(capture43W, capture43H, OF_IMAGE_COLOR_ALPHA);
//        captureRect.set( capture43Left, capture43Top, capture43W, capture43H);
//    } else {
//        fbo.allocate(capture51W, capture51H, GL_RGBA);
//        texScreen.allocate(capture51W, capture51H, GL_RGBA);
//        captureImage.allocate(capture51W, capture51H, OF_IMAGE_COLOR_ALPHA);
//        captureRect.set( capture51Left, capture51Top, capture51W, capture51H);
//    }

    
    fbo.allocate(captureW, captureH, GL_RGBA);
//    texScreen.allocate(captureW, captureH, GL_RGBA);
    captureImage.allocate(captureW, captureH, OF_IMAGE_COLOR_ALPHA);
//    captureRect.set( 0, 0, captureW, captureH);

//    fbo.setAnchorPoint( captureW*-0.5, captureH*-0.5 );

    
    cam.setAutoDistance(false);
    cam.setTransformMatrix(setMatrix);
    captureFunction();
    
//    texScreen.loadScreenData( captureRect.getLeft(), captureRect.getTop(), captureRect.getWidth(), captureRect.getHeight() );


}

//--------------------------------------------------------------
void ofApp::captureFunction(){
    
    fbo.begin();
    ofClear(0,255);
    
    ofPushMatrix();
    cam.setAutoDistance(false);
//    cam.setPosition(0, 0, 1500);
    
    float _ratio = 2;
    ofMatrix4x4 _double = ofMatrix4x4( _ratio, 0, 0, 0,
                                      0, _ratio, 0, 0,
                                      0, 0, _ratio, 0,
                                      0, 0, 0, _ratio );

    cam.setTransformMatrix(setMatrix);
    
    
    cam.begin();
//    ofPoint _posAll = ofPoint(0, -ofGetHeight()*0.5, 0);
//    ofTranslate(_posAll);
//    ofRotateX(-40);
//    ofRotateZ(180);
    
    
    ofScale( _ratio, _ratio, _ratio );
    pointTestDraw();
    cam.end();

    guiDrawing();

    ofPopMatrix();
    
    fbo.end();
    
//    ofPixels _p;
////    fbo.readToPixels(_p);
//    captureImage.setFromPixels(_p.getPixels(), _p.getWidth(), _p.getHeight(), OF_IMAGE_COLOR_ALPHA);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    if (modelSelect) {
        
        attack = 1;
        decay = 1;
        sustain = 1;
        release = 1;
        gain = 0.0;
        
        drawSynth.noteOff(0.0);
        
        attack = 10.0;
        decay = 200.0;
        sustain = 1.0;
        release = 500.0;
        gain = 0.5;
        
        modelIndex++;
        modelIndex = modelIndex%4;
        
        mesh1.clear();
        if ( modelIndex == 1 ) {
            model1.loadModel("mesh02_b/mesh02.obj");
        } else if ( modelIndex == 2 ) {
            model1.loadModel("mesh04_b/mesh04.obj");
        } else if ( modelIndex == 3 ) {
            model1.loadModel("mesh05_b/mesh05.obj");
        } else if ( modelIndex == 0 ) {
            model1.loadModel("mesh01_b/mesh01.obj");
        }
        mesh1 = model1.getMesh(0);
        
        numPoint = mesh1.getNumVertices();
        
        sectionPoint.clear();
        sectionPointMesh.clear();
        
        wave.clear();
        
        point3D.resize(numPoint);
        rawPoint3D.resize(numPoint);
        
        for (int i=0; i<numPoint; i++) {
            mesh1.setVertex(i, mesh1.getVertex(i)*40);
            point3D[i] = mesh1.getVertex(i);
            rawPoint3D[i] = mesh1.getVertex(i);
            
        }
        
        num_Point = ofToString(numPoint);
        
    }
    
    changePoint = changePoint + 1;
    if (changePoint>numPoint) changePoint = 0;
    
    if (ofGetFrameNum()%2==0) {
        playNoteIndex = playNoteIndex + 1;
    }
    if (playNoteIndex>numPoint) playNoteIndex = 0;
    
    
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
            offsets[i] = ofVec3f(ofRandom(0,_randomRange), ofRandom(0,_randomRange), ofRandom(0,_randomRange));
        }
    }
    
    if (seqPlayOnOff&&sectionPoint.size()>0) {
        seqPlay();
    } else {
        drawSynth.noteOff(0.0);
    }
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    cam.begin();
    
    ofPushMatrix();
    ofPushStyle();
    
//    ofPoint _posAll = ofPoint(0, -ofGetHeight()*0.5, 0);
//    ofTranslate(_posAll);
//    ofRotateX(-40);
//    ofRotateZ(180);
    
    if (pointView) {
        pointTestDraw();
    }
    
//    if (sphereView) {
//        sphere.setPosition(point3D[changePoint]);
//        sphere.draw();
//        ofVec3f _o = ofVec3f(0,0,-1000);
//        ofLine(_o, point3D[changePoint]);
//    }
//    
//    
//    if (seqPlayOnOff&&sectionPoint.size()>0) {
//        ofPushStyle();
//        ofSetColor(255, 0, 0, 120);
//        sphere.setPosition(point3D[playNoteIndex]);
//        sphere.draw();
//        ofPopStyle();
//        ofVec3f _o = ofVec3f(0,0,-1000);
//        ofLine(_o, point3D[playNoteIndex]);
//    }
    
    
    ofPushStyle();
    ofSetColor(255, 30);
    
//    if (lineView) {
//        vboLine.draw(GL_LINES, 0, lineMesh.getNumVertices());
//    }
    
    ofPopStyle();
    
    
//    if (wavePlaneView) {
//        ofPushMatrix();
//        ofPushStyle();
//        
//        ofSetColor(255, 255, 0, 60);
//        ofLine(lineStart, lineEnd);
//        
//        ofPopStyle();
//        ofPopMatrix();
//        ofPushMatrix();
//        ofPushStyle();
//        
//        ofSetColor(255, 0, 0, 60);
//        ofTranslate(lineStart);
//        ofRotateX(90);
//        ofRect(0,-100,0,1800,200);
//        
//        ofPopStyle();
//        ofPopMatrix();
//        
//        
//        ofPopStyle();
//        ofPopMatrix();
//    }
    
    ofPopMatrix();

    ofPushMatrix();
    ofPushStyle();
    ofSetColor(255, 255);
    if (modelView) {
        normal3DDraw();
    }
    ofPopStyle();
    ofPopMatrix();
    
    
    cam.end();
    
    setMatrix = cam.getGlobalTransformMatrix();
//    cout << setMatrix << endl;

    ofDrawBitmapString(ofToString(ofGetFrameRate(),1), 10, ofGetHeight()-10);
    
    guiDrawing();
    
    
    drawSectionPoint();
    
    ofPushStyle();
    ofSetColor(255, 0, 0, 120);
    ofNoFill();
    ofRect(captureRect);
    ofPopStyle();
    
    
//    captureImage.draw(10, 1000, captureRect.getWidth()*0.15, captureRect.getHeight()*0.15);
//    texScreen.draw(10, 1000, captureRect.getWidth()*0.15, captureRect.getHeight()*0.15);
    
    ofPushMatrix();
    
//    ofPushStyle();
//    ofSetColor(0, 120);
//    ofFill();
//    ofRect(10, 500, captureRect.getWidth()*0.15, captureRect.getHeight()*0.15);
//    ofPopStyle();

    ofPixels _p;
    fbo.readToPixels(_p);
    captureImage.setFromPixels(_p.getPixels(), captureW, captureH, OF_IMAGE_COLOR_ALPHA);
    captureImage.mirror(true, false);
    ofSetColor(255, 255);
    captureImage.draw(ofGetWidth()*0.5-captureW*0.15, ofGetHeight()*0.01, captureW*0.15, captureH*0.15);
    
    ofPopMatrix();
    
}

//--------------------------------------------------------------
void ofApp::pointTestDraw(){
    
    ofPushMatrix();
    ofPushStyle();
    
    glPointSize(1);
    mesh1.drawVertices();
    
    ofPopStyle();
    ofPopMatrix();
    
}


//--------------------------------------------------------------
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


//--------------------------------------------------------------
void ofApp::seqPlay(){
    
    ofVec3f _note = point3D[playNoteIndex];
    
    int _intScale[10] = {12,19,24,26,28,31,33,36,38,43};
    
    int _pitch = (int)ofMap( _note.z, minZ, maxZ, 0, 9, true );
    float _volume = ofMap( _note.y, minY, maxY, 0, 1 );
    
    float _fq = 440.0 * pow(2.0, (_intScale[_pitch]+24-69.0)/12.0 );
    
    int _pitchSelection;
    
    //    for (int i=0; i<5; i++) {
    //        for (int j=0; j<9; j++) {
    //            _pitchSelection = _intScale[i] + 12 * j;
    //
    //            if (_pitch == _pitchSelection) _volume = 0.0;
    //
    //        }
    //    }
    
    
    //    cout << "_pitch : " <<  _pitch << endl;
    //    cout << "_fq    : " <<  _fq << endl;
    //    cout << "_Volmu : " <<  _volume << endl;
    drawSynth.noteOn(_fq, _volume);
    
}


//--------------------------------------------------------------
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
void ofApp::guiDrawing(){
    
    ofPushMatrix();
    ofPushStyle();
    
    ofDisableDepthTest();
    gui.draw();
    ofEnableDepthTest();
    
    ofPopStyle();
    ofPopMatrix();
    
}



//--------------------------------------------------------------
void ofApp::drawSectionPoint(){
    
    ofPushMatrix();
    ofPushStyle();
    
    ofTranslate(0, ofGetHeight()-200);
    
    glPointSize(3);
    ofSetColor(0, 255, 0);
    
    if (sectionPoint.size()>0) {
        for (int i = 0; i<sectionPoint.size(); i++) {
            sectionPointMesh.addVertex(sectionPoint[i]);
        }
        sectionPointMesh.draw();
    }
    
    ofPopStyle();
    ofPopMatrix();
    
}


//--------------------------------------------------------------
void ofApp::sectionPointSetup(){
    
    sectionPoint.clear();
    sectionPointMesh.clear();
    
    wave.clear();
    drawingBegan = true;
    
    //    sectionPoint.resize(rawPoint3D.size());
    
    float _threshold = 3;
    for (int i=0; i<rawPoint3D.size(); i++) {
        
        if ((rawPoint3D[i].y<lineStart.y+_threshold)&&(rawPoint3D[i].y>lineStart.y-_threshold)) {
            
            ofVec3f _changePos = ofVec3f(
                                         ofMap(rawPoint3D[i].x,minX,maxX,ofGetWidth()-100,400),
                                         ofMap(rawPoint3D[i].z,minZ,maxZ,200,0),
                                         0
                                         );
            
            //            mesh1.setColor(i, ofFloatColor(1.0,0.0,0.0));
            _changePos = _changePos * ofVec3f( 1, 1, 1 );
            sectionPoint.push_back(_changePos);
            
        }
    }
    
    cout << rawPoint3D[0].x << endl;
    cout << rawPoint3D[rawPoint3D.size()].x << endl;
    
    StkFrames frames = createWaveTableFromDrawing();
    drawSynth.setWaveTable(frames);
    
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
    
    
    if (key == '1') {
        if (!aDown) {
            drawSynth.noteOn(NoteC, gain);
            aDown = true;
        }
    }else if (key == '2'){
        if (!sDown) {
            drawSynth.noteOn(NoteD, gain);
            sDown = true;
        }
    }else if (key == '3'){
        if (!dDown) {
            drawSynth.noteOn(NoteE, gain);
            dDown = true;
        }
    }else if (key == '4'){
        if (!fDown) {
            drawSynth.noteOn(NoteF, gain);
            fDown = true;
        }
    }else if (key == '5'){
        if (!gDown) {
            drawSynth.noteOn(NoteG, gain);
            gDown = true;
        }
    }else if(key == '6'){
        if (!hDown) {
            drawSynth.noteOn(NoteA, gain);
            hDown = true;
        }
    }else if (key == '7'){
        if (!jDown) {
            drawSynth.noteOn(NoteB, gain);
            jDown = true;
        }
        
    }else if (key =='8'){
        if (!kDown) {
            drawSynth.noteOn(NoteC2, gain);
            kDown = true;
        }
    }else if (key == '9'){
        if (!lDown) {
            drawSynth.noteOn(NoteD2, gain);
            lDown = true;
        }
    }
    
}



//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
    switch (key) {
        case '1':
            aDown = false;
            break;
        case '2':
            sDown = false;
            break;
        case '3':
            dDown = false;
            break;
        case '4':
            fDown = false;
            break;
        case '5':
            gDown = false;
            break;
        case '6':
            hDown = false;
            break;
        case '7':
            jDown = false;
            break;
        case '8':
            kDown = false;
            break;
        case '9':
            lDown = false;
        default:
            break;
    }
    
    // have to do this check to allow legato style playing
    if (noNotesDown()) {
        drawSynth.noteOff(.5);
    }
    
    
    float _chnageZ = 20;
    if (key=='s') {
        lineStart.y = lineStart.y + _chnageZ;
        //        lineStart.z = lineStart.z - _chnageZ;
        lineEnd.y = lineEnd.y + _chnageZ;
        //        lineEnd.z = lineEnd.z - _chnageZ;
        
        if(lineStart.y>0) {
            lineStart.y = 0;
            lineEnd.y = 0;
        }
        
        sectionPointSetup();
        
        attack = 1;
        decay = 1;
        sustain = 1;
        release = 1;
        gain = 0.0;
        
        drawSynth.noteOff(0.0);
        seqPlayOnOff = false;
        
        attack = 10.0;
        decay = 200.0;
        sustain = 1.0;
        release = 500.0;
        gain = 0.5;
        
    }
    
    if (key=='w') {
        lineStart.y = lineStart.y - _chnageZ;
        //        lineStart.z = lineStart.z + _chnageZ;
        lineEnd.y = lineEnd.y - _chnageZ;
        //        lineEnd.z = lineEnd.z + _chnageZ;
        
        if(lineStart.y<minY) {
            lineStart.y = minY;
            lineEnd.y = minY;
        }
        
        sectionPointSetup();
        
        attack = 1;
        decay = 1;
        sustain = 1;
        release = 1;
        gain = 0.0;
        
        drawSynth.noteOff(0.0);
        seqPlayOnOff = false;
        
        attack = 10.0;
        decay = 200.0;
        sustain = 1.0;
        release = 500.0;
        gain = 0.5;
        
    }
    
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


//--------------------------------------------------------------

bool ofApp::noNotesDown() const{
    if (!(aDown || sDown || dDown || fDown || gDown || hDown || jDown || kDown || lDown)) {
        return true;
    }else{
        return false;
    }
}

//--------------------------------------------------------------

void ofApp::adsrChanged(float &val){
    drawSynth.setAttack(attack/1000.0);
    drawSynth.setDecay(decay/1000.0);
    drawSynth.setSustain(sustain);
    drawSynth.setRelease(release/1000.0);
    drawSynth.setGain(gain);
}

//--------------------------------------------------------------

void ofApp::cutWaveToPoint(ofPoint cutPoint){
    vector<ofPoint> &points = sectionPoint;
    ofPoint lastPoint = points.back();
    points.pop_back();
    lastPoint = points.back();
}

//--------------------------------------------------------------

stk::StkFrames ofApp::createWaveTableFromDrawing(){
    int numberOfFrames = sectionPoint.size();
    stk::StkFrames frames(numberOfFrames,1);
    //    for (int i = 0; i < numberOfFrames; i++) {
    ////        float xValue = ofMap(i, 0, numberOfFrames-1, drawRegion.x, drawRegion.x+drawRegion.width);
    //        const vector<ofPoint> &points = sectionPoint;
    //        float lerpPercentage;
    //        float firstVal;
    //        float secondVal;
    //        float yValue;
    //        for (int j = 0; j < sectionPoint.size()-1; j++) {
    //            firstVal = points[j].x;
    //            secondVal = points[j+1].x;
    //            lerpPercentage = (0-firstVal)/(secondVal - firstVal);
    //            ofPoint newPoint = points[j].interpolated(points[j+1], lerpPercentage);
    //            yValue = transformYValue(newPoint.y);
    //            break;
    //
    //        }
    //        frames[i] = yValue;
    //    }
    
    for (int i=0; i<sectionPoint.size()-1; i++){
        frames[i] = ofMap(sectionPoint[i].y, -300, 300, -1, 1);
    }
    return frames;
}

//--------------------------------------------------------------

float ofApp::transformYValue(float yValue) const{
    return -ofMap(yValue, -300, 300, -1, 1);
}

//--------------------------------------------------------------

void ofApp::audioOut(float *output, int bufferSize, int nChannels){
    for (int i = 0; i < bufferSize; i++) {
        float value = drawSynth.tick();
        output[2*i] = value;
        output[2*i+1] = value;
    }
}


