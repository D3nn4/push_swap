#include <stdlib.h>
#include <stdio.h>
#include "interpreter.h"
#include "instruction.h"
#include "sort.h"

void freeCmd(t_cmd **cmd)
{
	t_cmd *to_free = *cmd;
	to_free->next = NULL;
	to_free->previous = NULL;
	free(to_free);
	return;
}

void freeList(t_list **list_cmd)
{
	t_list *to_free = *list_cmd;
	t_cmd *current = to_free->first_elem;
	while (current) {
		t_cmd *next = current->next;
		freeCmd(&current);
		current = next;
	}
	to_free->first_elem = NULL;
	free(to_free);
	return;
}