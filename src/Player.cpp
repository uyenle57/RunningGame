//
//  Ship.cpp
//  lab3
//
//  Created by Uyen Le on 20/10/2015.
//
//

#include <stdio.h>
#include "Player.h"


Player::Player(): x(ofGetWidth()/2), y(0), z(0) {

    //Set initial colour
    color.set(0);
    
    radius = 30;
}


void Player::draw() {
    
    ofPushMatrix();
    
    ofTranslate(0, 650, 0);
    ofSetColor(color);
    ofFill();
    ofDrawSphere(x, y, z, radius);
    
    ofPopMatrix();
}


void Player::left() {
    
    if( x > 220) { //This prevents user from going off the floor
        x -= 400;
    }
}

void Player::right() {
    
    if( x < 800 ) {
        x += 400;
    }
}


