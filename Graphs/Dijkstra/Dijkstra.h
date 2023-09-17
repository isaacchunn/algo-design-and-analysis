#ifndef DJIKSTRA_H
#define DJIKSTRA_H

#include "Graph.h"
#include "Node.h"
#include <queue>

class Dijkstra
{
public:
	//Simple wrapper that contains a static method
	static void CalculateShortestPath(Graph * g, Node * source);
    static void FindShortestPath(Graph * g, Node * source, Node* end);

private:
	//Private methods that are exclusive to djikstra
    static bool calculatedShortestPath;
    
    //Vector that stores the distance of each vertex to source node
	static vector<int> d;
    //Vector that stores the predecessor "node" of the associated shortest path
	static vector<Node> pi;
    //A vector that indicates if this node is already been accounted for
	static vector<int> S;
};
#endif

