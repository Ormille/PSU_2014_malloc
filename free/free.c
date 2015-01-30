/*
** main.c for malloc in /home/terran_j/rendu/PSU_2014_malloc
**
** Made by Julie Terranova
** Login   <terran_j@epitech.net>
**
** Started on  Mon Jan 26 11:41:48 2015 Julie Terranova
** Last update Fri Jan 30 12:04:03 2015 moran-_d
*/

#include "all.h"

void merge_block(t_zone *zone)
{
  if (zone->next != NULL && zone->next->isFree == 1)
    {
      zone->size += zone->next->size + sizeof(*zone);
      if (zone->next->next != NULL)
	zone->next->next->prev = zone;
      zone->next = zone->next->next;
    }
}

void	free(void *ptr)
{
  //  t_zone *zone;

  return;
  if (ptr == NULL)
    return;
  /*
  zone = (t_zone*)(ptr - sizeof(*zone));
  if (zone->isFree != 0)
    return;
  zone->isFree = 1;
  merge_block(zone);
  if (zone->prev != NULL && zone->prev->isFree == 1)
    {
      zone = zone->prev;
      merge_block(zone);
    }
  if (zone->next == NULL)
    {
      if (zone->prev != NULL)
	zone->prev->next = NULL;
      while ((void*)(zone->prev) + sizeof(*zone) > sbrk(0))
	sbrk(getpagesize() * -1);
    }
  */
}

