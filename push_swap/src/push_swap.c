#include <stdlib.h>
#include <stdio.h>
#include "interpreter.h"
#include "instruction.h"
#include "sort.h"

void push_swap(int ac, char **av)
{
	t_stacks * stacks = createStacks(ac, av);
	t_list *list_cmd = NULL;
	if (stacks) {
		printPile(stacks->stack[PILE_A]);
		printPile(stacks->stack[PILE_B]);
		if (!checkResult(stacks))
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
