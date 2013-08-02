//
//  syphonPlayer.h
//  comaDisq
//
//  Created by usm on 8/3/13.
//
//

#ifndef __comaDisq__syphonPlayer__
#define __comaDisq__syphonPlayer__

#include "ofMain.h"
#include "ofxSyphon.h"

class SyphonPlayer : public ofBaseApp {
public:
    ofxSyphonClient myClient;
    string syphonName;
    string urlAdrs;
    
    void readFile(string name);
    void setup();
    void draw();
};

#endif /* defined(__comaDisq__syphonPlayer__) */
