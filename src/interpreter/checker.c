#include <stdlib.h>
#include <stdio.h>
#include "interpreter.h"
#include "instruction.h"

void displayPiles(t_stacks *stacks)
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
	while (current_elem){
		printf("%d\n", current_elem->current_int);
		current_elem = current_elem->next;
	}
	return;
}
void checker(int ac, char **av)
{
	t_pile *pile_a = createPile(ac, av);
	if (pile_a == NULL)
		return;
	t_pile *pile_b = createPile(ac, NULL);
	if (pile_b == NULL)
		return;
	t_stacks * stacks = createStacks(pile_a, pile_b);
	displayPiles(stacks);
	freePile(&pile_a);
	freePile(&pile_b);
	free(stacks);
	return;
} 