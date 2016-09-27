//ra : rotate a - décale d’une position vers le haut tous les élements de la pile a.
//Le premier élément devient le dernier.
#include <stdlib.h> 
#include "interpreter.h"

void rotate(t_pile **pile_to_rotate)
{
	t_pile *pile = *pile_to_rotate;
	if (pile->first_element && pile->first_element->next){
		t_element *new_last = pile->first_element;
		pile->first_element = pile->first_element->next;
		pile->first_element->previous = NULL;
		t_element *current_elem = pile->first_element;
		while (current_elem->next)
			current_elem = current_elem->next;
		current_elem->next = new_last;
		new_last->previous = current_elem;
		new_last->next = NULL;
	}
}