/*
** main.c for malloc in /home/terran_j/rendu/PSU_2014_malloc
**
** Made by Julie Terranova
** Login   <terran_j@epitech.net>
**
** Started on  Mon Jan 26 11:40:51 2015 Julie Terranova
** Last update Mon Jan 26 14:37:46 2015 Julie Terranova
*/

#include "all.h"

void	*realloc(void *ptr, size_t size)
{
  if (ptr == NULL || size == 0)
    return NULL;


  // juste pr compiler:
  return 0;
}
