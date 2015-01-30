/*
** show_alloc_mem.c for show_alloc_mem in /home/terran_j/rendu/PSU_2014_malloc
**
** Made by Julie Terranova
** Login   <terran_j@epitech.net>
**
** Started on  Wed Jan 28 16:40:51 2015 Julie Terranova
** Last update Fri Jan 30 12:51:28 2015 Julie Terranova
*/

#include "all.h"
#include <stdio.h>

void	show_alloc_mem()
{
  t_zone *zone;

  zone = get_start();
  printf("break: %p\n", sbrk(0));
  while (zone != NULL)
    {
      if (zone->next != NULL)
	printf("%p - %p : %zu bytes\n", zone + sizeof(zone), zone + sizeof(zone) + zone->size, zone->size);
      /* else */
      /* 	{ */
      /* 	  if ((zone = sbrk(zone->size)) == (void *)(-1)) */
      /* 	    printf("%p - %p : %zu bytes\n", zone, NULL, zone->size); */
      /* 	  else */
      /* 	    printf("%p - %p : %zu bytes\n", zone, zone, zone->size); */
      /* 	} */
      zone = zone->next;
    }
}
