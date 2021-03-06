#include "instruction.h"

t_func tab_func_g[] = 
{
	{"sa", &swap, PILE_A},
	{"sb", &swap, PILE_B},
	{"ss", &swapAll, PILE_A},
	{"pa", &push, PILE_B},
	{"pb", &push, PILE_A},
	{"ra", &rotate, PILE_A},
	{"rb", &rotate, PILE_B},
	{"rr", &rotateAll, PILE_A},
	{"rra", &reverseRotate, PILE_A},
	{"rrb", &reverseRotate, PILE_B},
	{"rrr", &reverseRotateAll, PILE_A}
};