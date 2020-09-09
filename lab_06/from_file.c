#include "my_utils.h"

int from_file_to_array(FILE *const f, film_r *film)
{
    int right = 1;
    if ((fgets(film->title, MAX_LEN_TITLE, f) != NULL) && \
            (fscanf(f, "%*[\n]") || right) && \
            (fgets(film->name, MAX_LEN_NAME, f) != NULL) && \
            (fscanf(f, "%*[\n]") || right))
    {
        if (film->title[strlen(film->title) - 1] == '\n')
            film->title[strlen(film->title) - 1] = '\0';

        if (film->name[strlen(film->name) - 1] == '\n')
            film->name[strlen(film->name) - 1] = '\0';

        int rc = fscanf(f, "%d\n", &film->year);

        if ((rc != 1) || \
                ((rc == 1) && ((film->year <= MIN_YEAR) || \
                               (film->year >= MAX_YEAR))) || \
                (strlen(film->name) == 0) || \
                (strlen(film->title) == 0) || \
                (strlen(film->name) > MAX_RIGHT_NAMETITLE) || \
                (strlen(film->title) > MAX_RIGHT_NAMETITLE))
            return FILE_INVALID_ARG;
    }
    else
        return FILE_INVALID_ARG;

    return OK;
}

int add_info_txt(film_r films[], const film_r film, int len, char *field)
{
    film_r film_rewrite;
    int pos = 0;

    if (strcmp(field, "title") == 0)
        for (int i = 0; i < len; i++)
        {
            if (strcmp(film.title, films[i].title) < 0)
                break;
            ++pos;
        }

    if (strcmp(field, "name") == 0)
        for (int i = 0; i < len; i++)
        {
            if (strcmp(film.name, films[i].name) < 0)
                break;
            ++pos;
        }

    if (strcmp(field, "year") == 0)
        for (int i = 0; i < len; i++)
        {
            if (film.year < films[i].year)
                break;
            ++pos;
        }

    for (int i = len - 1; i >= pos; i--)
    {
        film_rewrite = films[i];
        films[i] = films[i + 1];
        films[i + 1] = film_rewrite;
    }

    films[pos] = film;

    return OK;
}

int read_from_file_all (film_r *films, FILE *const f, char *argv)
{
    film_r film;

    int len_catalog = 0;

    int rc = from_file_to_array(f, &film);

    if (rc == OK)
    {
        films[0] = film;
        len_catalog++;
    }
    else
        return FILE_INVALID_ARG;

    while (!feof(f))
    {
        rc = from_file_to_array(f, &film);
        if (rc == OK)
        {
            add_info_txt(films, film, len_catalog, argv);
            len_catalog++;
            if (len_catalog >= MAX_LEN_ARRAY)
                return FILE_INVALID_ARG;
        }

        if (rc == FILE_INVALID_ARG)
            return FILE_INVALID_ARG;
    }

    return len_catalog;
}
int check_feild(char *feild)
{
    if ((strcmp(feild, "title") != 0) && (strcmp(feild, "name") != 0) && (strcmp(feild, "year") != 0))
        return INVALID_ARG;

    return OK;
}
int check_key(char *key)
{
    int key_ = atoi(key);

    if ((key_ <= MIN_YEAR) || (key_ >= MAX_YEAR))
        return INVALID_ARG;

    return OK;
}
