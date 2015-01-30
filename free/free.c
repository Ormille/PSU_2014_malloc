/*
** main.c for malloc in /home/terran_j/rendu/PSU_2014_malloc
**
** Made by Julie Terranova
** Login   <terran_j@epitech.net>
**
** Started on  Mon Jan 26 11:41:48 2015 Julie Terranova
** Last update Fri Jan 30 11:12:26 2015 moran-_d
*/

#include "all.h"

void	free(void *ptr)
{
  t_zone *zone;

  if (ptr == NULL)
    return;
  zone = ptr - sizeof(*zone);
  if (zone->isFree != 0)
    return;
  zone->isFree = 1;
  if (zone->next->isFree == 1)
    {
      
    }
}
