//
//  depth.cpp
//  comaDisq
//
//  Created by coheiaoki on 2013/07/29.
//
//

#include "niConroller.h"

//--------------------------------------------------------------
void niController::setup(){
    nite::Status niteRet = nite::NiTE::initialize();
    myServer.setName("COMADEPTH");
    
    ofSetFrameRate(60);
	ofSetVerticalSync(true);
    glEnable(GL_DEPTH_TEST);
	ofBackground(0);
    try {
        device.setup();
        device.setDepthColorSyncEnabled();
        
        if (ir.setup(device)) // only for xtion device (OpenNI2-FreenectDriver issue)
        {
            ir.setSize(320, 240);
            ir.setFps(30);
            ir.start();
        }
        
        if (tracker.setup(device))
        {
            cout << "tracker inited" << endl;
        }
        throw "device not found";
    } catch (const char* str) {
        cout << str << endl;
    }

}

void niController::exit(){
	tracker.exit();
	device.exit();
}

//--------------------------------------------------------------
void niController::update(){
    device.update();
    //ユーザごとのpoint取得　現状0,0,0しか帰ってこない。
	for (int i = 0; i < tracker.getNumUser(); i++){
		ofxNiTE2::User::Ref user = tracker.getUser(i);
        user->draw();
        size_t cntJoint = user->getNumJoints();
        
        ofxNiTE2::Joint joint;
       
//        const vector<ofxNiTE2::Joint> joints;
        for (int j = 0; j<cntJoint; j++) {
            joint = user->getJoint(cntJoint);
            nite::SkeletonJoint skJoint = joint.get();
            nite::Point3f skPoint = skJoint.getPosition();
            ofVec3f points = joint.getPosition();
//            cout << points << "/" << &skPoint << endl;
            cout << joint.getGlobalPosition() << endl;
//            ofNode parent = *joint.getParent();
//            ofVec3f pos = parent.getPosition();
//            cout << pos << endl;

        }
	}
}

//--------------------------------------------------------------
void niController::draw(){
	// draw depth
	depth_image.setFromPixels( tracker.getPixelsRef(100, 1000) );
    myServer.publishTexture( &depth_image.getTextureReference() );
    
    //depthイメージを全面表示
//	depth_image.getTextureReference().bind();
//    glBegin(GL_POINT);
//    glTexCoord2f(10,0), glVertex2d(0, 0);
//    glTexCoord2f(ofGetWidth(),0), glVertex2d(ofGetWidth(), 0);
//    glTexCoord2f(ofGetWidth(),ofGetHeight()), glVertex2d(ofGetWidth(), ofGetHeight());
//    glTexCoord2f(10,ofGetHeight()), glVertex2d(0, ofGetHeight());
//    glEnd();
//    depth_image.getTextureReference().unbind();
//    depth_image.draw(0,0,ofGetWidth(),ofGetHeight());
    

  
    
    
	ofSetColor(255);
	depth_image.draw(300, 400,depth_image.getWidth(), depth_image.getHeight());
	ir.draw();
//
	// draw in 2D
//	ofPushView();
//	tracker.getOverlayCamera().begin(ofRectangle(0, 0, depth_image.getWidth(), depth_image.getHeight()));
//	ofDrawAxis(100);
//	tracker.draw();
//	tracker.getOverlayCamera().end();
//	ofPopView();
	
	// draw in 3D
    //	cam.begin();
    //	ofDrawAxis(100);
    //	tracker.draw();
    //
    //	// draw box
    //	ofNoFill();
    //	ofSetColor(255, 0, 0);
    //	for (int i = 0; i < tracker.getNumUser(); i++)
    //	{
    //		ofxNiTE2::User::Ref user = tracker.getUser(i);
    //		const ofxNiTE2::Joint &joint = user->getJoint(nite::JOINT_HEAD);
    //
    //		joint.transformGL();
    //		ofBox(300);
    //		joint.restoreTransformGL();
    //	}
    //
    //	cam.end();
    
}

//--------------------------------------------------------------
void niController::keyPressed(int key){
    
}

//--------------------------------------------------------------
void niController::keyReleased(int key){
    
}

//--------------------------------------------------------------
void niController::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void niController::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void niController::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void niController::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void niController::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void niController::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void niController::dragEvent(ofDragInfo dragInfo){ 
    
}