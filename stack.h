#ifndef stack_h
#define stack_h
#include "boolean.h"

typedef struct stacknode {
	int data;
	struct stacknode *next;
} *stack;

void init_stack(stack *);
boolean is_empty(stack);
boolean is_full(void);
void push(stack *, int);
int pop(stack *);
void print_stack(stack);

#endif