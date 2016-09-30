#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "interpreter.h"
#include "instruction.h"
#include "sort.h"
bool minIsFirst(t_stacks *stacks, t_list *cmd)
{
	t_pile *pile = stacks->stack[PILE_A];
	t_element *current = pile->first_element;
	if (pile->first_element) {
		int int_min = getMin(pile);
		if (int_min == current->current_int){
			applyCmd("pb", stacks);
			addCmd("pb", cmd);
			return true;
		}
	}
	return false;
}

bool minIsSecond(t_stacks *stacks, t_list *cmd)
{
	t_pile *pile = stacks->stack[PILE_A];
	t_element *current = pile->first_element;
	if (pile->first_element && pile->first_element->next) {
		int int_min = getMin(pile);
		if (int_min == current->next->current_int){
			applyCmd("sa", stacks);
			addCmd("sa", cmd);
			applyCmd("pb", stacks);
			addCmd("pb", cmd);
			return true;
		}
	}
	return false;
}

bool minIsLast(t_stacks *stacks, t_list *cmd)
{	
	t_pile *pile = stacks->stack[PILE_A];
	if (pile->pile_lenght > 3) {
		int int_min = getMin(pile);
		t_element *current = pile->first_element;
		while (current->next)
			current = current->next;
		if (int_min == current->current_int){
			applyCmd("rra", stacks);
			addCmd("rra", cmd);
			applyCmd("pb", stacks);
			addCmd("pb", cmd);
			return true;
		}
	}
	return false;
}

bool ifMinNear(t_stacks *stacks, t_list *cmd)
{
	if (minIsFirst(stacks, cmd) == false
		&& minIsSecond(stacks, cmd) == false
		&& minIsLast(stacks, cmd) == false) {
		return false;
	}
	return true;	
}