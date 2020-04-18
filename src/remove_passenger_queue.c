#include "remove_passenger_queue.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

/** This function removes a passenger from a queue at given index and frees the memory
 * 
 * The function remomves and frees memory location at given index. if the given index is at the head
 * the head is removed and new head is returned. If index is greater then length of queue the function 
 * causes program to exit.
 *  
 * @param[in] index int value that points to index of queue to return. indices start at 0.
 * @param[in, out] head pointer to head of the queue.
 * 
 * @return return the value of the head. head will point to new value head if index is 0.
 * */
struct passenger* remove_passenger_queue(int index, struct passenger* head){
    
    
    assert( head != NULL); //?< Precondition that head not be Null
    assert( index > -1); //?< Precondition that index not be negative


    struct passenger* temp = NULL;
    struct passenger* cur = head; //?< stores the current position of pointer to be used in while loop 
    if (index == 0){
        temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    else{
        int i = 0;

        /** Iterate through the queue until we are one node behind the 
         * node we want to delete. Or next node is null. Set next of previous 
         * node to next node and store the node to delete in temp. use free to 
         * delete current node. 
         * */ 
        
        while (i < index -1 && cur->next != NULL){
            cur = cur->next;
            i++;
        }
        
        /** This is precondition checks if index was greater than queue length and 
          this cannot be done at start as we do not know total length of queue at begining. 
          the check is cur->nect != NULL as we stop before element to be removed. if cur->next = NULL
          it means the index is greater than length as we are at end list and should have stopped 
          at index-1.*/
        assert( cur->next != NULL);

        temp = cur->next;
        cur->next = temp->next;
        free(temp);
    }
    return head;
}