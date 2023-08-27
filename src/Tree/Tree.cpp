//
//  Tree.cpp
//  TreeOfLife
//
//  Created by Mousbah on 24/12/2021.
//

#include "Tree.hpp"


void Tree::loadimage(string name) {
    imp.loadImage(name);
}

void Tree::update(const ofSoundPlayer& sound) {
   
    if (!captured and sound.getPosition()>0.2) {
        captured=true;
        imp.screenShot();
        imp.createParticles();
    }
}

void Tree::draw(const ofSoundPlayer& sound, float * fft, float pos) {
    if (sound.getPosition()<0.4) {
        ofPushStyle();
        node->draw(pos, sound, fft, para);
        ofPopStyle();
    }
    
    else{
        ofPushStyle();
        imp.update();
        imp.draw();
        ofPopStyle();
    }
    
}

void Tree::reset(string name) {
    captured=false;
    para.randomize();
    loadimage(name);
    delete node;
    node=NULL;
    node = new Node(para.startLength, para.startSize, para.rotRange, 0, para);
    randomizeColor();
}

void Tree::randomizeColor() {
    float branchHue = ofRandom(0, 255);
    float leafHue = ofRandom(0, 255);
    float leafSat = ofRandom(0, 255);
    ofColor c = ofColor(ofRandom(255), ofRandom(0, 255), 255);
    if (node) {
        node->setInitialColors(branchHue, leafHue, leafSat, c);
        node->randomizeColor();
    }
}


