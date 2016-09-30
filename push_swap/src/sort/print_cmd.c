#include <stdlib.h>
#include <stdio.h>
#include "interpreter.h"
#include "instruction.h"
#include "sort.h"

void printCmd(t_list *list_cmd)
{
	t_cmd *current_cmd = list_cmd->first_elem;
	while (current_cmd) {
		printf("%s\n", current_cmd->name);
		current_cmd = current_cmd->next;
	}
	return;
}