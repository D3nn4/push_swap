#include <stdlib.h>
#include "instruction.h"

t_stacks *createStacks(int ac, char **av)
{
	t_pile *pile_a = createPile(ac, av);
	if (pile_a == NULL)
		return NULL;
	t_pile *pile_b = createPile(ac, NULL);
	if (pile_b == NULL)
		return NULL;
	t_stacks *stacks = malloc(sizeof(*stacks));
	stacks->stack[PILE_A] = pile_a;
	stacks->stack[PILE_B] = pile_b;
	return stacks;
}