#ifndef __INTERPRETER_H__
#define __INTERPRETER_H__
#define NB_MIN 0
#define NB_MAX 9
#define NB_PILE 2
#define _SIZE_MAX_ 4096

typedef struct 	s_element
{
	int current_int;
	struct s_element *next;
	struct s_element *previous;
} 				t_element;

typedef struct 	s_pile
{
	t_element *first_element;
	int pile_lenght;
	int total_int;
} 				t_pile;

typedef struct 	s_stacks
{
	t_pile *stack[NB_PILE];
}				t_stacks;

void checker(int ac, char **av);
void addElement(int nb, t_pile *pile);
void checkResult (t_stacks *stacks);
void printPile (t_pile *pile);
void freePile(t_pile **pile);
void freeElem(t_element **element);
void freeStacks(t_stacks **stacks);


t_pile *createPile(int ac, char **av);
t_pile *getListInt(int ac, char **av, t_pile *pile);

t_stacks *createStacks(int ac, char **av);

#endif  //__INTERPRETER_H__