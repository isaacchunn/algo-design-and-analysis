#include <stdlib.h>
#include <stdio.h>

#define SIZE 10

/* NOTES:
- Similar to merge sort, a single element is treated as a small/trivial problem
- Follows divide and conquer hence a recursive algorithm
- Both sides of the pivot do not need to be sorted
- it just needs to satisfy (all left elements of pivot) < pivot < (all right elements of pivot)

//Time Complexity Analysis: (TODO: Try with Master's Theorem)
// Best case (nlogn)
// Average case (nlogn) probabilities
// Worst Case (n^2)

*/

void quickSort(int * arr, int low, int high, int ascending);
int partitionAscending(int * arr, int low, int high);
int partitionDescending(int * arr, int low, int high);
void print(int*,int);
void printInRange(int*, int, int);
void swap(int *, int,int);

//Global variables to print out key comparisons
int totalKeyComparisons = 0;
int cumulativeKeyComparisons = 0;
int occurence = 1;

int main()
{
    int array[SIZE] = {77,15,96,89,42,80,35,4,93,6};
    print(array,SIZE);
    quickSort(array, 0, SIZE-1,1);
    printf("[Ascending Quick Sort] Key Comparisons: %d\n", totalKeyComparisons); // should be 7 from lecture notes for last repetition
    print(array, SIZE);

    //Reset total key comparisons and occurence
    totalKeyComparisons = 0;
    occurence = 1;
    quickSort(array,0,SIZE-1,0);
    printf("[Descending Quick Sort] Key Comparisons: %d\n", totalKeyComparisons); // TODO - trace out on paper
    print(array, SIZE);

}

/// @brief Sample function to print out all elements in an array
/// @param arr array
/// @param n size of array
void print(int * arr, int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        if(i == n - 1)
            printf("%d", arr[i]);
        else
            printf("%d,", arr[i]);
    }
    printf("\n");
}

/// @brief Function that prints in range of start and end of an array to visualize the divide and conquer
/// @param arr arr
/// @param start start index 
/// @param end end index
void printInRange(int * arr, int start, int end)
{
    int i;
    printf("[");
    for(i = start; i <= end; i++)
    {
        if(i == end)
            printf("%d", arr[i]);
        else
            printf("%d,", arr[i]);
    }
    printf("]\n");
}

void printDetailedList(int * arr, int n, int pivotPos)
{
    int i;
    int spaces = 0;
    for(i = 0; i < n; i++)
    {
        if(arr[i] < 10)
            printf("0%d", arr[i]);
        else
            printf("%d", arr[i]);
        if(i != n - 1)
        {
            printf(",", arr[i]);
        }
    }
    printf("\n");

    //Print the pivot position using ^
    for(int i = 0; i < pivotPos * 3; i++)
    {
        printf(" ");
    }
    printf("^\n");
}

void quickSort(int * arr, int start, int end, int ascending)
{
    int pivot_pos;
    if(start < end)
    {
        //REset cumulative key comparisons
        cumulativeKeyComparisons = 0;
        //If start < end meaning non trivial solution, at least 2
        if(ascending)
            pivot_pos = partitionAscending(arr, start, end);
        else
            pivot_pos = partitionDescending(arr,start,end);
        
         printf("[Occurence: %d] Key Comparisons: [%d/%d] \n", occurence++, cumulativeKeyComparisons, totalKeyComparisons);
          
        //-1 as we assume the pivot pos is already in "sorted" position
        quickSort(arr,start, pivot_pos - 1, ascending);
        quickSort(arr,pivot_pos+1, end, ascending);
    }
}

/// @brief Partitions the array and arranges the array such that it satisfies left < pivot < right
/// @param low start index
/// @param high end index
int partitionAscending(int* arr, int low, int high)
{
    int i, last_small, pivot;
    //Generalize and use middle as the pivot always
    int mid = (low + high) / 2;

    //Swap the low and mid as a beauty feature, does not affect our time complexity
    swap(arr,low,mid);
    //Set the pivot to be the low element, as our "middle" element was swapped to the front
    pivot = arr[low];
    //Set last_small to be the first element
    last_small = low;

    //Run a for loop to achieve our left and right
    for(i = low + 1; i <= high; i++)
    {            
        totalKeyComparisons++;       
        cumulativeKeyComparisons++;
        if(arr[i] < pivot)
        {
            swap(arr, ++last_small, i); // colours it to be "yellow"
        }
    }
    //Finally, swap low to our final last_small, which brings it back to the middle
    swap(arr, low, last_small);

    //Print the array 
    printDetailedList(arr,SIZE, last_small);
    return last_small;
}

/// @brief Partitions the array and arranges the array such that it satisfies left > pivot > right
/// @param low start index
/// @param high end index
int partitionDescending(int* arr, int low, int high)
{
    int i, last_big, pivot;
    //Generalize and use middle as the pivot always
    int mid = (low + high) / 2;

    //Swap the low and mid as a beauty feature, does not affect our time complexity
    swap(arr,low,mid);
    //Set the pivot to be the low element, as our "middle" element was swapped to the front
    pivot = arr[low];
    //Set last_big to be the first element
    last_big = low;

    //Run a for loop to achieve our left and right
    for(i = low + 1; i <= high; i++)
    {        
        totalKeyComparisons++;       
        cumulativeKeyComparisons++;
        if(arr[i] > pivot)
        {
            swap(arr, ++last_big, i); // colours it to be "yellow"
        }
    }
    //Finally, swap low to our final last_big, which brings it back to the middle
    swap(arr, low, last_big);
    //Print the array 
    printDetailedList(arr,SIZE, last_big);
    return last_big;
}

/// @brief Swaps the elements in the given array between the two indexes (assumes correct input)
/// @param arr array
/// @param index1 index1
/// @param index2 index2
void swap(int * arr, int index1, int index2)
{
    //DO not need to swap between the same indexes
    if(index1 == index2)
        return;
    
    //Carry out our swaps
    int temp = arr[index1];
    arr[index1] =  arr[index2];
    arr[index2] = temp;
}
