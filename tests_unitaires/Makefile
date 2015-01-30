##
## Makefile for tests in /home/terran_j/rendu/PSU_2014_malloc/tests_unitaires
##
## Made by Julie Terranova
## Login   <terran_j@epitech.net>
##
## Started on  Fri Jan 30 16:52:21 2015 Julie Terranova
## Last update Fri Jan 30 17:43:35 2015 Julie Terranova
##

CC =    gcc

CFLAGS +=-Wall -Wextra -Werror
CFLAGS +=-I .././includes

RM =    rm -f

NAME_MALLOC = test_malloc

NAME_REALLOC = test_realloc

NAME_CALLOC = test_calloc

NAME_FREE = test_free

SRC_MALLOC =  ../malloc/malloc.c \
		main_malloc.c

SRC_REALLOC =  ../realloc/realloc.c \
		main_realloc.c

SRC_CALLOC =  ../calloc/calloc.c \
		main_calloc.c

SRC_FREE =  ../free/free.c \
		main_free.c

OBJ_MALLOC =  $(SRC_MALLOC:.c=.o)

OBJ_REALLOC =  $(SRC_REALLOC:.c=.o)

OBJ_CALLOC =  $(SRC_CALLOC:.c=.o)

OBJ_FREE =  $(SRC_FREE:.c=.o)

all:    $(NAME_MALLOC) $(NAME_REALLOC) $(NAME_CALLOC) $(NAME_FREE)

$(NAME_MALLOC):$(OBJ_MALLOC)
	$(CC) $(OBJ_MALLOC) -o $(NAME_MALLOC) $(LDFLAGS)

$(NAME_REALLOC):$(OBJ_REALLOC)
	$(CC) $(OBJ_REALLOC) -o $(NAME_REALLOC) $(LDFLAGS)

$(NAME_CALLOC):$(OBJ_CALLOC)
	$(CC) $(OBJ_CALLOC) -o $(NAME_CALLOC) $(LDFLAGS)

$(NAME_FREE):$(OBJ_FREE)
	$(CC) $(OBJ_FREE) -o $(NAME_FREE) $(LDFLAGS)

clean:
	$(RM) $(OBJ_MALLOC)
	$(RM) $(OBJ_REALLOC)
	$(RM) $(OBJ_CALLOC)
	$(RM) $(OBJ_FREE)

fclean: clean
	$(RM) $(NAME_MALLOC)
	$(RM) $(NAME_REALLOC)
	$(RM) $(NAME_CALLOC)
	$(RM) $(NAME_FREE)

re:     fclean all

.PHONY:  all clean fclean re
