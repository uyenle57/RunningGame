
#include "ofMain.h"
#include "ofApp.h"
#include "Player.h"
#include "Obstacle.h"
#include "Floor.h"
#include "WallRight.hpp"
//#include "WallLeft.hpp" - no need to include Parent class (WallLeft) because Child class (WallRight) already includes it
//#include "Coins.hpp" - same thing for Coins class

#include <vector>
using std::vector;

#include <algorithm>


//--------------------------------------------------------------
void ofApp::setup() {
    
    ofSetBackgroundColor(255);
    ofEnableSmoothing();    //smooth edges
    ofEnableDepthTest();  //enable z-axis depth testing so the game looks more realistic
    
    // Set up font
    titleText.load("frabk.ttf", 50);
    infoText.load("frabk.ttf", 20);
    
    // Load music
    soundtrack.load("soundtrack.mp3");
    soundtrack.setVolume(0.3f);  //set volume at 30%
    soundtrack.play();
    
    //Initialise variables
    journeyIndicator = 0; //variable to make the Journey bar grow
    score = 0;
    numLife = 3;   //user has 3 lives at start
    
    // Initialise booleans
    bStartScreen = true;
    bGameStart = false;
    bGameWin = false;
    bGameOver = false;
    
    //Draw obstacles vertically at the positions x,y,z
    for (int j=0; j < 3; j++) {
        obstacles.push_back(Obstacle(0, -400, j*-500, player));
    }
    
    //Initialise coins images
    for (int j=0; j < 10; j++) {
        coins.push_back(Coins(0, -400, j*-200, player));
    }
    
    //Initialise rows of tiles for Floor in the beginning
    floorSize = 50;
    for (int j=0; j < floorNum; j++) {
        floor.push_back(Floor(0, -250, j*floorSize-800));
    }
    
    //Initialise 10 rows of bricks for WallLeft
    brickSize = 320 ;
    for (int j=0; j < 10; j++) {
        wallLeft.push_back(WallLeft(0, -250, j*brickSize-800));
    }
    //and 10 for WallRight
    for (int j=0; j < 10; j++) {
        wallRight.push_back(WallRight(0, -250, j*brickSize-800));
    }
    
}

//--------------------------------------------------------------
void ofApp::draw() {
    
    ofSetFrameRate(20);
    
    ofColor colorOne(0,161, 225);  //blue
    ofColor colorTwo(173, 96, 255); //puple
    ofBackgroundGradient(colorOne, colorTwo, OF_GRADIENT_LINEAR);
    
    //Draw game start screen
    if (bStartScreen) {
        ofBackgroundGradient(colorOne,colorTwo, OF_GRADIENT_CIRCULAR);
        titleText.drawString("Running Game", ofGetWidth()/2-200, ofGetHeight()/2);
        ofDrawBitmapString("Enter to Start the Adventure...", ofGetWidth()/2, ofGetHeight()/2+50);
    }
    //Draw game win screen
    if (bGameWin) {
        gameWin();
    }
    //Draw game over screen
    if (bGameOver) {
        gameOver();
    }
    //Draw game start screen, which includes all the objects
    if (bGameStart) {
        
        infoText.drawString("Score: " + ofToString(score), ofGetWidth()-160, 45);  //display score
        
        for (auto & coins: coins) {
            coins.draw();
            coins.move();
        }
        player.draw();
        
        for (auto & floor: floor) {
            floor.draw();
            floor.move();
        }
        for (auto & wall: wallLeft ) {
            wall.draw();
            wall.move();
        }
        for (auto & wall: wallRight ) {
            wall.draw();
            wall.move();
        }
        for (auto & obstacle: obstacles) {
            obstacle.draw();
            obstacle.move();
        }
        
        journeyBar(); //Draw Length of Journey indicator
        lifeCount();  //Call count life function
        
        //std::cout <<floor.back().z << std::endl;
        
    } //bGameStart closes
}


//Collision detection
//checks if the player hits a box, if so, decrease a life
//checks if the player touches a coin, if so, increase score
//--------------------------------------------------------------
void ofApp::update() {
    
    for(auto & obstacle: obstacles) {
        
        if (player.x == ofGetWidth()/2) { //check if player is in middle lane
          if (obstacle.z == -160) {  //check if the obstacle's position is at -160 (which is right in front of the sphere)
              if(obstacle.secondbox = true){ //if boolean for the boxes in the middle lane is true
                  numLife -= 1; //decrease a life
                  obstacle.secondbox = false;
//                cout << "center!" ;
              }
          }
        }
        //do the same thing for the left and right lanes
        if (player.x == 112 && obstacle.z==-160) {
            if(obstacle.firstbox = true){
                numLife -= 1;
//                cout << "left! " ;
            }
          }
        if (player.x == 912 && obstacle.z==-160) {
            if(obstacle.thirdbox = true){
                numLife -= 1;
//                cout << "right! " ;
            }
          }

    } //obstacle for-loop close

    
    //Repeat the same collision detection technique for the Coins
    for (auto & coin: coins) {
        
        if (player.x == ofGetWidth()/2 && coin.z == -160) {
            if(coin.secondbox) {    //if boolean for the coins in the middle is true
                score += 1; //increase score
//                cout << "middle coin ";
            }
        }
        //do the same thing for the left and right lanes
        if (player.x == 112 && coin.z == -160) {
            if(coin.firstbox)
                score += 1;
//                cout << "left coin ";

            }
        if (player.x == 912 && coin.z == -160) {
            if(coin.thirdbox)
                score += 1;
//                cout << "right coin ";
            }
    } //coins for-loop close
    
}

