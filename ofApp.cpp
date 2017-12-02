#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(2);
    ofBackground(0);
    ofSetWindowTitle("day 9");
    ofEnableAlphaBlending();
    this->inputimg.load("data.jpg");
    dotsize = 1;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    if(ofGetFrameNum()>1){
        dotsize = ofGetFrameNum() % 100;
        if(dotsize==0){
            dotsize=1;
        }
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofPixels pixels = this->inputimg.getPixels();
    ofColor pixelcolor;
    for(int x=0;x<pixels.getWidth();x+=dotsize){
        for(int y=0;y<pixels.getHeight();y+=dotsize){
            pixelcolor = pixels.getColor(x, y);
            float bright = pixelcolor.getLightness();
            ofSetColor(bright*0.75, bright*0.75, 255);
            ofDrawCircle(x, y, dotsize/2);
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'x') {
        string now = ofGetTimestampString("%Y%m%d%H%M%S");
        this->outputimg.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
        this->outputimg.save("of" + now + ".jpg");
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
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

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
