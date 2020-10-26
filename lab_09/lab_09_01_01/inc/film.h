#ifndef FILM_H
#define FILM_H

#include "app.h"

int film_read(FILE *f, film_r *p_film);

int film_init(film_r *p_film, const char *title, const char *name, int year);

int film_copy(film_r *to, const film_r *from);

void film_free_one(film_r *p_film);

void film_print(FILE *f, film_r *p_film);

int add_in_array(film_r *films, film_r *film, int len, char const *field);

int swap_film_str(film_r *film1, film_r *film2);


#endif // FILM_H

