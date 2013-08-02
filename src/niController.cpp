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
    
    myServer.setName("COMADEPTH");
    
    ofSetFrameRate(60);
	ofSetVerticalSync(true);
    glEnable(GL_DEPTH_TEST);
	ofBackground(0);
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
}

void niController::exit(){
	tracker.exit();
	device.exit();
}

//--------------------------------------------------------------
void niController::update(){
	device.update();
}

//--------------------------------------------------------------
void niController::draw(){
	// draw depth
	depth_image.setFromPixels( tracker.getPixelsRef(1000, 4000) );
    myServer.publishTexture( &depth_image.getTextureReference() );
	
	ofSetColor(255);
	depth_image.draw(300, 400,depth_image.getWidth(), depth_image.getHeight());
	ir.draw();
	
	// draw in 2D
	ofPushView();
	tracker.getOverlayCamera().begin(ofRectangle(0, 0, depth_image.getWidth(), depth_image.getHeight()));
	ofDrawAxis(100);
	tracker.draw();
	tracker.getOverlayCamera().end();
	ofPopView();
	
	// draw in 3D
	cam.begin();
	ofDrawAxis(100);
	tracker.draw();

	// draw box
	ofNoFill();
	ofSetColor(255, 0, 0);
	for (int i = 0; i < tracker.getNumUser(); i++)
	{
		ofxNiTE2::User::Ref user = tracker.getUser(i);
		const ofxNiTE2::Joint &joint = user->getJoint(nite::JOINT_HEAD);
        
        ofVec3f tmp = joint.getGlobalPosition();
        ofTranslate(tmp);
        cout << "joint head : " << tmp << endl;
        
		joint.transformGL();
		ofBox(300);
		joint.restoreTransformGL();
	}

	cam.end();
    
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