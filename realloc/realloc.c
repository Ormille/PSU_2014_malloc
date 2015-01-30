/*
** main.c for malloc in /home/terran_j/rendu/PSU_2014_malloc
**
** Made by Julie Terranova
** Login   <terran_j@epitech.net>
**
** Started on  Mon Jan 26 11:40:51 2015 Julie Terranova
** Last update Fri Jan 30 16:24:24 2015 moran-_d
*/

#include <string.h>
#include <stdio.h>
#include "all.h"

void	*realloc(void *ptr, size_t size)
{
  t_zone *zone;
  void *new;

  new = ptr;
  if (size == 0)
    return (sbrk(0));
  if (ptr != NULL)
    {
      zone = (t_zone*)(ptr - sizeof(t_zone));
      if (size <= zone->size)
	zone->size = size;
      else
	{
	  new = malloc(size);
	  memmove(new, ptr, zone->size);
	  free(ptr);
	}
    }
  else
    new = malloc(size);
  return (new);
}
