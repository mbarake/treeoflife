//
//  Node.cpp
//  TreeOfLife
//
//  Created by Mousbah on 24/12/2021.
//

#include "Node.hpp"

Node::Node(float _len, float _size, float _rotRange, int _level, TreeParam & para) {
    len = _len * (1 + ofRandom(-0.25, 0.25));
    size = _size;
    level = _level;
    lim1 = ofRandom(0, 0.5);
    lim2 = ofRandom(0.5, 1);
    uniquea = ofRandom(0.1,1.2);
    
    if (level == 0 ) rot = 0;
    else if (level > 0) {
        rot = ofDegToRad(ofRandom(-_rotRange, _rotRange));
    }
    if (level < para.leafLevel) rot *= 0.9;
    
    windFactor = ofRandom(0.2, 1);
  
    if (level >= para.leafLevel && (ofRandom(0,1) < para.leafChance)) {
        doesBloom = true;
        bloomSize = ofRandom(para.bloomSizeAverage*0.7, para.bloomSizeAverage*1.3);
        leafRot = ofDegToRad(ofRandom(-180, 180));
        leafDelay = round(ofRandom(50, 150));
    }
    else {
        doesBloom = false;
    }
    
    if (level >= 3 and ofRandom(0,1) < para.flowerChance) {
        doesFlower = true;
        flowerScaleT = ofRandom(0.8, 1.2);
        flowerDelay = round(ofRandom(200, 250));
    }
    else {
        doesFlower = false;
    }
    
    float rr = _rotRange * para.rotDecay;
    
    if (level < para.levelMax) {
        n1 = new Node(len*para.lengthDecay, size*para.sizeDecay, rr, level+1, para);
        n2 = new Node(len*para.lengthDecay, size*para.sizeDecay, rr, level+1, para);
    }
}

void Node::setWind(float w) {
    mouseWind = w;
}

void Node::dance(const ofSoundPlayer & soundd ,TreeParam & para, float value) {
    
    
    ofPushMatrix();
    ofPushStyle();
    flowerScale += (flowerScaleT - flowerScale) * 0.1;
    ofScale(flowerScale);
    ofRotateRad(flowerScale*3);
    ofColor c(0,0,0);
    ofColor c2(flowerColor);
    c.setHsb(c2.getHue(),c2.getSaturation(),flowerBright);
    ofSetColor(c);
    
    ofFill();
    ofDrawEllipse(0, 0, para.flowerWidth*value, para.flowerHeight*value);
    ofRotateRad(ofDegToRad(360/3));
    ofDrawEllipse(0, 0, para.flowerWidth*value, para.flowerHeight*value);
    ofRotateRad(ofDegToRad(360/3));
    ofDrawEllipse(0, 0, para.flowerWidth*value, para.flowerHeight*value);
    ofSetColor(branchColor);
    ofFill();
    ofDrawEllipse(0, 0, 6*value, 6*value);
    
    ofPopMatrix();
    ofPopStyle();
}


void Node::update() {
    
    
    
}

void Node::draw(float xpos, const ofSoundPlayer & sound ,float * fft, TreeParam & para){
    
    ofPushMatrix();
    para.calculateWindEddect();
    ofTranslate(xpos, ofGetHeight()-50);
    setWind(para.mouseWind);
    draw(sound, fft, para);
    ofPopMatrix();
    
}

void Node::draw(const ofSoundPlayer & soundd ,float * fft, TreeParam & para) {
  
    if (level>para.levelMax) return;
    
    TreeParam & param = para;
    ofSetLineWidth(size);
    s += (1.0 - s) / (15 + (level*5));
    ofScale(s);
    ofPushMatrix();
    ofNoFill();
    if (level >= para.leafLevel) ofSetColor(branchColor);
    else ofSetColor(50);
    float rotOffset = sin(ofNoise( (float) ofGetElapsedTimeMillis() * 0.000006 * level )*100);
    if (!windEnabled) rotOffset = 0;
    
    ofRotateRad(rot + (rotOffset * 0.1 + mouseWind) * windFactor);
    ofDrawLine(0, 0, 0, -len);
    ofTranslate(0, -len);
    
    // draw leaves
    if (doesBloom) {
        if (leafDelay < 0) {
            leafScale += (1.0 - leafScale) * 0.05;
            ofFill();
            ofSetColor(leafColor);
            ofPushStyle();
            ofPushMatrix();
            ofScale(leafScale);
            ofRotateRad(leafRot);
            ofTranslate(0, -bloomSize/2);
            ofDrawEllipse(0, 0, bloomSize*param.bloomWidthRatio, bloomSize);
            ofPopMatrix();
            ofPopStyle();
        }
        else {
            leafDelay--;
        }
    }
    
    // draw flowers
    if (doesFlower && (level > levelMax-3)) {
        if (flowerDelay < 0) {
            
          
            for(int i=0; i<64; i++) {
                float value=1;
                bool amp=false;
                if (soundd.getPosition()>0 and soundd.getPosition()<lim1) {
                    amp=true;
                }
                if (soundd.getPosition()>0.5 and soundd.getPosition()<lim2) {
                    amp=true;
                }
                if (amp) {
                    value = fft[i]*a;
                }
                dance(soundd,param,value*uniquea);
            }

        } else {
            flowerDelay--;
        }
    }
    if (n1) n1->draw(soundd, fft, param);
    if (n2) n2->draw(soundd, fft, param);
    ofPopMatrix();
}

void Node::setInitialColors(float a, float b, float c, ofColor d) {
    branchHue = a;
    leafHue = b;
    leafSat = c;
    leafColor = d;
}

void Node::randomizeColor() {
    branchColor.setHsb(branchHue, ofRandom(50, 200), ofRandom(50, 200));
    leafColor.setHsb(leafHue, leafSat, ofRandom(50, 255));
    flowerBright = ofRandom(200, 255);
    flowerColor.setHsb(ofRandom(100,255),ofRandom(0,255),ofRandom(0,255));
    
    if (n1) {
        n1->setInitialColors(branchHue, leafHue, leafSat, leafColor);
        n1->randomizeColor();
    }
    if (n2) {
        n2->setInitialColors(branchHue, leafHue, leafSat, leafColor);
        n2->randomizeColor();
    }
}

