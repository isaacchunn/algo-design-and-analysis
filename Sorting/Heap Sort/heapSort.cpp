#include <stdio.h>
#include <iostream>
#include "heap.h"
#include "date.h"

using namespace std;

int main()
{
    //Create a new heap
    Heap<Date> heap;
    heap.SetHeapType(MAXIMISING);
    //Initialize the heap with some initial elements
    //vector<int> elements = {1,2,3,4,5,6,7};
    vector<Date> elements = {Date(1,7), Date(30,1), Date(22,3), Date(22,12), Date(30,5), Date(21,2), Date(3,11), Date(7,6), Date(22,2), Date(21,11), Date(30,12)};
    heap.SetElements(elements);
    

    //Then we want to construct our heap
    heap.PrintElements();
    //Print initial arrangement before it is "heaped"
    heap.PrintHeap();
    //Construct heap from our initial elements
    heap.ConstructHeap();
    //Print the heap 
    heap.PrintHeap();
    //Print the elements of the array
    heap.PrintElements();

    //Answer vector
    vector<Date> result;
    //Sort the heap and store into result
    heap.HeapSort(result);
    //Print the resulting elements
    heap.PrintElements();
    //Print answer array
    cout << "Sorted Array from Heap: [ ";
    for (auto i : result)
    {
        cout << i << " ";
    }
    cout << "]" << endl;
    return 0;    
}
