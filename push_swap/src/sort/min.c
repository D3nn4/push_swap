#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "interpreter.h"
#include "instruction.h"
#include "sort.h"

void findMin(t_stacks *stacks, t_list *cmd)
{
	//printf(" in findMin\n");
	t_pile *pile = stacks->stack[PILE_A];
	t_element *current = pile->first_element;
	int int_min = getMin(pile);
	int place = 1;
	while (current && int_min != current->current_int) {
		++place;
		current = current->next;
	}
	if (place <= (pile->pile_lenght/2)) { // /2 to know wich direction to rotate
		applyCmd("ra", stacks);
		if (addCmd("ra", cmd) == false)
				error_exit(&stacks, &cmd);
	}
	else {
		applyCmd("rra", stacks);
		if (addCmd("rra", cmd) == false)
				error_exit(&stacks, &cmd);
	}
	return;
}

bool minIsFirst(t_stacks *stacks, t_list *cmd)
{
	//printf(" in minIsFirst\n");
	t_pile *pile = stacks->stack[PILE_A];
	t_element *current = pile->first_element;
	if (pile->first_element) {
		int int_min = getMin(pile);
		if (int_min == current->current_int){
			applyCmd("pb", stacks);
			if (addCmd("pb", cmd) == false)
				error_exit(&stacks, &cmd);
			return true;
		}
	}
	return false;
}

bool minIsSecond(t_stacks *stacks, t_list *cmd)
{
	//printf(" in minIsSecond\n");
	t_pile *pile = stacks->stack[PILE_A];
	t_element *current = pile->first_element;
	if (pile->first_element && pile->first_element->next) {
		int int_min = getMin(pile);
		if (int_min == current->next->current_int){
			applyCmd("sa", stacks);
			if (addCmd("sa", cmd) == false)
				error_exit(&stacks, &cmd);
			applyCmd("pb", stacks);
			if (addCmd("pb", cmd) == false)
				error_exit(&stacks, &cmd);
			return true;
		}
	}
	return false;
}

bool minIsLast(t_stacks *stacks, t_list *cmd)
{	
	//printf(" in minIsLast\n");
	t_pile *pile = stacks->stack[PILE_A];
	if (pile->pile_lenght > 3) {
		int int_min = getMin(pile);
		t_element *current = pile->first_element;
		while (current->next)
			current = current->next;
		if (int_min == current->current_int){
			applyCmd("rra", stacks);
			if (addCmd("rra", cmd) == false)
				error_exit(&stacks, &cmd);
			applyCmd("pb", stacks);
			if (addCmd("pb", cmd) == false)
				error_exit(&stacks, &cmd);
			return true;
		}
	}
	return false;
}

bool ifMinNear(t_stacks *stacks, t_list *cmd)
{
	//printf(" in ifMinNear\n");
	if (minIsFirst(stacks, cmd) == false
		&& minIsSecond(stacks, cmd) == false
		&& minIsLast(stacks, cmd) == false) {
		return false;
	}
	//ifMaxNear(stacks, cmd);
	return true;	
}