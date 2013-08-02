#include "comaDisq.h"

//--------------------------------------------------------------
void comaDisco::setup(){
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
    
    niC = new niController();
    niC->setup();
    
    syphonPlayer = new SyphonPlayer();
    syphonPlayer->setup();
}

void comaDisco::exit(){
	tracker.exit();
	device.exit();

    niC->exit();
    delete niC;
}

//--------------------------------------------------------------
void comaDisco::update(){
	device.update();
    niC->update();
}

//--------------------------------------------------------------
void comaDisco::draw(){
	// draw depth
	depth_image.setFromPixels(tracker.getPixelsRef(1000, 4000));
	
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

    niC->draw();
    syphonPlayer->draw();
}

//--------------------------------------------------------------
void comaDisco::keyPressed(int key){
    niC->keyPressed(key);
}

//--------------------------------------------------------------
void comaDisco::keyReleased(int key){

}

//--------------------------------------------------------------
void comaDisco::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void comaDisco::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void comaDisco::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void comaDisco::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void comaDisco::windowResized(int w, int h){

}

//--------------------------------------------------------------
void comaDisco::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void comaDisco::dragEvent(ofDragInfo dragInfo){ 

}