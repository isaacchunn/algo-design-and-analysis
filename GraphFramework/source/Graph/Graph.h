#ifndef GRAPH_H
#define GRAPH_H

#include <unordered_map>
#include <vector>
#include <time.h>
#include "ListNode.h"
#include "../Misc/DataHandler.h"

using namespace std;

enum GRAPH_TYPE
{
	DIRECTIONAL,
	BIDIRECTIONAL,
	TOTAL_TYPE
};

class Graph
{
	public:
		Graph();
		Graph(Graph * g);
		Graph(GRAPH_TYPE type);
		~Graph();

		//Public for ease of accessibility as I want functions so I dont use struct.
		int V;
		int E;
		GRAPH_TYPE type;

		//Vector of nodes
		std::vector<Node*> nodes;

		//Initial graph
		vector<vector<int>> adjMatrix;
		vector<ListNode*> adjList;
		
		//Functions
		void SetNoOfVertices(int vertices);
		void Clear();
		void UpdateAdjacencyList();
		//CSV
		bool LoadGraph(std::string file);
		bool ExportGraph(std::string file);
		//Node addition and deletion later on
		//Printing
		void PrintAdjMatrix();
		void PrintAdjList();
		//Random function
		void GenerateRandomGraph(int numberOfNodes, int density);
		//New function to accomodate Prim's
		void AddBidirectionalEdge(int v1, int v2, int weight, bool oneIndexed = true);
		//Function to copy the necessary without the adjMatrix and adjList
		void SetupMST(Graph* g);
		
};

#endif

