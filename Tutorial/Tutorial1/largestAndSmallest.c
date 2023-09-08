#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

//Potential memory leak as it is never free-ed
typedef struct ans
{
    int min;
    int max;
} Answer;

#define SIZE 8

//Global variable for lesser parameters in the function
int max = INT_MIN;
int min = INT_MIN;

// int max(int a, int b)
// {
//       return a > b ? a : b;
// }
// int min (int a, int b )
// {
//     return a < b ? a : b;
// }

/// @brief Finds the smallest and largest number in an array
/// @param arr array
/// @param start start
/// @param end end
/// @return 
Answer * largestAndSmallest(int* arr, int start, int end)
{
    int mid;
    Answer * ans = malloc(sizeof(Answer));
    ans->min = 0;
    ans->max = 0;
    if (start == end) //i.e 0, 0 
    {
        //Just one element 
        ans->max = arr[start];
        ans->min = arr[start];
        return ans;
    }
    else if (end - start == 1)
    {
        //There are two elements in the array (just do two checks)
        ans->min = arr[start] < arr[end] ? arr[start] : arr[end];
        ans->max = arr[start] > arr[end] ? arr[start] : arr[end];
        return ans;
    }

    //Else calculate mid and divide and conquer recursively
    mid = (start+end) / 2;

    //Get left side and right side min maxes
    Answer* leftMinMax = largestAndSmallest(arr, start, mid);
    Answer* rightMinMax = largestAndSmallest(arr, mid + 1, end);

    //Then compare both answers to see our final answer
    ans->min = leftMinMax->min < rightMinMax->min ? leftMinMax->min : rightMinMax->min;
    ans->max = leftMinMax->max > rightMinMax->max ? leftMinMax->max : rightMinMax->max;

    return ans;
}
int main()
{
    int array[SIZE] = {14,40,31,28,3,15,17,51};
    Answer * ans = largestAndSmallest(array, 0 , SIZE-1);
    printf("Min:%d Max:%d", ans->min, ans->max);
    return 0;
}