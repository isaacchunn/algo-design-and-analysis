#include "Dijkstra.h"

#define DEBUGPRINT

//Static variable declarations
vector<int> Dijkstra::S = {};
vector<Node*> Dijkstra::pi = {};
vector<int> Dijkstra::pathCount = {};

void Dijkstra::CalculateShortestPath(Graph *g , Node * source)
{
    //Handle trivial cases
    if(g == NULL || source== NULL)
        return;
    
    cout << "Calculating Shortest Path from " << source->name << endl;
    
    //Initialize new priority queue
    //Priority queue in terms of int distances, we will utilise the map
    priority_queue<Node*, vector<Node*>, CompareNode> pq;
    
    //Clear our previous vectors
    pi.clear();
    S.clear();
    pathCount.clear();
    
    //Resize our containers to the new graph's vertices
    pi.resize(g->V);
    S.resize(g->V);
    pathCount.resize(g->V);
    
    //For each vertice in graph (assumed to be in ascending order)
    for(int v = 0; v < g->V; v++)
    {
        //Set distance of each node from source to be MAX
        g->nodes[v]->dist = INT_MAX;
        //Initialize all predecessors to NULL
        pi[v] = NULL;
        //Initialize all S to be 0 as none are in the set at this time
        S[v] = 0;
    }
    //Update distance to source to be 0 as source -> source is 0
    source->dist = 0;
    //Update distinct paths of source to source to be 1
    pathCount[source->vertex] = 1;
    
    //Store all into priority queue
    for(int v = 0; v < g->V; v++)
    {
        //Push all inside
        pq.push(g->nodes[v]);
    }
    
    //Print iterations
    int iteration = 1;
    
    //While the queue is not empty, extract
    while(!pq.empty())
    {
#ifdef DEBUGPRINT
        Debug(g,iteration++);
#endif
        //Pop first u to get first vertex
        Node * u = pq.top();
        pq.pop();
        //Set in array that this node is the smallest at this iteration
        S[u->vertex] = 1;
        
        //Then for each vertex v adjacent to u
        //Look into our adjacency matrix
        for(int i = 0; i < g->V; i++)
        {
            //Look through adjacent nodes
            int cost = g->adjMatrix[u->vertex][i];
            if(cost != INT_MAX)
            {
                //There is a link
                Node * adjNode = g->nodes[i];
                //If this node is not in the shortest path set
                //And the current distance to the node is more than the current cost to REACH current vertex + distance from this vertex to node
                if(S[adjNode->vertex] != 1 && adjNode->dist > u->dist + cost)
                {
                    //Update the distance of adjacent node to the shorter distance
                    adjNode->dist = u->dist + cost;
                    //Update pre-decessor
                    pi[adjNode->vertex] = u;
                    
                    //Update the counts to take into the distinct shortest paths of the parent as the shortest path is now from the parent
                    pathCount[adjNode->vertex] = pathCount[u->vertex];
                    
                    //Swap with another empty queue and populate
                    priority_queue<Node*, vector<Node*>, CompareNode> emptyPQ;
                    pq.swap(emptyPQ);
                    
                    //Append all nodes into the priority queue after updating the distance sof node
                    for(int v = 0; v < g->V; v++)
                    {
                        //As long as this vertex is not already in the set S
                        if(S[v] != 1)
                        {
                            //Push all inside
                            pq.push(g->nodes[v]);
                        }
                    }
                }
                else if(S[adjNode->vertex] != 1 && adjNode->dist == u->dist + cost)
                {
                    //This case handles the part where another adjacent node has the same cost (another distinct path)
                    //Increment the count of adj node by that of u which includes all the unique paths that go to u
                    pathCount[adjNode->vertex] += pathCount[u->vertex];
                }
            }
        }
    }
#ifdef DEBUGPRINT
    Debug(g,iteration++);
#endif
}

void Dijkstra::FindShortestPath(Graph * g, Node * source, Node * target)
{
    //Trivial case checking
    if(g == NULL || source == NULL || target == NULL)
    {
        cout << "Null pointer exception in finding shortest path" << endl;
        return;
    }
    //Calculate our shortest paths from the soruce node given
    CalculateShortestPath(g, source);
    vector<Node*> path;
    //Assign current node to be target so we can get our path in reverse
    Node * currentNode = target;
    int pathCost = currentNode->dist;
    while (currentNode != NULL && currentNode != source)
    {
        //Push back current node
        path.push_back(currentNode);
        currentNode = pi[currentNode->vertex];
    }
    //Check if no path was found
    if(currentNode == NULL)
    {
        cout << "No path between " << source->name << " and " << target->name << endl;
        return;
    }
    
    //Else we managed to find a path, so print out total cost
    cout << "Path found success! Path cost: " << pathCost << endl;
    //Push back final source node
    path.push_back(currentNode);
    //Just print in reverse first to show it works!
    for(int i = (int)path.size() - 1; i >= 0; i--)
    {
        cout << path[i]->vertex + 1;
        //cout << path[i]->name;
        if(i != 0)
            cout<< " -> ";
    }
    cout << endl;
}

void Dijkstra::Debug(Graph * g, int iteration)
{
    cout << "---\nIteration: " << iteration++ << endl;
    //Print S (for tutorial questions)
    cout << "S: ";
    for(auto i : S)
    {
        cout << i << " ";
    }
    cout << endl;
    //Print D
    cout << "D: ";
    for(int i = 0; i < g->V; i++)
    {
        cout << g->nodes[i]->dist << " ";
    }
    cout << endl;
    //Print pi
    cout << "Pi: ";
    for(auto i : pi)
    {
        if(i == NULL)
            cout << "NULL ";
        else
            //cout << i->name << " ";
            cout << i->vertex + 1 << " ";
    }
    cout << endl;
    //Print path counts
    cout << "Paths: ";
    for(auto i : pathCount)
    {
        //cout << i->name << " ";
        cout << i << " ";
    }
    cout  << endl;
}
