/*
** show_alloc_mem.c for show_alloc_mem in /home/terran_j/rendu/PSU_2014_malloc
**
** Made by Julie Terranova
** Login   <terran_j@epitech.net>
**
** Started on  Wed Jan 28 16:40:51 2015 Julie Terranova
** Last update Fri Feb  6 12:55:31 2015 moran-_d
*/

#include <stdio.h>
#include "all.h"

void	show_alloc_mem()
{
  t_zone *zone;

  zone = getStart();
  printf("break: %p\n", sbrk(0));
  while (zone != NULL)
    {
      printf("%p - %p : %zu bytes\n",
	     (void*)zone + sizeof(t_zone),
	     (void*)zone + sizeof(t_zone) + zone->size,
	     zone->size);
      zone = zone->next;
    }
}
