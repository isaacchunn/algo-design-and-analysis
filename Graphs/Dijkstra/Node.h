//
//  Node.h
//  Djikstra
//
//  Created by Isaac on 17/9/23.
//

#ifndef Node_h
#define Node_h

#include <string>

struct Node
{
    //Corresponds to which vertex
    int vertex;
    //Name of this node
    std::string name;
    //Distance to source
    int dist;
};

//Custom comparator that compares nodes by distance
struct CompareNode
{
    bool operator()(Node* const& n1, Node* const& n2)
    {
        return n1->dist > n2->dist;
    }
};
#endif /* Node_h */
