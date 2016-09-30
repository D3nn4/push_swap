#include <stdlib.h>
#include <stdio.h>
#include "interpreter.h"
#include "instruction.h"
#include "sort.h"

void emptyPileB( t_stacks *stacks, t_list *list_cmd)
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
	//t_data *data = getData(stacks);
	while (checkResult(stacks) == false) {
		if (ifMinNear(stacks, list_cmd) == false) {
			//findMin(stacks,list_cmd);
		}
		ifMaxNear(stacks, list_cmd);
	}
	emptyPileB(stacks, list_cmd);
	return list_cmd;
}
