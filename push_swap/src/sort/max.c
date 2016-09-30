#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "interpreter.h"
#include "instruction.h"
#include "sort.h"

bool isMaxFirst(t_stacks *stacks, t_list *cmd)
{
	t_pile *pile = stacks->stack[PILE_A];
	t_element *current = pile->first_element;
	if (pile->first_element && pile->first_element->next) {
		int int_max = getMax(pile);
		if (int_max == current->current_int){
			applyCmd("ra", stacks);
			addCmd("ra", cmd);
			return true;
		}
	}
	return false;
}

bool isMaxSecond(t_stacks *stacks, t_list *cmd)
{
	t_pile *pile = stacks->stack[PILE_A];
	t_element *current = pile->first_element;
	if (pile->first_element && pile->first_element->next) {
	int int_max = getMax(pile);
		if (int_max == current->next->current_int){
			applyCmd("sa", stacks);
			addCmd("sa", cmd);
			applyCmd("ra", stacks);
			addCmd("ra", cmd);
			return true;
		}
	}
	return false;
}

bool ifMaxNear(t_stacks *stacks, t_list *cmd)
{
	if (isMaxFirst(stacks, cmd) 
		|| isMaxSecond(stacks, cmd)) 
		return true;
	return false;
}