/*
** calloc.c for calloc in /home/terran_j/rendu/PSU_2014_malloc
**
** Made by Julie Terranova
** Login   <terran_j@epitech.net>
**
** Started on  Fri Jan 30 17:37:57 2015 Julie Terranova
** Last update Fri Jan 30 17:38:00 2015 Julie Terranova
*/

#include <string.h>
#include "all.h"

void *calloc(size_t nelem, size_t elsize)
{
  void *tmp;

  tmp = malloc(nelem * elsize);
  memset(tmp, 0, nelem * elsize);
  return (tmp);
}
