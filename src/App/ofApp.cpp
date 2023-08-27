#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    tree1.loadimage("quotes/q1.png");
   
    fft = new float[bands];

    music.push_back("Nova.mp3");
    music.push_back("trap.mp3");
    
    quotes.push_back("q1.png");
    quotes.push_back("q2.png");
    
    mySound.load("music/Nova.mp3");
    mySound.setLoop(true);
    mySound.play();
}

//--------------------------------------------------------------
void ofApp::update(){
    
    ofSoundUpdate();
    
    float * value = ofSoundGetSpectrum(bands);
    
    for(int i=0; i<bands; i++) {
        fft[i]*=decay;
        if (fft[i]<value[i]) {
            fft[i]=value[i];
        }
    }
    
    tree1.update(mySound);
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofClear(0);
    tree1.draw(mySound, fft, ofGetWidth()/2);
}

void ofApp::reset() {
    mySound.stop();
    int index1 = ofRandom(0, music.size());
    int index2 = ofRandom(0, quotes.size());
    string track = music[index1];
    string quote = quotes[index2];
    mySound.load("music/" + track);
    mySound.setLoop(true);
    mySound.play();
    tree1.reset("quotes/"+quote);
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
   
    reset();
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
