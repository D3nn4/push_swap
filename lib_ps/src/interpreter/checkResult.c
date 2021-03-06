#include <stdio.h>
#include <stdbool.h>
#include "instruction.h"
#include "interpreter.h"

bool  checkResult (t_stacks *stacks)
{
	if (stacks->stack[PILE_B]->pile_lenght != 0) {
		printf("KO\n");
		return false;
	}
	t_element *current_elem = stacks->stack[PILE_A]->first_element;
	while (current_elem->next) {
		if (current_elem->current_int > current_elem->next->current_int) {
			printf("KO\n");
			return false;
		}
		current_elem = current_elem->next;
	}
	printf("OK\n");
	return true;

}