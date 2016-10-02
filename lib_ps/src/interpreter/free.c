#include <stdlib.h>
#include <stdio.h>
#include "interpreter.h"
#include "instruction.h"
#include "../../../push_swap/include/sort.h"


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
	if (to_free->first_element) {
		t_element *current_elem = to_free->first_element;
		while (current_elem) {
			t_element *next_elem = current_elem->next;
			freeElem(&current_elem);
			current_elem = next_elem;
		}
		to_free->first_element = NULL;
	}
	free(to_free);
	return;
}

void freeStacks(t_stacks **stacks_to_remove)
{
	t_stacks *stacks = *stacks_to_remove;
	t_pile *pile_a = stacks->stack[PILE_A];
	t_pile *pile_b = stacks->stack[PILE_B];
	if (pile_a)
		freePile(&pile_a);
	if (pile_b)
		freePile(&pile_b);
	free(stacks);
	return;
}

void error_p(t_pile **pile)
{
	dprintf(2, "ERROR");
	freePile(pile);
}

void error_s(t_stacks **stacks)
{
	dprintf(2, "ERROR");
	freeStacks(stacks);
	exit(_EXIT_STATUS_);
}

