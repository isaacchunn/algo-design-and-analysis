//https://leetcode.com/problems/contains-duplicate/description/
//Copied from my previous solution on leetcode

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/*
The other way if there is no hash map present, is to use a sorting algorithm such as merge sort (nlogn), and then iterative check one key to it's next adjacent key to see duplicates
*/

bool containsDuplicate(vector<int>& nums)
{
    unordered_map<int, int> map;
    int size = nums.size();
    for(int i = 0; i < size; i++)
    {
        //If there already exists an element in the map
        if(map.count(nums[i]) != 0)
            return true;
        //Else store an element
        map[nums[i]]+=1;
    }
    return false;
}

//The complexity of lookup for std::unordered_map is O(1) (constant) in the average case, and O(N) (linear) in the worst case.
int main()
{
    vector<int> nums = {1,1,1,3,3,4,3,2,4,2};
    bool contains = containsDuplicate(nums);
    if(contains)
        cout << "The list has duplicates." << endl;
    else
        cout << "The list has no duplicates." << endl;
        
    return 0;
}