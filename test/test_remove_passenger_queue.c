#include "remove_passenger_queue.h"
#include "structures.h"
#include <stdio.h>
#include <stdlib.h>

void case_1(void);
void case_2(void);
void case_3(void);
void case_4(void);
void case_5(void);
void case_6(void);

struct passenger temp = {0,0,0,0,0,0};

int main(){
	int choice = 0;
	printf("Choose between the tests: \n");
	puts("1- Provide an empty list. The program should exit");
	puts("2- Input index is negative number. The program should exit.");
	puts("3- Provide a 2 node linked list and input index =2. The program should exit.");
	puts("4- Provide list with just one node. The function returns NULL pointer");
	puts("4- Provide list with 3 nodes and index =1. Return head pointer with middle node removed.");
	puts("4- Provide list with 3 nodes and index=2. Return head pointer with tail node removed.");
	
	scanf("%d",&choice);
	switch (choice)
	{
	case 1:
		case_1();
		break;
	case 2:
		case_2();
		break;
	case 3:
		case_3();
		break;
	case 4:
		case_4();
		case_5();
		case_6();
		break;
	default:
		puts("incorrect input run program again");
		break;
	}
	return 0;
}

/** This function tests case when empty head is passed.
 * The function passes and empty head pointer to remove_passenger_queue.
 * The function should cause the program to exit with assetion error.
 * @return void does not return anything.
 *  * */
void case_1(void){
	struct passenger* head = NULL;
	remove_passenger_queue(0, head); 
}

/** This function tests case when negtive index is passed.
 * The function passes a negative index to remove_passenger_queue.
 * The function should cause the program to exit with assetion error.
 * @return void does not return anything.
 *  * */
void case_2(void){
	struct passenger* head = malloc(sizeof(struct passenger));
	*head = temp;
	head->next = NULL;
	remove_passenger_queue(-2, head); 
}


/** This function tests case when index greater than length is passed.
 * The function passes a index greater than queue length to remove_passenger_queue.
 * The function should cause the program to exit with assetion error.
 * @return void does not return anything.
 *  * */
void case_3(void){
	struct passenger* head = malloc(sizeof(struct passenger));
	*head = temp;
	struct passenger* second = malloc(sizeof(struct passenger));
	*second = temp;
	head->next = second;
	second->next = NULL; 
	remove_passenger_queue(2, head); 
}


/** This function tests case one node queue is passed.
 * The function passes a one node queue and index 0 to remove_passenger_queue.
 * The function tests if resultant pointer points to NULL. 
 * @return void does not return anything.
 *  * */
void case_4(void){
	struct passenger* head = malloc(sizeof(struct passenger));
	*head = temp;
	head->next = NULL; 
	struct passenger* result = NULL;
	result = remove_passenger_queue(0, head); 
	if (result == NULL){
		printf("PASS: result points to NULL %p \n", result);
	}
	else{
		printf("FAIL: result points to %p \n",result);		
	}
}

/** This function tests case three node queue is passed.
 * The function passes a three node queue and index 1 to remove_passenger_queue.
 * The function tests if middle pointer is removed from queue. 
 * @return void does not return anything.
 *  * */
void case_5(void){
	struct passenger* head = malloc(sizeof(struct passenger));
	*head = temp;
	struct passenger* second = malloc(sizeof(struct passenger));
	*second = temp;
	struct passenger* third = malloc(sizeof(struct passenger));
	head->next = second;
	second->next = third;
	third->next = NULL; 
	struct passenger* result = NULL;
	struct passenger* middle = second;
	result = remove_passenger_queue(1, head); 
	if (result == head){
		printf("PASS: Removing middle element return points to head %p %p\n", result, head);
	}
	else{
		printf("FAIL: Removing middle element result does not points to  head %p %p\n",result, head);		
	}
	if (head->next == middle){
		printf("FAIL: Removing middle element MIDDLE ELEMENT NOT REMOVED PROPERLY. \n");
	}
	else if (head->next == third){
		printf("PASS: Removing middle element MIDDLE ELEMENT REMOVED PROPERLY \n");
	}
	else{
		printf("FAIL: Removing middle element  MIDDLE ELEMENT NOT REMOVED PROPERLY HEAD NOT POINT TO THIRD ELEMENT \n");
	}
}

/** This function tests case three node queue is passed.
 * The function passes a three node queue and index 2 to remove_passenger_queue.
 * The function tests if tail pointer is remomved from the queue. 
 * @return void does not return anything.
 *  * */
void case_6(void){
	struct passenger* head = malloc(sizeof(struct passenger));
	*head = temp;
	struct passenger* second = malloc(sizeof(struct passenger));
	*second = temp;
	struct passenger* third = malloc(sizeof(struct passenger));
	head->next = second;
	second->next = third; 
	third->next = NULL;
	struct passenger* result = NULL;
	result = remove_passenger_queue(2, head);
	if (result == head){
		printf("PASS: Removing tail return points to head %p %p\n", result, head);
	}
	else{
		printf("FAIL: Removing tail result does not points to  head %p %p\n",result, head);		
	}
	if (head->next == second){
		printf("PASS: Removing tail Head points to second node. Structure maintained.\n");
	}
	else{
		printf("FAIL: Removing tail Head does not point to second node. Sturucture not maintained.\n");
	}
	if (head->next->next == NULL && second->next == NULL){
		printf("PASS: Removing tail Last Element Removed Succesfully.\n");
	}
	else{
		printf("FAIL: Removing tail Last Element Not Removed Succesfully.\n");
	}
}