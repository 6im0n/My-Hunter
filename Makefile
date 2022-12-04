##
## EPITECH PROJECT, 2022
## makefile.c
## File description:
## a makefile who that compile my lib/my
##


SRC = 		lib/int_fnct.c \
			lib/score_to_str.c\
			lib/str_fnct.c \
			lib/my_getnbr.c\
			lib/my_strcmp.c\
			main.c \
			helper_handler.c\
			game.c \
			game_h_score.c\
			game_init.c \
			game_destroy.c \
			game_monster.c \
			game_handle_score.c \
			game_cursor.c \
			game_background.c \
			init_menu.c \
			load_menu.c \
			game_init_score.c\
			init_menu_text.c\
			game_over.c\
			menu.c

OBJ =   $(SRC:.c=.o)

CFLAGS = -I./include -W -Wall -Wextra -Wshadow
CSFMLFLAGS = -lcsfml-window -lcsfml-graphics -lcsfml-system -lcsfml-audio

NAME = my_hunter

# LIB = lib/libmy.a

 all: $(NAME)

# $(NAME):   $(OBJ)
# 	cd lib/ && make
# 	gcc $(CSFMLFLAGS) $(OBJ) -L./lib/ -lmy -o $(NAME)

# clean:
# 	cd lib/ && make clean
# 	rm -f $(OBJ)

# val:
# 	gcc $(CSFMLFLAGS) $(SRC) -g -o a.out -I./include
# 	valgrind ./a.out -R

# delval:
# 	rm -f vgcore*
# 	rm -f a.out

# fclean: clean delval
# 	cd lib/ && make fclean
# 	rm -f $(NAME)

# re:    fclean all
# 	cd lib/ && make re
# # 	rm -f $(OBJ)


$(NAME):   $(OBJ)
	gcc -g3 $(CSFMLFLAGS) -lm $(OBJ) -o $(NAME)
	touch -f save_score

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
