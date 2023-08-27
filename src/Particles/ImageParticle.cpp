//
//  ImageParticle.cpp
//  MusicTrap
//
//  Created by Mousbah Barake on 25/06/2021.
//

#include "ImageParticle.h"
#include "ParticleIM.h"

void ImageParticle::screenShot() {
    image.grabScreen(0, 0 , ofGetWidth(), ofGetHeight());
}

void ImageParticle::loadImage(string name) {
    finalimage.load(name);
}


void ImageParticle::createParticles() {
    particles.clear();
    ofPixels & pixels = image.getPixels();
    ofPixels & fpixels = finalimage.getPixels();
    int w = ofGetWidth();
    int h = ofGetHeight();
    int iw = finalimage.getWidth();
    int ih = finalimage.getHeight();
    for (int y = 0; y < pixels.getHeight(); y++) {
        for (int x = 0; x < pixels.getWidth(); x++) {
            
            ofImageType t = image.getImageType();
            
            const ofColor & color = pixels.getColor(x, y);
           
            
            if (color.r=='\0' and color.b=='\0' and color.g=='\0') {
                continue;
            }
            
            if (ofRandomf()<0.8f) {
                continue;
            }
            
            int fx = ofRandom(0, iw);
            int fy = ofRandom(0, ih);
            const ofColor & endcolor = fpixels.getColor(fx, fy);
            
            ParticleIM particle;
            particle.setup(x,y);
            particle.setInitialColor(color);
            particle.setEndColor(endcolor);
            float xx = fx-iw/2+w/2;
            float yy = fy-ih/2+h/2;
            particle.setTarget(xx, yy);
            particles.push_back(particle);
            
        }
    }
}

void ImageParticle::update() {
    finished=true;
    for (int i=0; i<particles.size(); i++) {
        bool status = particles[i].move();
        finished = finished&&status;
    }
}

void ImageParticle::draw() {
    ofPushMatrix();
    
    if (finished) {
        
        finalimage.draw(ofGetWidth()/2-finalimage.getWidth()/2,ofGetHeight()/2-finalimage.getHeight()/2);
                   
    }
    
    else {
        for (int i=0; i<particles.size(); i++) {
            particles[i].draw();
        }
    }
    ofPopMatrix();
}
