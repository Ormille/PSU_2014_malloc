/*
** main.c for malloc in /home/terran_j/rendu/PSU_2014_malloc
**
** Made by Julie Terranova
** Login   <terran_j@epitech.net>
**
** Started on  Mon Jan 26 11:40:01 2015 Julie Terranova
** Last update Fri Jan 30 11:36:39 2015 moran-_d
*/

#include "all.h"

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
      tmp->isFree = 1;
      tmp->size = getpagesize() - sizeof(*tmp);
    }
  else
    tmp = (t_zone*)addr;
  return (tmp);
}

int	pass_by_me(t_zone **ret, size_t size, t_zone *tmp)
{
  if ((*ret)->isFree == 0)
    {
      while ((void*)(*ret) + (*ret)->size + size
	     + (2 * sizeof(*ret)) >= sbrk(0))
	if (sbrk(getpagesize()) == (void*) -1)
	  return (-1);
      (*ret)->next = (t_zone*)((void*)(*ret) + sizeof(*ret) + (*ret)->size);
      (*ret)->next->prev = (*ret);
      (*ret)->next->next = NULL;
      (*ret) = (*ret)->next;
    }
  else
    {
      if ((*ret)->next == NULL)
	while ((void*)(*ret) + sizeof(*ret) + size >= sbrk(0))
	  if (sbrk(getpagesize()) == (void*) -1)
	    return (-1);
      tmp = (*ret)->next;
      (*ret)->next = (t_zone*)((void*)(*ret) + sizeof(*ret) + size);
      if (tmp != NULL)
	tmp->prev = (*ret)->next;
      (*ret)->next->prev = (*ret);
      (*ret)->next->next = tmp;
    }
  return (0);
}

void	*malloc(size_t size)
{
  t_zone *ret;

  if ((ret = get_start()) == NULL)
    return (NULL);
  if (size == 0)
    return ((void*)ret);
  while (ret->next != NULL &&
	 (ret->isFree == 0 ||
	  (ret->isFree == 1 && (ret->size + sizeof(*ret)) > size)))
    ret = ret->next;
  if (pass_by_me(&ret, size, NULL) == -1)
    return (NULL);
  ret->isFree = 0;
  ret->size = size;
  return ((void*)ret + sizeof(*ret));
}
