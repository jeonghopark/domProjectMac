#include "ofApp.h"

float sines[514]={0,0.012268,0.024536,0.036804,0.049042,0.06131,0.073547,0.085785,0.097992,0.1102,0.12241,0.13455,0.1467,0.15884,0.17093,0.18301,0.19507,0.20709,0.21909,0.23105,0.24295,0.25485,0.26669,0.2785,0.29025,0.30197,0.31366,0.32529,0.33685,0.34839,0.35986,0.37128,0.38266,0.39395,0.40521,0.41641,0.42752,0.4386,0.44958,0.46051,0.47137,0.48215,0.49286,0.50351,0.51407,0.52457,0.53497,0.54529,0.55554,0.5657,0.57578,0.58575,0.59567,0.60547,0.6152,0.62482,0.63437,0.6438,0.65314,0.66238,0.67151,0.68057,0.68951,0.69833,0.70706,0.7157,0.72421,0.7326,0.74091,0.74908,0.75717,0.76514,0.77298,0.7807,0.7883,0.79581,0.80316,0.81042,0.81754,0.82455,0.83142,0.8382,0.84482,0.85132,0.8577,0.86392,0.87006,0.87604,0.88187,0.8876,0.89319,0.89862,0.90396,0.90912,0.91415,0.91907,0.92383,0.92847,0.93295,0.93729,0.9415,0.94556,0.94949,0.95325,0.95691,0.96039,0.96375,0.96692,0.97,0.9729,0.97565,0.97827,0.98074,0.98306,0.98523,0.98724,0.98914,0.99084,0.99243,0.99387,0.99515,0.99628,0.99725,0.99808,0.99875,0.99927,0.99966,0.99988,0.99997,0.99988,0.99966,0.99927,0.99875,0.99808,0.99725,0.99628,0.99515,0.99387,0.99243,0.99084,0.98914,0.98724,0.98523,0.98306,0.98074,0.97827,0.97565,0.9729,0.97,0.96692,0.96375,0.96039,0.95691,0.95325,0.94949,0.94556,0.9415,0.93729,0.93295,0.92847,0.92383,0.91907,0.91415,0.90912,0.90396,0.89862,0.89319,0.8876,0.88187,0.87604,0.87006,0.86392,0.8577,0.85132,0.84482,0.8382,0.83142,0.82455,0.81754,0.81042,0.80316,0.79581,0.7883,0.7807,0.77298,0.76514,0.75717,0.74908,0.74091,0.7326,0.72421,0.7157,0.70706,0.69833,0.68951,0.68057,0.67151,0.66238,0.65314,0.6438,0.63437,0.62482,0.6152,0.60547,0.59567,0.58575,0.57578,0.5657,0.55554,0.54529,0.53497,0.52457,0.51407,0.50351,0.49286,0.48215,0.47137,0.46051,0.44958,0.4386,0.42752,0.41641,0.40521,0.39395,0.38266,0.37128,0.35986,0.34839,0.33685,0.32529,0.31366,0.30197,0.29025,0.2785,0.26669,0.25485,0.24295,0.23105,0.21909,0.20709,0.19507,0.18301,0.17093,0.15884,0.1467,0.13455,0.12241,0.1102,0.097992,0.085785,0.073547,0.06131,0.049042,0.036804,0.024536,0.012268,0,-0.012268,-0.024536,-0.036804,-0.049042,-0.06131,-0.073547,-0.085785,-0.097992,-0.1102,-0.12241,-0.13455,-0.1467,-0.15884,-0.17093,-0.18301,-0.19507,-0.20709,-0.21909,-0.23105,-0.24295,-0.25485,-0.26669,-0.2785,-0.29025,-0.30197,-0.31366,-0.32529,-0.33685,-0.34839,-0.35986,-0.37128,-0.38266,-0.39395,-0.40521,-0.41641,-0.42752,-0.4386,-0.44958,-0.46051,-0.47137,-0.48215,-0.49286,-0.50351,-0.51407,-0.52457,-0.53497,-0.54529,-0.55554,-0.5657,-0.57578,-0.58575,-0.59567,-0.60547,-0.6152,-0.62482,-0.63437,-0.6438,-0.65314,-0.66238,-0.67151,-0.68057,-0.68951,-0.69833,-0.70706,-0.7157,-0.72421,-0.7326,-0.74091,-0.74908,-0.75717,-0.76514,-0.77298,-0.7807,-0.7883,-0.79581,-0.80316,-0.81042,-0.81754,-0.82455,-0.83142,-0.8382,-0.84482,-0.85132,-0.8577,-0.86392,-0.87006,-0.87604,-0.88187,-0.8876,-0.89319,-0.89862,-0.90396,-0.90912,-0.91415,-0.91907,-0.92383,-0.92847,-0.93295,-0.93729,-0.9415,-0.94556,-0.94949,-0.95325,-0.95691,-0.96039,-0.96375,-0.96692,-0.97,-0.9729,-0.97565,-0.97827,-0.98074,-0.98306,-0.98523,-0.98724,-0.98914,-0.99084,-0.99243,-0.99387,-0.99515,-0.99628,-0.99725,-0.99808,-0.99875,-0.99927,-0.99966,-0.99988,-0.99997,-0.99988,-0.99966,-0.99927,-0.99875,-0.99808,-0.99725,-0.99628,-0.99515,-0.99387,-0.99243,-0.99084,-0.98914,-0.98724,-0.98523,-0.98306,-0.98074,-0.97827,-0.97565,-0.9729,-0.97,-0.96692,-0.96375,-0.96039,-0.95691,-0.95325,-0.94949,-0.94556,-0.9415,-0.93729,-0.93295,-0.92847,-0.92383,-0.91907,-0.91415,-0.90912,-0.90396,-0.89862,-0.89319,-0.8876,-0.88187,-0.87604,-0.87006,-0.86392,-0.8577,-0.85132,-0.84482,-0.8382,-0.83142,-0.82455,-0.81754,-0.81042,-0.80316,-0.79581,-0.7883,-0.7807,-0.77298,-0.76514,-0.75717,-0.74908,-0.74091,-0.7326,-0.72421,-0.7157,-0.70706,-0.69833,-0.68951,-0.68057,-0.67151,-0.66238,-0.65314,-0.6438,-0.63437,-0.62482,-0.6152,-0.60547,-0.59567,-0.58575,-0.57578,-0.5657,-0.55554,-0.54529,-0.53497,-0.52457,-0.51407,-0.50351,-0.49286,-0.48215,-0.47137,-0.46051,-0.44958,-0.4386,-0.42752,-0.41641,-0.40521,-0.39395,-0.38266,-0.37128,-0.35986,-0.34839,-0.33685,-0.32529,-0.31366,-0.30197,-0.29025,-0.2785,-0.26669,-0.25485,-0.24295,-0.23105,-0.21909,-0.20709,-0.19507,-0.18301,-0.17093,-0.15884,-0.1467,-0.13455,-0.12241,-0.1102,-0.097992,-0.085785,-0.073547,-0.06131,-0.049042,-0.036804,-0.024536,-0.012268,0,0.012268
};

