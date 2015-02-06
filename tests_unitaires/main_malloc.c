/*
** main_malloc.c for malloc in /home/terran_j/rendu/PSU_2014_malloc/tests_unitaires
**
** Made by Julie Terranova
** Login   <terran_j@epitech.net>
**
** Started on  Fri Jan 30 17:30:20 2015 Julie Terranova
** Last update Thu Feb  5 13:34:18 2015 Julie Terranova
*/

#include "all.h"
#include <stdio.h>

int	main()
{
  printf("Taille de la structure : %zu\n", sizeof(t_zone));
  show_alloc_and_free();

  char *a = malloc(15000);
  printf("Malloc de 15000:\n");
  show_alloc_and_free();

  char *c = malloc(10);
  char *d = malloc(10);
  char *d2 = malloc(1);
  printf("Plusieurs petits mallocs d'affilée:\n");
  show_alloc_and_free();

  char *b = malloc(getpagesize() + 10);
  printf("Malloc de plus d'une page:\n");
  show_alloc_and_free();

  char *e = malloc(-1);
  printf("Malloc de -1:\n");
  show_alloc_and_free();

  char *f = malloc(0);
  printf("Malloc de 0:\n");
  show_alloc_and_free();

  free(b);
  free(c);
  show_alloc_and_free();

  free(a);
  free(d);
  free(d2);
  show_alloc_and_free();

  free(e);
  free(f);
  show_alloc_and_free();

  return (0);
}
