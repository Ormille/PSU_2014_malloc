/*
** inc.h for malloc in /home/terran_j/rendu/PSU_2014_malloc/includes
**
** Made by Julie Terranova
** Login   <terran_j@epitech.net>
**
** Started on  Mon Jan 26 11:37:30 2015 Julie Terranova
** Last update Thu Jan 29 17:51:31 2015 moran-_d
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
  void		*stock;
}t_zone;

#endif
