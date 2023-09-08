#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

/*
Each of n elements in an array may have one of the key values red, white, or blue. Give an efficient
algorithm for rearranging the elements so that all the reds come before all the whites, and all the whites
come before all the blues. (It may happen that there are no elements of one or two of the colours.)
The only operations permitted on the elements are examination of a key to find out what colour it is,
and a swap, or interchange, of two elements (specified by their indices).
*/

//Just setup an enum of values
enum COLORS
{
  RED,
  WHITE,
  BLUE
};

void swap (COLORS *x, COLORS *y)
{
    COLORS t = *x;
    *x = *y;
    *y = t;
}


void printColors(vector<COLORS> colors)
{
    cout << "[";
    for (auto color : colors)
    {  
        if(color == RED)
            cout << " Red ";
        else if(color == WHITE)
            cout << " White ";
        else if (color == BLUE)
            cout << " Blue ";
    }
    cout << "]" << endl;
}

void printColorsWithPointers(vector<COLORS> colors, int r, int c, int b)
{
    cout << "[";
    for (auto color : colors)
    {  
        if(color == RED)
            cout << " Red ";
        else if(color == WHITE)
            cout << " White ";
        else if (color == BLUE)
            cout << " Blue ";
    }
    cout << "]" << endl;
    //Very discrete method to just print out stuff
    for(int i = 0; i < colors.size(); i++)
    {
        cout << "   ";
        if(i == r || i == c || i == b)
            cout <<"^";
        cout << "   ";
    }
    cout << endl;
    for(int i = 0; i < colors.size(); i++)
    {
        cout << "   ";
        if(i == r)
            cout <<"R";
        else if (i == c)
            cout << "C";
        else if (i == b)
            cout << "B";
        cout << "   ";
    }
    cout << endl;
}

/// @brief Sorts an vector of "colors" where the red comes first, followed by whites, then blue
/// @param colors colors vector
void sortByColor(vector<COLORS>& colors)
{
    //Declare our pointers
    int left = 0;
    int right = colors.size() - 1;
    int red = 0;
    int blue = colors.size() - 1;

    cout <<"Initial Array before sorting" << endl;
    printColorsWithPointers(colors,red,left,blue);
    //While left < right
    while(left <= blue)
    {
        //Check if current is red, else we swap current with red ptr
        if(colors[left] == RED)
        {
            //Swap with red ptr
            swap(colors[left], colors[red]);
            //Increment both pointers
            //Analysis: We can increment left pointer, as any earlier element that we pass by is "guaranteed to be white/red"
            left++;
            red++;
        }
        else if(colors[left] == WHITE)
        {
            //We ignore whites as they are "assumed to be in correct place"
            left++;
        }
        else if (colors[left] == BLUE)//implies its blue
        {
            //Swap with our blue ptr
            swap(colors[left], colors[blue]);
            blue--;
        }
        printColorsWithPointers(colors,red,left,blue);
    }

}


int main()
{
    //Create a color vector for arbitrary input
    vector<COLORS> colors = {WHITE, WHITE, RED, BLUE, WHITE, BLUE, RED, WHITE, WHITE, RED, BLUE, WHITE, BLUE, RED, WHITE};
    printColors(colors);
    sortByColor(colors);
    printColors(colors);
    return 0;   
}