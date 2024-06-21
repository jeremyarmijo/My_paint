##
## EPITECH PROJECT, 2023
## makefile
## File description:
## pour my_printf
##
SRC	=	./src/loop_paints.c			\
		./src/main.c				\
		./src/init_game.c			\
		./src/destroy_all.c			\
		./src/handle_button.c		\
		./src/push_new_button.c		\
		./src/nb_of_pointers.c		\
		./src/init_menu.c			\
		./src/reset_menu.c			\
		./src/struct_action_button.c\
		./src/print_menu.c			\
		./src/button_management.c	\
		./src/init_all_button.c		\
		./src/options.c				\
		./src/set_menu.c			\
		./src/draw_tools.c			\
		./src/duplicate_string.c	\
		./src/pos_not_button.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_paint

COMP	=	-o my_paint

CPPFLAGS	=	-iquote ./include

CFLAGS	=	-Wall -Wextra

CSFMLFLAGS	=	-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

all: $(NAME)

$(NAME):	$(OBJ)
	$(CC) $(COMP) $(CFLAGS) $(CSFMLFLAGS) $(OBJ)

test:
	make re
	./$(NAME)

clean:
	$(RM) $(OBJ)
	$(RM) ./src/*#
	$(RM) ./src/*~
	$(RM) $(NAME)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
