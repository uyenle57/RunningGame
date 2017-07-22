//
//  enemy.hpp
//  lab3
//
//  Created by Uyen Le on 20/10/2015.
//
// Parent class for Coins class

#ifndef Obstacle_h
#define Obstacle_h

#include <stdio.h>
#include "ofMain.h"
#include "Player.h"


class Obstacle {
    
protected:
    vector<int> numBox; //this variable is shared with the Child class
    
public:
    
    // Constructor
    Obstacle(int _x, int _y, int _z, Player & player);
    
    // Methods
    void move();
    void draw();
    
    // Properties
    float ox, oy, oz;
    int x,y,z;  //x,y,z positions for the box
    bool firstbox, secondbox, thirdbox;  //booleans for the index of the boxes
    
    ofColor color;
    
    Player *player;

    
};

#endif /* Obstacle_h */
