//pa : push a - prend le premier élément au sommet de b et le met sur a. Ne fait
//rien si b est vide
#include <stdlib.h>
#include "interpreter.h"
#include "instruction.h"

void push(t_stacks *stacks, int pile_nb)
{	
	t_pile *p_to = NULL;
	t_pile *p_from = NULL;
	if (pile_nb == 1) {
		p_to = stacks->stack[PILE_A];
		p_from = stacks->stack[pile_nb];
	}
	if (pile_nb == 0) {
		p_to = stacks->stack[PILE_B];
		p_from = stacks->stack[pile_nb];
	}
	if (p_from->first_element) {
		t_element *to_move = p_from->first_element;
		if (to_move->next)
			to_move->next->previous = NULL;
		p_from->first_element = p_from->first_element->next;
		to_move->next = p_to->first_element;
		p_to->first_element = to_move;
		if (to_move->next)
			to_move->next->previous = to_move;
		++p_to->pile_lenght;
		--p_from->pile_lenght;
	}
	return;
}