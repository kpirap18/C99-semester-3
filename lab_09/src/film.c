#include "film.h"
#define _POSIX_X_SOURCE 200809L
/*int film_read(FILE *f, film_r *p_film)
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
}*/

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
        //printf("%s", title);
        if (title[strlen(title) - 2] == '\n')
            title[strlen(title) - 2] = '\0';

        //printf("%s", title);
        if ((read = getline(&name, &n, f)) != -1)
        {
            //printf("%s", name);
            if (name[strlen(name) - 2] == '\n')
                name[strlen(name) - 2] = '\0';
            //printf("%s", name);
            rc = fscanf(f, "%d\n", &year);

            //printf("%d", year);
            if ((rc != 1) || \
                    ((rc == 1) && ((year <= MIN_YEAR) || \
                                (year >= MAX_YEAR))) || \
                    (strlen(name) == 0) || \
                    (strlen(title) == 0))
            {
                //printf("jjj");
                rc = FILE_INVALID_ARG;
            }
            //printf("%d", rc);
            if (rc == 1)
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
    
    free(title);
    free(name);

    return rc;
}

int film_init(film_r *p_film, const char *title, const char *name, int year)
{
    char *tit = NULL;
    char *nam = NULL;
    int rc = OK;

    tit = malloc((strlen(title) + 1) * sizeof(char));
    if (tit)
    {
        nam = malloc((strlen(name) + 1) * sizeof(char));
        if (nam)
        {
            tit = strcpy(tit, title);
            nam = strcpy(nam, name);

            free(p_film->name);
            free(p_film->title);

            p_film->title = tit;
            p_film->name = nam;
            p_film->year = year;

            rc = OK;
        }
        else
        {
            printf("No nam\n");
            free(tit);
            rc = MEMORY_ERR;
        }
    }
    else
    {
        printf("No tit\n");
        rc = READ_ERROR;
    }
    
    return rc;
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
