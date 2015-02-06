/*
** main_realloc.c for realloc in /home/terran_j/rendu/PSU_2014_malloc/tests_unitaires
**
** Made by Julie Terranova
** Login   <terran_j@epitech.net>
**
** Started on  Fri Jan 30 17:30:45 2015 Julie Terranova
** Last update Thu Feb  5 21:57:13 2015 Julie Terranova
*/

#include <stdio.h>
#include "all.h"

int     main()
{
  printf("Taille de la structure : %zu\n", sizeof(t_zone));
  show_alloc_and_free();

  char *a = malloc(10);
  a = realloc(a, 15000);
  printf("Realloc de 15000:\n");
  show_alloc_and_free();

  char *c = malloc(10);
  c = realloc(c, 10);
  char *d = malloc(10);
  d = realloc(d, 10);
  char *d2 = malloc(400);
  d2 = realloc(d2, 1);
  printf("Plusieurs petits reallocs d'affilée:\n");
  show_alloc_and_free();

  char *b = malloc(10);
  b = realloc(b, getpagesize() + 10);
  printf("Realloc de plus d'une page:\n");
  show_alloc_and_free();

  char *e = malloc(10);
  e = realloc(e, -1);
  printf("Realloc de -1:\n");
  show_alloc_and_free();

  char *f = malloc(10);
  f = realloc(f, 0);
  printf("Realloc de 0:\n");
  show_alloc_and_free();

  char *f2 = malloc(10);
  f2 = realloc(NULL, 150);
  printf("Realloc de NULL:\n");
  show_alloc_and_free();

  free(NULL);
  free(f2);
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
