#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "interpreter.h"
#include "instruction.h"

void applyCmd (char *buff, t_stacks *stacks)
{
	extern t_func tab_func_g[];
	int i = 0;
	for (i = 0; i < NB_FUNC; i++) {
		if (strcmp(buff, tab_func_g[i].cmd) == 0) {
			tab_func_g[i].ptrFnc(stacks, tab_func_g[i].pile_nb);
			return;
		}
	}
	dprintf(2, "ERROR\n");
	return;
}