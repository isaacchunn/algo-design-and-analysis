#include "Kruskal.h"

/// <summary>
/// Builds a MST using Kruskal + UnionFind
/// </summary>
/// <param name="g">graph</param>
/// <param name="mst">mst</param>
/// <param name="source">source node</param>
void Kruskal::BuildMST(Graph* g, Graph* mst, Node* source)
{
	//Initialize a new priority queue
	PriorityQueue* pq = new PriorityQueue(MINIMISING);
	//Insert all the edges of the graph into the priority queue

}

/// <summary>
/// Builds a MST using Kruskal + UnionFind
/// </summary>
/// <param name="g">graph</param>
/// <param name="mst">mst</param>
/// <param name="sourceVertex">source vertex</param>
void Kruskal::BuildMST(Graph* g, Graph* mst, int sourceVertex)
{	
	//No vertices
	if (g->V == 0)
		return;
	//Get a node from g
	try
	{
		Node* n = g->nodes[sourceVertex];
		BuildMST(g, mst, n);
	}
	catch (std::exception e)
	{
		return;
	}
}
