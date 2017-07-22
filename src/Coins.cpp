//
//  Coins.cpp
//  uyenWIP
//
//  Created by Uyen Le on 26/11/2015.
//
// This class's methods and properties are pretty much the same as class Obstacles

#include "Coins.hpp"
#include "Obstacle.h"


Coins::Coins(int _x, int _y, int _z, Player &player): Obstacle(_x, _y, _z, player){
    
    radius = 50;
}


void Coins::draw() {
    
    for (int i =0; i < numBox.size(); i++) {

        ofPushMatrix();
        ox = i*400-300;
        oy = 690;
        oz = 0;
        
        ofTranslate(ox, oy, oz);
    
        //here I'm using all 3 index number variables
        //because there should always be coins appear randomly at all 3 lanes
        if ((i==0 && firstbox)||(i==1 && secondbox)||(i==2 && thirdbox)) {
            ofSetColor(255, 223, 10);   //yellow
            ofFill();
            ofRotate(TWO_PI*13);    //make them stand up, comment out this line to see the original orientation
            ofDrawCylinder(x, y, z, radius, 20); //radius: 50, height: 20
        }
        ofPopMatrix();
    }
}



