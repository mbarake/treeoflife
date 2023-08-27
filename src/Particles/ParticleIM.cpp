//
//  ParticleIM.cpp
//  TreeDreams
//
//  Created by Mousbah Barake on 25/06/2021.
//

#include "ParticleIM.h"


void ParticleIM::setup(float x, float y) {
    
    pos.set(x, y);
    vel.set(0, 0);
    isKilled=false;
    
    maxSpeed = ofRandom(2, 3);
    maxForce = ofRandom(2, 5);
    
    currentColor= ofColor::yellow;
    endColor = ofColor::red;
    colorBlendRate = ofRandom(0.05, 0.1);
    currentSize = 2;
    targetSize = 5;
}

bool ParticleIM::move() {
   
    float proximityMult = 1;
    float distToTarget =  ofDist(pos.x, pos.y, target.x, target.y);
   
    if ((distToTarget) <=1) {
        return true;
    }
    
    currentColor = currentColor.lerp(endColor, colorBlendRate);
    currentSize = ofLerp(currentSize, targetSize, 0.1);
    
    if (distToTarget < closeEnoughTarget) {
        proximityMult = distToTarget/closeEnoughTarget;
        vel*=0.95;
    }
       
    else{
        vel*=0.99;
        ofVec2f steer;
        steer.set(target.x, target.y);
        steer-=pos;
        steer.normalize();
        steer*=(maxSpeed*proximityMult);
        
        vel+=(steer);
        vel.limit(maxForce);
        pos+=vel;
     
        return false;
    }
   
    return true;
}


void ParticleIM::draw() {
    ofPushMatrix();
    ofSetColor(currentColor);
    ofFill();
    ofDrawCircle(pos.x, pos.y, currentSize);
    ofPopMatrix();
}


void ParticleIM::kill() {
    
    if (!isKilled) {
        endColor = ofColor::black;
        isKilled = true;
    }
}

bool ParticleIM::isOutOfBounds(int width, int height) {
    
    return (pos.x < 0 || pos.x > width ||
            pos.y < 0 || pos.y > height);
}

void ParticleIM::setTarget(float x, float y) {
    target.set(x,y);
}

void ParticleIM::setInitialColor(ofColor color) {
    currentColor = color;
}

void ParticleIM::setEndColor(ofColor color) {
    endColor = color;
}


ofVec2f ParticleIM::getPos() const {
    return pos;
}

