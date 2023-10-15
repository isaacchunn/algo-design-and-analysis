#ifndef KRUSKAL_H
#define KRUSKAL_H

#include<vector>
#include "../Graph/Node.h"
#include "../PriorityQueue/PriorityQueue.h"
#include "../PriorityQueue/PriorityQueueArray.h"
#include "../Graph/Graph.h"
#include "../UnionFind/QuickFind.h"
#include "../UnionFind/QuickUnion.h"
#include "../UnionFind/WQUPC.h"
#include "../Misc/Timer.h"

class Kruskal
{
	public:
		//Functions to build our MST
		static void BuildMST(Graph* g, Graph* mst, Node* source, UNION_TYPE type);
		static void BuildMST(Graph* g, Graph* mst, int sourceVertex, UNION_TYPE type);
};


#endif