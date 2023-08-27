#pragma once

#include "ofMain.h"
#include "Tree.hpp"
#include <vector>
using namespace std;

class ofApp : public ofBaseApp{
    
    
    private:
    
        Tree tree1;
        Tree tree2;
        ofSoundPlayer mySound;
        const int bands =64;
        float * fft;
        float decay=0.95f;
        bool dtree=true;
        vector<string> music;
        vector<string> quotes;
    
    

	public:
		void setup();
		void update();
		void draw();
        void reset();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};
