/*
** show_alloc_and_free.c for show in /home/terran_j/rendu/PSU_2014_malloc/tests_unitaires
**
** Made by Julie Terranova
** Login   <terran_j@epitech.net>
**
** Started on  Sat Jan 31 14:07:03 2015 Julie Terranova
** Last update Fri Feb  6 12:55:20 2015 moran-_d
*/

#include <stdio.h>
#include "all.h"

void    show_alloc_and_free()
{
  t_zone *zone;

  zone = getStart();
  printf("break: %p\n", sbrk(0));
  while (zone != NULL)
    {
      if (zone->isFree == 0)
        printf("%p - %p : %zu bytes\n",
               (void*)zone + sizeof(t_zone),
               (void*)zone + sizeof(t_zone) + zone->size,
               zone->size);
      else if (zone->isFree == 1)
        printf("FREE'D BLOCK : %p - %p : %zu bytes\n",
               (void*)zone + sizeof(t_zone),
               (void*)zone + sizeof(t_zone) + zone->size,
               zone->size);
      zone = zone->next;
    }
}
