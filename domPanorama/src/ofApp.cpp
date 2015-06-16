#include "ofApp.h"

float sines[514]={0,0.012268,0.024536,0.036804,0.049042,0.06131,0.073547,0.085785,0.097992,0.1102,0.12241,0.13455,0.1467,0.15884,0.17093,0.18301,0.19507,0.20709,0.21909,0.23105,0.24295,0.25485,0.26669,0.2785,0.29025,0.30197,0.31366,0.32529,0.33685,0.34839,0.35986,0.37128,0.38266,0.39395,0.40521,0.41641,0.42752,0.4386,0.44958,0.46051,0.47137,0.48215,0.49286,0.50351,0.51407,0.52457,0.53497,0.54529,0.55554,0.5657,0.57578,0.58575,0.59567,0.60547,0.6152,0.62482,0.63437,0.6438,0.65314,0.66238,0.67151,0.68057,0.68951,0.69833,0.70706,0.7157,0.72421,0.7326,0.74091,0.74908,0.75717,0.76514,0.77298,0.7807,0.7883,0.79581,0.80316,0.81042,0.81754,0.82455,0.83142,0.8382,0.84482,0.85132,0.8577,0.86392,0.87006,0.87604,0.88187,0.8876,0.89319,0.89862,0.90396,0.90912,0.91415,0.91907,0.92383,0.92847,0.93295,0.93729,0.9415,0.94556,0.94949,0.95325,0.95691,0.96039,0.96375,0.96692,0.97,0.9729,0.97565,0.97827,0.98074,0.98306,0.98523,0.98724,0.98914,0.99084,0.99243,0.99387,0.99515,0.99628,0.99725,0.99808,0.99875,0.99927,0.99966,0.99988,0.99997,0.99988,0.99966,0.99927,0.99875,0.99808,0.99725,0.99628,0.99515,0.99387,0.99243,0.99084,0.98914,0.98724,0.98523,0.98306,0.98074,0.97827,0.97565,0.9729,0.97,0.96692,0.96375,0.96039,0.95691,0.95325,0.94949,0.94556,0.9415,0.93729,0.93295,0.92847,0.92383,0.91907,0.91415,0.90912,0.90396,0.89862,0.89319,0.8876,0.88187,0.87604,0.87006,0.86392,0.8577,0.85132,0.84482,0.8382,0.83142,0.82455,0.81754,0.81042,0.80316,0.79581,0.7883,0.7807,0.77298,0.76514,0.75717,0.74908,0.74091,0.7326,0.72421,0.7157,0.70706,0.69833,0.68951,0.68057,0.67151,0.66238,0.65314,0.6438,0.63437,0.62482,0.6152,0.60547,0.59567,0.58575,0.57578,0.5657,0.55554,0.54529,0.53497,0.52457,0.51407,0.50351,0.49286,0.48215,0.47137,0.46051,0.44958,0.4386,0.42752,0.41641,0.40521,0.39395,0.38266,0.37128,0.35986,0.34839,0.33685,0.32529,0.31366,0.30197,0.29025,0.2785,0.26669,0.25485,0.24295,0.23105,0.21909,0.20709,0.19507,0.18301,0.17093,0.15884,0.1467,0.13455,0.12241,0.1102,0.097992,0.085785,0.073547,0.06131,0.049042,0.036804,0.024536,0.012268,0,-0.012268,-0.024536,-0.036804,-0.049042,-0.06131,-0.073547,-0.085785,-0.097992,-0.1102,-0.12241,-0.13455,-0.1467,-0.15884,-0.17093,-0.18301,-0.19507,-0.20709,-0.21909,-0.23105,-0.24295,-0.25485,-0.26669,-0.2785,-0.29025,-0.30197,-0.31366,-0.32529,-0.33685,-0.34839,-0.35986,-0.37128,-0.38266,-0.39395,-0.40521,-0.41641,-0.42752,-0.4386,-0.44958,-0.46051,-0.47137,-0.48215,-0.49286,-0.50351,-0.51407,-0.52457,-0.53497,-0.54529,-0.55554,-0.5657,-0.57578,-0.58575,-0.59567,-0.60547,-0.6152,-0.62482,-0.63437,-0.6438,-0.65314,-0.66238,-0.67151,-0.68057,-0.68951,-0.69833,-0.70706,-0.7157,-0.72421,-0.7326,-0.74091,-0.74908,-0.75717,-0.76514,-0.77298,-0.7807,-0.7883,-0.79581,-0.80316,-0.81042,-0.81754,-0.82455,-0.83142,-0.8382,-0.84482,-0.85132,-0.8577,-0.86392,-0.87006,-0.87604,-0.88187,-0.8876,-0.89319,-0.89862,-0.90396,-0.90912,-0.91415,-0.91907,-0.92383,-0.92847,-0.93295,-0.93729,-0.9415,-0.94556,-0.94949,-0.95325,-0.95691,-0.96039,-0.96375,-0.96692,-0.97,-0.9729,-0.97565,-0.97827,-0.98074,-0.98306,-0.98523,-0.98724,-0.98914,-0.99084,-0.99243,-0.99387,-0.99515,-0.99628,-0.99725,-0.99808,-0.99875,-0.99927,-0.99966,-0.99988,-0.99997,-0.99988,-0.99966,-0.99927,-0.99875,-0.99808,-0.99725,-0.99628,-0.99515,-0.99387,-0.99243,-0.99084,-0.98914,-0.98724,-0.98523,-0.98306,-0.98074,-0.97827,-0.97565,-0.9729,-0.97,-0.96692,-0.96375,-0.96039,-0.95691,-0.95325,-0.94949,-0.94556,-0.9415,-0.93729,-0.93295,-0.92847,-0.92383,-0.91907,-0.91415,-0.90912,-0.90396,-0.89862,-0.89319,-0.8876,-0.88187,-0.87604,-0.87006,-0.86392,-0.8577,-0.85132,-0.84482,-0.8382,-0.83142,-0.82455,-0.81754,-0.81042,-0.80316,-0.79581,-0.7883,-0.7807,-0.77298,-0.76514,-0.75717,-0.74908,-0.74091,-0.7326,-0.72421,-0.7157,-0.70706,-0.69833,-0.68951,-0.68057,-0.67151,-0.66238,-0.65314,-0.6438,-0.63437,-0.62482,-0.6152,-0.60547,-0.59567,-0.58575,-0.57578,-0.5657,-0.55554,-0.54529,-0.53497,-0.52457,-0.51407,-0.50351,-0.49286,-0.48215,-0.47137,-0.46051,-0.44958,-0.4386,-0.42752,-0.41641,-0.40521,-0.39395,-0.38266,-0.37128,-0.35986,-0.34839,-0.33685,-0.32529,-0.31366,-0.30197,-0.29025,-0.2785,-0.26669,-0.25485,-0.24295,-0.23105,-0.21909,-0.20709,-0.19507,-0.18301,-0.17093,-0.15884,-0.1467,-0.13455,-0.12241,-0.1102,-0.097992,-0.085785,-0.073547,-0.06131,-0.049042,-0.036804,-0.024536,-0.012268,0,0.012268
};


