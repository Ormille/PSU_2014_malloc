/*
** main_malloc.c for malloc in /home/terran_j/rendu/PSU_2014_malloc/tests_unitaires
**
** Made by Julie Terranova
** Login   <terran_j@epitech.net>
**
** Started on  Fri Jan 30 17:30:20 2015 Julie Terranova
** Last update Wed Feb  4 16:47:06 2015 Julie Terranova
*/

#include "all.h"
#include <stdio.h>

int	main()
{
  // verifier le retour comparé au vrai malloc (pour les 4)
  // avec malloc(-1) malloc(0) malloc(getpagesize() - t_zone) malloc(getpagesize() - (2 * t_zone) - 1) malloc(1)

  printf("Taille de la structure : %zu\n", sizeof(t_zone));
  show_alloc_and_free();

  char *a = malloc(15000);
  printf("Malloc de 15000:\n");
  show_alloc_and_free();

  char *c = malloc(10);
  char *d = malloc(10);
  char *e = malloc(10);
  char *f = malloc(10);
  printf("Plusieurs petits mallocs d'affilée:\n");
  show_alloc_and_free();

  char *b = malloc(getpagesize() + 10);
  printf("Malloc de plus d'une page:\n");
  show_alloc_and_free();

  free(b);
  free(c);
  show_alloc_and_free();

  free(a);
  free(d);
  free(e);
  free(f);
  show_alloc_and_free();


  return (0);
}
