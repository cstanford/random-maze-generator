/* 
 * File:   Cell.cpp
 * Author: Connor Stanford
 * Submitted: 3/18/2015
 * Certificate of Authenticity: I certify that this assignment is entirely my
 * own work. 
 *
 */
#include "Cell.h"

using namespace std;

Cell::Cell() {
    // all walls in cell are true by default
    northWall = true;
    southWall = true;
    eastWall = true;
    westWall = true;
    
    // all borders in cell are false by default
    northBorder = false;
    southBorder = false;
    eastBorder = false;
    westBorder = false;
    
    
}

Cell::~Cell()
{
}


void Cell::breakWall(int wall) // 0 = north, 1 = south, 2 = east, 3 = west
{
    switch(wall){
        case 0: northWall = false;
        return;
        
        case 1: southWall = false;
        return;
        
        case 2: eastWall = false;
        return;
                
        case 3: westWall = false;
        return;   
    }
}

bool Cell::checkWall(int wall) // 0 = north, 1 = south, 2 = east, 3 = west
{
    switch(wall){
        case 0: return northWall;
        
        case 1: return southWall;
        
        case 2: return eastWall;
        
        case 3: return westWall;
        
        
    }
}


void Cell::setBorder(int wall) // 0 = north, 1 = south, 2 = east, 3 = west
{
    switch(wall){
        case 0: northBorder = true;
        break;
        
        case 1: southBorder = true;
        break;
        
        case 2: eastBorder = true;
        break;
        
        case 3: westBorder = true;
        break;    
        
    }
}

bool Cell::checkBorder(int wall) // 0 = north, 1 = south, 2 = east, 3 = west
{
    switch(wall){
        case 0: return northBorder;
        
        case 1: return southBorder;
                
        case 2: return eastBorder;
                
        case 3: return westBorder;  
        
    }
}

void Cell::displayRemainingWalls()
{
    if( northWall ){
        cout << " North ";
    }
    if( southWall ){
        cout << " South ";
    }
    if( eastWall ){
        cout << " East ";
    }
    if( westWall ){
        cout << " West ";
    }
    cout << endl;
    
}

void Cell::setIndexNumber(int index)
{
    indexNum = index;
}

int Cell::getIndexNumber()
{
    return indexNum;
}
