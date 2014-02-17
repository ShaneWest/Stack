#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/*
	Initializing a Stack
	
	Using pass by reference, this subprogram sets the pointer
	to the top of the stack to null.
*/

void init_stack(stack *s) {
	*s = NULL;
}

/*
	Checks to see if a stack is empty
	
	This subprogram determines whether or not the pointer to the
	top of the stack is pointing to null. It returns either a "true"
	value or a "false" value.
*/
boolean is_empty(stack s) {
	return (s == NULL);
}

/*
	Check to see if a stack is full
	
	This programs creates a temporary pointer and attempts
	to allocate memory the size of a stacknode structure.
	If sucessful, temp will point to that memory, the subprogram
	will return FALSE, and temp will be freed. If unsucessful temp
	will point to null and return TRUE.
*/

boolean is_full(void) {
	stack temp;
	temp = (stack)malloc(sizeof(struct stacknode));
	if (temp == NULL)
		return TRUE;
	else {
		free (temp);
		return FALSE;
	}
}

/*
	Pushing onto a stack
	
	This subprogram receives stack using pass by reference and data to
	be added using pass by value. It creates a temporary pointer and
	allocates memory the size of a stacknode structure that is assigned to temp.
	It then assigns the data portion of the structure to the item to be pushed,
	sets the next pointer to point to the top of the stack, and moves the the top
	pointer to the new stacknode structure.
*/

void push(stack *s, int x) {
	stack temp;
	temp = (stack)malloc(sizeof(struct stacknode));
	temp -> data = x;
	temp -> next = *s;
	(*s) = temp;
}

/*
	Popping items off a stack
	
	This subprogram receives stack using pass by reference. It creates a
	temporary stack called temp. It then sets the temporary stack pointer
	to the top of the stack, sets the data to be popped equal to temp's data,
	moves the top pointer to temp's next pointer, frees temp, and returns
	data popped.
*/

int pop(stack *s) {
	stack temp;
	int data_popped;
	temp = *s;
	data_popped = temp->data;
	*s = temp->next;
	free(temp);
	return data_popped;
}

/*
	Printing a stack
	
	This subprogram checks to see if the stack is empty. If not, it prints
	the top item in the stack, calls itself, and continues to print the contents
	of the stack.
*/
void print_stack(stack s) {
	if (!is_empty(s)) {
		printf("%d\n", s->data);
		print_stack(s->next);
	}
}