void ofApp::setup(){
    
    ofEnableAlphaBlending();
    ofSetupScreen();
    ofSetFrameRate(60);
    
    ofBackground(0);
    
    //    ofDisableArbTex(); // we need GL_TEXTURE_2D for our models coords.
    //    ofEnableDepthTest();
    ofEnablePointSprites();
    
    figureImg.load("domFigure01.jpg");
    
    float _scale1 = 1.0;
    model1.setScale(_scale1, _scale1, _scale1);
    model1.loadModel("domFigure_01.obj");
    model1.setPosition(0, 0, 0);
    model1.setScaleNomalization(true);
    
    mesh.setMode(OF_PRIMITIVE_POINTS);
    mesh = model1.getMesh(0);
    mesh.enableColors();
    mesh.enableIndices();
    
    modelIndex = 0;
    
    glEnable(GL_POINT_SMOOTH);
    glPointSize(1);
    
    numPoint = mesh.getNumVertices();
    for (int i=0; i<numPoint; i++) {
        mesh.addVertex(mesh.getVertex(i));
        mesh.addColor(ofColor(255));
    }
    
    cam.setAutoDistance(false);
    cam.setDistance(27);
    cam.setPosition(-10, -17, 20);
    cam.setOrientation(ofVec3f(75,-88,0));

//    ofMatrix4x4 _set = ofMatrix4x4(-0.999579, -0.0169588, 0.0235487,        0,
//                                   0.0213099, -0.979775, 0.198957,        0,
//                                   0.0196984, 0.199375, 0.979725,        0,
//                                   -0.924138, -16.1977,  42.9644,        1);
//    cam.setTransformMatrix(_set);
    
    captureW = ofGetWidth()-20;
    captureH = BIT;
    
    line = 0;
    
    for (int i = 0; i < 514 ; i ++) {
        sineBuffer[i] = sines[i];
    }
    
    maxHertz = 8000;
    spectrum = new SpectrumDrawer( 1, maxHertz );
    //    spectrum->loadImageSpectrum("model4_downup_contrast.jpg");
    
    playerHead = new PlayerHead();
    
//    soundStream.setDeviceID(0);
//    soundStream.setup(this, 2, 0, SAMPLE_RATE, INITIAL_BUFFER_SIZE, 4 );
    ofSoundStreamSetup( 2, 2, this, SAMPLE_RATE, INITIAL_BUFFER_SIZE, 4 );
//    ofSoundStreamStop();
    
    imageFormat.addListener(this, &ofApp::imageFormatButtonClick);
    
    gui.setup();
    gui.add(frameRate.setup("FrameRate", " "));
    gui.add(modelSelect.setup("Model Select"));
    gui.add(speed.setup("speed", 1.0, 0.0, 10.0) );
    gui.add(openf.setup( "Open Picture", false) );
    gui.add(maxHz.setup( "Spectrum Max HZ", 5000, 300.0, 8000.0) );
    gui.add(minHz.setup( "Spectrum Min HZ", 50, 1.0, 200.0) );
    gui.add(lineSize.setup( "LINE", 13.0, 0.0, 20.0) );
    gui.add(reset.setup("Reset!", ""));
    gui.add(imageFormat.setup("Image Format Quad/Land", true) );
    gui.add(returnZero.setup("Return Zero"));
    gui.add(pointView.setup("Point Cloud", true));
    gui.add(maxZDepth.setup( "Max zDepth", 1.0, 0.0, 10.0) );
    gui.add(minZDepth.setup( "Min zDepth", 0.0, -10.0, 10.0) );
    gui.add(zDepthShape.setup("zDepth Shape", false));
    gui.add(brightness.setup("PointBright", 120, 0, 255));
    gui.add(imageProcessView.setup("ImageProcess", true));
    gui.add(errorMath.setup("error", true));
    gui.add(errorLength.setup("ErrorLength", 20, 2, 50));
    gui.add(fadeLength.setup("FadeLength", 1, 0, 1));
    gui.add(volume.setup("Volume", 10, 0, 20));
    
    texScreen.allocate(captureW, captureH, GL_RGB);
    captureImage.allocate(captureW, captureH, OF_IMAGE_COLOR);
    texProcessScreen.allocate(captureW, captureH, GL_RGB);
    captureProcessImage.allocate(captureW, captureH, OF_IMAGE_COLOR);
    
    bImageCapture = true;
    
    //    camInterface.setAutoDistance(false);
    //    camInterface.setDistance(-1000);
    //    camInterface.move(-500, 0, 1000);
    
    bGuiView = true;
    imageProcessCapture = false;
}


