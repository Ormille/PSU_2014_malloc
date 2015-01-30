/*
** main.c for malloc in /home/terran_j/rendu/PSU_2014_malloc
**
** Made by Julie Terranova
** Login   <terran_j@epitech.net>
**
** Started on  Mon Jan 26 11:40:51 2015 Julie Terranova
** Last update Fri Jan 30 17:48:22 2015 moran-_d
*/

#include <string.h>
#include "all.h"

void	if_low_enough(t_zone *zone, size_t size)
{
  t_zone *nzone;

  nzone = (t_zone*)((void*)zone + sizeof(t_zone) + size);
  nzone->size = (zone->size - sizeof(t_zone) - size);
  zone->size = size;
  nzone->isFree = 1;
  nzone->next = zone->next;
  if (nzone->next != NULL)
    nzone->next->prev = nzone;
  nzone->prev = zone;
  zone->next = nzone;
}

void	*realloc(void *ptr, size_t size)
{
  t_zone *zone;
  void *new;

  if (size == 0)
    return (sbrk(0));
  if (ptr == NULL)
    return (malloc(size));
  zone = (t_zone*)(ptr - sizeof(t_zone));
  if (size + sizeof(t_zone) <= zone->size)
    if_low_enough(zone, size);
  else
    {
      new = malloc(size);
      memmove(new, ptr, zone->size);
      free(ptr);
    }

  return (new);
}
