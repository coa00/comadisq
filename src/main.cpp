#include "ofMain.h"
#include "comaDisq.h"
#include "ofAppGlutWindow.h"
#include "ofxNI2.h"
#include "ofxNiTE2.h"
#include "ofxSyphon.h"

//========================================================================
int main( ){

    ofAppGlutWindow window;
	ofSetupOpenGL(&window, 1024,768, OF_WINDOW);			// <-------- setup the GL context

	// this kicks off the running of my app
	// can be OF_WINDOW or OF_FULLSCREEN
	// pass in width and height too:
	ofRunApp( new comaDisco());
    ofxNI2::Device device;
	ofxNiTE2::UserTracker tracker;
    
    ofxSyphonServer myServer;

}
