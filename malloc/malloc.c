/*
** main.c for malloc in /home/terran_j/rendu/PSU_2014_malloc
**
** Made by Julie Terranova
** Login   <terran_j@epitech.net>
**
** Started on  Mon Jan 26 11:40:01 2015 Julie Terranova
** Last update Thu Jan 29 12:44:34 2015 Julie Terranova
*/

#include "all.h"

void	do_some_space(t_zone *ret)
{

}

int	get_page_size(t_zone *ret)
{
  ret->page_size = getpagesize();
  if ((ret->stock = sbrk(ret->size + sizeof(t_zone))) == (void *)(-1))
    return (-1);
  return (0);
}

void	*malloc(size_t size)
{
  t_zone ret;

  ret.size = size;
  if (size == 0)
    return (sbrk(0));
  if (get_page_size(&ret) == -1)
    return (NULL);

  //  while (ret != NULL)
    //  ret = ret->next;

  ret = do_some_space(&ret);

  // moment d'utiliser mon stock.

  // pour compiler:
  return 0;
}
