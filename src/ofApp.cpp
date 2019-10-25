#include "ofApp.h"

using namespace cv;
using namespace ofxCv;

//--------------------------------------------------------------
void ofApp::setup(){

    ofBackground(0);
    
    // 드로우시 배경 삭제 안되게..
    ofSetBackgroundAuto(false);
    // 초기 이미지 에러핸들링
    if(filename != ""){
        aa.load(filename);
    }
    
    //
    fbo1.allocate(512, 512, GL_RGBA);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    //int xx, yy;
    int x, y;
    //x
    x= ofGetMouseX();
    //y
    y= ofGetMouseY();

    // 좌측에 이미지 띄우고
    if(aa.isAllocated()){
        if (ofGetMousePressed(OF_MOUSE_BUTTON_LEFT)) {
            // 화면에 주황색 그리기
            ofSetColor(255, 155, 0);
            ofDrawCircle(x, y, 5);
            // 메모리 버퍼에 그리기
            fbo1.begin();
                ofSetColor(1);
                ofDrawCircle(x, y, 5);
            fbo1.end();
            
            ofSetWindowTitle("Mouse Drawing ...");
        }// if mousePressed
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if(key == 'm' || key =='M'){

        fbo1.begin();
            
            temp.grabScreen(0, 0, 512, 512);
            temp.saveImage("/Users/Kerbal/Desktop/mask.jpg");
            aa.saveImage("/Users/Kerbal/Desktop/image.jpg");
        fbo1.end();
        ofClear(0, 255);
        
        ofSetWindowTitle("Image and Mask file Saved ~ !!");
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
        ofSetColor(255);
        aa.draw(0, 0, 512, 512);
    }
    
    // clear
    //ofBackground(0);
    ofSetBackgroundAuto(false);
    
    ofSetWindowTitle("Image Loaded ~");
}
