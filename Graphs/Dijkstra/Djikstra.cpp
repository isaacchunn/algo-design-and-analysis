#include "Dijkstra.h"

bool Dijkstra::calculatedShortestPath = false;
vector<int> Dijkstra::S = {};
vector<Node*> Dijkstra::pi = {};

void Dijkstra::CalculateShortestPath(Graph *g , Node * source)
{
    //Initially, do some trivial case checkign
    if(g == NULL)
        return;
    
    //Initialize new priority queue
    calculatedShortestPath = true;
    //Priority queue in terms of int distances, we will utilise the map
    priority_queue<Node*, vector<Node*>, CompareNode> pq;
    //Clear our previous vectors
    //d.clear();
    pi.clear();
    S.clear();
    //Resize vectors to the new graph's vertices
    //d.resize(g->V);
    pi.resize(g->V);
    S.resize(g->V);
    
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
    
    //Store all into priority queue
    for(int v = 0; v < g->V; v++)
    {
        //Push all inside
        pq.push(g->nodes[v]);
    }
    /*
    //Print out initial state of priority queue
    while (!pq.empty()) {
        std::cout << pq.top()->name << ' ';
        pq.pop();
    }
     */
    
    //While the queue is not empty, extract
    while(!pq.empty())
    {
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
                    //Swap with another empty queue and populate
                    priority_queue<Node*, vector<Node*>, CompareNode> emptyPQ;
                    pq.swap(emptyPQ);
                    //Append all again
                    for(int v = 0; v < g->V; v++)
                    {
                        //Push all inside
                        pq.push(g->nodes[v]);
                    }
                }
            }
        }
        
    }
    
}

void Dijkstra::FindShortestPath(Graph * g, Node * source, Node * target)
{
    if(!calculatedShortestPath)
        CalculateShortestPath(g, source);

    //Else , access the pi at vertex and find the path from target vertex
    vector<Node*> path;
    Node * currentNode = target;
    while (currentNode != NULL && currentNode != source)
    {
        //Push back current node
        path.push_back(currentNode);
        currentNode = pi[currentNode->vertex];
    }
    if(currentNode == NULL)
    {
        cout << "No path between " << source->name << " and " << target->name << endl;
        return;
    }
    cout << "Path found success!" << endl;
    //Push back final source node
    path.push_back(currentNode);
    //Just print in reverse first to show it works!
    for(int i = path.size() - 1; i >= 0; i--)
    {
        cout << path[i]->name;
        if(i != 0)
            cout<< " -> ";
    }
    cout << endl;
}
