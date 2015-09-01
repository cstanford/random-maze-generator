# random-maze-generator
=======================

Problem Description: 
Name: Random Maze Generator
This program will generate a random maze using two dimensions given by the user.
Once the maze has been generated, the program will output which walls still
remain in each cell of the maze.

Problem Specification:
This program will automatically generate a random maze using the following
algorithm: View the maze as a grid of cells where each cell is enclosed by
four walls separating it from all adjoining cells. Randomly select a wall
separating two cells and remove it if a path in the maze does not already 
join the two cells. Continue randomly removing walls between two cells, not
currently joined by a path, until all cells are reachable from every other
cell. Then randomly select a cell on one edge of the maze and a cell on the
opposing edge of the maze and remove their outer walls to create an entrance
and exit for the maze. The implementation will include a Union/Find (DisjSet)
class, which uses a forest of trees formed by the partition of a set via the
parent pointer array implementation. Furthermore, the implementation will 
utilize the weighted union rule. The weight used will be the number of 
elements in the partition (nodes in the tree ). The implementation will also
utilize path compression in the find function. When executed, the program 
will prompt the user for the two dimensions of the maze. It will then 
generate the maze following the above algorithm using the union/find class.
The maze will then be written to the output. Each line of the output will 
represent one square or cell in the maze and indicate which walls remain 
around that square.
