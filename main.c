/*
** main.c for main in /home/terran_j/rendu/PSU_2014_malloc
**
** Made by Julie Terranova
** Login   <terran_j@epitech.net>
**
** Started on  Fri Jan 30 17:38:17 2015 Julie Terranova
** Last update Fri Jan 30 17:38:20 2015 Julie Terranova
*/

#include <stdio.h>
#include "all.h"

int main()
{
  printf("SIZE : %zu\n", sizeof(t_zone));
  show_alloc_mem();

  char *a = malloc(15000);

  char *c = malloc(10);
  char *d = malloc(10);
  char *e = malloc(10);
  char *f = malloc(10);
  char *b = malloc(getpagesize() + 10);

  show_alloc_mem();

  free(b);
  free(c);

  show_alloc_mem();

  free(a);
  free(d);
  free(e);
  free(f);

  show_alloc_mem();
}
