//
//  syphonPlayer.cpp
//  comaDisq
//
//  Created by usm on 8/3/13.
//
//

#include "syphonPlayer.h"

void SyphonPlayer::setup(){
    readFile("syphonServerName.txt");
    myClient.setup();
    myClient.setServerName(syphonName);
}

void SyphonPlayer::readFile(string fileName){
    ifstream fin; //declare a file stream
    fin.open( ofToDataPath(fileName).c_str() ); //open your text file
    if(!fin.is_open()){
        cout << "Faled to import urlfile" << endl;
    }
    
    while(fin!=NULL) //as long as theres still text to be read
    {
        string str; //declare a string for storage
        stringstream sstr;
        sstr.str("");
        getline(fin, str); //get a line from the file, put it in the string
        sstr << str;
        string typ, adrs;
        sstr >> typ >> adrs;
        if(typ=="url"){
            urlAdrs = adrs;
            cout << adrs << endl;
        }else if(typ=="syphon"){
            syphonName = adrs;
            cout << "syphon name : " << syphonName << endl;
        }
        
    }
    cout << "setup: url.txt was Loaded, added " << urlAdrs << " address" << endl;
}

void SyphonPlayer::draw(){
    ofEnableAlphaBlending();
    ofEnableBlendMode(OF_BLENDMODE_SCREEN);
    ofSetColor(255,255,255,255);
    myClient.draw(0, 0, ofGetWidth(), ofGetHeight());
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
}