float fqNote[24] = {130.81, 138.59, 146.83, 155.56, 164.81, 174.61, 185.00, 196.00, 207.65, 220.00, 233.08, 246.94, 261.63, 277.18, 293.66, 311.13, 329.63, 349.23, 369.99, 392.00, 415.30, 440.00, 466.16, 493.88
};


bool maxX( ofColor a, ofColor b){
    
    float _aSum = a.r + a.g + a.b;
    float _bSum = b.r + b.g + b.b;
    
    return _aSum > _bSum;
}




void ofApp::setup(){
    
    ofSetFrameRate(60);
    ofBackground(0);
    
    domPanorama.load("panorama_up.png");
    domPanoramaPixel.allocate( domPanorama.getWidth(), domPanorama.getHeight(), OF_IMAGE_COLOR_ALPHA );
    domPanoramaPixel = domPanorama.getPixels();
    domPanoramaFromPixel.allocate( domPanorama.getWidth(), domPanorama.getHeight(), OF_IMAGE_COLOR_ALPHA );
    
    panorama360_line.load("panorama_up_line.png");
    panorama360_linePixel.allocate( domPanorama.getWidth(), domPanorama.getHeight(), OF_IMAGE_COLOR_ALPHA );
    panorama360_linePixel = panorama360_line.getPixels();
    
    panorama360_line_black.load("panorama_up_line_black.png");
    panorama360_line_blackPixel.allocate( domPanorama.getWidth(), domPanorama.getHeight(), OF_IMAGE_COLOR_ALPHA );
    panorama360_line_blackPixel = panorama360_line_black.getPixels();
    
    line = 7;
    
    for (int i=0; i<514 ; i++) {
        sineBufferNormalRight[i] = sines[i];
        sineBufferNormalLeft[i] = sines[i];
        sineBufferLine[i] = sines[i];
    }
    
    threshold = 0.9;
    maxHertz = 4000;
    minHertz = 50;
    movXRight = ofGetWidth()*0.5;
    movXLeft = movXRight;
    
    ofSoundStreamSetup( 2, 0, this, SAMPLE_RATE, INITIAL_BUFFER_SIZE, 4 );
    ofSoundStreamStop();
    
    speed = 0.5;
    directionX = speed;
    
    widthForLandscape = ofGetWidth();
    heightForLandscape = domPanorama.getHeight();
    
    widthOnePixel = 30;
    heightOnePixel = (ofGetHeight() - heightForLandscape) * 0.9;
    
    onePixelLineRight.resize(heightOnePixel);
    onePixelRight.allocate( widthOnePixel, heightOnePixel, OF_IMAGE_COLOR_ALPHA );
    
    onePixelLineLeft.resize(heightOnePixel);
    onePixelLeft.allocate( widthOnePixel, heightOnePixel, OF_IMAGE_COLOR_ALPHA );
    
    
    imgonePixelDrawRight.allocate(  widthOnePixel, heightOnePixel, OF_IMAGE_COLOR_ALPHA );
    imgonePixelDrawLeft.allocate(  widthOnePixel, heightOnePixel, OF_IMAGE_COLOR_ALPHA );
    
    onePixelSort.allocate( widthOnePixel, heightOnePixel, OF_IMAGE_COLOR_ALPHA );
    imgonePixelSortDrawRight.allocate(  widthOnePixel, heightOnePixel, OF_IMAGE_COLOR_ALPHA );
    lineOnePixelRight.allocate( widthOnePixel, heightOnePixel, OF_IMAGE_COLOR_ALPHA );
    imgLineOnePixelRight.allocate(  widthOnePixel, heightOnePixel, OF_IMAGE_COLOR_ALPHA );
    
    linePosieion = 150;
    
}


