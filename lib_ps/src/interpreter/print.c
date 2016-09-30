#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include "interpreter.h"
#include "instruction.h"

void displayStacks(t_stacks *stacks)
{
	printf("pile_a\n");
	printPile(stacks->stack[PILE_A]);
	printf("pile_b\n");
	printPile(stacks->stack[PILE_B]);
	return;
}

void printPile(t_pile *pile)
{
	t_element *current_elem = pile->first_element;
	while (current_elem) {
		printf("%d\n", current_elem->current_int);
		current_elem = current_elem->next;
	}
	return;
}