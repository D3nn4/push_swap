#include "interpreter.h"

int main (int argc, char **argv)
{
	if (argc > 1)
		push_swap(argc,argv);
	return 0;
}