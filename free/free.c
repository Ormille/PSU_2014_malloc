/*
** main.c for malloc in /home/terran_j/rendu/PSU_2014_malloc
**
** Made by Julie Terranova
** Login   <terran_j@epitech.net>
**
** Started on  Mon Jan 26 11:41:48 2015 Julie Terranova
** Last update Wed Feb  4 12:23:58 2015 Julie Terranova
*/

#include "all.h"
#include <pthread.h>

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

void	free(void *ptr)
{
  t_zone *zone;

  pthread_mutex_lock(&freez);
  if (ptr == NULL || ptr + sizeof(t_zone) >= sbrk(0))
    {
      pthread_mutex_unlock(&freez);
      return;
    }
  zone = (t_zone*)(ptr - sizeof(t_zone));
  if (zone->isFree != 0)
    {
      pthread_mutex_unlock(&freez);
      return;
    }
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
  pthread_mutex_unlock(&freez);
}
