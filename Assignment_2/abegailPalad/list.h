#ifndef LIST_H
#define LIST_H

#include <stdbool.h>
#include <assert.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

/*Note: In a list with n values, the head is position 1 and the tail 
is position n; therefore, if the value is in the list, ll_contains returns 
a logical true, the off into the linked list. If the value is not found 
in the list, 0 is returned; therefore, if the value is not in the list, ll_contains 
returns a logical false. Most often, this will be used to determine if a node is in 
the linked list, and not where it is in the list, thus the optimization to have it 
return 0 (logical false), and a 1-indexed off otherwise (logical true).*/

/*If the value is not in the list, two things will happen. 0 is returned and ll_contains will 
return a false*/

/*Need to create a node and linked list struct*/

struct node {
	int value;
	struct node *next;
};

struct linked_list {
	struct node *head;
	int len;
};


/*create allocates and returns a pointer to a linked list. 
If unable to allocate the list, ll_create returns NULL. You 
must always check if malloc returns NULL.*/
static inline struct linked_list *ll_create(void) {
	//dynamic memory location malloc
	//struct linked_list* list = (struct linked_list)malloc(sizeof(struct linked_list));
	struct linked_list* list = (struct linked_list *)malloc(sizeof(struct linked_list));
	list -> len = 0;
	list -> head = NULL;

	if(list == NULL)
		return NULL;

	return list;
}

/*deallocates a linked list, only if it is empty. 
Return 1 if the linked list is destroyed, 
and 0 if it couldn’t be destroyed.*/
static inline int ll_destroy(struct linked_list *ll) {
	if(ll->len)
		return 0;
	else {
		free(ll); //free from heap
		ll = NULL;
		return 1;}
}

/*inserts a value at the head of the linked list.*/
static inline void ll_add(struct linked_list *ll, int value) {
	struct node *node = (struct node *)malloc(sizeof(struct node));
	assert(node != NULL);
	node -> value = value;
	node -> next = ll->head;
	ll -> head = node;
	ll -> len++; 
}

/* returns the total number of values in the linked list.*/
static inline int ll_length(struct linked_list *ll)
{
	return ll -> len;
}

/*removes the value at the head of the linked list and returns true. 
If the list is empty, ll_remove_first returns false.*/
static inline bool ll_remove_first(struct linked_list *ll)
{
	if(ll->len)
	{
		struct node *del = ll->head; // delete node
		ll->head = ll->head->next;
		free(del);
		ll->len--;
		return true; 
	}

	return false;
}

/* searches the linked list from head to tail and returns 
the first position at which the value is found.*/
static inline int ll_contains(struct linked_list *ll, int value)
{
	int off = 1;
	bool found = false;
	struct node *ptr = ll->head;

	while(ptr != NULL && !found)
	{
		if(ptr->value == value)
			found = true;
		else{
			ptr = ptr->next;
			off++;
		}
	}

	if(found)
		return off;

	return 0;
}

#endif