// Length of Journey Indicator
// that indicates levels of difficulty and how far the player has ran
// the user wins if they reach the end of the game without dying
// --------------------------------------------------------------
void ofApp::journeyBar() {
    
    ofSetColor(255);
    ofNoFill();
    ofDrawRectangle(30, 80, 25, 120);
    
    //draw marks - each mark indicates the level of difficulty
    //Bottom mark: Level 1
    ofDrawBitmapString("Level 1", 60, 170);
    ofFill();
    ofDrawRectangle(30, 165, 25, 3);
    
    //Middle mark: Level 2
    ofDrawBitmapString("Level 2", 60, 140);
    ofDrawRectangle(30, 135, 25, 3);
    
    //Top mark: Level 3
    ofDrawBitmapString("Level 3", 60, 110);
    ofDrawRectangle(30, 105, 25, 3);
    
    //The progress indicator that increases length of rectangle as the game runs
    ofDrawRectangle(30, 200, 25, journeyIndicator);
    
    //Below is the code that creates the difficulty level of the game:
    //basically I increase the frame rate every time the indicator reaches a new Level mark
    //to make it more challenging and fun to play
    if (journeyIndicator >= -34) {
        journeyIndicator -= 0.09;   //make it grow until it reaches the top of the bar
    }
    else if (journeyIndicator <= -34 && journeyIndicator >= -65) {  //if reaches Level 1 (and between Level 1 & Level 2)
        ofSetFrameRate(70); //faster
        journeyIndicator -= 0.06;  //every time we increase the frame rate, we have to make the 'indicator' grow slower
                            //so that it grows consistently throughout the game
                            //if not, it'll grow faster & faster and the game will finish much sooner than expected
    }
    else if (journeyIndicator <= -65 && journeyIndicator >= -94) {  //if reaches Level 2
        ofSetFrameRate(110);   //fasterrrr
        journeyIndicator -= 0.03;  //decrease 'growth' rate
    }
    else if (journeyIndicator <= -94 && journeyIndicator >= -120) {  //if reaches Level 3 until end of game
        ofSetFrameRate(160);  //woah super fast!
        journeyIndicator -= 0.01;  //decrease 'growth' rate again
    }
    //display game Win screen if player reaches the end of Journey bar
    else if (journeyIndicator <= -34) {
        bGameStart = false;
        bGameWin = true;
    }
    
//    cout << indicator << " ";

}

// Life count function
// It's called if player runs out of life, and the game Over becomes True (the player loses)
// --------------------------------------------------------------
void ofApp::lifeCount() {
    
    infoText.drawString("Lives: " + ofToString(numLife), 30, 45);  //display life count
    
    if (numLife == 0) {
        bGameOver = true;
        bGameStart = false;
    }
}


// Game Win (if player wins)
// --------------------------------------------------------------
void ofApp::gameWin() {
    
    titleText.drawString("CONGRATULATIONS :)", ofGetWidth()/2-300, ofGetHeight()/2-150);
    titleText.drawString("You won!", ofGetWidth()/2-150, ofGetHeight()/2-80);
    infoText.drawString("Your Score: " + ofToString(score), ofGetWidth()/2-100, ofGetHeight()/2+30);
    
    ofDrawBitmapString("Rerun the program to play again", 400, ofGetHeight()/2+200);
}

// Game over (if player loses)
// --------------------------------------------------------------
void ofApp::gameOver() {
    
    titleText.drawString("YOU LOST :(", ofGetWidth()/2-150, ofGetHeight()/2-150);
    infoText.drawString("Your Score: " + ofToString(score), ofGetWidth()/2-100, ofGetHeight()/2+30);

    ofDrawBitmapString("Rerun the program to play again", 400, ofGetHeight()/2+200);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    
    if (key == OF_KEY_LEFT) {
        player.left();
    }
    else if (key == OF_KEY_RIGHT) {
        player.right();
    }
    
    if (key == OF_KEY_RETURN) {  //Press Enter to start game
        bGameStart = true;
        bStartScreen = false;
    }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
