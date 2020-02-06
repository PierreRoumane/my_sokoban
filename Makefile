##
## EPITECH PROJECT, 2019
## CPool_lib_2019
## File description:
## Makefile
##

SRC	=	src/main.c \
		src/get_read.c \
		src/my_sokoban.c \
		src/player.c \
		src/error_handling.c \
		src/misc/get_base.c \
		src/misc/get_player.c \
		src/misc/check_map.c

NAME	=	my_sokoban

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-W -Wall -Wextra -I include/ -g

LDFLAGS	=	-L lib/my/ -lmy

RM 		=	@find . \( -name "*.o" -o -name "*~" \) -delete

all:	lib_compile $(NAME)

lib_compile:
	@make -C lib/my/ --no-print-directory

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) -lncurses $(LDFLAGS)
	$(RM)

clean:
	@make clean -C lib/my/ --no-print-directory
	$(RM)

fclean: clean
	$(RM)
	@make fclean -C lib/my/ --no-print-directory

re:	fclean all
