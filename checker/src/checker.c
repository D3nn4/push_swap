#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include "interpreter.h"
#include "instruction.h"


void checker(int ac, char **av)
{
	size_t size_max = _SIZE_MAX_;
	bool status = true;
	t_stacks * stacks = createStacks(ac, av);
	if (stacks) {
		//displayStacks(stacks);
		while (status) {
			int ret = 0;
			char *buff = NULL;
			ret = getline(&buff, &size_max, stdin);
			buff[ret - 1] = '\0';
			if (buff[0] == '\0') {
				checkResult(stacks); 
				status = false;
			}
			else 
				applyCmd(buff, stacks);
			free(buff);
			// displayStacks(stacks);
		}
		freeStacks(&stacks);
	}
	return;
} 
