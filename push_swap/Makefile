NAME = push_swap

SRC = 	src/push_swap.c \
		src/main.c \
		src/sort/data.c \
		src/sort/list_cmd.c \
		src/sort/sorting.c \
		src/sort/min.c \
		src/sort/max.c \
		src/sort/free_cmd.c \
		src/sort/print_cmd.c 

SRC_LIB =	../lib_ps/src/instruction/tab_function.c \
	 		../lib_ps/src/instruction/swap.c \
		  	../lib_ps/src/instruction/push.c \
	 		../lib_ps/src/instruction/rotate.c \
	  		../lib_ps/src/instruction/reverse_rotate.c \
	  		../lib_ps/src/instruction/cmd.c \
	  		../lib_ps/src/interpreter/print.c \
	  		../lib_ps/src/interpreter/get_pile.c \
	 		../lib_ps/src/interpreter/free.c \
	  		../lib_ps/src/interpreter/stacks.c \
	  		../lib_ps/src/interpreter/checkResult.c

HEADER_FLAG = 	-I../lib_ps/include \
			-Iinclude/

OBJDIR = build

all : $(NAME)

$(NAME) : 
	gcc -ggdb3 -Wall -Wextra $(HEADER_FLAG) -c $(SRC) $(SRC_LIB)
	gcc -o $(NAME)   *.o 

clean : 
	rm -f *.o

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re ft_ls