#include <stdlib.h>
#include "interpreter.h"
#include "instruction.h"

void freeElem(t_element **element)
{
	t_element *to_free = *element;
	to_free->next = NULL;
	to_free->previous = NULL;
	free(to_free);
	return;
}

void freePile(t_pile **pile)
{
	t_pile *to_free = *pile;
	t_element *current_elem = to_free->first_element;
	while (current_elem) {
		t_element *next_elem = current_elem->next;
		freeElem(&current_elem);
		current_elem = next_elem;
	}
	to_free->first_element = NULL;
	free(to_free);
	return;
}

void freeStacks(t_stacks **stacks_to_remove)
{
	t_stacks *stacks = *stacks_to_remove;
	t_pile *pile_a = stacks->stack[PILE_A];
	t_pile *pile_b = stacks->stack[PILE_B];
	freePile(&pile_a);
	freePile(&pile_b);
	free(stacks);
	return;
}