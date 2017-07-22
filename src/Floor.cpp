//
//  Floor.cpp
//  uyenWIP
//
//  Created by Uyen Le on 12/11/2015.
//
//


#include <stdio.h>
#include "Floor.h"



Floor::Floor(int posx, int posy, int posz): x(posx), y(posy), z(posz){
    
    color.set(255,255,255,50);
    
    for(int i=0 ; i < 20; i++) { //create 20 columns of tiles
        numTiles.push_back(i);
    }
    
}


void Floor::draw() {

    for(int i=0; i < numTiles.size(); i++) {    //horizontal loop

        ofPushMatrix();
        tx = i * tsize;
        ty = 1000;
        tz = tsize - 1000;
    
        ofTranslate(tx, ty, tz);
        ofRotateZ(PI/2);
        
        ofSetColor(color);
        ofFill();
        ofDrawBox(x, y, z, 80, 150, 30);  //x,y,z positions with width, height, depth

        ofPopMatrix();
    }
}


void Floor::move() {
    z += 20; //move towards the user by 20 pixels every frame
    
    //This adds new rows to the floor, creating a continuous animation
    //For every element of floor that equals to 0 (front screen)
    //new elements are added at z = -1000
    
    if (z >= ofGetWindowHeight()+400) {   //add 200 to increase the bound so that users can't see elements being deleted
    //if (z >= ofGetWindowHeight()) {   //uncomment this and then comment out the first line to see what I mean
        z = -800;
    }
}