//--------------------------------------------------------------
void ofApp::update(){
    
    if (bPlaying) {
        movXRight = movXRight + directionX;
    }
    if (movXRight > ofGetWidth()) movXRight = ofGetWidth() * 0.5;
    
    movXLeft = ofGetWidth() - movXRight;
    
    float _xPosForImage = movXRight;
    
    if ( bPlaying ) {
        
        for(int n = 0;n<BIT;n++){
            
            int _yRatioRight = (int)ofMap(n, 0, BIT-1, 0, domPanorama.getHeight()-20);
            ampNormalRight[n] = (ampNormalRight[n]*line + getampNormalRight(movXRight, _yRatioRight))/(line+1);
//            hertzScaleNormalRight[n] = int(getFreqNormalRight(n));
            
            int _fqRight = fqNote[ (int)ofMap(getFreqNormalRight(n), minHertz, maxHertz, 0, 24) ] + 220;
            hertzScaleNormalRight[n] = (int)ofMap(getFreqNormalRight(n), minHertz, maxHertz, 1, 10) * 220;

            
            int _yRatioLeft = (int)ofMap(n, 0, BIT-1, 0, domPanorama.getHeight()-20);
            ampNormalLeft[n] = (ampNormalLeft[n]*line + getampNormalLeft(movXLeft, _yRatioLeft))/(line+1);
//            hertzScaleNormalLeft[n] = int(getFreqNormalLeft(n));
            
            int _fqLeft = fqNote[ (int)ofMap(getFreqNormalLeft(n), minHertz, maxHertz, 0, 24) ] + 220;
            hertzScaleNormalLeft[n] = (int)ofMap(getFreqNormalLeft(n), minHertz, maxHertz, 1, 10) * 220;;
            
            //            int _yRatioRight = (int)ofMap(n, 0, BIT-1, 0, domPanorama.getHeight());
            //            ampLine[n] = (ampLine[n]*line + getAmpLine(movX, _yRatioRight))/(line+1);
            //            hertzScaleLine[n] = int(getFreqLine(n));
            
        }
        
    }
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofPushStyle();
    ofSetColor(255, 255);
    domPanorama.draw(0, 0);
    ofSetColor(0, 255, 255, 180);
    panorama360_line.draw(0, 0);
    ofPopStyle();
    //    panoramaLineDraw();
    
    ofPushStyle();
    ofSetColor(0, 255, 0, 255);
    ofDrawLine(movXRight, 0, movXRight, heightForLandscape);
    ofDrawLine(movXLeft, 0, movXLeft, heightForLandscape);
    ofPopStyle();
    
    
    ofPushMatrix();
    
    ofPushMatrix();
    ofTranslate( movXLeft - widthOnePixel * 0, ofGetHeight() - heightOnePixel );
    audioSpecturmLeft();
    ofPopMatrix();
    
    ofPushMatrix();
    ofTranslate( movXLeft - widthOnePixel * 2, ofGetHeight() - heightOnePixel );
    onePixelDrawLeft();
    ofPopMatrix();

    
    
    ofPushMatrix();
    ofTranslate( movXRight + widthOnePixel * 0, ofGetHeight() - heightOnePixel );
    audioSpecturmRight();
    ofPopMatrix();
    
    ofPushMatrix();
    ofTranslate( movXRight + widthOnePixel * 1, ofGetHeight() - heightOnePixel );
    onePixelDrawRight();
    ofPopMatrix();
    
//    ofPushMatrix();
//    ofTranslate( movXRight + widthOnePixel * 2, ofGetHeight() - heightOnePixel );
//    onePixelSortDrawRight();
//    ofPopMatrix();
    
    ofPopMatrix();
    
    
    //    ofPushMatrix();
    //    ofTranslate(ofGetWidth() * 0.5 + widthOnePixel*2, ofGetHeight()-heightOnePixel );
    //    lineonePixelDrawRight();
    //    ofPopMatrix();
    
    
    ofDrawBitmapString( ofToString(ofGetFrameRate(),1), 10, ofGetHeight() - 10 );
    
    //    connectionLineDraw();
    
    
}


