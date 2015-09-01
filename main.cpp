/* 
 * File name:   Random Maze Generator
 * Author:      Connor Stanford 
 * Due Date :   March 18, 2015
 * Due Time :   10:00 pm                             
 * Certificate of Authenticity: I certify that this assignment is entirely my
 * own work. 
 * 
 *
 * Problem Description: 
 * Name: Random Maze Generator
 * This program will generate a random maze using two dimensions given by the user.
 * Once the maze has been generated, the program will output which walls still
 * remain in each cell of the maze.
 * 
 * Problem Specification:
 * This program will automatically generate a random maze using the following
 * algorithm: View the maze as a grid of cells where each cell is enclosed by
 * four walls separating it from all adjoining cells. Randomly select a wall
 * separating two cells and remove it if a path in the maze does not already 
 * join the two cells. Continue randomly removing walls between two cells, not
 * currently joined by a path, until all cells are reachable from every other
 * cell. Then randomly select a cell on one edge of the maze and a cell on the
 * opposing edge of the maze and remove their outer walls to create an entrance
 * and exit for the maze. The implementation will include a Union/Find (DisjSet)
 * class, which uses a forest of trees formed by the partition of a set via the
 * parent pointer array implementation. Furthermore, the implementation will 
 * utilize the weighted union rule. The weight used will be the number of 
 * elements in the partition (nodes in the tree ). The implementation will also
 * utilize path compression in the find function. When executed, the program 
 * will prompt the user for the two dimensions of the maze. It will then 
 * generate the maze following the above algorithm using the union/find class.
 * The maze will then be written to the output. Each line of the output will 
 * represent one square or cell in the maze and indicate which walls remain 
 * around that square.
 * 
 * 
 * System Architecture Description
 * Object: mySet    Class: DisjointSets
 * mySet is a disjoint set that will be used to keep track of which cells are
 * connected in the maze. Every cell will have an index number that correlates
 * directly to mySet. 
 * 
 * Object: Maze     Class: Cell
 * Maze is a two dimensional array made of individual cells that is used to
 * represent all walls of the randomly generated maze to be. The program will
 * randomly select cells in Maze to destroy – generating a path through the maze.
 * 
 */


#include <iostream> 
#include <fstream> 
#include <iomanip> 
#include <cstdlib> 
#include <string>
#include <time.h>
#include "Cell.h"
#include "DisjointSets.h"
using namespace std;



int main(){
    

    // Ask User for the dimensions of the maze
    int rows, columns;
    cout << "Enter the number of rows in the maze: ";
    cin >> rows;
    cout << endl << "Enter the number of columns in the maze: ";
    cin >> columns;
    cout << endl;
    
    
    
    // The number of elements in the disjoint sets will be the
    // number of rows * the number of columns. 
    int elementsInSet = ((rows * columns));
    DisjointSets mySet(elementsInSet);
    
   
    
    // construct the initial grid that will become the maze
    Cell Maze[rows][columns];
    
    // set indexNumber for all elements in Maze[][]
    int indexCount = 0;
    for(int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            Maze[i][j].setIndexNumber(indexCount);
            indexCount++;
        }
    }
    
    
    // Set borders for all cells 
    // A border cannot be broken until the maze is completed and randomly 
    // generate a random entrance and exit on the east and west sides of the 
    // maze
    
    // if the cell is on the first row - northWall is a border
    for(int i = 0; i < columns; i++)
    {
        Maze[0][i].setBorder(0);
    }

    //if row[rows - 1 ] - southWall is a  border
    for(int i = 0; i < columns; i++)
    {
        Maze[(rows - 1)][i].setBorder(1);
    }
    
     //if column[columns - 1] - eastWall is a border
    for(int i = 0; i < rows; i++)
    {
        Maze[i][(columns - 1)].setBorder(2);
    }
    
     // if column[0] - westWall is a border
    for(int i = 0; i < rows; i++)
    {
        Maze[i][0].setBorder(3);
    }

   
    // Randomly select a cell and remove walls.
    // repeat until there is only one set in the disjoint sets
    srand (time(NULL));// remaining   
    while( mySet.getNumOfSets() > 1)  // repeat until there is only one set 
    { 
    
        int randRow = (rand() % rows);
        int randColumn = (rand() % columns);
        int randomWall = (rand() % 4);

        // index number of the randomly selected cell
        int index = Maze[randRow][randColumn].getIndexNumber();


        switch(randomWall){
            
            // if the randomly selected cell wall is not a border wall - 
            // destroy the wall and the associated wall of the neighbor cell.

            
            case 0:       // north wall
                if( Maze[randRow][randColumn].checkBorder(0) == false)
                {
                    if( mySet.find(index) != mySet.find((index-columns)))
                    {
                        mySet.unionSets(index, (index - columns));
                        Maze[ randRow ][ randColumn ].breakWall(0);
                        Maze[ (randRow - 1) ][ randColumn ].breakWall(1);
                    }
                }
                break;

            case 1:             // south wall
                if( Maze[randRow][randColumn].checkBorder(1) == false)
                {

                    if( mySet.find(index) != mySet.find((index + columns)))
                    {
                      mySet.unionSets(index, (index + columns));
                      Maze[ randRow ][ randColumn ].breakWall(1);
                      Maze[ (randRow + 1) ][ randColumn ].breakWall(0);
                    }

                }
                break;
                
            case 2:             // east wall
                if( Maze[randRow][randColumn].checkBorder(2) == false)
                {
                    if( mySet.find(index) != mySet.find((index + 1)))
                    {
                        mySet.unionSets(index, (index + 1 ));
                        Maze[ randRow ][ randColumn ].breakWall(2);
                        Maze[ randRow ][ (randColumn + 1) ].breakWall(3);
                    }
                }
                break;

            case 3:             // west wall
                if( Maze[randRow][randColumn].checkBorder(3) == false)
                {
                    if( mySet.find(index) != mySet.find((index - 1)) )
                    {
                        mySet.unionSets(index, ((index - 1)));
                        Maze[ randRow ][ randColumn].breakWall(3);
                        Maze[ randRow ][ (randColumn - 1)].breakWall(2);
                    }
                }
                break;   
        }
        
        
      }
  
  
  // Randomly break a wall on the east and west side of the maze for 
  // an Entrance and an Exit
  int entrance = rand() % rows;
  int exit = rand() % rows;
  Maze[entrance][0].breakWall(3);
  Maze[exit][columns - 1].breakWall(2);
  
 
  // Display remaining walls to console, which forms our maze. 
   for(int i = 0; i < rows; i++)
   {
       for(int j = 0; j < columns; j++)
       {
           cout << "Cell " << setw(2) << right
                << ( Maze[i][j].getIndexNumber() + 1) << ":";
           Maze[i][j].displayRemainingWalls();
       }
   }
      
    return 0;
}
