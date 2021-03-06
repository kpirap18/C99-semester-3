#include "film.h"

int film_read(FILE *f, film_r *p_film)
{
    char *title = NULL, *name = NULL;
    int year;
    size_t n = 0;
    int rc = 0;

    ssize_t read;

    if ((read = getline(&title, &n, f)) != -1)
    {
        n = 0;
        title[strlen(title) - 1] = '\0';

        if ((read = getline(&name, &n, f)) != -1)
        {
            name[strlen(name) - 1] = '\0';
            rc = fscanf(f, "%d\n", &year);

            if ((rc == 1) && ((year > MIN_YEAR) && (year < MAX_YEAR)) && \
                    (strlen(name) != 0) && \
                    (strlen(title) != 0))
            {
                rc = film_init(p_film, title, name, year);
            }
            else
            {
                rc = FILE_INVALID_ARG;
            }
        }
        else
        {
            rc = FILE_INVALID_ARG;
        }
    }
    else
    {
        rc = FILE_INVALID_ARG;
    }
    
    free(title);
    free(name);

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
    else
    {
        free(tit);
        free(nam);
    }
    
    return READ_ERROR;
}

int film_copy(film_r *to, const film_r *from)
{
    if (from->year == 0 || from->title == NULL || from->name == NULL)
    {
        film_free_one(to);
        to->title = NULL;
        to->name = NULL;
        to->year = 0;

        return OK;
    }
    
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
