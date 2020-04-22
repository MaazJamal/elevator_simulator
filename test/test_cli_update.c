#include "cli_update.h"
#include "structures.h"
#include "globals.h"
#include "stdio.h"
#include "stdlib.h"

static void case1(void);
static void case2(void);
static void case3(void);

struct elevator dummy1 = {1,0,0,1,0,3,10,30,15,0};
struct elevator dummy2 = {0,0,0,1,0,6,10,2,3,0};
struct elevator dummy3 = {1,0,0,0,0,0,10,5,0,0};

void test_cli_update(void){
int chose;
elevator_count = 3;
printf("Choose between tests:\n");
printf("1-Screen Clear Test\n");
printf("2-Display Test.\n");
printf("3-Repeated Calls test\n");
scanf("%d",&chose);
switch (chose){
	case 1:
	case1();
	break;

	case 2:
	case2();
	break;

	case 3:
	case3();
	break;
};
}

/** Simple test to check if it can clear the screen.
 * 
 * */
void case1(void){
	printf("THIS LINE SHOULD NOT BE VISIBLE FAIL.\n");
	struct elevator arr[3] = {dummy1,dummy2,dummy3};
	cli_update(arr);
}

/** Test to check it can work properly with dynamic array
 * */
void case2(void){
	struct elevator* arr = malloc(sizeof(struct elevator)*3);
	arr[0]= dummy1;
	arr[1]= dummy2;
	arr[2]= dummy3;
	cli_update(arr);
}

/** Test to check it can work properly with dynamic array
 * and repeated calls.
 * */
void case3(void){
	struct elevator* arr = malloc(sizeof(struct elevator)*3);
	arr[0]= dummy1;
	arr[1]= dummy2;
	arr[2]= dummy3;
	for(int i=0;i<1000;i++){
		printf("THIS LINE SHOULD NOT BE VISIBLE AT END.\n");
		cli_update(arr);
		arr[0].cur_floor = i%50;
		arr[0].timer = 10 - i%10;
		arr[0].passenger_count = 10-i%6;
		arr[1].direction_down = i%2;
		arr[1].moving = i%2;
		arr[1].timer = 10 -i%10;
		arr[2].moving = i%2;
		arr[2].cur_floor= i%10;
		arr[2].timer = 10 -i%10;
		printf("This is iteration count: %d\ns",i);
	}
}