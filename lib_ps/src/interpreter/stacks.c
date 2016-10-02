#include <stdlib.h>
#include <stdio.h>
#include "instruction.h"
#include "interpreter.h"

t_stacks *createStacks(int ac, char **av)
{
	t_stacks *stacks = malloc(sizeof(*stacks));
	if (stacks == NULL) {
		dprintf(2, "ERROR\n");
		exit(_EXIT_VALUE_);
	}
	stacks->stack[PILE_A] = NULL;
	stacks->stack[PILE_B] = NULL;
	t_pile *pile_a = createPile(ac, av);
	if (pile_a == NULL) {
		error_s(&stacks);
	}
	stacks->stack[PILE_A] = pile_a;
	t_pile *pile_b = createPile(ac, NULL);
	if (pile_b == NULL) {
		error_s(&stacks);
	}
	stacks->stack[PILE_B] = pile_b;
	return stacks;
}