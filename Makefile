##
## EPITECH PROJECT, 2022
## makefile.c
## File description:
## a makefile who that compile my lib/my
##


SRC = 		main.c

OBJ =   $(SRC:.c=.o)

CFLAGS = -I./include -W -Wall -Wextra -Wshadow

NAME = my_hunter

# LIB = lib/libmy.a

 all: $(NAME)

# $(NAME):   $(OBJ)
# 	cd lib/ && make
# 	gcc $(OBJ) -L./lib/ -lmy -o $(NAME)

# clean:
# 	cd lib/ && make clean
# 	rm -f $(OBJ)

# val:
# 	gcc $(SRC) -g -o a.out -I./include
# 	valgrind ./a.out -R

# delval:
# 	rm -f vgcore*
# 	rm -f a.out

# fclean: clean delval
# 	cd lib/ && make fclean
# 	rm -f $(NAME)

# re:    fclean all
# 	cd lib/ && make re
# 	rm -f $(OBJ)


$(NAME):   $(OBJ)
	gcc -lcsfml-window -lcsfml-graphics -lcsfml-system -lcsfml-audio $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

val:
	gcc $(SRC) -g -o a.out -I./include
	valgrind ./a.out -R

delval:
	rm -f vgcore*
	rm -f a.out

fclean: clean delval
	rm -f $(NAME)

re:    fclean all
	rm -f $(OBJ)
