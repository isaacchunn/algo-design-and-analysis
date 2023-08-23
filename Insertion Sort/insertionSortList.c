#include <stdlib.h>
#include <stdio.h>
//Question Reference: https://leetcode.com/problems/insertion-sort-list/description/

//Definition for singly-linked list.
struct ListNode {
      int val;
      struct ListNode *next;
};

struct ListNode* insertionSortList(struct ListNode* head){
       //Need our first initial loop that goes all the way to the back of the list
        //Handle base case
        if(head == NULL)
            return NULL;
        //Start from first index as if 2nd element is NULL, list already sorted
        struct ListNode * curr = head->next;
        //Store a previous as the sorted side is on the left of linked list.
        struct ListNode * prev = head;
        //Instead of swapping nodes, can swap int
        int temp = 0;
        while(curr != NULL)
        {
            //Check if the previous element is larger, if already smaller, we are done here
            if(prev->val > curr->val)
            {
                //Second while loop to move it until we reach the smallest value
                struct ListNode * iterator = head;
                //While we have not reached the current 
                while(iterator != curr)
                {
                    //Iterate forward and check, if earlier occurences are larger than current,
                    if(iterator->val > curr->val)
                    {
                        //Swap the values between them
                        temp = iterator->val;
                        iterator->val = curr->val;
                        curr->val = temp;
                    }
                    iterator = iterator->next;
                }
            }
            //Update previous
            prev = curr;
            curr = curr->next;
        }
        return head;
}

int main()
{
    return 0;
}