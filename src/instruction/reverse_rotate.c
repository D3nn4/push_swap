//rra : reverse rotate a - décale d’une position vers le bas tous les élements de
//la pile a. Le dernier élément devient le premier.
#include <stdlib.h> 
#include "interpreter.h"

void reverseRotate(t_pile **pile_to_rr)
{
	t_pile *pile = *pile_to_rr;
	if (pile->first_element && pile->first_element->next){
		t_element *current_elem = pile->first_element;
		while(current_elem->next->next)
			current_elem = current_elem->next;
		t_element *to_move = current_elem->next;
		to_move->next = pile->first_element->next;
		current_elem->next = NULL;
		pile->first_element = to_move;
		to_move->previous = NULL;
		to_move->next->previous = to_move;
	}
}