#include "Prim.h"

//Initialize static variables
std::vector<Node*> Prim::pi = {};
std::vector<int> Prim::S = {};

void Prim::BuildMST(Graph* g, Graph* mst, Node* source)
{
	//Trivial case checking
	if (g == NULL || source == NULL)
		return;
	//Initialize our priority queue that is minimising
	PriorityQueue<Node*> * pq = new PriorityQueue<Node*>(MINIMISING);

	//Clear our vectors
	pi.clear();
	S.clear();

	//Resize our vectors
	pi.resize(g->V);
	S.resize(g->V);

	//For each vertice in graph (assumed to be in ascending order)
	for (int v = 0; v < g->V; v++)
	{
		//Set distance of each node from source to be MAX
		g->nodes[v]->SetDistanceFromSource(INT_MAX);
		//Initialize all predecessors to NULL
		pi[v] = NULL;
		//Initialize all S to be 0 as none are in the set at this time
		S[v] = 0;
	}

	//Set the d of source vertex and visited to be 1
	//Update distance to source to be 0 as source -> source is 0
	source->SetDistanceFromSource(0);
	//Done in pq loop
	//S[source->GetVertex()] = 1;
	//Insert source into pq
	pq->Insert(source);

	//While there are fringe vertexes
	while (!pq->IsEmpty())
	{
		//Get the minimum is equivalent of deletion
		Node* u = pq->Top();
		//Set visited of u to be 1
		S[u->GetVertex()] = 1;
		//Update fringe
		UpdateFringe(g, pq, u);
	}
	//After all this, update MST
	UpdateMST(mst);
}

void Prim::BuildMST(Graph* g, Graph* mst, int sourceVertex)
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

void Prim::UpdateFringe(Graph* g, PriorityQueue<Node*>* pq, Node* u)
{
	//Trivial case checking
	if (g == NULL || pq == NULL || u == NULL)
		return;

	//Find all vertices that are adjacent to u, so just use our adj list~
	ListNode* curr = g->adjList[u->GetVertex()];
	//Traverse the adj list
	while (curr != NULL)
	{
		Node* adjNode = curr->node;
		int adjVertex = adjNode->GetVertex();
		if (S[adjVertex] != 1) //If its not already a tree vertex
		{
			//This is the current cost of the weight of edge u->adjNode
			int newWeight = curr->cost;
			//This means that the node has not been a neighbour of some other vertex
			if (adjNode->GetDistanceFromSource() == INT_MAX)
			{
				//Update distance to tree vertex as weight and update predecessors
				adjNode->SetDistanceFromSource(newWeight);
				pi[adjVertex] = u;
				//Insert int othe priority queue as this was not a neighbour before so its not in the priority queue
				pq->Insert(adjNode);
			}
			else if (newWeight < adjNode->GetDistanceFromSource()) //adj node was already discovered by a previous node, and the new weight is found is shorter
			{
				//Delete it from the pq
				pq->Delete(adjNode);
				//Update distance to tree vertex as weight and update predecessors
				adjNode->SetDistanceFromSource(newWeight);
				pi[adjVertex] = u;
				//Have to reinsert into the priority queue
				pq->Insert(adjNode);
			}
		}
		curr = curr->next;
	}
}

/// <summary>
/// Update our MST based on our pi array
/// </summary>
/// <param name="mst"></param>
void Prim::UpdateMST(Graph* mst)
{
	//Loop through our pi array and update back to our source
	for (int i = 0; i < mst->V; i++)
	{
		//Check through our pi array, and set the links accordingly as long as pi isnt null at index
		if (pi[i] == NULL)
			continue;

		//If its not NULL, then parent is stored in pi[i];
		Node* parent = pi[i];
		int parentVertex = parent->GetVertex();
		//Update bidirectional edge in mst
		mst->AddBidirectionalEdge(i, parentVertex, mst->nodes[i]->GetDistanceFromSource(), false);
	}
	mst->UpdateAdjacencyList();
}
