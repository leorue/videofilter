#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    camWidth 		= 2880;	// try to grab at this size.
    camHeight 		= 1800;
    
    //we can now get back a list of devices.
    vector<ofVideoDevice> devices = vidGrabber.listDevices();
    
    for(int i = 0; i < devices.size(); i++){
        cout << devices[i].id << ": " << devices[i].deviceName;
        if( devices[i].bAvailable ){
            cout << endl;
        }else{
            cout << " - unavailable " << endl;
        }
    }
    
    vidGrabber.setDeviceID(0);
    vidGrabber.setDesiredFrameRate(60);
    vidGrabber.initGrabber(camWidth,camHeight);
    
    videoInverted 	= new unsigned char[camWidth*camHeight*3];
    videoTexture.allocate(camWidth,camHeight, GL_RGB);
    ofSetVerticalSync(true);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    ofBackground(100,100,100);
    
    vidGrabber.update();

    int totalPixels = camWidth*camHeight*3;
    unsigned char * pixels = vidGrabber.getPixels();
    
    if( currentMode == INVERTED_MODE ){
        for (int i = 0; i < totalPixels; i++){
            frameNum ++;
            videoInverted[i] = (int)ofRandom(150,210) - pixels[i];
        }
        videoTexture.loadData(videoInverted, camWidth,camHeight, GL_RGB);
    }
    else if( currentMode == OUTLINE_MODE ){
        for (int i = 0; i < totalPixels; i++){
            frameNum ++;
            videoInverted[i] = 155 + pixels[i];
        }
        videoTexture.loadData(videoInverted, camWidth,camHeight, GL_RGB);
    }
    else if( currentMode == TOON_MODE ){
        for (int i = 0; i < totalPixels; i++){
            frameNum ++;
            videoInverted[i] = 20 * pixels[i];
        }
        videoTexture.loadData(videoInverted, camWidth,camHeight, GL_RGB);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetHexColor(0xffffff);

    if( currentMode == STANDARD_MODE ){
        vidGrabber.draw(0,0);
    }
    else if( currentMode == INVERTED_MODE || currentMode == OUTLINE_MODE || currentMode == TOON_MODE ){
        videoTexture.draw(0,0,camWidth,camHeight);
        ofDrawBitmapString("Pixel Counter: " + ofToString(frameNum),ofGetWidth()-150,20);
    }
    ofSetColor(230);
    ofDrawBitmapString("Keys 1-3 to change mode\n" +   currentModeStr, 10, 20);
    
    ofDrawBitmapString("fps: " + ofToString((int)ofGetFrameRate()),ofGetWidth()-150,40);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == ' '){
        currentMode = STANDARD_MODE;
        currentModeStr = "Reset Mode";
    }
    if( key == '1'){
        currentMode = INVERTED_MODE;
        currentModeStr = "1 - Inverted Mode";
    }
    if( key == '2'){
        currentMode = OUTLINE_MODE;
        currentModeStr = "2 - Outline Mode";
    }
    if( key == '3'){
        currentMode = TOON_MODE;
        currentModeStr = "3 - Toon Mode";
    }
    if (key == 'f'){
        ofToggleFullscreen();
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
