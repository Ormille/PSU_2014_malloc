/*
** main.c for malloc in /home/terran_j/rendu/PSU_2014_malloc
**
** Made by Julie Terranova
** Login   <terran_j@epitech.net>
**
** Started on  Mon Jan 26 11:40:01 2015 Julie Terranova
** Last update Wed Jan 28 18:23:44 2015 Julie Terranova
*/

#include "all.h"

int	verif_page_size(t_zone *ret)
{
  if (PAGE_SIZE != 4096)
    return (-1);
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
  if (verif_page_size(&ret) == -1)
    return (NULL);


  // pour compiler:
  return 0;
}
