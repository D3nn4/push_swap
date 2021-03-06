#ifndef __INSTRUCTION_H__
#define __INSTRUCTION_H__
#include "interpreter.h"

#define PILE_A 0
#define PILE_B 1
#define NB_FUNC 11

typedef struct 	s_func
{
	const char *cmd;
	void (*ptrFnc) (t_stacks*, int);
	int pile_nb;
}				t_func;

void rotate(t_stacks *stacks, int pile_nb);
void swap(t_stacks *stacks, int pile_nb);
void push(t_stacks *stacks, int pile_nb);
void reverseRotate(t_stacks *stacks, int pile_nb);
void rotateAll(t_stacks *stacks, int pile_nb);
void swapAll(t_stacks *stacks, int pile_nb);
void reverseRotateAll(t_stacks *stacks, int pile_nb);
void applyCmd (char *buff, t_stacks *stacks);

#endif // __INSTRUCTION_H__