/*
** main.c for malloc in /home/terran_j/rendu/PSU_2014_malloc
**
** Made by Julie Terranova
** Login   <terran_j@epitech.net>
**
** Started on  Mon Jan 26 11:40:01 2015 Julie Terranova
** Last update Fri Jan 30 09:46:27 2015 moran-_d
*/

#include "all.h"

int	locate_stock(t_zone *ret)
{
  if ((ret->stock = sbrk(ret->size + sizeof(t_zone))) == (void *)(-1))
    return (-1);
  return (0);
}

t_zone *get_start()
{
  static void *addr = NULL;
  t_zone *tmp;

  if (addr == NULL)
    {
      if ((addr = sbrk(getpagesize())) == (void*) -1)
	return (NULL);
      tmp = (t_zone*)addr;
      tmp->next = NULL;
      tmp->prev = NULL;
      tmp->stock = NULL;
      tmp->isFree = 1;
      tmp->size = getpagesize() - sizeof(*tmp);
    }
  else
    tmp = (t_zone*)addr;

  return (tmp);
}

void	*malloc(size_t size)
{
  t_zone *ret;
  t_zone *tmp;

  if ((ret = get_start()) == NULL)
    return (NULL);
  if (size == 0)
    return ((void*)ret);

  while ((ret->isFree == 1 && (ret->size + sizeof(t_zone)) < size)
	 && ret->next != NULL)
    ret = ret->next;

  if (ret->isFree == 0)
    {
      while ((void*)ret + ret->size + size + (2 * sizeof(t_zone)) < sbrk(0))
	if (sbrk(getpagesize()) == (void*) -1)
	  return (NULL);
      ret->next = (t_zone*)((void*)ret + sizeof(t_zone) + ret->size);
      ret->next->prev = ret;
      ret->next->next = NULL;
      ret = ret->next;
    }
  else
    {
      tmp = ret->next;
      ret->next = (t_zone*)((void*)ret + sizeof(t_zone) + size);
      tmp->prev = ret->next;
      ret->next->prev = ret;
      ret->next->next = tmp;
    }
  ret->isFree = 0;
  ret->size = size;
  ret->stock = (void*)ret + sizeof(t_zone);

  return (ret->stock);
}
