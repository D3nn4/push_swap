NAME = checker

SRC = 	src/main.c \
	  	src/instruction/tab_function.c \
	 	src/instruction/swap.c \
	  	src/instruction/push.c \
	 	src/instruction/rotate.c \
	  	src/instruction/reverse_rotate.c \
	  	src/instruction/cmd.c \
	  	src/interpreter/checker.c \
	  	src/interpreter/print.c \
	  	src/interpreter/get_pile.c \
	 	src/interpreter/free.c \
	  	src/interpreter/stacks.c \
	  	src/interpreter/checkResult.c

HEADER = include

OBJDIR = build

all : $(NAME)

$(NAME) : 
	gcc -ggdb3 -Wall -Wextra -I$(HEADER) -c $(SRC)
	gcc -o $(NAME)   *.o 

clean : 
	rm -f *.o

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re ft_ls