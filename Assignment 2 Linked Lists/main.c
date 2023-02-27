#include "list.h"
#include <stdio.h>

/*Then code in a file like main.c can include this header file 
(like a library) and use the linked list that is readily available.*/

int main() {

	struct linked_list* llist = ll_create(); //create linked list

	//Check if memory allocation is successful
	if(!llist){
		printf("Error! Memory allocation failure\n");
	} else {
		printf("Success! Memory properly allocated\n");
	}

	int length = ll_length(llist); // Grab the length of the list

	printf("Initial Length: %d\n", length); // Print the initial length of the list, should be 0

	//Adding values to the linked list
	ll_add(llist, 1);
	ll_add(llist, 2);
	ll_add(llist, 3);
	ll_add(llist, 4);
	ll_add(llist, 5);
	ll_add(llist, 6);
	ll_add(llist, 7);
	ll_add(llist, 8);
	ll_add(llist, 9);

	length = ll_length(llist);
	printf("New length after adding values: %d\n", length);

	ll_remove_first(llist); //remove the first value

	length = ll_length(llist); //new length
	printf("New length after removing the head: %d\n", length);

	int destroy = ll_destroy(llist); //destryoying the list
	printf("New length after destroying linked list: %d\n", destroy);


	return 0;
}
