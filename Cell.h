/* 
 * File:   Cell.h
 * Author: Connor Stanford
 * Submitted: 3/18/2015
 * Certificate of Authenticity: I certify that this assignment is entirely my
 * own work. 
 *
 * 
 * Class Information:
 * Name: Cell
 * Description: An object used to view the maze as a grid of cells. This class
 *              holds the information pertaining to each cell wall in the grid. 
 * Base Class: Not applicable
 * 
 * Class Attributes (data members):
 * Name:  IndexNum
 * Description: The index number of each cell. Used to reference each cell to
 *              its corresponding member in the disjoint sets.
 * Type: int
 * Range of acceptable values: Not applicable.
 * 
 * Name:  northBorder
 * Description: Used to determine if the cell in question is a northern border
 *              of the maze. False by default.
 * Type: bool
 * Range of acceptable values: Not applicable.
 * 
 * Name:  northWall
 * Description:  Used to determine if the cell in question’s north wall remains
 *               in tact or has been destroyed. True by default. 
 * Type: bool
 * Range of acceptable values: Not applicable.
 * 
 * Name:  southBorder
 * Description: Used to determine if the cell in question is a southern border
 *              of the maze. False by default.
 * Type: bool
 * Range of acceptable values: Not applicable.
 * 
 * Name:  southWall
 * Description:  Used to determine if the cell in question’s south wall remains
 *               in tact or has been destroyed. True by default. 
 * Type: bool
 * Range of acceptable values: Not applicable.
 * 
 * Name:  eastBorder
 * Description: Used to determine if the cell in question is an eastern border
 *              of the maze. False by default.
 * Type: bool
 * Range of acceptable values: Not applicable.
 * 
 * 
 * Name:  eastWall
 * Description:  Used to determine if the cell in question’s east wall remains
 *               in tact or has been destroyed. True by default. 
 * Type: bool
 * Range of acceptable values: Not applicable.
 * 
 * Name:  westBorder
 * Description: Used to determine if the cell in question is a western border
 *              of the maze. False by default.
 * Type: bool
 * Range of acceptable values: Not applicable.
 * 
 * Name:  westWall
 * Description:  Used to determine if the cell in question’s west wall remains
 *               in tact or has been destroyed. True by default. 
 * Type: bool
 * Range of acceptable values: Not applicable.
 * 
 * Class Operations (member functions):
 * Prototype: void breakWall(int wall);
 * Description: Destroys the cells specified wall – 0 for northWall, 1 for
 *              southWall, 2 for eastWall, 3 for westWall.
 * Precondition(s): Assumes that the intended wall to be destroyed is true. 
 * Postcondition(s): The selected cell wall’s value returns  false. 
 * Cost analysis: O(1)
 * Visibility: Public
 *
 * Prototype: void checkWall(int wall);
 * Description: Checks to see if the specified cell’s wall is true or false – 0
 *              for northWall, 1 for southWall, 2 for eastWall, 3 for westWall.
 * Precondition(s):None. 
 * Postcondition(s): Returns true if the wall remains, and false if otherwise. 
 * Cost analysis: O(1)
 * Visibility: Public
 * 
 * Prototype: void checkBorder(int wall);
 * Description: Checks to see if the specified cell wall is a border– 0 for
 *              northBorder, 1 for southBorder, 2 for eastBorder, 3 for westBorder.
 * Precondition(s):None. 
 * Postcondition(s): Returns true if the wall is a border, and false if otherwise. 
 * Cost analysis: O(1)
 * Visibility: Public
 * 
 * Prototype: void setBorder(int wall);
 * Description: Sets the specified cell wall as a border– 0 for northBorder,
 *              1 for southBorder, 2 for eastBorder, 3 for westBorder.
 * Precondition(s):None. 
 * Postcondition(s): The specified cell border returns true.  
 * Cost analysis: O(1)
 * Visibility: Public
 * 
 * Prototype: void displayRemainingWalls();
 * Description: Displays what walls remain true for the specified cell to the console.
 * Precondition(s):None. 
 * Postcondition(s): Displays results to the console. 
 * Cost analysis: O(1)
 * Visibility: Public
 * 
 * Prototype: void setIndexNumber(int index);
 * Description: Sets the index number of the specified cell.
 * Precondition(s):None. 
 * Postcondition(s): The index number of the cell will be set to index.
 * Cost analysis: O(1)
 * Visibility: Public
 * 
 * 
 * Prototype: int getIndexNumber();
 * Description: Returns the index number of the specified cell.
 * Precondition(s): None. 
 * Postcondition(s): Returns the integer value of the specified cell’s index number. 
 * Cost analysis: O(1)
 * Visibility: Public
 * 
 * 
 */

#ifndef CELL_H
#define	CELL_H
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

class Cell {
public:
    Cell();
    virtual ~Cell();
    
    
    void breakWall(int wall);   // 0 = north, 1 = south, 2 = east, 3 = west
    bool checkWall(int wall);   //
    
    bool checkBorder(int wall); // 0 = north, 1 = south, 2 = east, 3 = west
    void setBorder(int wall);
    void displayRemainingWalls();
    
    void setIndexNumber(int index);
    int getIndexNumber();
private:
    
    int indexNum;
    
    bool northBorder;
    bool northWall;
    bool southBorder;
    bool southWall;
    bool eastBorder;
    bool eastWall;
    bool westBorder;
    bool westWall;

};

#endif	/* CELL_H */
