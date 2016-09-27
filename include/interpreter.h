#ifndef __INTERPRETER_H__
#define __INTERPRETER_H__
#define NB_MIN 0
#define NB_MAX 9
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

void checker(int ac, char **av);
void addElement(int nb, t_pile *pile);
void printPile (t_pile *pile);
void freePile(t_pile **pile);
void freeElem(t_element **element);

t_pile *createPile(int ac, char **av);
t_pile *getListInt(int ac, char **av, t_pile *pile);

#endif  //__INTERPRETER_H__