#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include "ListNode.h"

using namespace std;

struct Graph
{
	int V;
	int E;

	//Adjacency Matrix Implementation
	vector<vector<int>> adjMatrix;
	//Adjacency List Implementation
	vector<ListNode*> adjList;
};

#endif

