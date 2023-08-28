#include <stdlib.h>
#include <stdio.h>
/*
Insertion Sort
    Best Case: O(n)
    Worst Case: O(n^2)
    Average Case: O(n^2)
*/

#define SIZE 6

/// @brief Carries out insertion sort on a list in ascending order.
/// @param arr dynamic array
/// @param n size
void insertionSortAscending(int * arr, int n)
{
    printf("-Sorting list in ascending order with Insertion Sort-\n");
    int i,j,temp;
    int keyComparisons = 0;
    int cumulativeKeyComparisons = 0;
    print(arr, n);
    for(i = 1; i < n; i++)
    {
        printf("%d\n",arr[i]);
        cumulativeKeyComparisons  = 0;
        for(j = i; j > 0; j--)
        {               
            cumulativeKeyComparisons++;
            keyComparisons++;
            //If condition check to see if the previous value is larger
            if(arr[j] < arr[j-1])
            {
                //Swap between the two
                temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
            else
                break;
  
        }
        print(arr,n);
        printf("[Occurence %d] Key Comparisons: [%d/%d]\n", i, cumulativeKeyComparisons, keyComparisons);
    }
}

/// @brief Carries out insertion sort on a list in descending order.
/// @param arr dynamic array
/// @param n size
void insertionSortDescending(int * arr, int n)
{
    printf("-Sorting list in descending order with Insertion Sort-\n");
    int i,j,temp;
    int keyComparisons = 0;
    for(i = 1; i < n; i++)
    {
        for(j = i; j > 0; j--)
        {
            keyComparisons++;
            //If condition check to see if the previous value is larger
            if(arr[j] > arr[j-1])
            {
                //Swap between the two
                temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
            else
                break;
        }
    }
    printf("Key Comparisons: %d\n", keyComparisons);
}

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

int main()
{
    /*
    int array[6] = {45,29,6,64,12,16};
    //Initial print
    print(array,6);

    insertionSortAscending(array, 6);
    print(array,6);

    insertionSortDescending(array, 6);
    print(array,6);
    */
   
    int array[SIZE] = {45,29,6,64,12,16};
    int array2[SIZE] = {45,29,6,64,12,16};
    int array3[SIZE] = {5,5,5,5,5,5};
    //Initial print
    print(array,SIZE);
  //Initial print
    print(array2,SIZE);

    insertionSortAscending(array, SIZE);
    print(array,SIZE);

    insertionSortDescending(array2, SIZE);
    print(array2,SIZE);

    insertionSortAscending(array2, SIZE);
    print(array2, SIZE);
    
    insertionSortAscending(array3, SIZE);
    print(array3, SIZE);

    return 0;
}