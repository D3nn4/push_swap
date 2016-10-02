#include <stdlib.h>
#include <stdio.h>
#include "interpreter.h"
#include "instruction.h"
#include "sort.h"

bool checkSort(t_pile *pile)
{
	//printf(" in checkSort\n");
	t_element *current_elem = pile->first_element;
	while (current_elem->next) {
		if (current_elem->current_int > current_elem->next->current_int)
			return false;
		current_elem = current_elem->next;
	}
	return true;
}

void emptyPileB(t_stacks *stacks, t_list *cmd)
{
	//printf(" in emptyPileB\n");
	t_pile *pile_b = stacks->stack[PILE_B];
	while (pile_b->first_element){
		applyCmd("pa", stacks);
		if (addCmd("pa", cmd) == false)
				error_exit(&stacks, &cmd);
	}
}

t_list *sortStacks(t_stacks *stacks)
{
	//printf(" in sortStacks\n");
	t_list *list_cmd = createListCmd();
	if (list_cmd == NULL)
		error_exit(&stacks, &list_cmd);
	ifMaxNear(stacks, list_cmd);
	while (checkSort(stacks->stack[PILE_A]) == false) {
		if (ifMinNear(stacks, list_cmd) == false) {
			findMin(stacks,list_cmd);
		}
		
		if (!stacks->stack[PILE_A]->first_element)
			emptyPileB(stacks, list_cmd);
	}
	if (stacks->stack[PILE_B]->first_element)
		emptyPileB(stacks, list_cmd);
	return list_cmd;
}
