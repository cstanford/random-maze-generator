/* 
 * File:   DisjointSets.cpp
 * Author: Connor Stanford
 * Submitted: 3/18/2015
 * Certificate of Authenticity: I certify that this assignment is entirely my
 * own work. 
 *
 */

#include "DisjointSets.h"

DisjointSets::DisjointSets() {
}


DisjointSets::DisjointSets(int numElements)
{   // creates a vector of length numElements.
    // initializes each cell to contain the value -1.
    for(int i = 0; i < numElements; i++)
    {
        set.push_back(-1);
    }
    elementsInSet = numElements;
    numOfSets = numElements;
}


DisjointSets::~DisjointSets() {
    
}

void DisjointSets::unionSets(int root1, int root2)
{
    // Union of two disjoint sets using the weighted union rule.
    int i = find(root1);
    int j = find(root2);
    
    if( set[j] < set[i]) 
    { //if j is deeper than i
        --set[i];       
        set[j] = i;    
    }
    else
    {
        --set[j];
        set[i] = j;
    }
  
    numOfSets--;         // A union will result in one less disjointed set
}

int DisjointSets::find(int x)
{
    // Performs a find with path compression
    
    if( set[ x ] < 0 )
        return x;
    else
        return set[ x ] = find( set[ x ] );
}

int DisjointSets::getNumOfSets()
{
    return numOfSets;
}

int DisjointSets::getNumOfElements()
{
    return elementsInSet;
}


