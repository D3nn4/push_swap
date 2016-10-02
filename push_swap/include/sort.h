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

void error_exit(t_stacks **stacks, t_list **cmd);
void emptyPileB( t_stacks *stacks, t_list *list_cmd);
void printCmd(t_list *list_cmd);
void freeList(t_list **list_cmd);
void freeCmd(t_cmd **cmd);
void findMin(t_stacks *stacks, t_list *list_cmd);

int getMax(t_pile *pile);
int getMin(t_pile *pile);

bool addCmd(char *cmd, t_list *list);
bool ifMaxNear(t_stacks *stacks, t_list *cmd);
bool isMaxFirst(t_stacks *stacks, t_list *cmd);
bool isMaxSecond(t_stacks *stacks, t_list *cmd);
bool ifMinNear(t_stacks *stacks, t_list *cmd);
bool minIsFirst(t_stacks *stacks, t_list *cmd);
bool minIsSecond(t_stacks *stacks, t_list *cmd);
bool minIsLast(t_stacks *stacks, t_list *cmd);
bool checkSort(t_pile *pile);


t_list *createListCmd();
t_list *sortStacks(t_stacks *stacks);

//t_data *getData(t_stacks *stacks);



#endif // __SORT_H__