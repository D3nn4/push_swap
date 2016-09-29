#include "interpreter.h"
#include <stdio.h>

int main (int argc, char **argv)
{	
	if (argc > 1)
		checker(argc,argv);
	return 0;
}