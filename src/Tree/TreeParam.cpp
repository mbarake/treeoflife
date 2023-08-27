//
//  TreeParam.cpp
//  TreeOfLife
//
//  Created by Mousbah on 25/12/2021.
//

#include "TreeParam.hpp"


void TreeParam::calculateWindEddect() {
    float dx = ofGetMouseX() - ofGetPreviousMouseX();
    mouseWindV += dx * mDamp;
    mouseWindV += (0 - mouseWind) * wDamp;
    mouseWindV *= mFriction;
    mouseWind += mouseWindV;
}

void TreeParam::decLevel() {
    levelMax--;
}

void TreeParam::randomize() {
    rotDecay = ofRandom(0.9, 1.1);
    lengthRand = ofRandom(0.0, 0.2);
    leafChance = ofRandom(0, 0.2);
    sizeDecay = ofRandom(0.4, 0.7);
    leafLevel = ofRandom(2, 6);
    bloomWidthRatio = ofRandom(0.01, 0.9);
    bloomSizeAverage = ofRandom(10, 20);
    flowerWidth = ofRandom(5, 10);
    flowerHeight = ofRandom(10, 20);
    flowerChance = ofRandom(0, 0.1);
    
    mouseWind = 1;
    mDamp = 0.0002;
    wDamp = 0.005;
    mouseWindV = 0;
    mFriction = 0.96;
    startLength = ofRandom(30, 70);
    startSize = ofRandom(15, 95);
    rotRange = ofRandom(10, 60);
    lengthDecay = ofMap(startLength, 30, 90, 1.2, 0.7);
}