//--------------------------------------------------------------
void ofApp::imageFormatButtonClick(bool &_b){
    
    //    captureImage.clear();
    //    texScreen.clear();
    //    texScreen.allocate(captureW, captureH, GL_RGB);
    //    captureImage.allocate(captureW, captureH, OF_IMAGE_COLOR);
    //    captureRect.set( 10, ofGetHeight()-512-10, captureW, captureH );
    
}

//--------------------------------------------------------------
void ofApp::captureFunction(){
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    //  ooooooooooooooooooooooooooooooaaaaaaaaaaaaaaaaaaaaaaaaaaauuuaaaaaaaaauaaaaaaaaaaaaaaäaaaaaaæaaaaaazzzzzzz
    //    texScreen.loadScreenData( ofGetHeight()-BIT-10, 10, captureW, captureH);
    
    cout << cam.getDistance() << endl;
    cout << cam.getPosition() << endl;
    cout << cam.getOrientationEuler() << endl;
    

    
    if (modelSelect) {
        
        spectrum->stop();
        
        modelIndex++;
        modelIndex = modelIndex%7;
        
        mesh.clear();
        
        switch ( modelIndex ) {
            case 0:
                model1.loadModel("domFigure_01.obj");
                cam.setDistance(27);
                cam.setPosition(-10, -17, 20);
                cam.setOrientation(ofVec3f(75,-88,0));
                figureImg.load("domFigure01.jpg");
                break;

            case 1:
                model1.loadModel("domFigure_05.obj");
                cam.setDistance(45);
                cam.setPosition(29, 32, -10);
                cam.setOrientation(ofVec3f(-100,4,-43));
                figureImg.load("domFigure05.jpg");
                break;

            case 2:
                model1.loadModel("domFigure_06.obj");
                cam.setDistance(22);
                cam.setPosition(-11, 18, 5);
                cam.setOrientation(ofVec3f(-43,0,33));
                figureImg.load("domFigure06.jpg");
                break;

            case 3:
                model1.loadModel("mesh01_b/mesh01.obj");
                cam.setDistance(45);
                cam.setPosition(8, -6, 44);
                cam.setOrientation(ofVec3f(-158,-171,0));
                figureImg.load("mesh01.jpg");
                break;

            case 4:
                model1.loadModel("mesh02_b/mesh02.obj");
                cam.setDistance(45);
                cam.setPosition(3, -14, 43);
                cam.setOrientation(ofVec3f(-165,-174,-3));
                figureImg.load("mesh02.jpg");
                break;

            case 5:
                model1.loadModel("mesh04_b/mesh04.obj");
                cam.setDistance(42);
                cam.setPosition(4, -11, 40);
                cam.setOrientation(ofVec3f(-167,-168,0));
                figureImg.load("mesh05.jpg");
                break;

            case 6:
                model1.loadModel("mesh05_b/mesh05.obj");
                cam.setDistance(67);
                cam.setPosition(-7, -21, 63);
                cam.setOrientation(ofVec3f(-170,173,-2));
                figureImg.load("mesh06.jpg");
                break;

                
                
            default:
                break;
        }
        
//        if ( modelIndex == 1 ) {
//            model1.loadModel("domFigure_05.obj");
//            cam.setDistance(45);
//            cam.setPosition(29, 32, -10);
//            cam.setOrientation(ofVec3f(-100,4,-43));
//        } else if ( modelIndex == 2 ) {
//            model1.loadModel("domFigure_06.obj");
//            cam.setDistance(22);
//            cam.setPosition(-11, 18, 5);
//            cam.setOrientation(ofVec3f(-43,0,33));
//        } else if ( modelIndex == 3 ) {
//            model1.loadModel("domFigure_01.obj");
//            cam.setDistance(27);
//            cam.setPosition(-10, -17, 20);
//            cam.setOrientation(ofVec3f(75,-88,0));
//        }
        mesh = model1.getMesh(0);
        
        numPoint = mesh.getNumVertices();
        
        for (int i=0; i<numPoint; i++) {
            mesh.addVertex(mesh.getVertex(i));
            mesh.addColor(ofColor(255));
        }
        //        imageCapture();
        
    }
    
    
    
    spectrum->speed = speed;
    spectrum->maxHz = maxHz;
    spectrum->minHz = minHz;
    line = lineSize;
    
    if(openf) {
        openFile();
    }
    
    if(reset){
        spectrum->speed = 3;
        spectrum->maxHz = maxHertz;
        spectrum->minHz = 1;
        reset=false;
    }
    
    if (spectrum->playing) {
        playerHead->x1 += speed;
        playerHead->x2 += speed;
        
        if (playerHead->x1>ofGetWidth()-10){
            playerHead->x1 = 10;
            playerHead->x2 = 10;
        }
    }
    
    if (returnZero) {
        playerHead->x1 = 0;
        playerHead->x2 = 0;
    }
    
    frameRate = ofToString(ofGetFrameRate(),1);
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    cam.begin();
    
    ofPushMatrix();
    if (pointView) pointDraw();
    ofPopMatrix();
    
    ofPushMatrix();
    if (zDepthShape) zDepthShapeDraw();
    ofPopMatrix();
    
    cam.end();
    
    setMatrix = cam.getGlobalTransformMatrix();
    //                cout << setMatrix << endl;
    
    
    ofPushMatrix();
    
    spectrum->update();
    playerHead->update();
    
    ofPushMatrix();
    
    ofTranslate(playerHead->x1, 10);
    
    ofPushStyle();
    if ( spectrum->playing ) {
        vector< pair <float,float > > points = playerHead -> getPoints(BIT);
        for(int n = 0;n<BIT;n++){
            ofSetColor(0, 255, 0, 120);
            amp[n] = (amp[n]*line + spectrum -> getAmp(points[n].first, points[n].second))/(line+1);
            hertzScale[n] = int(spectrum -> getFreq(points[n].second));
            
            //        float a = (outp[n]-outp[n+1]);
            //        if (a > .5 or a < - .5) {
            //            ofSetColor(255, 0, 0,255);
            //        }else {
            //            ofSetColor(255, 255, 255,255);
            //        }
            //        if (n<INITIAL_BUFFER_SIZE) {
            //            ofLine(n*2,outp[n]*10.0 + 20 + 532 ,n*2+2,outp[n+1]*10.0 + 20 + 532);
            //        }
            //        ofRect(n*1,0 + 532, 1, amp[n]*10.0);
            
            ofRect( 0, n*1, amp[n]*30.0, 1 );
            
        }
    }
    ofPopStyle();
    ofPopMatrix();
    
    ofPopMatrix();
    
    if (bGuiView) {
        gui.draw();
    }
    
    
    edgeDraw();
    
    if(bImageCapture) {
        bImageCapture = false;
        imageCapture();
    }
    
    interfaceView();
    
    if (!spectrum->playing) {
        if (imageProcessView) {
            //            captureImage.clear();
            //            texScreen.clear();
            ofPushMatrix();
            ofPushStyle();
            texProcessScreen.loadScreenData( 10, ofGetHeight()-512-10, captureW, captureH );
            captureProcessImage.mirror(true, false);
            //        captureProcessRect.set( 10, ofGetHeight()-512-10, captureW, captureH );
            ofPixels _pProcess;
            _pProcess.setImageType(OF_IMAGE_COLOR_ALPHA);
            texProcessScreen.readToPixels(_pProcess);
            
            int r;
            int g;
            int b;
            unsigned char * _rawPixels = _pProcess.getPixels();
            
            int _length = errorLength;
            if (errorMath) {
                for (int j=0; j<captureH; j++) {
                    for (int i=0; i<captureW-_length; i+=_length) {
                        int _index = i + j * (captureW);
                        
                        r = _rawPixels[_index*3];
                        g = _rawPixels[_index*3+ 1];
                        b = _rawPixels[_index*3+ 2];

                        for (int k=0; k<_length; k++) {
                            _pProcess.setColor(i+k, j, ofColor( ((r+g+b)/3.0/85.0)*brightness*(ofMap(k,0,_length,1,fadeLength)) ) );
                        }
                    }
                }
                
                for (int j=0; j<captureH; j++) {
                    for (int i=captureW-_length; i<captureW; i++) {
                        _pProcess.setColor(i, j, ofColor(0) );
                    }
                }
                
            } else {
                for (int j=0; j<captureH; j++) {
                    for (int i=0; i<captureW; i++) {
                        int _index = i + j * captureW;
                        r = _rawPixels[_index*3];
                        g = _rawPixels[_index*3+ 1];
                        b = _rawPixels[_index*3+ 2];
                        
                        if ((r+g+b)/3.0 > brightness) {
                            _pProcess.setColor(i, j, ofColor( ((r+g+b)/3.0/85.0)*brightness,255));
                        } else {
                            _pProcess.setColor(i, j, ofColor(0,255));
                        }
                    }
                }
            }


            _pProcess.mirror(true, false);
            
            captureProcessImage.setFromPixels(_pProcess.getData(), _pProcess.getWidth(), _pProcess.getHeight(), OF_IMAGE_COLOR);
            
            float _size = 0.4;
            captureProcessImage.draw( ofGetWidth()-captureW*_size, 10, captureW*_size, captureH*_size );
            
            figureImg.draw( ofGetWidth()-figureImg.width*0.25, captureH*_size, figureImg.width*0.25, figureImg.height*0.25 );

            ofPopStyle();
            ofPopMatrix();
        }
    }
    
    if (modelSelect) {
        imageCapture();
    }
    
    
}


