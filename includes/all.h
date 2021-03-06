/*
** all.h for malloc in /home/terran_j/rendu/PSU_2014_malloc
**
** Made by Julie Terranova
** Login   <terran_j@epitech.net>
**
** Started on  Fri Jan 30 10:58:51 2015 Julie Terranova
** Last update Fri Feb  6 13:19:55 2015 moran-_d
*/

#ifndef ALL_H_
# define ALL_H_

#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

typedef struct __attribute__((__packed__)) s_zone {
  struct s_zone *next;
  struct s_zone *prev;
  size_t	size;
  int		isFree;
}t_zone;

pthread_mutex_t *getMutex();
t_zone	*getStart();
void    *___malloc(size_t size);
void    *malloc(size_t size);
void    ___free(void *ptr);
void    free(void *ptr);
void    *realloc(void *ptr, size_t size);
void    show_alloc_mem();
void    show_alloc_and_free();

#endif
