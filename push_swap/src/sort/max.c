#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "interpreter.h"
#include "instruction.h"
#include "sort.h"

bool isMaxFirst(t_stacks *stacks, t_list *cmd)
{
	//printf(" in isMaxFirst\n");
	t_pile *pile = stacks->stack[PILE_A];
	t_element *current = pile->first_element;
	if (pile->first_element && pile->first_element->next) {
		int int_max = getMax(pile);
		if (int_max == current->current_int){
			applyCmd("ra", stacks);
			if (addCmd("ra", cmd) == false)
				error_exit(&stacks, &cmd);
			return true;
		}
	}
	return false;
}

bool isMaxSecond(t_stacks *stacks, t_list *cmd)
{
	//printf(" in isMaxSecond\n");
	t_pile *pile = stacks->stack[PILE_A];
	t_element *current = pile->first_element;
	if (pile->first_element && pile->first_element->next) {
	int int_max = getMax(pile);
		if (int_max == current->next->current_int){
			applyCmd("sa", stacks);
			if (addCmd("sa", cmd) == false)
				error_exit(&stacks, &cmd);
			applyCmd("ra", stacks);
			if (addCmd("ra", cmd) == false)
				error_exit(&stacks, &cmd);
			return true;
		}
	}
	return false;
}

bool ifMaxNear(t_stacks *stacks, t_list *cmd)
{
	//printf(" in ifMaxNear\n");
	if (isMaxFirst(stacks, cmd) 
		|| isMaxSecond(stacks, cmd)) 
		return true;
	return false;
}