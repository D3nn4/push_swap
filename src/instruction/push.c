//pa : push a - prend le premier élément au sommet de b et le met sur a. Ne fait
//rien si b est vide
#include <stdlib.h>
#include "interpreter.h"

void push(t_pile **to_pile, t_pile **from_pile)
{	
	t_pile *p_to = *to_pile;
	t_pile *p_from = *from_pile;
	if (p_from->first_element)	{
		t_element *to_move = p_from->first_element;
		to_move->next->previous = NULL;
		p_from->first_element = p_from->first_element->next;
		to_move->next = p_to->first_element;
		p_to->first_element = to_move;
		to_move->next->previous = to_move;
		p_to->pile_lenght++;
		p_from->pile_lenght--;
	}
	return;

}