//--------------------------------------------------------------
void ofApp::connectionLineDraw(){
    
    ofPushStyle();
    ofSetColor(255, 255, 255, 90);
    ofDrawLine( movXRight, heightForLandscape, ofGetWidth() * 0.5, ofGetHeight() - heightOnePixel );
    ofDrawLine( movXRight, heightForLandscape, ofGetWidth() * 0.5 + 150, ofGetHeight() - heightOnePixel );
    ofDrawLine( movXRight, heightForLandscape, ofGetWidth() * 0.5 - widthOnePixel*2, ofGetHeight() - heightOnePixel );
    ofDrawLine( movXRight, heightForLandscape, ofGetWidth() * 0.5 - widthOnePixel*2 + widthOnePixel, ofGetHeight() - heightOnePixel );
    ofDrawLine( movXRight, heightForLandscape, ofGetWidth() * 0.5 - widthOnePixel*4, ofGetHeight() - heightOnePixel );
    ofDrawLine( movXRight, heightForLandscape, ofGetWidth() * 0.5 - widthOnePixel*4 + widthOnePixel, ofGetHeight() - heightOnePixel );
    ofDrawLine( movXRight, heightForLandscape, ofGetWidth() * 0.5 + widthOnePixel*2, ofGetHeight() - heightOnePixel );
    ofDrawLine( movXRight, heightForLandscape, ofGetWidth() * 0.5 + widthOnePixel*2 + widthOnePixel, ofGetHeight() - heightOnePixel );
    ofPopStyle();
    
    
}






