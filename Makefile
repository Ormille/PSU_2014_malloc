##
## Makefile for malloc in /home/terran_j/rendu/PSU_2014_malloc
##
## Made by Julie Terranova
## Login   <terran_j@epitech.net>
##
## Started on  Mon Jan 26 10:27:45 2015 Julie Terranova
## Last update Wed Jan 28 18:35:50 2015 Julie Terranova
##

LIB_NAME    = libmy_malloc_$(HOSTTYPE).so

LIB_LINK    = libmy_malloc.so

LIB_SRC     = malloc/malloc.c \
	      realloc/realloc.c \
	      free/free.c \
	      show_alloc_mem/show_alloc_mem.c \

LIB_OBJ     = $(LIB_SRC:.c=.o)

CFLAGS      = -Wall -Werror -Wextra -I ./includes -fPIC

CCFLAGS    += -fPIC

CC	    = gcc

all:         $(LIB_NAME)

$(LIB_NAME): $(LIB_OBJ)
	     $(CC) -shared -o $(LIB_NAME) $(LIB_OBJ) $(CFLAGS)
	     ln -s $(LIB_NAME) $(LIB_LINK)
	     @echo "<===== Compilation OK =====>"

clean:
	     @rm -f $(LIB_OBJ)
	     @echo "<===== Clean =====>"

fclean:  clean
	 @rm -f $(LIB_NAME)
	 @rm -f $(LIB_LINK)
	 @echo "<===== FClean =====>"

re:      fclean all

.PHONY:	 all clean fclean re
