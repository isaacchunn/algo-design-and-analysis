#include <stdlib.h>
#include <stdio.h>

/*
Insertion Sort
    Best Case: O(n)
    Worst Case: O(n^2)
    Average Case: O(n^2)
*/

/// @brief Carries out insertion sort on a list in ascending order.
/// @param arr dynamic array
/// @param n size
void insertionSortAscending(int * arr, int n)
{
    printf("-Sorting list in ascending order with Insertion Sort-\n");
    int i,j,temp;
    int keyComparisons = 0;
    for(i = 1; i < n; i++)
    {
        for(j = i; j > 0; j--)
        {               
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
    }
    printf("Key Comparisons: %d\n", keyComparisons);
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

void main()
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
   
    int array[3] = {45,29,6};
    int array2[3] = {45,29,6};
    //Initial print
    print(array,3);
  //Initial print
    print(array2,3);

    insertionSortAscending(array, 3);
    print(array,3);

    insertionSortDescending(array2, 3);
    print(array2,3);
}