//--------------------------------------------------------------
void ofApp::pointDraw(){
    
    ofPushMatrix();
    ofPushStyle();
    
    glPointSize(1);
    
    ofSetColor(255);
    mesh.drawVertices();
    
    ofPopStyle();
    ofPopMatrix();
    
    
}

//--------------------------------------------------------------
void ofApp::zDepthShapeDraw(){
    
    ofPushMatrix();
    ofPushStyle();
    for (int i=0; i<mesh.getNumVertices(); i++) {
        float _z = mesh.getVertex(i).z;
        ofSetColor(255, 30);
        if ((_z>minZDepth)&&(_z<maxZDepth)) {
            ofDrawCircle(mesh.getVertex(i).x, mesh.getVertex(i).y, mesh.getVertex(i).z, mesh.getVertex(i).z*0.05);
        }
    }
    ofPopStyle();
    ofPopMatrix();
    
}


//--------------------------------------------------------------
void ofApp::edgeDraw(){
    
    ofPushStyle();
    
    ofSetColor(0);
    ofDrawRectangle(0, 0, ofGetWidth(), 10);
    ofDrawRectangle(0, BIT, ofGetWidth(), 76);
    ofDrawRectangle(0, ofGetHeight()-10, ofGetWidth(), 10);
    ofDrawRectangle(0, 0, 10, ofGetHeight());
    ofDrawRectangle(ofGetWidth()-10, 0, 10, ofGetHeight());
    
    ofPopStyle();
    
}


