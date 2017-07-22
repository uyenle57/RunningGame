//
//  Floor.hpp
//  uyenWIP
//
//  Created by Uyen Le on 12/11/2015.
//
//

#ifndef Floor_h
#define Floor_h
#include <stdio.h>
#include "ofMain.h"

class Floor {   //Base class

protected:  //not private so that Wall class can use these variables
    
    int tsize = 55;  //size of tiles
    float tx, ty, tz; //position variables for tiles
    vector<int> numTiles;    //create an array of number of tiles
    //so that new elements can be added to front and back of the array
    int index = 2;  //variable to keep track of current number of tile
 
    
public:

    Floor(int posx, int posy, int posz); //Constructor
    
    //Properties
    ofColor (color);
    int x, y, z;    //variables for x,z,y coordinates
    
    //Methods
    void draw();
    void move();
    
};

#endif /* Floor_hpp */
