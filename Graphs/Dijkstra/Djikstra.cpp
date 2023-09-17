#include "Dijkstra.h"

bool Dijkstra::calculatedShortestPath = false;


void Dijkstra::CalculateShortestPath(Graph *g , Node * source)
{
    //Initially, do some trivial case checkign
    if(g == NULL)
        return;
    
    calculatedShortestPath = true;
    
    //Clear our previous vectors
    d.clear();
    pi.clear();
    S.clear();
    
    //For each vertice in graph (assumed to be in ascending order)
    for(int v = 0; v < g->V; v++)
    {
        d[v] = INT_MAX;
        pi[
        
    }
}

void Dijkstra::FindShortestPath(Graph * g, Node * sourceVertex, Node * targetVertex)
{
    if(!calculatedShortestPath)
        CalculateShortestPath(g, sourceVertex);
    
}
