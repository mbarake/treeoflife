//
//  TreeParam.hpp
//  TreeOfLife
//
//  Created by Mousbah on 25/12/2021.
//

#ifndef TreeParam_hpp
#define TreeParam_hpp

#include "ofMain.h"
#include <stdio.h>

class TreeParam {
    
    
public:
    
    float rotDecay;
    float lengthRand;
    float leafChance;
    float sizeDecay;
    float leafLevel;
    float bloomWidthRatio;
    float bloomSizeAverage;
    float flowerWidth;
    float flowerHeight;
    float flowerChance;
    
    float mouseWind;
    float mDamp;
    float wDamp;
    float mouseWindV;
    float mFriction;
    float startLength;
    float startSize;
    float rotRange;
    float lengthDecay;
    
    float levelMax = 9;
    
    
    
public:
    
    void decLevel();
    void randomize();
    void calculateWindEddect();
};


#endif /* TreeParam_hpp */
