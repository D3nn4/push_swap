#include <stdlib.h>
#include "instruction.h"

t_stacks *createStacks(t_pile *pile_a, t_pile *pile_b)
{
	t_stacks *stacks = malloc(sizeof(*stacks));
	stacks->stack[PILE_A] = pile_a;
	stacks->stack[PILE_B] = pile_b;
	return stacks;
}