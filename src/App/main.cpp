#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){
	ofSetupOpenGL(1224,800,OF_WINDOW);
    glEnable(GL_POINT_SMOOTH);
    glPointSize(1);
    ofBackground(0);
	ofRunApp(new ofApp());

}
