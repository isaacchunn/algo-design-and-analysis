#include "Edge.h"

Edge::Edge()
{
}

Edge::Edge(Node* source, Node* to, int weight)
    :weight(weight)    
{
    nodes.first = source;
    nodes.second = to;
}

Edge::~Edge()
{
}

/// <summary>
/// Gets the destination node. Does not matter if its bidirectional as both are the same.
/// </summary>
/// <returns>destination node</returns>
Node* Edge::GetTo()
{
    return nodes.second;
}

/// <summary>
/// Returns the weight of this edge
/// </summary>
/// <returns></returns>
int Edge::GetWeight()
{
    return weight;
}

bool Edge::operator>(const Edge& other) const
{
    return weight > other.weight;
}

bool Edge::operator<(const Edge& other) const
{
    return weight < other.weight;
}

bool Edge::operator>=(const Edge& other) const
{
    return weight >= other.weight;
}

bool Edge::operator<=(const Edge& other) const
{
    return weight <= other.weight;
}

Node* Edge::GetSource()
{
    return nodes.first;
}

std::ostream& operator<<(std::ostream& os, const Edge* other)
{
    os << "(" << other->nodes.first->GetName() << "," << other->nodes.second->GetName() << ") Weight: " << other->weight;
    return os;
}

std::ostream& operator<<(std::ostream& os, const Edge& other)
{
    os << "(" << other.nodes.first->GetName() << "," << other.nodes.second->GetName() << ") Weight: " << other.weight;
    return os;
}
