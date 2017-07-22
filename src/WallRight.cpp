//
//  WallRight.cpp
//  uyenWIP
//
//  Created by Uyen Le on 15/11/2015.
//
// Child class from Parent class (WallLeft)
// because Wall Right should look & function the same way as Wall Left, and to save time repeating code


#include "WallRight.hpp"
#include "WallLeft.hpp"


//Constructor inherits from WallLeft's Constructor and Move function
WallRight::WallRight(int posx, int posy, int posz): WallLeft(posx, posy, posz) {
    
    //empty constructor
}


//But not draw function because WallRight positions are different
//so we have to create draw() function
//however notice that I didn't have to create the variables below because they're already created in WallLeft class
void WallRight::draw() {
        
    for (int i=0; i < numBrick; i++) {
        ofPushMatrix();
        wx = 1100;
        wy = 0;
        wz = i * wsize - 1400;
        
        ofTranslate(wx, wy, wz);
        ofRotateY(TWO_PI-5);
        
        ofSetColor(color);
        ofNoFill();
        ofDrawBox(x, y, z, 20, 2000, 300);  //reverse the shape
        ofPopMatrix();
    }
}


