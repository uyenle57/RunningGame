//
//  Ship.h
//  lab3
//
//  Created by Uyen Le on 20/10/2015.
//
//

#ifndef Player_h
#define Player_h
#include <stdio.h>
#include "ofMain.h"


class Player {

private:
    
public:
    Player(); //Constructor
    
    int x, y, z ;
    int radius;
        
    void draw();
    void detection();
    void left();
    void right();
    
    ofColor(color);
    
};


#endif /* Player_h */
