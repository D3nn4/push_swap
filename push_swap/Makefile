NAME = push_swap

SRC = 	

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