#ifndef HEAP_H
#define HEAP_H

// For the array representation of the heap
#include <iostream>
#include <vector>
#include <string>


using namespace std; 

enum HEAP_TYPE
{
    MAXIMISING,
    MINIMISING,
    TOTAL_MODE
};

class Heap
{
    private:
        //Have the heap store a vector of elements
        std::vector<int> elements;
        //Store the type of heap
        HEAP_TYPE heapType;
        //Store last pointer to present the "sorted result"
        int last_ptr;
        //Store then name of this heap for identification
        string heapName;

    public:
        //Constructors, Destructors
        Heap();
        Heap(HEAP_TYPE type, string name);
        ~Heap();
        
        //Accessors and Mutators
        void SetHeapType(HEAP_TYPE type);
        HEAP_TYPE GetHeapType();
        
        //Print the heap
        void PrintElements();
        void PrintHeap();

        //Typical methods of heap
        bool ConstructHeap();
        bool SetElements(vector<int>& other);
        bool Insert(int element);
        void Delete();
        
        bool HeapSort(vector<int>& result);

    private:
        //Private methods that are exclusive to the heap
        void Heapify(int H);
        void FixHeap(int H, int k);
        bool isLeaf(int H);
      
};



#endif