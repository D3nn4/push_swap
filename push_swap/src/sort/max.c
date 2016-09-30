#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "interpreter.h"
#include "instruction.h"
#include "sort.h"

bool isMaxFirst(t_stacks *stacks, t_list *cmd)
{
	printf("isMaxFirst IN\n");
	int int_max = getMax(stacks->stack[PILE_A]);
	printf("/////////1/////////\n");
	t_pile *pile = stacks->stack[PILE_A];
	printf("/////////2/////////\n");
	t_element *current = pile->first_element;
	printf("/////////3/////////\n");
	if (int_max == current->current_int){
		printf("/////////4/////////\n");
		applyCmd("ra", stacks);
		printf("/////////5/////////\n");
		addCmd("ra", cmd);
		printf("isMaxFirst OUT\n");
		return true;
	}
	printf("isMaxFirst OUT\n");
	return false;
}

bool isMaxSecond(t_stacks *stacks, t_list *cmd)
{
	//printf("isMaxSecond IN\n");
	int int_max = getMax(stacks->stack[PILE_A]);
	t_pile *pile = stacks->stack[PILE_A];
	t_element *current = pile->first_element;
	if (int_max == current->next->current_int){
		applyCmd("sa", stacks);
		addCmd("sa", cmd);
		applyCmd("ra", stacks);
		addCmd("ra", cmd);
		//printf("isMaxSecond OUT\n");
		return true;
	}
	//printf("isMaxSecond OUT\n");
	return false;
}

bool ifMaxNear(t_stacks *stacks, t_list *cmd)
{
	if (isMaxFirst(stacks, cmd) 
		|| isMaxSecond(stacks, cmd)) 
		return true;
	return false;
}