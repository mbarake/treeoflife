//
//  Tree.hpp
//  TreeOfLife
//
//  Created by Mousbah on 24/12/2021.
//
#pragma once
#ifndef Tree_hpp
#define Tree_hpp

#include "ofMain.h"
#include "Node.hpp"
#include "TreeParam.hpp"
#include "ImageParticle.h"

class Tree : public ofNode{
    
private:
    
    TreeParam para;
    Node * node;
    ImageParticle imp;
    bool captured=false;
    
public:
    Tree() {
        para.randomize();
        node = new Node(para.startLength, para.startSize, para.rotRange, 0, para);
        randomizeColor();
    }
    ~Tree() {
        delete node;
    }
   
    void loadimage(string);
    void update(const ofSoundPlayer&);
    void draw(const ofSoundPlayer&, float *, float);
    void reset(string);
    void randomizeColor();
    
};


#endif /* Tree_hpp */
