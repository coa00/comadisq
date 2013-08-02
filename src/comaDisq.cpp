#include "comaDisq.h"

//--------------------------------------------------------------
void comaDisco::setup(){
    niC = new niController();
    niC->setup();
    
    syphonPlayer = new SyphonPlayer();
    syphonPlayer->setup();
}

void comaDisco::exit(){
    niC->exit();
    delete niC;
}

//--------------------------------------------------------------
void comaDisco::update(){
    niC->update();
}

//--------------------------------------------------------------
void comaDisco::draw(){
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