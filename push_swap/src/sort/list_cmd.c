#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "sort.h"
void addCmd(char *cmd, t_list *list)
{
	t_cmd *to_add = malloc(sizeof(*to_add));
	if (to_add == NULL) {
		dprintf(2, "ERROR");
		exit(_EXIT_STATUS_);
	}
	to_add->name = strdup(cmd);
	to_add->next = NULL;
	if (list->first_elem == NULL) {
		to_add->previous = NULL;
		list->first_elem = to_add;
	}
	else {
		t_cmd *current = list->first_elem;
		while (current->next)
			current = current->next;
		current->next = to_add;
		to_add->previous = current;
	}
	++list->nb_cmd;
	return;
}

t_list *createListCmd()
{
	t_list *list_cmd = malloc(sizeof(*list_cmd));
	if (list_cmd == NULL) {
		dprintf(2, "ERROR");
		exit(_EXIT_STATUS_);
	}
	list_cmd->first_elem = NULL;
	list_cmd->nb_cmd = 0;
	return list_cmd;
}