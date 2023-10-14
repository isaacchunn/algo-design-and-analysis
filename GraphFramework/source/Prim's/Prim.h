#ifndef PRIM_H
#define PRIM_H

#include<vector>
#include "../Graph/Node.h"
#include "../PriorityQueue/PriorityQueue.h"
#include "../Graph/Graph.h"

/// <summary>
/// Static class to hold our distances and pi arrays, Prim works on *undirected* graphs.
/// </summary>
class Prim {
	private:
		static std::vector<Node*> pi; //vector of nodes to figure out parents
		static std::vector<int> S; //vector to realize whether a vertex is part of the spanning tree being built

		//private function to update fringe
		static void UpdateFringe(Graph* g, PriorityQueue<Node*>* pq, Node* u);
		static void UpdateMST(Graph* mst);
	public:
		//Functions to build our MST
		static void BuildMST(Graph* g, Graph * mst, Node* source);
		static void BuildMST(Graph* g, Graph * mst, int sourceVertex);
		//Functions to print our MST, or save it somewhere else
};

#endif