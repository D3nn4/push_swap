#include <stdlib.h>
#include <stdio.h>
#include "interpreter.h"
#include "instruction.h"
#include "sort.h"

void findMin(t_stacks *stacks, t_list *list_cmd)
{
	t_pile *pile = stacks->stack[PILE_A];
	t_element *current = pile->first_element;
	int int_min = getMin(pile);
	int place = 1;
	while (current && int_min != pile->first_element->current_int) {
		++place;
		current = current->next;
	}
	if (place <= (pile->pile_lenght/2)) { // /2 to know wich direction to rotate
		applyCmd("ra", stacks);
		addCmd("ra", list_cmd);
	}
	else {
		applyCmd("rra", stacks);
		addCmd("rra", list_cmd);
	}
	return;
}

bool checkSort(t_pile *pile)
{
	t_element *current_elem = pile->first_element;
	while (current_elem->next) {
		if (current_elem->current_int > current_elem->next->current_int)
			return false;
		current_elem = current_elem->next;
	}
	return true;
}

void emptyPileB(t_stacks *stacks, t_list *list_cmd)
{
	t_pile *pile_b = stacks->stack[PILE_B];
	while (pile_b->first_element){
		applyCmd("pa", stacks);
		addCmd("pa", list_cmd);
	}
}

t_list *sortStacks(t_stacks *stacks)
{
	t_list *list_cmd = createListCmd();
	while (checkSort(stacks->stack[PILE_A]) == false) {
		if (ifMinNear(stacks, list_cmd) == false) {
			findMin(stacks,list_cmd);
		}
		ifMaxNear(stacks, list_cmd);
		if (!stacks->stack[PILE_A]->first_element)
			emptyPileB(stacks, list_cmd);
	}
	if (stacks->stack[PILE_B]->first_element)
		emptyPileB(stacks, list_cmd);
	return list_cmd;
}
