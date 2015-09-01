/* 
 * File:   DisjointSets.h
 * Author: Connor Stanford
 * Submitted: 3/18/2015
 * Certificate of Authenticity: I certify that this assignment is entirely my
 * own work. 
 *
 * 
 * Name: DisjointSets
 * Description: A disjoint sets data structure 
 * Base Class: Not applicable
 * 
 * Class Attributes (data members):
 * Name:  set
 * Description: a vector used to contain a specified number of items in the set.
 * Type: int 
 * Range of acceptable values: Not applicable.
 * 
 * Name:  elementsInSet
 * Description: keeps a count of the total number of elements in the disjoint sets.
 * Type: int 
 * Range of acceptable values: Not applicable.
 * 
 * Name:  numOfSets
 * Description: keeps a count of the total sets in the disjoint sets.
 * Type: int 
 * Range of acceptable values: Not applicable.
 * 
 * Class Operations (member functions):
 * Prototype: void unionSets(int root1, int root2);
 * Description: Performs a union of two disjoint sets using the weighted
 *              union rule. 
 * Precondition(s): Assumes that root1 and root2 are not already in the same
 *                  disjoint set.
 * Postcondition(s): root1 and root2 will be placed in the same disjoint set.
 *                   numOfSets will be decremented by 1.
 * Cost analysis: O(log n)
 * Visibility: Public
 * 
 * Prototype: int find(int x);
 * Description: Returns the root of the tree containing x – optimized by path compression. 
 * Precondition(s): none. 
 * Postcondition(s): : Returns an integer value representing the root of the tree containing x.
 * Cost analysis: O(M log n)
 * Visibility: Public
 *
 * Prototype: int getNumOfSets();
 * Description: Returns the number of disjoint sets currently in set[];
 * Precondition(s): None.
 * Postcondition(s): An integer value is returned. 
 * Cost analysis: Θ(1)
 * Visibility: Public
 * 
 * Prototype: int getNumOfElements();
 * Description:Returns the number of elements currently in set[]. 
 * Precondition(s): None.
 * Postcondition(s): An integer value is returned. 
 * Cost analysis: Θ(1)
 * Visibility: Public
 *
 */

#ifndef DISJOINTSETS_H
#define	DISJOINTSETS_H

#include <vector>
using namespace std;

class DisjointSets {
public:
    DisjointSets();
    explicit DisjointSets(int numElements);
    
    int find(int x);
    void unionSets(int root1, int root2);
    virtual ~DisjointSets();
    int getNumOfSets();
    int getNumOfElements();
    
   
   
private:
    vector<int> set;
    int elementsInSet;
    int numOfSets;
};

#endif	/* DISJOINTSETS_H */


