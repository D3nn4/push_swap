//sa : swap a - intervertit les 2 premiers éléments au sommet de la pile a. Ne fait
//rien s’il n’y en a qu’un ou aucun.
#include <stdlib.h>
#include "interpreter.h"

void swap(t_pile **pile_to_swap)
{
	t_pile *pile = *pile_to_swap;
	if (pile->first_element && pile->first_element->next){
		t_element *to_swap = pile->first_element;
		to_swap->previous = to_swap->next;
		pile->first_element = pile->first_element->next;
		to_swap->next = pile->first_element->next;
		pile->first_element->next = to_swap;
		pile->first_element->previous = NULL;
	}
	return;
}