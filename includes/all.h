/*
** inc.h for malloc in /home/terran_j/rendu/PSU_2014_malloc/includes
**
** Made by Julie Terranova
** Login   <terran_j@epitech.net>
**
** Started on  Mon Jan 26 11:37:30 2015 Julie Terranova
** Last update Wed Jan 28 18:33:31 2015 Julie Terranova
*/

#ifndef ALL_H_
# define ALL_H_

#include <stdlib.h>
#include <unistd.h>

#define PAGE_SIZE (4096)

typedef struct __attribute__((__packed__)) /*s_zone*/ {
  size_t	size;
  void		*stock;
  struct s_zone *prev;
  struct s_zone *next;
}t_zone;

#endif
