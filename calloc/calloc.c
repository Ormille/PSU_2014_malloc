/*
** calloc.c for calloc in /home/moran-_d/rendu/PSU_2014_malloc/calloc
**
** Made by moran-_d
** Login   <moran-_d@epitech.net>
**
** Started on  Fri Jan 30 16:46:12 2015 moran-_d
** Last update Wed Feb  4 17:29:09 2015 Julie Terranova
*/

#include <string.h>
#include "all.h"
#include <pthread.h>
#include <errno.h>

void *calloc(size_t nelem, size_t elsize)
{
  void *tmp;

  if (nelem == 0 || elsize == 0)
    {
      errno = ENOMEM;
      return (NULL);
    }
  tmp = malloc(nelem * elsize);
  pthread_mutex_lock(&malls);
  memset(tmp, 0, nelem * elsize);
  pthread_mutex_unlock(&malls);
  return (tmp);
}
