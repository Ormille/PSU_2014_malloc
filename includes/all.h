/*
** inc.h for malloc in /home/terran_j/rendu/PSU_2014_malloc/includes
**
** Made by Julie Terranova
** Login   <terran_j@epitech.net>
**
** Started on  Mon Jan 26 11:37:30 2015 Julie Terranova
** Last update Mon Jan 26 18:08:14 2015 Julie Terranova
*/

#ifndef ALL_H_
# define ALL_H_

#include <stdlib.h>

typedef struct s_zone {
  size_t	size;
  int		ptr;
  struct s_zone *prev;
  struct s_zone *next;
}t_zone;

#endif
