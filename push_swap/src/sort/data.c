#include <stdlib.h>
#include <stdio.h>
#include "interpreter.h"
#include "instruction.h"
#include "sort.h"

int getMin(t_pile *pile)
{
	int min = 0;
	if (pile->first_element){
		t_element *current = pile->first_element;
		min = current->current_int;
		while (current->next) {
			int next_int = current->next->current_int;
			if (min > next_int)
				min = next_int;
			current = current->next;
		}
	}
	return min;
}

int getMax(t_pile *pile)
{
	int max = 0;
	if (pile->first_element){
		t_element *current = pile->first_element;
		max = current->current_int;
		while (current->next) {
			int next_int = current->next->current_int;
			if (max < next_int)
				max = next_int;
			current = current->next;
		}
	}
	return max;
}
/*
t_data *getData(t_stacks *stacks)
{
	t_data *data = malloc(sizeof(*data));
	if (data == NULL) {
		dprintf(2, "ERROR");
		exit(_EXIT_STATUS_);
	}
	data->total_int = stacks->stack[PILE_A]->total_int;
	data->total_a = stacks->stack[PILE_A]->pile_lenght;
	data->total_b = stacks->stack[PILE_B]->pile_lenght;
	data->min_a = getMin(stacks->stack[PILE_A]);
	data->max_a = getMax(stacks->stack[PILE_A]);
	data->min_b = getMin(stacks->stack[PILE_B]);
	data->min_b = getMax(stacks->stack[PILE_B]);
	return data;
}
*/
