//
//  Node.hpp
//  TreeOfLife
//
//  Created by Mousbah on 24/12/2021.
//

#ifndef Node_hpp
#define Node_hpp

#include "ofMain.h"
#include "TreeParam.hpp"

class Node : public ofBaseApp{
    
public:
    
    Node() {}
    
    Node(float _len, float _size, float _rotRange, int _level, TreeParam &);
    
    ~Node() {
        if (n2) {
            delete n2;
            n2=NULL;
        }
        if (n1) {
            delete n1;
            n1=NULL;
        }
    }
    
    
private:
    bool windEnabled = true;
    float mouseWind = 0;
    float rotRange = 7;
    int levelMax = 9;
    float branchHue = 50;
    float leafHue = 150;
    float leafSat = 100;
    
    
    float startLength;
    float startSize;
    ofColor trunkColor;
    ofColor bgColor;
    float lengthRand = ofRandom(0.0, 0.2);
   
    
    float len;
    float size;
    float rot;
    int level;
    float s = 0;
    float windFactor = 1.0;
   
    bool doesBloom =false;
    ofColor branchColor;
    float bloomSize;
    ofColor leafColor;
    float leafRot;
    float leafScale = 0;
    int leafDelay;
   
    ofColor flowerColor;
    bool doesFlower=false;
    float flowerScale = 0.0;
    float flowerScaleT = 1.0;
    float flowerBright = 255;
    int flowerDelay;
    int a =5;
    
    float lim1;
    float lim2;
    float uniquea;
    
    Node * n1 = NULL;
    Node * n2 = NULL;
    
public:
    virtual void update();
    virtual void draw(float, const ofSoundPlayer&, float *, TreeParam & para);
    virtual void draw(const ofSoundPlayer&, float *, TreeParam & para);
    void dance(const ofSoundPlayer&, TreeParam & para, float value);
    virtual void randomizeColor();
    virtual void setInitialColors(float, float, float, ofColor);
    virtual void setWind(float);
    
};

#endif /* Node_hpp */
