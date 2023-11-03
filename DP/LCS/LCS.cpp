#include "LCS.h"

string LCS::ConstructLCS(string text1, string text2, char** values)
{
    //Let text1 exist on the columns, and then text2 exist on the rows
    int col = text1.length();
    int row = text2.length();

    //Initialize a stack
    stack<char> charStack;

    //Loop through while i and j is not empty, we start from the last
    while (col != 0 && row != 0)
    {
#ifdef DEBUG
        cout << row << " " << col << endl;
#endif
        if (values[row][col] == '\\')
        {
            //Push this into the stack
            charStack.push(text2[row-1]);
            row--;
            col--;
        }
        else if (values[row][col] == '|')
        {
            //Reduce the row
            row--;
        }
        else
        {
            //Reduce the column
            col--;
        }
    }
    string result;
    while (!charStack.empty())
    {
        result += charStack.top();
        charStack.pop();
    }
    return result;
}

void LCS::PrintArray(string text1, string text2, int** values)
{
    //Let text1 exist on the columns, and then text2 exist on the rows
    int n = text1.length();
    int m = text2.length();
    //Print header first
    cout << "\t\t";
    for (int i = 0; i <= n; i++)
    {
        cout << text1[i] << "\t";
    }
    cout << endl;
    for (int row = 0; row <= m; row++)
    {
        if (row != 0)
            cout << text2[row - 1] << "\t";
        else
            cout << "\t";
        for (int col = 0; col <= n; col++)
        {
            cout << values[row][col] << "\t";
        }
        cout << endl;
    }
}

void LCS::PrintArray(string text1, string text2, char** values)
{
    //Let text1 exist on the columns, and then text2 exist on the rows
    int n = text1.length();
    int m = text2.length();
    //Print header first
    cout << "\t\t";
    for (int i = 0; i <= n; i++)
    {
        cout << text1[i] << "\t";
    }
    cout << endl;
    for (int row = 0; row <= m; row++)
    {
        if (row != 0)
            cout << text2[row - 1] << "\t";
        else
            cout << "\t";
        for (int col = 0; col <= n; col++)
        {
            cout << values[row][col] << "\t";
        }
        cout << endl;
    }
}

string LCS::CalculateLCS(string text1, string text2)
{
    //Let text1 exist on the columns, and then text2 exist on the rows
    int cols = text1.length();
    int rows = text2.length();
    //Allocate an array on the heap
    //For ACGGA, it would generate 6 rows
    /*
    |
    |
    |
    |
    |
    |
    */
    int** values = new int* [rows + 1];
    char** hintArray = new char* [rows + 1];
    //For each row, we instantiate up to cols which is 5
    for (int i = 0; i <= rows; i++)
    {
        values[i] = new int[cols + 1];
        hintArray[i] = new char[cols + 1];
    }

    //Do our initialization
    for (int i = 0; i <= cols; i++)
    {
        //Set the first row to be 0 and the hint to be -
        values[0][i] = 0;
        hintArray[0][i] = '-';
    }
    for (int j = 1; j <= rows; j++)
    {
        //Set first column starting from 1st row to be | and 0
        values[j][0] = 0;
        hintArray[j][0] = '|';
    }

    //Compute LCS, we should update from left to right
    for (int row = 1; row <= rows; row++)
    {
        for (int col = 1; col <= cols; col++)
        {
#ifdef DEBUG
            PrintArray(text1, text2, values);
            PrintArray(text1, text2, hintArray);
            cout << row << " " << col << " -> " << text1[col - 1] << " " << text2[row - 1] << endl;
#endif
            //This means xi and yj are the same and the optimal character for this sub solution
            if (text1[col - 1] == text2[row - 1])
            {
                //values is the diagonal left of this sequence
                //+1 to indicate length
                values[row][col] = values[row - 1][col - 1] + 1;
                hintArray[row][col] = '\\';
            }
            //Compare both top and bottom
            else if (values[row - 1][col] >= values[row][col - 1])
            {
                //This means the above row was bigger
                values[row][col] = values[row - 1][col];
                hintArray[row][col] = '|';
            }
            else
            {
                //Left was bigger
                values[row][col] = values[row][col - 1];
                hintArray[row][col] = '-';
            }
        }
    }
#ifdef DEBUG
    cout << "Values" << endl;
    PrintArray(text1,text2,values);
    cout << "Hint Array" << endl;
    PrintArray(text1, text2, hintArray);
#endif

    string subsequence = ConstructLCS(text1, text2, hintArray);

    //Deallocate our array
    for (int i = 0; i <= rows; i++)
    {
        delete[] values[i];
        delete[] hintArray[i];
    }
    delete[] values;
    delete[] hintArray;

    return subsequence;
   
}
