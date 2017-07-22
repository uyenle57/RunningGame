#pragma once

#include "ofMain.h"
#include "Obstacle.h"
#include "Coins.hpp"
#include "Player.h"
#include "Floor.h"
//#include "WallLeft.hpp" - no need to include Parent class (WallLeft) because Child class (WallRight) is already includes it
#include "WallRight.hpp"

#include <vector>
using std::vector;


class ofApp : public ofBaseApp {

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    void journeyBar();
    float journeyIndicator;
    
    void lifeCount();
    int numLife, score;
    
    void gameWin();
    void gameOver();
    
    bool bStartScreen, bGameStart, bGameWin, bGameOver;
    
    ofTrueTypeFont titleText, infoText;  //load font from bin/data
    ofSoundPlayer soundtrack, bump;
    
    //Object classes
    Player player;  //the user
    vector <Obstacle> obstacles;
    vector <Coins> coins;
    deque <Floor> floor;
    int floorSize;   //size of Floor
    float floorNum = 100;
    
    deque <WallLeft> wallLeft;
    deque <WallRight> wallRight;
    int brickSize;
    
};

