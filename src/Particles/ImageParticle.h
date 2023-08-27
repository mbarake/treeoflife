//
//  ImageParticle.h
//  MusicTrap
//
//  Created by Mousbah Barake on 25/06/2021.
//

#ifndef ImageParticle_h
#define ImageParticle_h

#include "ofMain.h"
#include "ParticleIM.h"


class ImageParticle {
    
    
    public:
    
        void loadImage(string name);
        void screenShot();
        void createParticles();
        void draw();
        void update();
    
    ofImage image;
    ofImage finalimage;
    vector<ParticleIM> particles;
    bool finished=false;
    bool stop=false;
};


#endif /* ImageParticle_h */
