//#include "PriorityQueueArray.h"

#include <string>
#include <iostream>
#include <type_traits>

using namespace std;

template <class T>
PriorityQueueArray<T>::PriorityQueueArray()
	: type(HEAP_TYPE::MINIMISING), size(0)
{
}

template <class T>
PriorityQueueArray<T>::PriorityQueueArray(HEAP_TYPE type)
	: type(type) ,size(0)
{
}

/// <summary>
/// Inserts a node into the back of a vector.
/// </summary>
/// <param name="n">element</param>
template <class T>
bool PriorityQueueArray<T>::Insert(T n)
{
	//Check if priority queue is a pointer and if its null return false
	if(std::is_pointer<T>::value && n == NULL)
		return false;

	elements.push_back(n);
	size++;
	return true;
}

/// <summary>
/// Gets the smallest node in the array in O(n) time (pointer version)
/// </summary>
/// <returns>smallest node, null if queue empty</returns>
template <class T>
template <typename U>
typename std::enable_if<!std::is_pointer<U>::value, T>::type PriorityQueueArray<T>::GetSmallest()
{
	//Trivial case check
	if(size == 0)
		return NULL;
	
	//Searches through the list and gets the smallest element (should be overloaded if necessary)
	//Only takes the "first smallest even if there may be multiple processes of the same weight."
	T min = elements[0];
	int index = 0;
	for (int i = 1; i < size; i++)
	{
		if (elements[i] < min)
		{
			//Set min to be this distance and update indices
			min = elements[i];
			index = i;
		}
	}
	elements[index] = elements[size - 1];
	elements.pop_back();
	size--;
	return min;
}

/// <summary>
/// Gets the smallest node in the array in O(n) time (not pointer version)
/// </summary>
/// <returns>smallest node, null if queue empty</returns>
template <class T>
template <typename U>
typename std::enable_if<std::is_pointer<U>::value, T>::type PriorityQueueArray<T>::GetSmallest()
{
	//Trivial case check
	if(size == 0)
		return NULL;
	
	//Searches through the list and gets the smallest element (should be overloaded if necessary)
	//Only takes the "first smallest even if there may be multiple processes of the same weight."
	T min = elements[0];
	int index = 0;
	for (int i = 1; i < size; i++)
	{
		T ele = elements[i];
		if (*ele < *min)
		{
			//Set min to be this distance and update indices
			min = ele;
			index = i;
		}
	}
	elements[index] = elements[size - 1];
	elements.pop_back();
	size--;
	return min;
}

/// <summary>
/// Checks if the queue is empty
/// </summary>
/// <returns>true if empty, false if not.</returns>
template <class T>
bool PriorityQueueArray<T>::IsEmpty()
{
	return size == 0;
}

/// <summary>
/// Prints out the array in simple fashion, does nothing than to check if something is inside.
/// </summary>
template <class T>
void PriorityQueueArray<T>::PrintQueue()
{
	for (auto n : elements)
		cout << n << " ";
	cout << endl;
}

/// <summary>
/// Loops through the queue to find if said node exists
/// </summary>
/// <param name="n"></param>
/// <returns></returns>
template <class T>
bool PriorityQueueArray<T>::Delete(T n)
{
	//Cjheck if its a pointer and n is null
	if(std::is_pointer<T>::value && n == NULL)
		return false;

	for (int i = 0; i < size; i++)
	{
		if (elements[i] == n)
		{
			//Update elements[i] to be last element, then pop back
			elements[i] = elements[size-1];
			elements.pop_back();
			size--;
			break;
		}
	}
	return true;
}
