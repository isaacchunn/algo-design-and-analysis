#ifndef EDGE_H
#define EDGE_H

#include "Node.h"

class Edge
{
	private:
		std::pair<Node*, Node*> nodes;
		int weight;
	public:
		Edge();
		Edge(Node* source, Node* to, int weight);
		~Edge();

		Node* GetSource();
		Node* GetTo();
		int GetWeight();

		//Overload and add comparisons for heap
		bool operator>(const Edge& other) const;
		bool operator<(const Edge& other) const;
		bool operator>=(const Edge& other) const;
		bool operator<=(const Edge& other) const;

		//Overloaded ostream
		friend std::ostream& operator<<(std::ostream& os, const Edge* other);
		friend std::ostream& operator<<(std::ostream& os, const Edge& other);
};


#endif