#include <stdio.h>
#include "stack.h"

/*
	Shane West
	

	This program provides the user with a menu that deals
	with stacks. The menu contains four options: Push, Pop,
	List and Quit. 
*/

int menu(void);

int main(void) {
	int selection, data_to_add, data_removed;
	stack top;
	init_stack(&top);
  	selection = menu();
  	while (selection != 4) {
   	  switch (selection) {
	
/*
	Case 1: Push
	
	If the user chooses "Push" the program well check to see 
	if the stack is full. If the stack is not full the program
	will receive a number from the user and push it onto the stack.
	If the stack is full the user will be prompted with an error message.

*/
        case 1: if (!is_full()) {
						printf("Enter a number: ");
						scanf("%d", &data_to_add);
						push(&top, data_to_add);
					} else
						printf("Stack is full!\n");
                break;

/*
	Case 2: Pop
	
	If the user chooses "Pop" the program well check to see 
	if the stack is empty. If the stack is not empty the program
	will remove the last number that was added to the stack and display
	a message telling the user what was popped.If the stack is empty the
	user will be prompted with an error message.

*/

        case 2: if (!is_empty(top)) {
						data_removed = pop(&top);
						printf("%d was popped.\n", data_removed);
					} else
						printf("Stack is empty!\n");
					break;
					
/*
	Case 3: List
	
	If the user chooses "List" the program well check to see 
	if the stack is empty. If the stack is not empty the program
	will print out the stack. If the stack is empty the user will
	be prompted with an error message.

*/

		  case 3: if (!is_empty(top)) {
						print_stack(top);
					} else
						printf("Stack is empty!\n");
					break;
/*
	Default:
	
	If the user does not enter a selection between 1-4 the program
	will prompt the user with an error message.
*/
					
	   default: printf("%d is not a valid selection\n", selection);
     }
     selection = menu();
  }

/*
	If the user enters 4(Quit) the program will end.
*/
  printf("Bye!\n");
}

/*
	Menu Subprogram
	
	This prints out the options for the menu, gets a selection
	from the user, and returns that selection.
*/
	
int menu(void) {
    int choice;
    printf("1: Push\n");
    printf("2: Pop\n");
    printf("3: List\n");
    printf("4: Quit\n");
    printf("Enter a Selection: ");
    scanf("%d", &choice);
    return choice;
}