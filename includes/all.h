/*
** all.h for malloc in /home/terran_j/rendu/PSU_2014_malloc
**
** Made by Julie Terranova
** Login   <terran_j@epitech.net>
**
** Started on  Fri Jan 30 10:58:51 2015 Julie Terranova
** Last update Fri Jan 30 10:58:54 2015 Julie Terranova
*/

#ifndef ALL_H_
# define ALL_H_

#include <stdlib.h>
#include <unistd.h>

typedef struct __attribute__((__packed__)) s_zone {
  struct s_zone *next;
  struct s_zone *prev;
  size_t	size;
  int		isFree;
}t_zone;

#endif
