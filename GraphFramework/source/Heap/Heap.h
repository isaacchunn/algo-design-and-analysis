#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <vector>
#include <string>
#include "../Graph/Node.h"
#include <type_traits>
using namespace std; 

enum TYPE
{
    MAXIMISING,
    MINIMISING,
    TOTAL_MODE
};

/// <summary>
/// Only works with pointer variables now that is sufficient for the graph implementations
/// </summary>
/// <typeparam name="T"></typeparam>

template<class T>
class Heap
{
    private:
        //Have the heap store a vector of elements
        std::vector<T> elements;
        //Store the type of heap
        TYPE heapType;
        //Store last pointer to present the "sorted result"
        int last_ptr;
        //Store the name of this heap for identification
        string heapName;
        //Misc
        int keyComparisons;

    public:
        //Constructors, Destructors
        Heap();
        Heap(TYPE type, string name);
        ~Heap();
        
        //Accessors and Mutators
        void SetHeapType(TYPE type);
        void SetName(string name);
        TYPE GetHeapType();
        string GetName();
        vector<T> GetElements();
        
        //Print the heap
        void PrintElements();
        void PrintHeap();
        void PrintHeapArray();

        //Typical methods of heap
        bool ConstructHeap();
        bool SetElements(vector<T>& other);
        bool Insert(T element);
        void Delete();
        void Delete(T element);
        //*
        bool HeapSort(vector<T>& result);

    private:
        //Private methods that are exclusive to the heap
        void Heapify(int H);
        template <typename U = T>
        typename std::enable_if<std::is_pointer<U>::value>::type FixHeap(int H, T k, int maxIndex);  
        template <typename U = T>
        typename std::enable_if<!std::is_pointer<U>::value>::type FixHeap(int H, T k, int maxIndex);
        bool isLeaf(int H);
};
//template file inclusion
#include "Heap.tpp"
#endif
