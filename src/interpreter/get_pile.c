#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "interpreter.h"

void addElement(int nb, t_pile *pile)
{
	t_element *to_add = malloc(sizeof(*to_add));
	if (to_add == NULL) {
		dprintf(2, "ERROR\n");
		return;
	}
	to_add->current_int = nb;
	to_add->previous = NULL;
	to_add->next = NULL;
	if (pile->first_element == NULL)
		pile->first_element = to_add;
	else {
		t_element *current_elem = pile->first_element;
		while (current_elem->next)
			current_elem = current_elem->next;
		current_elem->next = to_add;
		to_add->previous = current_elem;
	}
	return;
}

t_pile *getListInt(int ac, char **av, t_pile *pile)
{
	int i = 0;
	for (i = 1; i < ac; ++i) {
		if (strlen(av[i]) != 1) {
			dprintf(2, "ERROR\n");
		return NULL;
		}
		int nb = av[i][0] - '0';
		if (NB_MIN <= nb && nb <= NB_MAX)
			addElement(nb, pile);
		else {
		dprintf(2, "ERROR\n");
		return NULL;
		}
		++pile->pile_lenght;
		++pile->total_int;
	}
	return pile;
}

t_pile *createPile(int ac, char **av)
{
	t_pile *pile = malloc(sizeof(*pile));
	if (oile == NULL) {
		dprintf(2, "ERROR\n");
		return;
	}
	pile->first_element = NULL;
	pile->pile_lenght = 0;
	pile->total_int = 0;
	if (av)
		pile = getListInt(ac,av,pile);
	return pile;		
}