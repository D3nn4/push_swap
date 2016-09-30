#ifndef __SORT_H__
#define __SORT_H__
#define _EXIT_STATUS_ 0
#include <stdbool.h>
#include "interpreter.h"
#include "instruction.h"

typedef struct 	s_cmd
{
	char *name;
	struct s_cmd *next;
	struct s_cmd *previous;
}				t_cmd;
typedef struct 	s_list
{
	t_cmd *first_elem;
	int nb_cmd;
}				t_list;
/*typedef struct 	s_data
{
	int total_int;
	int total_a;
	int total_b;
	int min_a;
	int max_a;
	int min_b;
	int max_b;
}				t_data;
*/
void addCmd(char *cmd, t_list *list);
void emptyPileB( t_stacks *stacks, t_list *list_cmd);
void printCmd (t_list *list_cmd);
void freeList(t_list **list_cmd);
void freeCmd(t_cmd **cmd);

int getMax(t_pile *pile);
int getMin(t_pile *pile);

bool ifMaxNear(t_stacks *stacks, t_list *cmd);
bool isMaxFirst(t_stacks *stacks, t_list *cmd);
bool isMaxSecond(t_stacks *stacks, t_list *cmd);
bool ifMinNear(t_stacks *stacks, t_list *cmd);
bool minIsFirst(t_stacks *stacks, t_list *cmd);
bool minIsSecond(t_stacks *stacks, t_list *cmd);
bool minIsLast(t_stacks *stacks, t_list *cmd);



t_list *createListCmd();
t_list *sortStacks(t_stacks *stacks);

//t_data *getData(t_stacks *stacks);



#endif // __SORT_H__