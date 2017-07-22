//
//  Walls.cpp
//  uyenWIP
//
//  Created by Uyen Le on 14/11/2015.
//
//

#include <stdio.h>
#include "WallLeft.hpp"

WallLeft::WallLeft(int posx, int posy, int posz): x(posx), y(posy), z(posz) {

    color.set(255,255,255);
    
}


void WallLeft::draw() {
    
    for (int i=0; i < numBrick; i++) { //drawing only 1 brick so that only 1 is added at a time
        ofPushMatrix();
        wx = -110;
        wy = 0;
        wz = i * wsize - 1400;
        
        ofTranslate(wx, wy, wz);
        ofRotateY(TWO_PI-5);
                
        ofSetColor(color);
        ofNoFill();
        ofDrawBox(x, y, z, 20, 2000, 300);
        ofPopMatrix();
    }
}


void WallLeft::move() {
    z += 20; //move towards the user to create the illusion of user running forward
    
    if (z >= ofGetWindowHeight() + 800) {
        z = -800;
    }
}


