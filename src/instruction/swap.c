//sa : swap a - intervertit les 2 premiers éléments au sommet de la pile a. Ne fait
//rien s’il n’y en a qu’un ou aucun.
#include <stdlib.h>
#include "interpreter.h"
#include "instruction.h"

void swap(t_stacks *stacks, int pile_nb)
{
	t_pile *pile = stacks->stack[pile_nb];
	if (pile->first_element && pile->first_element->next){
		t_element *to_swap = pile->first_element;
		to_swap->previous = to_swap->next;
		pile->first_element = pile->first_element->next;
		to_swap->next = pile->first_element->next;
		pile->first_element->next = to_swap;
		pile->first_element->previous = NULL;
	}
	return;
}

void swapAll(t_stacks *stacks, int pile_nb)
{
	(void)pile_nb;
	swap(stacks, PILE_A);
	swap(stacks, PILE_B);
	return;
}