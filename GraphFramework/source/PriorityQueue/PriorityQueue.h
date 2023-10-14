#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

//Wrapper class for our heap that contains many public functions
#include "../Heap/Heap.h"
#include "../Graph/Node.h"

/// <summary>
/// Only works with pointers for now, will find a better way in the future
/// </summary>
/// <typeparam name="T"></typeparam>
template<class T>
class PriorityQueue
{
	public:
		Heap<T> heap;
	public:
		PriorityQueue();
		PriorityQueue(TYPE heapType);
		~PriorityQueue();

		//Typical queue functions
		bool Insert(T n);
		bool Delete(T n);
		T Top();
		//Some debugging functions
		void PrintQueue();
		//Other needed functions
		bool IsEmpty();
};

#include "PriorityQueue.tpp"
#endif

