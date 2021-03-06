/*
** main.c for malloc in /home/terran_j/rendu/PSU_2014_malloc
**
** Made by Julie Terranova
** Login   <terran_j@epitech.net>
**
** Started on  Mon Jan 26 11:40:51 2015 Julie Terranova
** Last update Fri Feb  6 13:24:34 2015 moran-_d
*/

#include <string.h>
#include <limits.h>
#include "all.h"

void	split_block(t_zone *zone, size_t size)
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

void	merge_and_split(t_zone *zone, size_t size)
{
  zone->size += zone->next->size + sizeof(t_zone);
  if (zone->next->next != NULL)
    zone->next->next->prev = zone;
  zone->next = zone->next->next;
  split_block(zone, size);
}

void	*realloc(void *ptr, size_t size)
{
  t_zone *zone;
  void *new;

  if (size <= 0 || size >= INT_MAX)
    return (sbrk(0));
  if (ptr == NULL)
    return (malloc(size));
  pthread_mutex_lock(getMutex());
  zone = (t_zone*)(ptr - sizeof(t_zone));
  new = ptr;
  if (size + sizeof(t_zone) <= zone->size)
    split_block(zone, size);
  else if (zone->next != NULL && zone->isFree == 1 &&
	   zone->size + zone->next->size > size)
    merge_and_split(zone, size);
  else
    {
      new = ___malloc(size);
      if (new != NULL)
	memmove(new, ptr, zone->size);
      ___free(ptr);
    }
  pthread_mutex_unlock(getMutex());
  return (new);
}