//--------------------------------------------------------------
void ofApp::interfaceView(){
    
    interfaceBackgroundW = ofGetWidth()-20;
    interfaceBackgroundH = ofGetHeight()-BIT*2-20;
    interfaceBackgroundTop = BIT+20;
    interfaceBackgroundLeft = 10;
    
    //    ofBoxPrimitive _box;
    //    _box.set(70, 70, 70);
    //    camInterface.begin();
    //
    //    _box.drawWireframe();
    //
    //    camInterface.end();
    
}

//--------------------------------------------------------------
void ofApp::imageCapture(){
    
    //        captureImage.clear();
    //    texScreen.clear();
    //    texScreen.allocate(captureW, captureH, GL_RGB);
    //    captureImage.allocate(captureW, captureH, OF_IMAGE_COLOR);
    
    texScreen.loadScreenData( 10, ofGetHeight()-512-10, captureW, captureH );
    captureImage.mirror(true, false);
    captureRect.set( 10, ofGetHeight()-512-10, captureW, captureH );
    ofPixels _p;
    texScreen.readToPixels(_p);
    
    _p.mirror(true, false);
    captureImage.setFromPixels(_p.getData(), _p.getWidth(), _p.getHeight(), OF_IMAGE_COLOR);
    spectrum->loadImageSpectrum(captureImage);
    
}


