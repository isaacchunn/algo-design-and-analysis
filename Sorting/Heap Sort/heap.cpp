#include "heap.h"

Heap::Heap()
	: heapType(MAXIMISING),
	last_ptr(0),
	heapName("Default")

{

}

Heap::Heap(HEAP_TYPE type, string name)
	: heapType(type),
	last_ptr(0),
	heapName(name)
{
}

Heap::~Heap()
{

}

void Heap::SetHeapType(HEAP_TYPE type)
{
	this->heapType = type;
}

HEAP_TYPE Heap::GetHeapType()
{
	return this->heapType;
}

/// <summary>
/// Prints the elements in the heap
/// </summary>
void Heap::PrintElements()
{
	if (elements.size() == 0)
	{
		cout << "There are no elements in this heap!" << endl;
		return;
	}
	//Else just print out normally
	cout << "Heap Elements: [ ";
	for (int i = 0; i < elements.size(); i++)
	{
		cout << elements[i] << " ";
	}
	cout << "]" << endl;
}

/// <summary>
/// https://stackoverflow.com/questions/36385868/java-how-to-print-heap-stored-as-array-level-by-level
/// </summary>
void Heap::PrintHeap()
{
	string sb = "";
	int max = 0;
	for (int i = 0; i < elements.size(); i++) {
		for (int j = 0; j < pow(2, i) && j + pow(2, i) <= elements.size(); j++) {

			if (j > max) {
				max = j;
			}
		}
	}
	for (int i = 0; i < elements.size(); i++) {
		for (int j = 0; j < pow(2, i) && j + pow(2, i) <= elements.size(); j++) {
           
			for (int k = 0; (k < max / ((int)pow(2, i))); k++) {
				sb.append(" ");
			}
			sb.append(to_string(elements[j + (int)pow(2, i) - 1]));
			sb.append(" ");
		}
		//prevent overprinting by using height as print lines
		if(i < log2(elements.size()) - 1)
			sb.append("\n");
	}
	cout << sb << endl;
}

/// <summary>
/// Constructs the heap based on the elements in the heap
/// </summary>
/// <returns>True if heap was constrtucted, false if elements in heap is 0</returns>
bool Heap::ConstructHeap()
{
	//Check if the size of vector isnt 0, or has already constructed
	if (elements.size() == 0)
	{
		std::cout << "===Construct Heap===\n There are no elements to construct a heap!" << std::endl;
		return false;
	}
    keyComparisons = 0;
	//Else just call heapify
	Heapify(0);
    
    //Print out the key comparisons
    std::cout << "Key Comparisons: " << keyComparisons << endl;
	return true;
}

/// <summary>
/// Sets the elements of our current heap based on another vector
/// </summary>
/// <param name="other">other vector</param>
/// <returns>True by default.</returns>
bool Heap::SetElements(vector<int>& other)
{
	//Clear the current vector first
	elements.clear();
	elements = other;
	return true;
}

/// <summary>
/// Inserts an element into the heap
/// </summary>
/// <param name="element">new element</param>
/// <returns>True by default.</returns>
bool Heap::Insert(int element)
{
	//Insert at the back and then reconstruct heap
	this->elements.push_back(element);
	return true;
}

/// <summary>
/// Deletes the max node of an already constructed heap and reconstructs the heap by FixHeap()
/// </summary>
void Heap::Delete()
{
	//Return if nothing to Delete
	if (this->elements.size() == 0)
	{
		std::cout << "===Delete===\n There are no elements to delete!" << std::endl;
		return;
	}

	//Handle the trivial case later if theres only one
	// 
	//Store the last element of heap into temp variable
	int k = elements.at(elements.size() - 1);
	//Delete the rightmost element at the lowest level
	//Stores the first element so the elements in the heap are also eventually sorted
	elements[elements.size() - 1] = -1;
	//Then fix heap based on first index and k
	FixHeap(0, k);
}

/// <summary>
/// Uses the heap to sort a list of numbers
/// </summary>
/// <param name="result">result vector</param>
/// <returns>True if sorting was done, false if there are no elements to sort</returns>
bool Heap::HeapSort(vector<int>& result)
{
	//This assumes that the array has already been heapified, and the sorting is just deletions and fixing the heap
	//Check if current elements is empty
    int size = (int)this->elements.size();
	if (size == 0)
	{
		std::cout << "===Heap Sort===\n There are no elements to sort!" << std::endl;
		return false;
	} 
	std::cout << "===Heap Sort===" << std::endl;
	PrintElements();
	std::cout << "===After Heap Sort===" << std::endl;
	//Else populate result based on our heap sort
	result.clear();
	//Resize the result vector into n elements size
	result.resize(size);
	//We already have anarray of n elements
	for (int i = size - 1; i >= 0; i--)
	{
		//The first element of the heap is the largest
		int currMax = elements[0];
		//Call the delete function
		Delete();
		//Then assign this curr max to the end of our array
		result[i] = currMax;
	}
	return true;
}

/// <summary>
/// Recursive function that heapifys the heap to ensure partial order of heap is maintained
/// </summary>
/// <param name="H">index of root (usually 0)</param>
void Heap::Heapify(int H)
{
	//This is 0 indexed
	//Check if this is leaf
	if (!isLeaf(H)) //
	{
		//Heapify both left and right subtrees
		Heapify((H * 2) + 1);
		Heapify((H * 2) + 2);
		//Then set k as the element at this index
		PrintHeap();
		int k = elements[H];
		FixHeap(H, k);
	}
}

/// <summary>
/// Fixes the heap by comparing root and descendants
/// </summary>
/// <param name="H">index of root</param>
/// <param name="k">value to compare</param>
void Heap::FixHeap(int H, int k)
{
	//Error handling
	if (H < 0 || H >= elements.size())
		return;

	//Using 0 indexed list
	//Check if parent head is a leaf node
	if (isLeaf(H))
	{
		//Insert k at index H
		elements[H] = k;
	}
	else
	{
		//Accessing of elements is 0 index
		int left = (H * 2) + 1;
		int right = (H * 2) + 2;
        
        int largerSubHeap = 0;
        //Error handle the right as current node might not have a right child
        if(right >= this->elements.size())
        {
            keyComparisons++;
            //There isnt a need to compare, as it is automatically the largest of the children
            largerSubHeap = left;
        }
        else
        {
            //Then there are two children, and we must compare them both, adding 1 comparison
            largerSubHeap = elements[left] > elements[right] ? left : right; // 1 comparison
            keyComparisons++;
        }
        
        keyComparisons++;
		//Check k higher than larger element
		if (k >= elements[largerSubHeap]) // another comparison so 2 comparisons per fix heap
		{
			//Safely insert as k is larger than both left and rightchild of current root
			elements[H] = k;
		}
		else
		{
			//We msut insert root of the larger sub heap in root of H
			elements[H] = elements[largerSubHeap];
			FixHeap(largerSubHeap, k);
		}
	}
}

/// <summary>
/// Returns true if the nodes is a leaf node
/// </summary>
/// <param name="H">0-indexed index of the node</param>
/// <returns>None</returns>
bool Heap::isLeaf(int H)
{
	return (H * 2) + 1 >= elements.size();
}
