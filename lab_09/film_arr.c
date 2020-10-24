#include "film_arr.h"

int f_count(FILE *f, int *n)
{
    film_r buf = { NULL, NULL, 0};
    int i = 0, rc = OK;

    while (rc == OK && (!feof(f)))
    {
        //printf("rc = %d\n", rc);
        rc = film_read(f, &buf);

        if (rc == OK)
        {
            i++;
            film_free_one(&buf);
        }
    }

    *n = i;

    if (rc != OK && feof(f) && (*n) > 0)
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
            //printf("F_COUNT!!!\n count = %d", n);
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
int swap_film_str(film_r *film1, film_r *film2)
{
    film_r buf = { NULL, NULL, 0};
    int rc = OK;

    if (film_copy(&buf, film1) || film_copy(film1, film2) || film_copy(film2, &buf))
        {
            rc = MEMORY_ERR;
        }
    film_free_one(&buf);

    return rc;
}
int add_in_array(film_r *films, film_r *film, int len, char const *field)
{
    int pos = 0;
    int rc = OK;

    if (strcmp(field, "title") == 0)
    {
        //printf("titile\n");
        for (int i = 0; i < len; i++)
        {
            if (strcmp(film->title, films[i].title) < 0)
                break;
            ++pos;
        }
    }

    if (strcmp(field, "name") == 0)
    {
        //printf("name\n");
        for (int i = 0; i < len; i++)
        {
            if (strcmp(film->name, films[i].name) < 0)
                break;
            ++pos;
        }
    }

    if (strcmp(field, "year") == 0)
    {
        //rintf("year\n");
        for (int i = 0; i < len; i++)
        {
            if (film->year < films[i].year)
                break;
            ++pos;
        }
    }
    //f_print(stdout, films, len);
    //printf("len = %d\npos = %d\n", len, pos);
    for (int i = len - 1; i >= pos; i--)
    {
        //printf("\nfor \n");
        rc = swap_film_str(&films[i], &films[i + 1]);
    }
    //film_print(stdout, film);
    rc = film_copy(&films[pos], film);
    //printf("\nrc = %d\n", rc);
    return rc;
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
        //printf("i = %d\n", i);
        rc = add_in_array(p_films, &buf, i, field);
    }

    return rc;
}

int film_found(film_r *films, char *field, char *key, int len_catalog)
{
    int left = 0;
    int right = len_catalog - 1;
    int search = -1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (strcmp(field, "title") == 0)
        {
            if (strncmp(key, films[mid].title, 
            (strlen(key) < strlen(films[mid].title)) ? strlen(key) : strlen(films[mid].title)) == 0)
            {
                search = mid;
                break;
            }
            if (strncmp(key, films[mid].title, 
            (strlen(key) < strlen(films[mid].title)) ? strlen(key) : strlen(films[mid].title)) < 0)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        if (strcmp(field, "name") == 0)
        {
            if (strncmp(key, films[mid].name, 
            (strlen(key) < strlen(films[mid].name)) ? strlen(key) : strlen(films[mid].name)) == 0)
            {
                search = mid;
                break;
            }
            if (strncmp(key, films[mid].name, 
            (strlen(key) < strlen(films[mid].name)) ? strlen(key) : strlen(films[mid].name)) < 0)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

        if (strcmp(field, "year") == 0)
        {
            int key_year = atoi(key);

            if (key_year == films[mid].year)
            {
                search = mid;
                break;
            }
            if (key_year < films[mid].year)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }

    }
    if (search == -1)
        return NOT_FOUND;
    else
        return search;
}

void f_free(film_r *p_films, int n)
{
    for (int i = 0; i < n; i++)
    {
        film_free_one(p_films + i);
    }
        
    free(p_films);
}

void f_print(FILE *f, film_r *p_film, int n)
{
    for (int i = 0; i < n; i++)
        film_print(f, p_film + i);
}
