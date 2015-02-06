/*
** main.c for main in /home/terran_j/rendu/PSU_2014_malloc
**
** Made by Julie Terranova
** Login   <terran_j@epitech.net>
**
** Started on  Fri Jan 30 17:38:17 2015 Julie Terranova
** Last update Sat Jan 31 16:00:42 2015 moran-_d
*/

#include <stdio.h>
#include "all.h"

int main()
{
  char*z;

  free(z);

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

  a = malloc(400);
  show_alloc_mem();
  free(a);

  show_alloc_mem();
}
