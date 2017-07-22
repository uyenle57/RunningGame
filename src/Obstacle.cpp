//
//  enemy.cpp
//  lab3
//
//  Created by Uyen Le on 20/10/2015.
//
//


#include "Obstacle.h"


Obstacle::Obstacle(int _x, int _y, int _z, Player &player):x(_x), y(_y), z(_z), player(&player) {
    
    //Set random colors
    color.set( ofRandom(255), ofRandom(255), ofRandom(255) );
        
    for(int i=0 ; i < 3; i++) { //create column of 3 balls
        numBox.push_back(i);
    }
    
    //Make boxes in the left and right lanes appear, but not in the middle lane
    firstbox = true;
    secondbox = false;
    thirdbox = true;
}

void Obstacle::move() {
    z += 20;   //obstacles move towards the user
    
    if(z > ofGetWindowHeight() + 500) { //for each box that goes outside the screen
        z = -800;  //add new boxes at the beginning of the floor
        
        //Randomisation
        //Boxes in each lane has 50% chance of appearing
        bool temp;  //create a temporary boolean
        
        if(ofRandom(100) < 50)
            temp = true;
        else
            temp = false;
        firstbox = temp;
        
        if(ofRandom(100) < 50)
            temp = true;
        else
            temp = false;
        secondbox = temp;
        
        if(ofRandom(100) < 50)
            temp = true;
        else
            temp = false;
        thirdbox = temp;
        
        //However the above code will leave 3 boxes appear at the same time, and we dont want that
        //because if so, the player cannot dodge.
        //So to solve that, I check that when all 3 boxes appear at the same time
        //each box has 1/3 chance (33%) of appearing, this will ensure only 2 boxes appear
        if(firstbox && secondbox && thirdbox) {
            int tempInt = ofRandom(100);
            if(tempInt < 33)
                firstbox=false;
            else if (tempInt < 66)
                secondbox=false;
            else
                thirdbox=false;
        }
    }
}

void Obstacle::draw() {
        
    for (int i=0; i < numBox.size(); i++ ) {
        ofPushMatrix();
        
        ox = i*400 + 100; //*400 to draw them 400 pixels apart horizontally, then +100 to shift them a bit to the right
        oy = 1000;
        oz = 0;
        
        ofTranslate(ox, oy, oz);
        

        if ((i==0 && firstbox)||(i==1 && secondbox)||(i==2 && thirdbox)) {
            ofSetColor(color);
            ofFill();
            ofDrawBox(x, y, z, 130);
        }
        ofPopMatrix();
    }
}