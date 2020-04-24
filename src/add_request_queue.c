/**
 * @file add_request_queue.c
 * @brief contains the definition of add_request_queue
 * 
 * @author Maaz Jamal
 * 
 * */
#include "add_request_queue.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief Adds a passenger struct to the passenger queue.
 * 
 * Adds a passenger to passenger queue. This function can be used to make queues for the 
 * requests from passengers from the file or on a floor.
 * @param[in,out] head is a pointer to the head of the queue
 * @param[in] passenger_queue passenger struct containing data of the passenger. 
 * @return passenger* returns pointer to the updated head of queue if operation is fine. head ptr is unchanged if memory cannot be allocated. 
 *  */
struct passenger *add_request_queue(struct passenger *head, struct passenger passenger_queue)
{
    struct passenger *temp = (struct passenger *)malloc(sizeof(struct passenger));
    *temp = passenger_queue;
    struct passenger *cur = head;

    if (temp == NULL)
    {
        fprintf(stderr, "MEMORY ALLOCATION FAILED IN add_request_queue. \n");
        fprintf(stderr, "SKIPPING ADDING PASSENGER TO QUEUE");
        return head;
    }
    if (head == NULL)
    {
        temp->next = NULL;
        head = temp;
        return head;
    }

    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = temp;
    temp->next = NULL;
    return head;
}