//--------------------------------------------------------------
void ofApp::audioSpecturmRight(){
    
    if ( bPlaying ) {
        ofPushStyle();
        ofSetColor(0, 255, 0, 255);
        for(int n=0; n<BIT; n++){
            int _yRatioLeft = (int)ofMap(n, 0, BIT - 1, 0, heightOnePixel);
            int _yRatioRight = (int)ofMap(n, 0, BIT - 1, 0, heightOnePixel);
            ofDrawRectangle( 0, _yRatioLeft, -ampNormalRight[n] * 30.0, 1 );
            ofDrawRectangle( 0, _yRatioRight, ampNormalRight[n] * 30.0, 1 );
        }
        ofPopStyle();
    }
    
    ofPushStyle();
    ofSetColor(0, 255, 0, 255);
    ofDrawLine( 0, 0, 0, heightOnePixel );
    ofPopStyle();
    
    
}



//--------------------------------------------------------------
void ofApp::audioSpecturmLeft(){
    
    if ( bPlaying ) {
        ofPushStyle();
        ofSetColor(0, 255, 0, 255);
        for(int n=0; n<BIT; n++){
            int _yRatioLeft = (int)ofMap(n, 0, BIT - 1, 0, heightOnePixel);
            int _yRatioRight = (int)ofMap(n, 0, BIT - 1, 0, heightOnePixel);
            ofDrawRectangle( 0, _yRatioLeft, -ampNormalLeft[n] * 30.0, 1 );
            ofDrawRectangle( 0, _yRatioRight, ampNormalLeft[n] * 30.0, 1 );
        }
        ofPopStyle();
    }
    
    ofPushStyle();
    ofSetColor(0, 255, 0, 255);
    ofDrawLine( 0, 0, 0, heightOnePixel );
    ofPopStyle();
    
}


//--------------------------------------------------------------
void ofApp::onePixelDrawRight(){
    
    float _xPosForImage = movXRight;
    for (int n = 0; n<heightOnePixel; n++){
        for (int i = 0; i<widthOnePixel; i++){
            int _yRatioLeft = (int)ofMap(n, 0, heightOnePixel - 1, 0, domPanorama.getHeight());
            ofColor _color = domPanoramaPixel.getColor( _xPosForImage, _yRatioLeft );
            onePixelRight.setColor( i, n, _color );
            
            float _sum = (_color.r + _color.g + _color.b) / 3.0;
            onePixelLineRight[n] = _color;
        }
    }
    
    if (onePixelRight.size()>0) {
        imgonePixelDrawRight.setFromPixels( onePixelRight.getData(), widthOnePixel, heightOnePixel, OF_IMAGE_COLOR_ALPHA );
        imgonePixelDrawRight.draw( 0, 0 );
    }
    
    
}



//--------------------------------------------------------------
void ofApp::onePixelDrawLeft(){
    
    float _xPosForImage = movXLeft;
    for (int n = 0; n<heightOnePixel; n++){
        for (int i = 0; i<widthOnePixel; i++){
            int _yRatioLeft = (int)ofMap(n, 0, heightOnePixel - 1, 0, domPanorama.getHeight());
            ofColor _color = domPanoramaPixel.getColor( _xPosForImage, _yRatioLeft );
            onePixelLeft.setColor( i, n, _color );
            
            float _sum = (_color.r + _color.g + _color.b) / 3.0;
            onePixelLineLeft[n] = _color;
        }
    }
    
    if (onePixelLeft.size()>0) {
        imgonePixelDrawLeft.setFromPixels( onePixelLeft.getData(), widthOnePixel, heightOnePixel, OF_IMAGE_COLOR_ALPHA );
        imgonePixelDrawLeft.draw( 0, 0 );
    }
    
    
}


