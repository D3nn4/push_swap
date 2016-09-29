#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "interpreter.h"
#include "instruction.h"

void applyCmd (char *buff, t_stacks *stacks)
{
	int i = 0;
	for (i = 0; i < NB_FUNC; i++) {
		if (strcmp(buff, tab_func[i].cmd) == 0) {
			tab_func[i].function(stacks, tab_func.pile_nb);
			exit(0);
		}
	}
	printf("No command %s\n", buff);
	return;
}