#include "ofApp.h"

using namespace cv;
using namespace ofxCv;

//--------------------------------------------------------------
void ofApp::setup(){

    ofBackground(0);
    ofSetBackgroundAuto(false);
    
    if(filename != ""){
        aa.load(filename);
    }
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    int xx, yy;
    xx= ofGetMouseX()+512;
    if(xx > 507) xx=507;
    
    yy= ofGetMouseY();
    
    if(aa.isAllocated()){
        aa.draw(0, 0, 512, 512);
        if (ofGetMousePressed(OF_MOUSE_BUTTON_LEFT)) {
            //
            ofSetColor(1);
            ofDrawCircle(xx, yy, 5);
            //
            ofSetColor(255, 255, 0, 100);
            ofDrawCircle(xx, yy, 5);
        }
    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if(key == 's') {
        bb.allocate(512, 512, OF_IMAGE_GRAYSCALE);
        bb.grabScreen(512, 0, 512, 512);
        bb.setImageType(OF_IMAGE_GRAYSCALE);
        bb.save("/Users/kerbal/Desktop/1_mask.png");
        
        ofLog() <<"Saved OK !" ;
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

    if( dragInfo.files.size() > 0 ){
        
        filename= dragInfo.files[0];
        aa.load(filename);
        //img.setImageType(OF_IMAGE_COLOR);
    }
    
    // clear
    ofBackground(0);
    ofSetBackgroundAuto(false);
}
