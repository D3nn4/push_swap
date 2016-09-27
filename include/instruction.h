#ifndef __INSTRUCTION_H__
#define __INSTRUCTION_H__

void rotate(t_pile **pile_to_rotate);
void swap(t_pile **pile_to_swap);
void push(t_pile **to_pile, t_pile **from_pile);
void reverseRotate(t_pile **pile_to_rr);

#endif // __INSTRUCTION_H__