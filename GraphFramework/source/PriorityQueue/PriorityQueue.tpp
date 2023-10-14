//#include "PriorityQueue.h"

template<class T>
PriorityQueue<T>::PriorityQueue()
{
	heap.SetHeapType(MAXIMISING);
}
template<class T>
PriorityQueue<T>::PriorityQueue(HEAP_TYPE heapType)
{
	//Set our heap type
	heap.SetHeapType(heapType);
}
template<class T>
PriorityQueue<T>::~PriorityQueue()
{
}

/// <summary>
/// Inserts a node into the heap
/// </summary>
/// <param name="n"></param>
template<class T>
bool PriorityQueue<T>::Insert(T n)
{
	if (n == NULL)
		return false;

	heap.Insert(n);
	return true;
}

/// <summary>
/// Removes a specific node from the heap
/// </summary>
/// <param name="n"></param>
template<class T>
bool PriorityQueue<T>::Delete(T n)
{
	if (n == NULL)
		return false;
	heap.Delete(n);
	return true;
}

/// <summary>
/// Gets the top node of the priority queue and removes that element from the queue
/// </summary>
/// <returns></returns>
template<class T>
T PriorityQueue<T>::Top()
{
//	//If the heap is empty
//	if (IsEmpty())
//	{
//#ifdef DEBUG
//		cout << "Empty heap" << endl;
//#endif
//		return NULL;
//	}
	
	//Else we can get the heap's first index and call delete
	T n = heap.GetElements()[0];
	heap.Delete();

	return n;
}

/// <summary>
/// Function to print the queue=
/// </summary>
template<class T>
void PriorityQueue<T>::PrintQueue()
{
	heap.PrintHeap();
	cout << endl;
	heap.PrintElements();
}

/// <summary>
/// Checks if the queue is empty
/// </summary>
/// <returns></returns>
template<class T>
bool PriorityQueue<T>::IsEmpty()
{
	//return heap size is 0
	return heap.GetElements().empty();
}
