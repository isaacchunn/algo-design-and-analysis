#include <stdio.h>
#include <stdlib.h>

struct _listNode{
    int item;
    struct _listNode* next;
};
typedef struct _listNode ListNode;

void printList(ListNode *head);
void deleteList(ListNode **ptrHead);

void reverseKNodes(ListNode** head, int K);

int main()
{
    ListNode *head = NULL, *temp;
    int i = 0;
    int K = 0;

    scanf("%d",&K);

    while (scanf("%d", &i)){
        if (head == NULL){
        head = (ListNode*) malloc(sizeof(ListNode));
        temp = head;
     }
     else{
        temp->next = (ListNode*) malloc(sizeof(ListNode));
        temp = temp->next;
    }
    temp->item = i;
    }
    temp->next = NULL;

    reverseKNodes(&head, K);
    printList(head);
    deleteList(&head);
    return 0;
}

void printList(ListNode *head){
    while(head !=NULL){
        printf("%d ",head->item);
        head = head->next;
    }
    printf("\n");
}
void deleteList(ListNode **ptrHead){
    ListNode *cur = *ptrHead;
    ListNode *temp;
    while (cur!= NULL) {
        temp=cur->next;
        free(cur);
        cur=temp;
    }
    *ptrHead=NULL;
}

/// @brief Reverses each segment of k nodes in a linked list
/// @param head head of linked list
/// @param K number of nodes per segment for reversal
void reverseKNodes(ListNode** head, int K){
    //Write your code here
    int count = 0;
    int i;
    //Store our current pointer
    ListNode * curr = *head;
    //This is used to store our "traversal" node 
    ListNode * temp = *head;
    //Temporary storage of next and previousd
    ListNode * next = NULL;
    ListNode * prev = NULL;
    //Temporary storage of first and last nodees
    ListNode * lastNode = *head;
    ListNode * firstNode = NULL;
    //Temporary flag to update the head once
    int updatedHead = 0;

    //Handle the trivial cases where either head is 0 or K is < 0
    if(*head == NULL || K < 0)
        return;
    
    while(1)
    {
        //If temp is null, means we have no remaining elements left to segment (a trivial case)
        if(temp == NULL)
            return;

        //Else we do a pass of up to K first to check if there still exists >= k elements
        //Include first index as we count the 1st element as part of the K
        //Assuming ur list is 1,2,3
        //Before first repetition: temp = 1 (temp must be 1 as on line 81, temp is head, and head cannot be null, which is why we can start at 1)
        for(i = 1; i < K; i++)
        {
            //Go to the next element of k
            temp = temp->next;
            //If we encounter a null, we have less than k nodes so we automatically return out of function
            if(temp == NULL)
            {
                //If last node is head, that means the list has initially < k elements
                //But if its not head, that means we have reversed other segments, and now we just link it back up to where the current pointer is at since we are not reversing
                if(lastNode != *head)
                    lastNode->next = curr;
                return;
            }
        }

        //If in this repetition, there are still at >=k more elements left in the list to reverse, then we store our firstNode as our current
        //Assuming the list is 1,2,3,4,5,6
        //First repetition: we store firstNode as curr (which is 1)
        //Second repetition: we store firstNode as curr (which is 4) -> you will see why later
        firstNode = curr;

        //After our initial checks, we can then reverse K nodes using typical pointers strategy in an iterative fashion
        for(i = 0; i < K; i++)
        {
            //Store curr's next into next
            next = curr->next;
            //Set curr next to be our prev, in the first element, this would mean our first element next is NULL!
            curr->next = prev;
            //Set the previous node to now be curr
            prev = curr;
            //And our curr node to be the next
            curr = next;
        }

        //After k times, curr is the "firstNode" of the next segment of k, if its not NULL
        //So assuming the list is 1,2,3,4,5,6
        //On the first repetition after this reversal
        //the list now looks like this NULL <- 1 <- 2 <-3  |  4 -> 5 -> 6, where the | link is broken due to our reversal, but the curr is still at the next node before the breaking of link
        //                                     ^        ^     ^
        //                                   head      prev  curr
        temp = curr;

        //For the first repetition after reversal, there is no other nodes to link for now, so just update head as current is infront
        if(updatedHead == 0)
        {
            //If we have not updated the head before then we basically make it like this now if we set head to be prev
            //              firstNode
            //                 v
            //       3 -> 2 -> 1 -> NULL  |  4 -> 5 -> 6
            //       ^
            // head and previous

            *head = prev;
            //Which is why, we set previous back to NULL as we dont want the next iteration to link back to our 3, which gives us a final list of: (after the first repetition)
            //         firstNode
            //            v
            //  3 -> 2 -> 1 -> NULL  |  4 -> 5 -> 6
            //  ^
            // head 
            prev = NULL;
            updatedHead = 1;
        }
        else
        {
            //Else, we have updated the head before, so there are definitely > 1 segments
            //Given that this if statement has occured, then it must mean that there are > 1 segments due to the nature of our code
            //Assuming 2nd repetition where list is 1,2,3,4,5,6 and the 4,5,6 part has also been reversed, the list will look like
            //                              firstNode
            //                                 v
            //  3 -> 2 -> 1 -> NULL  | NULL <- 4 <- 5 <- 6 | NULL (note that curr is allowed to go out of bounds for good reason)
            //  ^         ^                              ^     ^
            // head    lastNode                        prev  curr
            //Hence, it becomes obvious that if we link lastNode -> prev, we get the following result

            //                          firstNode
            //                             v
            //  3 -> 2 -> 1 ->   6 -> 5 -> 4 -> NULL  | NULL
            //  ^         ^      ^                ^       ^
            // head    lastNode prev                       curr

            lastNode->next = prev;
            //update last node to be first node, and push our last node forward
            lastNode = firstNode;       
            //And of course, we set prev back to NULL to prevent any loops     
            prev = NULL;
        }  
    }
}

    //All in all, as a brief summary, what we do is we ensure to store the reference to the first node, e.g 1,2,3 - the firstNode is 1.
    //After the reversal, the expected result is 3,2,1 if k is 3. However, on the first reversals, we must update the head to be 3, which is why we have the if statement to detect that case.
    //Also, since we initially set our firstNode's reference to point at 1, we can see that all we have to do is just use firstNode->next = the remaining parts of the list to join it back together.
    //Hence, the firstNode stores the "first element of" a segment k such that after the reversal, it is easy to use this node to link with other elements. This done in a slow and fast pointer way.
    //This method seems to be worse, as a recursive method could obviously return a better and cleaner result, but due to assignment limitations, all of it was done in one function. 
