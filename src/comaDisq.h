#pragma once

#include "ofMain.h"
<<<<<<< HEAD
#include "ofxNI2.h"
#include "ofxNiTE2.h"
#include "OpenNI.h"
=======
#include "niConroller.h"
>>>>>>> 78cdb6ace32cd8f5235ba00d6c4539ba9b3677b2

class comaDisco : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        void exit();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
<<<<<<< HEAD
        ofxNI2::Device device;
        ofxNI2::IrStream ir;
        ofxNiTE2::UserTracker tracker;
        ofImage depth_image;
        ofEasyCam cam;
=======
        niController *niC;
>>>>>>> 78cdb6ace32cd8f5235ba00d6c4539ba9b3677b2
};
