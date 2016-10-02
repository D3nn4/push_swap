#include <stdlib.h>
#include <stdio.h>
#include "interpreter.h"
#include "instruction.h"
#include "sort.h"

void push_swap(int ac, char **av)
{
	//printf(" in push_swap\n");
	t_stacks * stacks = createStacks(ac, av);
	t_list *list_cmd = NULL;
	if (stacks) {
		if (checkSort(stacks->stack[PILE_A]) == false)
			list_cmd = sortStacks(stacks);
		freeStacks(&stacks);
	}
	if (list_cmd) {
		if (list_cmd->first_elem)
			printCmd (list_cmd);
		freeList(&list_cmd);
	}
	return;
} 
