#ifndef PRIORITY_QUEUE_ARRAY_H
#define PRIORITY_QUEUE_ARRAY_H

#include "../Graph/Node.h"
#include "../Heap/Heap.h"
#include <vector>
#include <type_traits>

/// <summary>
/// Mimics the behaviour of a priority queue using an array (* TYPE DOES NOT DO ANYTHING FOR NOW, IT IS ONLY MINIMIZING REGARDLESS OF TYPE!)
/// </summary>
template <class T>
class PriorityQueueArray
{
	private:
		std::vector<T> elements;
		HEAP_TYPE type;
		int size;
	public:
		PriorityQueueArray();
		PriorityQueueArray(HEAP_TYPE type);

		//Typical queue functions
		bool Insert(T n);
		bool Delete(T n);
		template <typename U = T>
		typename std::enable_if<std::is_pointer<U>::value, T>::type GetSmallest();
		template <typename U = T>
		typename std::enable_if<!std::is_pointer<U>::value, T>::type GetSmallest();
		bool IsEmpty();

		//Some debugging functions
		void PrintQueue();
};

#include "PriorityQueueArray.tpp"
#endif

