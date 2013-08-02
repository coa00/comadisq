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
    sender.setup(HOST,PORT);
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
    //ユーザごとのpoint取得　現状0,0,0しか帰ってこない。
//	for (int i = 0; i < tracker.getNumUser(); i++){
//		ofxNiTE2::User::Ref user = tracker.getUser(i);
//        user->draw();
//        size_t cntJoint = user->getNumJoints();
    
        
       

//        for (int j = 1; j<cntJoint; j++) {
//            const ofxNiTE2::Joint &joint = user->getJoint(j);
//            ofVec3f points = joint.getGlobalPosition();
//            cout << points << "/" << &skPoint << endl;
//            cout << joint.getGlobalPosition() << endl;
//            ofNode parent = *joint.getParent();
//            ofVec3f pos = parent.getPosition();
//            cout << pos << endl;

//        }
//	}
}

//--------------------------------------------------------------
void niController::draw(){
	// draw depth
	depth_image.setFromPixels( tracker.getPixelsRef(100, 1000) );
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
        string status = "";
		ofxNiTE2::User::Ref user = tracker.getUser(i);
        nite::UserId userId = user->getId();
        cout << userId << endl;
        if (user->isNew()){
            status = "new";
        }else if(user->isVisible()){
            status = "Visible";
        }else if(user->isLost()){
            status = "lost";
        }
        headOscSet(status, userId);
        
        if (user->isNew()||user->isVisible())
        {
            for (int j=0; j< user->getNumJoints();j++) {
                const ofxNiTE2::Joint &joint = user->getJoint(j);
                ofVec3f point = joint.getGlobalPosition();
//                cout << joint.getGlobalPosition() << endl;
                jointOscSet(point);
                joint.transformGL();
                ofBox(50);
                joint.restoreTransformGL();
            }
        }
        sender.sendMessage(m);
	}	
	cam.end();
    
}

void::niController::headOscSet(string status,int userId){
    m.clear();
	m.setAddress("/comadisq/joint/");
    m.addStringArg(status);
    m.addInt64Arg(userId);
}

void::niController::jointOscSet(ofVec3f pos){
    m.addFloatArg(pos.x);
    m.addFloatArg(pos.y);
    m.addFloatArg(pos.z);
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