//--------------------------------------------------------------
void ofApp::audioRequested 	(float * output, int bufferSize, int nChannels){
    
    if(spectrum->playing){
        
        for (int i = 0; i < bufferSize; i++){
            
            wave = 0.0;
            
            for(int n = 0;n<BIT;n++){
                
                if (amp[n]>0.00001) {
                    phases[n] += 512./(44100.0/(hertzScale[n]));
                    
                    if ( phases[n] >= 511 ) phases[n] -=512;
                    
                    //remainder = phases[n] - floor(phases[n]);
                    //wave+=(float) ((1-remainder) * sineBuffer[1+ (long) phases[n]] + remainder * sineBuffer[2+(long) phases[n]])*amp[n];
                    
                    wave+=(sineBuffer[1+ (long) phases[n]])*amp[n];
                }
            }
            
            wave/=10.0;
            if(wave>1.0) wave=1.0;
            if(wave<-1.0) wave=-1.0;
            
            output[i*nChannels    ] = wave * volume;
            output[i*nChannels + 1] = wave * volume;
            outp[i] = wave;
        }
    } else {
        for (int i = 0; i < bufferSize; i++){
            output[i*nChannels    ] = 0;
            output[i*nChannels + 1] = 0;
            outp[i] = 0;
        }
    }
    
    
}

