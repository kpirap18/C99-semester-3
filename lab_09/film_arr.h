#ifndef FILM_ARR_H
#define FILM_ARR_H

#include "film.h"
#include "my_main.h"

int f_create(FILE *f, film_r **pp_films, int *n_films, char const *field);

int f_count(FILE *f, int *n);

int f_read(FILE *f, film_r *p_films, int n, char const *field);

void f_free(film_r *p_films, int n);

void f_print(FILE *f, film_r *p_film, int n);

#endif // FILM_ARR_H
