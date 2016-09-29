//rra : reverse rotate a - décale d’une position vers le bas tous les élements de
//la pile a. Le dernier élément devient le premier.
#include <stdlib.h> 
#include <stdio.h>
#include "interpreter.h"
#include "instruction.h"

void reverseRotate(t_stacks *stacks, int pile_nb)
{
	t_pile *pile = stacks->stack[pile_nb];
	if (pile->first_element && pile->first_element->next) {
		t_element *current_elem = pile->first_element;
		while(current_elem->next->next)
			current_elem = current_elem->next;
		t_element *to_move = current_elem->next;
		to_move->next = pile->first_element;
		current_elem->next = NULL;
		pile->first_element = to_move;
		to_move->previous = NULL;
		to_move->next->previous = to_move;
	}
	return;
}

void reverseRotateAll(t_stacks *stacks, int pile_nb)
{
	(void)pile_nb;
	reverseRotate(stacks, PILE_A);
	reverseRotate(stacks, PILE_B);
	return;
}