//
//  depth.h
//  comaDisq
//
//  Created by coheiaoki on 2013/07/29.
//
//

#ifndef __comaDisq__depth__
#define __comaDisq__depth__

#include "ofMain.h"
#include "ofxNI2.h"
#include "ofxNiTE2.h"
#include "OpenNI.h"
#include "ofxSyphon.h"
#include "ofxOsc.h"

class niController : public ofBaseApp{
    
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
    
    ofxNI2::Device device;
    ofxNI2::IrStream ir;
    ofxNiTE2::User user;
    ofxNiTE2::UserTracker tracker;
    ofImage depth_image;
    ofEasyCam cam;
    vector<ofxNiTE2::User::Ref> users_arr;
    
    ofxSyphonServer myServer;
    
};

#endif /* defined(__comaDisq__depth__) */
