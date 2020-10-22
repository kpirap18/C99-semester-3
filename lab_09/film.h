#ifndef FILM_H
#define FILM_H

#include "my_main.h"

int film_read(FILE *f, film_r *p_film);

int film_init(film_r *p_film, const char *title, const char *name, int year);

int film_copy(film_r *to, const film_r *from);

void film_free_one(film_r *p_film);

void film_print(FILE *f, film_r *p_film);

#endif // FILM_H

