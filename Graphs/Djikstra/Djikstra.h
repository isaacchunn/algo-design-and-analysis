#ifndef DJIKSTRA_H
#define DJIKSTRA_H

#include "Graph.h"
#include "ListNode.h"
#include <queue>

class Djikstra
{
public:
	//Simple wrapper that contains a static method
	static void FindShortestPath(Graph * g, ListNode * source);

private:
	//Private methods that are exclusive to djikstra
	static vector<int> d;
	static vector<int> pi;
	static vector<int> S;
};
#endif

