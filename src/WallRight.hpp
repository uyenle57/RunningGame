//
//  WallRight.hpp
//  uyenWIP
//
//  Created by Uyen Le on 15/11/2015.
//
// Child class from Parent class (WallLeft)


#ifndef WallRight_hpp
#define WallRight_hpp

#include <stdio.h>
#include "WallLeft.hpp" 



class WallRight: public WallLeft {

private:

public:
    
    //Constructor
    WallRight(int posx, int posy, int posz);
    
    //Properties
    //Child class has no properties of its own as it inherits them from the WallLeft class
    
    //Methods
    void draw();  //right wall's orientation is different so I have to draw it separately
    
    //move() is not created because it will inherit from WallLeft class
};

#endif /* WallRight_hpp */
