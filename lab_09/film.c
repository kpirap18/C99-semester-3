#include "film.h"

int film_read(FILE *f, film_r *p_film)
{
    char title[MAX_LEN_TITLE], name[MAX_LEN_NAME];
    int year;
    int rc = 0;

    int right = 1;
    if ((fgets(title, MAX_LEN_TITLE, f) != NULL) && \
            (fscanf(f, "%*[\n]") || right) && \
            (fgets(name, MAX_LEN_NAME, f) != NULL) && \
            (fscanf(f, "%*[\n]") || right))
    {
        if (title[strlen(title) - 1] == '\n')
            title[strlen(title) - 1] = '\0';

        if (name[strlen(name) - 1] == '\n')
            name[strlen(name) - 1] = '\0';

        rc = fscanf(f, "%d\n", &year);

        if ((rc != 1) || \
                ((rc == 1) && ((year <= MIN_YEAR) || \
                               (year >= MAX_YEAR))) || \
                (strlen(name) == 0) || \
                (strlen(title) == 0) || \
                (strlen(name) > MAX_RIGHT_NAMETITLE) || \
                (strlen(title) > MAX_RIGHT_NAMETITLE))
            return FILE_INVALID_ARG;
        rc = film_init(p_film, title, name, year);
    }
    else
        return FILE_INVALID_ARG;

    return rc;
}

int film_init(film_r *p_film, const char *title, const char *name, int year)
{
    char *tit = strdup(title);
    char *nam = strdup(name);

    if (tit && nam)
    {
        free(p_film->name);
        free(p_film->title);

        p_film->title = tit;
        p_film->name = nam;
        p_film->year = year;

        return OK;
    }

    return READ_ERROR;
}

int film_copy(film_r *to, const film_r *from)
{
    return film_init(to, from->title, from->name, from->year);
}

void film_free_one(film_r *p_film)
{
    free(p_film->title);
    p_film->title = NULL;
    free(p_film->name);
    p_film->name = NULL;
}

void film_print(FILE *f, film_r *p_film)
{
    fprintf(f, "%s\n", p_film->title);
    fprintf(f, "%s\n", p_film->name);
    fprintf(f, "%d\n", p_film->year);
}
