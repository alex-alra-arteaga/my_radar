##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile that compiles
##

SRC =	$(wildcard ./lib/my/utils/*.c)\
			$(wildcard ./lib/my/graphical/*.c) \
			src/main.c \
			src/graphic/object/plane/plane.c \
			src/graphic/object/tower/tower.c \
			src/graphic/scene/scene.c \
			src/graphic/window/window.c \
			src/oop/object.c \
			src/system/system.c \
			src/system/clock/clock.c \
			src/system/manage_files/manage_files.c \
			src/system/timer/timer.c \
			src/graphic/object/quadtree/quadtree.c \
			src/system/system_utils.c \
			src/system/system_utils02.c \
			src/system/manage_files/manage_files_utils.c \
			src/system/event/event.c

OBJ = 	$(SRC:.c=.o)

NAME = my_radar

CFLAGS = -I ./includes/ -lcsfml-graphics -lcsfml-window -lcsfml-system -g3

CFLAGS2 = -lcsfml-audio -lm

all:	$(NAME)

$(NAME):	lib $(OBJ)
		gcc -g3 -o $(NAME) $(OBJ) $(CFLAGS) $(CFLAGS2)

lib:
	make -C ./lib/my/ -lmy

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