//--------------------------------------------------------------
void ofApp::onePixelSortDrawRight(){
    
    vector<ofColor> _sortOnePixel = onePixelLineRight;
    std::sort(_sortOnePixel.begin(), _sortOnePixel.end(), maxX);
    
    
    float _xPosForImage = movXRight;
    for (int n = 0; n<heightOnePixel; n++){
        for (int i = 0; i<widthOnePixel; i++){
            int _yRatioLeft = (int)ofMap(n, 0, heightOnePixel - 1, 0, domPanorama.getHeight());
            onePixelSort.setColor( i, n, _sortOnePixel[n] );
        }
    }
    
    if (onePixelRight.size()>0) {
        imgonePixelSortDrawRight.setFromPixels( onePixelSort.getData(), widthOnePixel, heightOnePixel, OF_IMAGE_COLOR_ALPHA );
        imgonePixelSortDrawRight.draw( 0, 0 );
    }
    
    
}


//--------------------------------------------------------------
void ofApp::lineonePixelDrawRight(){
    
    float _xPosForImage = movXRight;
    for (int n = 0; n<heightOnePixel; n++){
        for (int i = 0; i<widthOnePixel; i++){
            int _yRatioLeft = (int)ofMap(n, 0, heightOnePixel - 1, 0, domPanorama.getHeight());
            ofColor _color = panorama360_line_blackPixel.getColor( _xPosForImage, _yRatioLeft );
            lineOnePixelRight.setColor( i, n, _color );
        }
    }
    
    if (lineOnePixelRight.size()>0) {
        ofPushStyle();
        ofSetColor(0, 255, 255, 180);
        imgLineOnePixelRight.setFromPixels( lineOnePixelRight.getData(), widthOnePixel, heightOnePixel, OF_IMAGE_COLOR_ALPHA );
        imgLineOnePixelRight.draw( 0, 0 );
        ofPopStyle();
    }
    
}


