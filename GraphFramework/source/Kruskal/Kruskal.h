#ifndef KRUSKAL_H
#define KRUSKAL_H

#include<vector>
#include "../Graph/Node.h"
#include "../PriorityQueue/PriorityQueue.h"
#include "../Graph/Graph.h"
#include "../UnionFind/QuickFind.h"

class Kruskal
{
	private:
		static void UpdateMST(Graph* mst);
	public:
		//Functions to build our MST
		static void BuildMST(Graph* g, Graph* mst, Node* source);
		static void BuildMST(Graph* g, Graph* mst, int sourceVertex);
};


#endif