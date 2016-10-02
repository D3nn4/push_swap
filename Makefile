NAME = make_both

all :  
	cd checker; make 
	cd push_swap; make

clean : 
	cd checker; make clean
	cd push_swap; make clean

fclean : clean
	cd checker; make fclean
	cd push_swap; make fclean

re : fclean all

