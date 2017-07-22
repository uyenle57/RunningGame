//
//  Coins.hpp
//  uyenWIP
//
//  Created by Uyen Le on 26/11/2015.
//
// Child class that holds coins images


#ifndef Coins_hpp
#define Coins_hpp

#include <stdio.h>
#include "ofMain.h"
#include "Obstacle.h"
#include "Player.h"


class Coins: public Obstacle {
    
private:
    
public:
    
    //Constructor
    Coins(int posx, int posy, int posz, Player & player);
    
    //Methods
    void draw();
    
    float radius;
    
};

#endif /* Coins_hpp */
