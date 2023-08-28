#include <stdlib.h>
#include <stdio.h>

#define SIZE 8

/* NOTES:
- A single element is treated as a small/trivial problem
- Follows divide and conquer hence a recursive algorithm
- Merge is probably the most confusing part with for loops as compared to creating another list
- Space efficient but slower time on this iterative approach

//Time Complexity Analysis: (TODO: Try with Master's Theorem)
// Best case (n/2)
// Average case (?)
// Worst Case (n-1)

- Sample List
-[9,3,7,5,6,4,8,2]
  ^     ^       ^
start  mid     end
*/

void mergeSort(int*,int,int, int);
void mergeAscending(int*, int,int,int);
void mergeDescending(int*, int,int,int);
void print(int*,int);
void printInRange(int*, int, int);

//Global variable to print out key comparisons
int totalKeyComparisons = 0;
int cumulativeKeyComparisons = 0;
int occurence = 1;

int main (void)
{
    int array[SIZE] = {23,23,23,23,23,23,23,23};
    print(array, SIZE);
    totalKeyComparisons = 0;
    mergeSort(array,0,SIZE-1,1);
    printf("[Ascending Merge Sort] Key Comparisons: %d\n", totalKeyComparisons); // should be 7 from lecture notes for last repetition
    print(array, SIZE);

    //Reset total key comparisons and occurence
    totalKeyComparisons = 0;
    occurence = 1;
    mergeSort(array,0,SIZE-1,0);
    printf("[Descending Merge Sort] Key Comparisons: %d\n", totalKeyComparisons); // TODO - trace out on paper
    print(array, SIZE);
    return 0;
}

/// @brief Sorts an array using merge sort in ascending order
/// @param arr array
/// @param start start
/// @param end end
void mergeSort(int * arr, int start, int end, int ascending)
{
    int mid;
    //Check if start < end
    //If start == end (single element (one index))
    //If start < end (at least 2 elements, considered a "large problem")
    if(start < end)
    {
        //Then we calculate mid
        mid = (start + end) / 2;
        //Split the list into two halfs and call recursively
        mergeSort(arr,start,mid, ascending);
        mergeSort(arr,mid + 1, end, ascending);

        //Reset cumulative key comparisons
        cumulativeKeyComparisons =0;

        //Merge the list together
        if(ascending)
            mergeAscending(arr,start,mid,end);
        else
            mergeDescending(arr, start, mid, end);
        printf("[Occurence: %d] Key Comparisons: [%d/%d] \n", occurence++, cumulativeKeyComparisons, totalKeyComparisons);
    }
}

/// @brief Carries out the merge operation of "two parts of an array" in ascending order
/// @param arr arr
/// @param start start index
/// @param mid mid index
/// @param end end index
void mergeAscending(int * arr, int start, int mid, int end)
{
    int i, temp;
    //Settle indexes from each part of the list
    int a = start;
    //Mid + 1 is first element of our list
    int b = mid + 1;
    
    //Print out what is being merged
    printInRange(arr,start,mid);
    printInRange(arr, mid+1,end);

    //Base case is settled outside
    //Do a while loop to check which one finishes first, a or b.
    while(a <=mid && b <=end)
    {
        //Increment our key comparisons as there is a guaranteed check anyway
        cumulativeKeyComparisons++;
        totalKeyComparisons++;
        
        //Case 1: arr[a] < arr[b] - do nothing as it is in correct slot, so just increment a
        if(arr[a] < arr[b])
        {
            a++;
        }
        //Case 2: arr[a] > arr[b] - have to right shift by one and store temp
        else if (arr[a] > arr[b])
        {
            //Store index at 2nd list as our temp
            temp = arr[b++];
            //Go backwards from mid to a to right shift
            for(i = ++mid; i > a; i--)
            {
                arr[i] = arr[i-1];
            }
            //Then assign the temp at a
            arr[a++] = temp;
        }
        //Case 3: arr[a] == arr[b], slot[a] in correct position, so move slot[b] beside slot[a]
        else if (arr[a] == arr[b])
        {
            //Since we are incrementing mid each time
            //Assuming a list that was sorted from the front, at the last 2 repetitions, our mid and end will be as follows
            //[x,x,x,x,x,x, 9 , 9]
            //              ^   ^
            //             mid  end
            //Which means we can break as they are already assumed to be sorted and the largest, which in theory saves the time taken to compute everything else in the if statement
            if(a == mid && b == end)
                break;
            
            temp = arr[b++];
            //Increment a to make space
            a++;
            //Go backwards from mid to a to right shift
            for(i = ++mid; i > a; i--)
            {
                arr[i] = arr[i-1];
            }
             //Then assign the temp at a
            arr[a++] = temp;         
        }
    }
}

/// @brief Carries out the merge operation of "two parts of an array" in descending order
/// @param arr arr
/// @param start start index
/// @param mid mid index
/// @param end end index
void mergeDescending(int *arr, int start, int mid, int end)
{
    int i, temp;
    //Settle indexes from each part of the list
    int a = start;
    //Mid + 1 is first element of our list
    int b = mid + 1;
    
    //Print out what is being merged
    printInRange(arr,start,mid);
    printInRange(arr, mid+1,end);

    //Base case is settled outside
    //Do a while loop to check which one finishes first, a or b.
    while(a <=mid && b <=end)
    {        
        //Increment our key comparisons as there is a guaranteed check anyway
        cumulativeKeyComparisons++;
        totalKeyComparisons++;

        //Case 1: arr[a] > arr[b] - do nothing as it is in correct slot, so just increment a
        if(arr[a] > arr[b])
        {
            a++;
        }
        //Case 2: arr[a] < arr[b] - have to right shift by one and store temp
        else if (arr[a] < arr[b])
        {
            //Store index at 2nd list as our temp
            temp = arr[b++];
            //Go backwards from mid to a to right shift
            for(i = ++mid; i > a; i--)
            {
                arr[i] = arr[i-1];
            }
            //Then assign the temp at a
            arr[a++] = temp;
        }
        //Case 3: arr[a] == arr[b], slot[a] in correct position, so move slot[b] beside slot[a]
        else if (arr[a] == arr[b])
        {
            //Since we are incrementing mid each time
            //Assuming a list that was sorted from the front, at the last 2 repetitions, our mid and end will be as follows
            //[x,x,x,x,x,x, 9 , 9]
            //              ^   ^
            //             mid  end
            //Which means we can break as they are already assumed to be sorted and the largest, which in theory saves the time taken to compute everything else in the if statement
            if(a == mid && b == end)
                break;
            
            temp = arr[b++];
            //Increment a to make space
            a++;
            //Go backwards from mid to a to right shift
            for(i = ++mid; i > a; i--)
            {
                arr[i] = arr[i-1];
            }
             //Then assign the temp at a
            arr[a++] = temp;         
        }
    }
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