//--------------------------------------------------------------
void ofApp::audioReceived(float * input, int bufferSize, int nChannels){
    
}


//--------------------------------------------------------------
void ofApp::openFile(string URL){
    
    string _output;
    spectrum->pause();
    if(URL==""){
        ofFileDialogResult result = ofSystemLoadDialog("Open File", false, "");
        
        if(result.bSuccess){
            URL = result.filePath;
            _output = "URL to open: \n "+URL;
            string extension;
            for(int i = URL.length()-3; i < URL.length(); i++){
                extension+=URL[i];
            }
            spectrum->loadImageSpectrum(URL);
        }else {
            _output = "OPEN canceled. ";
        }
    }
    
}


//--------------------------------------------------------------
void ofApp::loadCapture(ofImage _img){
    
    spectrum->pause();
    
    spectrum->loadImageSpectrum(_img);
    
}



//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if (key==' '){
        if (spectrum->playing) {
            spectrum->pause();
            ofSoundStreamStop();
            cout << "stop";
        }else {
            spectrum->play();
            ofSoundStreamStart();
            cout << "play";
        }
    } else if (key=='g') {
        bGuiView = !bGuiView;
    }
}


//--------------------------------------------------------------
void ofApp::guiSetting(){
    
}

//--------------------------------------------------------------
void ofApp::close() {
    
    model1.clear();
    mesh.clear();
    spectrum->pause();
    spectrum->stop();
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
    if (key=='c'){
        imageCapture();
    } else if (key=='p') {
        spectrum->loadImageSpectrum(captureProcessImage);
    }
    
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
    playerHead->mouseMoved(x,y);
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    playerHead->mouseDragged(x,y,button);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    playerHead->mousePressed(x,y,button);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    playerHead->mouseReleased(x,y,button);
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo info) {
    
}