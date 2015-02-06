/*
** main_calloc.c for calloc in /home/terran_j/rendu/PSU_2014_malloc/tests_unitaires
**
** Made by Julie Terranova
** Login   <terran_j@epitech.net>
**
** Started on  Fri Jan 30 17:30:56 2015 Julie Terranova
** Last update Thu Feb  5 21:44:56 2015 Julie Terranova
*/

#include <stdio.h>
#include "all.h"

int     main()
{
  printf("Taille de la structure : %zu\n", sizeof(t_zone));
  show_alloc_and_free();

  char *a = calloc(5, 15000);
  printf("Calloc de 5 elem de 15000:\n");
  show_alloc_and_free();

  char *c = calloc(2, 10);
  char *d = calloc(-1, 10);
  char *d2 = calloc(0, 1);
  printf("Plusieurs petits callocs d'affilée(2, -1, 0):\n");
  show_alloc_and_free();

  char *b = calloc(25, getpagesize() + 10);
  printf("Calloc de 25 elem de plus d'une page:\n");
  show_alloc_and_free();

  char *e = calloc(1, -1);
  printf("Calloc de -1:\n");
  show_alloc_and_free();

  char *f = calloc(1, 0);
  printf("Calloc de 0:\n");
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
