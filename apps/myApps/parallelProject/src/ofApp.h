#pragma once

#include "ofMain.h"

enum videoMode{
    STANDARD_MODE = 0,
    INVERTED_MODE,
    OUTLINE_MODE,
    TOON_MODE
};

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        void setMode(videoMode newMode);
    
        ofVideoGrabber 		vidGrabber;
        unsigned char * 	videoInverted;
        ofTexture			videoTexture;
        int 				camWidth;
        int 				camHeight;
        int                 frameNum;
        string              currentModeStr;
        videoMode           currentMode;
};