//--------------------------------------------------------------
void ofApp::audioRequested 	(float * output, int bufferSize, int nChannels){
    
    if (bPlaying) {
        
        for (int i = 0; i < bufferSize; i+=2){
            
            waveLine = 0.0;
            waveNormalRight = 0.0;
            
            for(int n=0; n<BIT; n++){
                
                if (ampNormalRight[n]>0.00001) {
                    phasesNormalRight[n] += 512. / (44100.0 / (hertzScaleNormalRight[n]));
                    
                    if ( phasesNormalRight[n] >= 511 ) phasesNormalRight[n] -= 512;
                    
                    //remainder = phases[n] - floor(phases[n]);
                    //wave+=(float) ((1-remainder) * sineBuffer[1+ (long) phases[n]] + remainder * sineBuffer[2+(long) phases[n]])*amp[n];
                    
                    if ( phasesNormalRight[n] < 0 ) phasesNormalRight[n] = 0;
                    
                    waveNormalRight += (sineBufferNormalRight[1 + (long)phasesNormalRight[n]]) * ampNormalRight[n];
                }
                
                
                if (ampNormalLeft[n]>0.00001) {
                    phasesNormalLeft[n] += 512. / (44100.0 / (hertzScaleNormalLeft[n]));
                    
                    if ( phasesNormalLeft[n] >= 511 ) phasesNormalLeft[n] -= 512;
                    
                    //remainder = phases[n] - floor(phases[n]);
                    //wave+=(float) ((1-remainder) * sineBuffer[1+ (long) phases[n]] + remainder * sineBuffer[2+(long) phases[n]])*amp[n];
                    
                    if ( phasesNormalLeft[n] < 0 ) phasesNormalLeft[n] = 0;
                    
                    waveNormalLeft += (sineBufferNormalLeft[1 + (long)phasesNormalLeft[n]]) * ampNormalLeft[n];
                }
                
                
                //                if (ampLine[n]>0.00001) {
                //                    phasesLine[n] += 512./(44100.0/(hertzScaleLine[n]));
                //
                //                    if ( phasesLine[n] >= 511 ) phasesLine[n] -= 512;
                //
                //                    //remainder = phases[n] - floor(phases[n]);
                //                    //wave+=(float) ((1-remainder) * sineBuffer[1+ (long) phases[n]] + remainder * sineBuffer[2+(long) phases[n]])*amp[n];
                //
                //                    if ( phasesLine[n] < 0 ) phasesLine[n] = 0;
                //
                //                    waveLine += (sineBufferLine[1 + (long)phasesLine[n]]) * ampLine[n];
                //                }
                
            }
            
            waveLine /= 20.0;
            waveNormalRight /= 20.0;
            waveNormalLeft /= 20.0;
            if(waveLine>1.0) waveLine=1.0;
            if(waveLine<-1.0) waveLine=-1.0;
            if(waveNormalRight>1.0) waveNormalRight=1.0;
            if(waveNormalRight<-1.0) waveNormalRight=-1.0;
            if(waveNormalLeft>1.0) waveNormalLeft=1.0;
            if(waveNormalLeft<-1.0) waveNormalLeft=-1.0;
            
            float _volume = 0.85;
            output[i*nChannels    ] = (waveNormalLeft) / 1.0 * _volume;
            output[i*nChannels + 1] = (waveNormalRight) / 1.0 * _volume;
        }
        
    } else {
        for (int i = 0; i < bufferSize; i++){
            output[i*nChannels    ] = 0;
            output[i*nChannels + 1] = 0;
        }
    }
    
    
}

//--------------------------------------------------------------
void ofApp::audioReceived(float * input, int bufferSize, int nChannels){
    
}



//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}


//--------------------------------------------------------------
void ofApp::close() {
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
    if (key==' ') bPlaying = !bPlaying;
    
    if (bPlaying) {
        ofSoundStreamStart();
    } else {
        ofSoundStreamStop();
    }
    
    if (key==356) {
        directionX = -speed;
    } else if (key==358) {
        directionX = speed;
    }
    
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
    
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
    threshold = ofMap(mouseY, 0, ofGetHeight(), 1, 0);
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
    widthForLandscape = w;
    heightForLandscape = h * 0.3;
    
    widthOnePixel = 100;
    heightOnePixel = (h - heightForLandscape) * 0.8;
    
    onePixelLineRight.resize(heightOnePixel);
    onePixelRight.allocate( widthOnePixel, heightOnePixel, OF_IMAGE_COLOR_ALPHA );
    
    onePixelLineLeft.resize(heightOnePixel);
    onePixelLeft.allocate( widthOnePixel, heightOnePixel, OF_IMAGE_COLOR_ALPHA );
    
    
    imgonePixelDrawRight.allocate(  widthOnePixel, heightOnePixel, OF_IMAGE_COLOR_ALPHA );
    onePixelSort.allocate( widthOnePixel, heightOnePixel, OF_IMAGE_COLOR_ALPHA );
    imgonePixelSortDrawRight.allocate(  widthOnePixel, heightOnePixel, OF_IMAGE_COLOR_ALPHA );
    lineOnePixelRight.allocate( widthOnePixel, heightOnePixel, OF_IMAGE_COLOR_ALPHA );
    imgLineOnePixelRight.allocate(  widthOnePixel, heightOnePixel, OF_IMAGE_COLOR_ALPHA );
    
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo info) {
    
}



