//
//  Walls.hpp
//  uyenWIP
//
//  Created by Uyen Le on 14/11/2015.
//
// Parent Class for WallRight class

#ifndef WallLeft_hpp
#define WallLeft_hpp

#include <stdio.h>
#include "ofMain.h"


class WallLeft {
    
protected:  //not private so that WallRight class can use these variables
    
    int wsize = 50; //size of wall
    float wx, wy, wz;   //position variables
    int numBrick = 1;

public:
    
    WallLeft(int posx, int posy, int posz);
    
    //Properties
    ofColor(color);
    int x,y,z;
    
    //Methods
    void draw();
    void move();
};

#endif /* Walls_hpp */
