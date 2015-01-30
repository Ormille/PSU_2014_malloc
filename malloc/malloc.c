/*
** main.c for malloc in /home/terran_j/rendu/PSU_2014_malloc
**
** Made by Julie Terranova
** Login   <terran_j@epitech.net>
**
** Started on  Mon Jan 26 11:40:01 2015 Julie Terranova
** Last update Fri Jan 30 16:28:53 2015 moran-_d
*/

#include "all.h"

t_zone *get_start()
{
  static void *addr = NULL;
  t_zone *tmp;

  if (addr == NULL || addr + sizeof(t_zone) > sbrk(0))
    {
      if ((addr = sbrk(getpagesize())) == (void*) -1)
	return (NULL);
      tmp = (t_zone*)addr;
      tmp->next = NULL;
      tmp->prev = NULL;
      tmp->isFree = 1;
      tmp->size = getpagesize() - sizeof(t_zone);
    }
  else
    tmp = (t_zone*)addr;
  return (tmp);
}

t_zone	*pass_by_me(t_zone *ret, size_t size)
{
  if (ret->isFree == 0)
    {
      while ((void*)ret + ret->size + size
	     + (2 * sizeof(t_zone)) >= sbrk(0))
	if (sbrk(getpagesize()) == (void*) -1)
	  return (NULL);
      ret->next = (t_zone*)((void*)ret + sizeof(t_zone) + ret->size);
      ret->next->prev = ret;
      ret->next->next = NULL;
      ret = ret->next;
    }
  else if (ret->next == NULL)
    {
      while ((void*)ret + sizeof(t_zone) + size >= sbrk(0))
	if (sbrk(getpagesize()) == (void*) -1)
	  return (NULL);
    }
  return (ret);
}

#include <stdio.h>
void	*malloc(size_t size)
{
  t_zone *ret;

  //  printf("MALLOC ENTER. SIZE = %zu\n", size);
  //  show_alloc_mem();

  if ((ret = get_start()) == NULL)
    return (NULL);
  if (size == 0)
    return ((void*)ret);
  while (ret->next != NULL &&
	 (ret->isFree == 0 ||
	  (ret->isFree == 1 && (ret->size < sizeof(t_zone)) + size)))
    ret = ret->next;
  if ((ret = pass_by_me(ret, size)) == NULL)
    return (NULL);
  ret->isFree = 0;
  ret->size = size;

  //  printf("MALLOC EXIT. Addr = %p\n", ((void*)ret + sizeof(t_zone)));
  //  show_alloc_mem();

  return ((void*)ret + sizeof(t_zone));
}