//--------------------------------------------------------------
float ofApp::getPixelNormalRight(int x, int y){
    
    ofColor _color = domPanoramaPixel.getColor(x, y);
    
    float _r = _color.r;
    float _g = _color.g;
    float _b = _color.b;
    
    float _sum = 1.0 - (_r + _g + _b) / 255.0 / 3.0;
    
    return _sum;
    
}

//--------------------------------------------------------------
float ofApp::getPixelNormalLeft(int x, int y){
    
    ofColor _color = domPanoramaPixel.getColor(x, y);
    
    float _r = _color.r;
    float _g = _color.g;
    float _b = _color.b;
    
    float _sum = 1.0 - (_r + _g + _b) / 255.0 / 3.0;
    
    return _sum;
    
}


//--------------------------------------------------------------
float ofApp::getPixelLine(int x, int y){
    
    ofColor _color = panorama360_line_blackPixel.getColor(x, y);
    
    float _r = _color.r;
    float _g = _color.g;
    float _b = _color.b;
    
    float _sum = (_r + _g + _b) / 255.0 / 3.0;
    
    return _sum;
    
}



//--------------------------------------------------------------
float ofApp::getampNormalRight(float x, float y){
    
    float _amp = 0;
    _amp = getPixelNormalRight(x, y);
    
    if (_amp<threshold) {
        _amp = 0;
    }
    
    return _amp;
    
    
}


//--------------------------------------------------------------
float ofApp::getampNormalLeft(float x, float y){
    
    float _amp = 0;
    _amp = getPixelNormalLeft(x, y);
    
    if (_amp<threshold) {
        _amp = 0;
    }
    
    return _amp;
    
    
}

//--------------------------------------------------------------
float ofApp::getAmpLine(float x, float y){
    
    float _amp = 0;
    _amp = getPixelLine(x, y);
    
    if (_amp<threshold) {
        _amp = 0;
    }
    
    return _amp;
    
    
}

//--------------------------------------------------------------
float ofApp::getFreqNormalRight(float y){
    float freq=0;
    
    //    if(height>0){
    //    y-=9;
    
    float _maxHz = maxHertz;
    float _minHz = minHertz;
    float yToFreq = (y/BIT)*_maxHz;
    
    //TODO logarithmic scale
    //    freq = 1-(log(yToFreq)-log(_minHz)) / (log(_maxHz)-log(_minHz));
    //    freq *= _maxHz;
    freq = 1-(yToFreq-_minHz) / (_maxHz-_minHz);
    //    freq= (BIT-y+_minHz)/BIT*(_maxHz-_minHz);
    freq *= _maxHz;
    //    }
    
    
    return freq;
    
}


//--------------------------------------------------------------
float ofApp::getFreqNormalLeft(float y){
    float freq=0;
    
    //    if(height>0){
    //    y-=9;
    
    float _maxHz = maxHertz;
    float _minHz = minHertz;
    float yToFreq = (y/BIT)*_maxHz;
    
    //TODO logarithmic scale
    //    freq = 1-(log(yToFreq)-log(_minHz)) / (log(_maxHz)-log(_minHz));
    //    freq *= _maxHz;
    freq = 1-(yToFreq-_minHz) / (_maxHz-_minHz);
    //    freq= (BIT-y+_minHz)/BIT*(_maxHz-_minHz);
    freq *= _maxHz;
    //    }
    
    return freq;
    
}


//--------------------------------------------------------------
float ofApp::getFreqLine(float y){
    float freq=0;
    
    //    if(height>0){
    //    y-=9;
    
    float _maxHz = maxHertz;
    float _minHz = minHertz;
    float yToFreq = (y/BIT)*_maxHz;
    
    //TODO logarithmic scale
    freq = 1-(log(yToFreq)-log(_minHz)) / (log(_maxHz)-log(_minHz));
    //    freq *= _maxHz;
    //    freq = 1-(yToFreq-_minHz) / (_maxHz-_minHz);
    //    freq= (BIT-y+_minHz)/BIT*(_maxHz-_minHz);
    freq *= _maxHz;
    //    }
    
    
    return freq;
    
    
}



