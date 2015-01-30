/*
** main.c for test in /home/moran-_d/rendu/PSU_2014_malloc
** 
** Made by moran-_d
** Login   <moran-_d@epitech.net>
** 
** Started on  Fri Jan 30 12:24:44 2015 moran-_d
** Last update Fri Jan 30 15:31:54 2015 moran-_d
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
