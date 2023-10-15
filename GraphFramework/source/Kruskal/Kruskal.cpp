#include "Kruskal.h"

/// <summary>
/// Builds a MST using Kruskal + UnionFind
/// </summary>
/// <param name="g">graph</param>
/// <param name="mst">mst</param>
/// <param name="source">source node</param>
void Kruskal::BuildMST(Graph* g, Graph* mst, Node* source, UNION_TYPE type)
{
	//Initialize a new priority queue
	PriorityQueue<Edge*> * pq = new PriorityQueue<Edge*>(MINIMISING);
	//Insert all the edges of the graph into the priority queue
	for (int i =  0; i < (int)g->edges.size(); i++)
	{
		//cout << g->edges[i] << endl;
		pq->Insert(g->edges[i]);
	}
	//Create our union find based on whatever we want by upcasting
	UnionFind* uf = NULL;
	switch (type)
	{
	case QUICKFIND:
		uf = new QuickFind(g->edges.size());
		break;
	case QUICKUNION:
		break;
	case WQUPC:
		break;
	case TOTAL_UNION_TYPE:
		break;
	default:
		break;
	}
	
	//While priority queue is not empty, and the edges have not reached V - 1 (for MST)
	while (!pq->IsEmpty() && mst->E < mst->V -1)
	{
		//Get the minimum cost edge
		Edge * e = pq->Top();
		//cout << "Chosen " << e << endl;
		//Get both node vertexes
		int v = e->GetSource()->GetVertex();
		int w = e->GetTo()->GetVertex();

		//If the two vertexes are not connected, then union them and add this edge into the MST
		if (!uf->Connected(v, w))
		{
			//cout << "Adding " << e << endl;
			uf->UnionV(v, w);
			//Add a bidirectional edge into a mst
			mst->AddBidirectionalEdge(v, w, e->GetWeight(), false);
			//Increment E
			mst->E++;
		}	
		else
		{
			//cout << "Reject " << e << endl;
		}
	}
	//After these, we can update our mst adj list
	mst->UpdateAdjacencyList();
}

/// <summary>
/// Builds a MST using Kruskal + UnionFind
/// </summary>
/// <param name="g">graph</param>
/// <param name="mst">mst</param>
/// <param name="sourceVertex">source vertex</param>
void Kruskal::BuildMST(Graph* g, Graph* mst, int sourceVertex, UNION_TYPE type)
{	
	//No vertices
	if (g->V == 0)
		return;
	//Get a node from g
	try
	{
		Node* n = g->nodes[sourceVertex];
		BuildMST(g, mst, n, type);
	}
	catch (std::exception e)
	{
		return;
	}
}
