#include <stdlib.h>
#include <stdio.h>
#include "interpreter.h"
void printPile (t_pile *pile)
{
	t_element *current_elem = pile->first_element;
	while (current_elem){
		printf("%d\n", current_elem->current_int);
		current_elem = current_elem->next;
	}
}
void checker(int ac, char **av)
{
	

	t_pile *pile_a = createPile(ac, av);
	if (pile_a == NULL)
		return;
	t_pile *pile_b = createPile(ac, NULL);
	if (pile_b == NULL)
		return;
	printf("pile_a\n");
	printPile(pile_a);
	printf("pile_b\n");
	printPile(pile_b);
	freePile(&pile_a);
	freePile(&pile_b);
	return;
} 