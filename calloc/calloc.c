/*
** calloc.c for calloc in /home/moran-_d/rendu/PSU_2014_malloc/calloc
** 
** Made by moran-_d
** Login   <moran-_d@epitech.net>
** 
** Started on  Fri Jan 30 16:46:12 2015 moran-_d
** Last update Fri Jan 30 16:48:30 2015 moran-_d
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
