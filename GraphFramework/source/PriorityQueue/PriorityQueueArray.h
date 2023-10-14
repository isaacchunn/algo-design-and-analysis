#ifndef PRIORITY_QUEUE_ARRAY_H
#define PRIORITY_QUEUE_ARRAY_H

#include "../Graph/Node.h"
#include "../Heap/Heap.h"

#include <vector>
#include <set>

/// <summary>
/// Mimics the behaviour of a priority queue using an array (* TYPE DOES NOT DO ANYTHING FOR NOW, IT IS ONLY MINIMIZING REGARDLESS OF TYPE!)
/// </summary>
class PriorityQueueArray
{
	private:
		std::vector<Node*> elements;
		HEAP_TYPE type;
		int size;
	public:
		PriorityQueueArray();
		PriorityQueueArray(HEAP_TYPE type);

		//Typical queue functions
		bool Insert(Node* n);
		bool Delete(Node* n);
		bool Delete(int vertex);
		Node* GetSmallest();
		bool IsEmpty();

		//Some debugging functions
		void PrintQueue();
};
#endif

