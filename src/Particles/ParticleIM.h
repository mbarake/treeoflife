//
//  ParticleIM.h
//  MusicTrap
//
//  Created by Mousbah Barake on 25/06/2021.
//

#ifndef ParticleIM_h
#define ParticleIM_h

#include "ofMain.h"

class ParticleIM {
    
    public:
        
        void setup(float x, float y);
        bool move();
        void draw();
        bool isOutOfBounds(int, int);
        void kill();
        void setTarget(float x, float y);
        void setTarget2(float x, float y);
        void setInitialColor(ofColor color);
        void setEndColor(ofColor color);
        void setEndColor2(ofColor color);
        ofVec2f getPos() const;
  
    private:
        ofVec2f pos;
        ofVec2f vel;
        ofVec2f target;
        bool isKilled = false;
        float maxSpeed;
        float maxForce;
        ofColor currentColor;
        ofColor endColor;
        float colorBlendRate;
        int currentSize;
        int targetSize;
        int closeEnoughTarget = 10;
    };


#endif /* ParticleIM_h */
