/*
** main.c for malloc in /home/terran_j/rendu/PSU_2014_malloc
**
** Made by Julie Terranova
** Login   <terran_j@epitech.net>
**
** Started on  Mon Jan 26 11:41:48 2015 Julie Terranova
** Last update Fri Feb  6 13:28:44 2015 moran-_d
*/

#include <pthread.h>
#include "all.h"

void try_merge_block(t_zone *zone)
{
  if (zone->next != NULL && zone->next->isFree == 1)
    {
      zone->size += zone->next->size + sizeof(t_zone);
      if (zone->next->next != NULL)
	zone->next->next->prev = zone;
      zone->next = zone->next->next;
    }
}

void	___free(void *ptr)
{
  t_zone *zone;

  if (ptr == NULL || ptr + sizeof(t_zone) >= sbrk(0)
      || ((zone = (t_zone*)(ptr - sizeof(t_zone))))->isFree != 0)
    return;
  zone->isFree = 1;
  try_merge_block(zone);
  if (zone->prev != NULL && zone->prev->isFree == 1)
    try_merge_block((zone = zone->prev));
  if (zone->next == NULL)
    {
      if (zone->prev != NULL)
	zone->prev->next = NULL;
      while ((void*)zone < sbrk(0) - getpagesize())
	sbrk(getpagesize() * -1);
    }
}

void	free(void *ptr)
{
  pthread_mutex_lock(getMutex());
  ___free(ptr);
  pthread_mutex_unlock(getMutex());
}
