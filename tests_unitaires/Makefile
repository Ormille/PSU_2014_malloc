##
## Makefile for tests in /home/terran_j/rendu/PSU_2014_malloc/tests_unitaires
##
## Made by Julie Terranova
## Login   <terran_j@epitech.net>
##
## Started on  Fri Jan 30 16:52:21 2015 Julie Terranova
## Last update Sat Feb  7 17:32:56 2015 Julie Terranova
##

CC	=	gcc

CFLAGS	+=	-Wall -Wextra
CFLAGS	+=	-I .././includes

RM	=	rm -f

NAME_MALLOC  =	test_malloc_free

NAME_REALLOC =	test_realloc

NAME_CALLOC  =	test_calloc

SRC_MALLOC   =	main_malloc_free.c \
		../malloc/malloc.c \
		../realloc/realloc.c \
		../calloc/calloc.c \
		../free/free.c \
		../show_alloc_mem/show_alloc_mem.c \
		show_alloc_and_free.c

SRC_REALLOC  =	main_realloc.c \
		../malloc/malloc.c \
		../realloc/realloc.c \
		../calloc/calloc.c \
		../free/free.c \
		../show_alloc_mem/show_alloc_mem.c \
		show_alloc_and_free.c

SRC_CALLOC   =  main_calloc.c \
		../malloc/malloc.c \
		../realloc/realloc.c \
		../calloc/calloc.c \
		../free/free.c \
		../show_alloc_mem/show_alloc_mem.c \
		show_alloc_and_free.c

OBJ_MALLOC   =	$(SRC_MALLOC:.c=.o)

OBJ_REALLOC  =	$(SRC_REALLOC:.c=.o)

OBJ_CALLOC   =	$(SRC_CALLOC:.c=.o)

all:    $(NAME_MALLOC) $(NAME_REALLOC) $(NAME_CALLOC)

$(NAME_MALLOC): $(OBJ_MALLOC)
	$(CC) $(OBJ_MALLOC) -o $(NAME_MALLOC) $(LDFLAGS)

$(NAME_REALLOC): $(OBJ_REALLOC)
	$(CC) $(OBJ_REALLOC) -o $(NAME_REALLOC) $(LDFLAGS)

$(NAME_CALLOC): $(OBJ_CALLOC)
	$(CC) $(OBJ_CALLOC) -o $(NAME_CALLOC) $(LDFLAGS)

clean:
	$(RM) $(OBJ_MALLOC)
	$(RM) $(OBJ_REALLOC)
	$(RM) $(OBJ_CALLOC)

fclean: clean
	$(RM) $(NAME_MALLOC)
	$(RM) $(NAME_REALLOC)
	$(RM) $(NAME_CALLOC)

re:     fclean all

.PHONY:  all clean fclean re
