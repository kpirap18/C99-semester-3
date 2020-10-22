#include "film_arr.h"

int f_count(FILE *f, int *n)
{
    film_r buf = { NULL, NULL, 0};
    int i = 0, rc = OK;

    while (rc == OK)
    {
        rc = film_read(f, &buf);

        if (rc == OK)
        {
            i++;
            film_free_one(&buf);
        }
    }

    *n = i;

    if (rc != OK && feof(f))
        rc = OK;

    return rc;
}

int f_create(FILE *f, film_r **pp_films, int *n_films, char const *field)
{
    film_r *film;
    int n, rc;

    *pp_films = NULL;
    *n_films = 0;

    rc = f_count(f, &n);

    if (rc == OK)
    {
        film = calloc(n, sizeof(film_r));
        if (film)
        {
            rewind(f);

            rc = f_read(f, film, n, field);

            if (rc == OK)
            {
                *pp_films = film;
                *n_films = n;
            }
            else
            {
                f_free(film, n);
            }
        }
        else
        {
            rc = MEMORY_ERR;
        }
    }

    return rc;
}

int add_in_array(film_r *films, film_r *film, int len, char const *field)
{
    film_r film_rewrite;
        int pos = 0;

        if (strcmp(field, "title") == 0)
            for (int i = 0; i < len; i++)
            {
                if (strcmp(film->title, films[i].title) < 0)
                    break;
                ++pos;
            }

        if (strcmp(field, "name") == 0)
            for (int i = 0; i < len; i++)
            {
                if (strcmp(film->name, films[i].name) < 0)
                    break;
                ++pos;
            }

        if (strcmp(field, "year") == 0)
            for (int i = 0; i < len; i++)
            {
                if (film->year < films[i].year)
                    break;
                ++pos;
            }

        for (int i = len - 1; i >= pos; i--)
        {
            film_rewrite = films[i];
            films[i] = films[i + 1];
            films[i + 1] = film_rewrite;
        }

        film_copy(&films[pos], film);

        return OK;
    }

int f_read(FILE *f, film_r *p_films, int n, char const *field)
{
    int rc = OK;
    film_r buf = { NULL, NULL, 0};

    rc = film_read(f, &buf);
    film_copy(&p_films[0], &buf);

    for (int i = 1; rc == OK && i < n; i++)
    {
        rc = film_read(f, &buf);
        rc = add_in_array(p_films, &buf, i, field);
    }

    return rc;
}

void f_free(film_r *p_films, int n)
{
    for (int i = 0; i < n; i++)
        film_free_one(p_films + i);
    free(p_films);
}

void f_print(FILE *f, film_r *p_film, int n)
{
    for (int i = 0; i < n; i++)
        film_print(f, p_film + i);
}
